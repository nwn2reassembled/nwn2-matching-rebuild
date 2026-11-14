"""Crash-persistent, exclusive native attempt journals; never reset old histories.

Opt-in utility, not connected to running controllers. A truncated final append is
a blocker, not permission to roll back a sent request. Hash chains detect accidental
corruption; they are not signatures or protection against a malicious file owner.
"""
import fcntl
import json
import os
from pathlib import Path

from native_unit import digest, hash_value, require, text
from native_workflow import attempt_transition


def _record(previous, event):
    record = {'previous': previous, 'event': event}
    record['sha256'] = digest(record)
    return record


def _write(stream, record):
    stream.write(json.dumps(record, sort_keys=True, separators=(',', ':')) + '\n')
    stream.flush()
    os.fsync(stream.fileno())


def create_journal(path, attempt_id, context_sha256):
    text(attempt_id)
    hash_value(context_sha256)
    state = {'id': attempt_id, 'context_sha256': context_sha256, 'state': 'planned',
             'submission_limit': 3, 'requests_sent': 0, 'request_ids': [], 'outstanding': None}
    # Exclusive creation, no automatic replacement or truncation of prior history.
    with Path(path).open('x', encoding='utf-8') as stream:
        fcntl.flock(stream, fcntl.LOCK_EX)
        _write(stream, _record(None, {'kind': 'initialize', 'state': state}))
    descriptor = os.open(Path(path).parent, os.O_RDONLY | os.O_DIRECTORY)
    try:
        os.fsync(descriptor)
    finally:
        os.close(descriptor)
    return state


def _read(stream):
    content = stream.read()
    require(content and content.endswith('\n'), 'Incomplete attempt journal; preserve and investigate')
    state, previous = None, None
    for index, line in enumerate(content.splitlines()):
        record = json.loads(line)
        expected = dict(record)
        checksum = expected.pop('sha256')
        require(checksum == digest(expected) and record['previous'] == previous, 'Journal chain disagreement')
        event = record['event']
        if index == 0:
            require(event['kind'] == 'initialize', 'Missing journal initialization')
            state = event['state']
            text(state['id'])
            hash_value(state['context_sha256'])
            require(state == {'id': state['id'], 'context_sha256': state['context_sha256'], 'state': 'planned',
                              'submission_limit': 3, 'requests_sent': 0, 'request_ids': [], 'outstanding': None},
                    'Invalid initial budget')
        else:
            state = attempt_transition(state, event)
        previous = checksum
    return state, previous


def read_journal(path):
    with Path(path).open(encoding='utf-8') as stream:
        fcntl.flock(stream, fcntl.LOCK_SH)
        return _read(stream)[0]


def append_event(path, event, expected_state_sha256):
    with Path(path).open('r+', encoding='utf-8') as stream:
        fcntl.flock(stream, fcntl.LOCK_EX)
        state, previous = _read(stream)
        require(digest(state) == expected_state_sha256, 'Stale attempt state; no overwrite')
        result = attempt_transition(state, event)
        stream.seek(0, os.SEEK_END)
        _write(stream, _record(previous, event))
        return result
