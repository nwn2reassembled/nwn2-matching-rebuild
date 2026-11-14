"""Offline contexts, regression plans, routing, accounting and attempt state.

These utilities never call models/compilers or mutate existing controller ledgers.
Plans are advisory until the trusted compiler/independent-review chain executes.
"""
from collections import Counter
import json

from matching import sha256
from native_unit import digest, hash_value, number, require, validate_unit
from native_verify import validate_receipt, verifier_identity

FAILURES = {'waiting', 'capability-blocked-unattempted', 'declaration-blocked', 'abi-blocked',
            'compile-failure', 'ordinary-mismatch', 'local-exact-awaiting-independent-verification',
            'checker-disagreement', 'stale-context', 'uncertain-request', 'infrastructure-failure',
            'integration-regression', 'output-token-exhausted', 'budget-exhausted'}


def context_pack(unit, prior_attempts=()):
    """No function bodies, target instructions, assets, or secrets in task packets."""
    validate_unit(unit)
    pack = {'schema_version': 1, 'unit': unit['id'], 'unit_sha256': digest(unit),
            'target': unit['target'], 'recipe': unit['recipe'], 'files': unit['files'],
            'evidence': unit['evidence'], 'bindings': unit['bindings'],
            'regions': unit['regions'], 'eh_closures': unit['eh_closures'],
            'names': unit.get('names', []),
            'verifier': verifier_identity(), 'prior_attempts': []}
    for attempt in prior_attempts:
        require(attempt['state'] in FAILURES, 'Unknown attempt classification')
        # Do not forward free-form model output or arbitrary checkpoint payloads.
        pack['prior_attempts'].append({k: attempt[k] for k in
                                       ('id', 'state', 'requests_sent', 'submissions_used', 'context_sha256')})
    pack['context_sha256'] = digest(pack)
    return pack


def route(unit, *, idle, uncertain=False, spent=False, declarations_ready=True,
          abi_ready=True, measured_cost=None):
    if spent or uncertain:
        return {'action': 'preserve-no-replay', 'reason': 'spent-or-uncertain-history'}
    if not declarations_ready or not abi_ready:
        return {'action': 'dependency-repair', 'reason': 'declarations' if not declarations_ready else 'abi'}
    try:
        validate_unit(unit)
    except (ValueError, KeyError, TypeError):
        return {'action': 'capability-blocked-unattempted', 'reason': 'missing-reviewed-context'}
    if not idle:
        return {'action': 'waiting', 'reason': 'idle-only', 'requests_consumed': 0}
    complex_unit = bool(unit['eh_closures']) or len(unit['bindings']) > 8 or len(unit['regions']) > 4
    return {'action': 'parent-review-required' if complex_unit else 'eligible-for-existing-local-lane-review',
            'size_bytes': sum(r['size'] for r in unit['regions']), 'measured_cost': measured_cost,
            'dispatch_enabled': False, 'submission_limit': 3, 'concurrency_limit': 3}


def attempt_transition(state, event):
    """Pure, append-journal-friendly reducer. No reset/resume-after-exhaustion event.

    Caller persists request-sent BEFORE network I/O; an outstanding request survives
    a crash as uncertain and cannot be replayed. Waiting never burns requests.
    """
    current = dict(state)
    require(current['submission_limit'] == 3, 'Historical limit cannot be raised')
    number(current['requests_sent'], 0, 3)
    terminal = {'output-token-exhausted', 'budget-exhausted', 'uncertain-request',
                'local-exact-awaiting-independent-verification', 'infrastructure-failure',
                'checker-disagreement', 'stale-context', 'integration-regression',
                'declaration-blocked', 'abi-blocked'}
    kind = event['kind']
    if kind == 'waiting':
        require(current['state'] not in terminal and current.get('outstanding') is None, 'Terminal/outstanding request')
        current['state'] = 'waiting'
    elif kind == 'request-sent':
        require(current['state'] not in terminal and current.get('outstanding') is None, 'No replay of terminal/outstanding request')
        require(current['requests_sent'] < 3 and event['context_sha256'] == current['context_sha256'], 'Budget/stale context')
        require(event['request_id'] and event['request_id'] not in current['request_ids'], 'Duplicate request identity')
        current['requests_sent'] += 1
        current['request_ids'] = current['request_ids'] + [event['request_id']]
        current.update(outstanding=event['request_id'], state='request-outstanding')
    elif kind == 'response':
        require(current['state'] == 'request-outstanding' and current.get('outstanding') == event['request_id'], 'No matching outstanding request')
        require(event['result'] in FAILURES - {'waiting', 'capability-blocked-unattempted'}, 'Invalid response classification')
        current.update(outstanding=None, state=event['result'])
        if current['requests_sent'] == 3 and current['state'] not in terminal:
            current['state'] = 'budget-exhausted'
    elif kind == 'response-lost':
        require(current['state'] == 'request-outstanding', 'No outstanding request')
        current['state'] = 'uncertain-request'
    else:
        raise ValueError('Unsupported event; budgets cannot be reset')
    return current


def regression_plan(before, after, changed_files=(), discovery_uncertain=False):
    """Conservative immutable plan: recipe/evidence changes invalidate all units.

    Input paths from all headers must be declared. Uncertain include discovery or
    changed undeclared files rebuild everything; no comment-only bypass.
    """
    for units in (before, after):
        for key, unit in units.items():
            validate_unit(unit)
            require(key == unit['id'], 'Unit map identity mismatch')
    changed = set(changed_files)
    declared = {f['path'] for u in list(before.values()) + list(after.values()) for f in u['files'].values()}
    global_change = discovery_uncertain or bool(changed - declared)
    changed_units = {k for k in set(before) | set(after)
                     if k not in before or k not in after or digest(before[k]) != digest(after[k])}
    # Bindings/EH/ABI can cross unit boundaries. Until dependency discovery is
    # independently proven complete, any changed recipe/context rebuilds all.
    if changed_units:
        global_change = True
    affected = set(after) if global_change else {k for k, u in after.items()
                                                 if changed & {f['path'] for f in u['files'].values()}}
    plan = {'schema_version': 1, 'before': {k: digest(v) for k, v in sorted(before.items())},
            'after': {k: digest(v) for k, v in sorted(after.items())},
            'affected': sorted(affected), 'removed': sorted(set(before) - set(after)),
            'conservative_full_rebuild': global_change, 'changed_files': sorted(changed),
            'verifier': verifier_identity(), 'acceptance': 'independent-pinned-reference-not-baseline-only'}
    plan['plan_sha256'] = digest(plan)
    return plan


def assess_plan(plan, units, receipts):
    content = dict(plan)
    recorded = content.pop('plan_sha256')
    require(recorded == digest(content) and plan['verifier'] == verifier_identity(), 'Stale/tampered plan')
    require(plan['after'] == {k: digest(v) for k, v in sorted(units.items())}, 'Stale plan inputs')
    require(set(receipts) == set(plan['affected']), 'Missing/extra shard results')
    for key in plan['affected']:
        validate_receipt(receipts[key], units[key])
    regressions = sorted(k for k in receipts if not receipts[k]['all_regions_exact'])
    return {'plan_sha256': recorded, 'regressions': regressions,
            'state': 'integration-regression' if regressions else 'ready-for-independent-parent-review',
            'baseline_modified': False, 'integration_credit': False,
            'removed_units_require_review': plan['removed']}


def coverage(items, ranges):
    """Logical item counts and per-artifact physical union bytes are separate."""
    identities = [i['id'] for i in items]
    require(len(identities) == len(set(identities)), 'Duplicate logical inventory identity')
    grouped = {}
    functions = set()
    for record in ranges:
        require(record['independently_verified'] is True, 'Candidate ranges are not coverage')
        key = (record['binary'], record['artifact_sha256'])
        hash_value(record['artifact_sha256'])
        start, size = number(record['rva']), number(record['size'], 1)
        require(start + size <= 0x100000000, 'Coverage range overflow')
        grouped.setdefault(key, []).append((start, start + size))
        if record['kind'] == 'function':
            functions.add((key, start))
    union = []
    for key, spans in sorted(grouped.items()):
        merged = []
        for start, end in sorted(spans):
            if merged and start <= merged[-1][1]:
                merged[-1][1] = max(merged[-1][1], end)
            else:
                merged.append([start, end])
        union.append({'binary': key[0], 'artifact_sha256': key[1], 'ranges': merged,
                      'unique_bytes': sum(end - start for start, end in merged)})
    return {'known_items': len(items), 'item_states': dict(Counter(i['status'] for i in items)),
            'unique_function_entries': len(functions), 'physical': union,
            'unique_bytes': sum(r['unique_bytes'] for r in union), 'exact_artifact_claim': False}


def project_scope(root):
    """Overlay current trusted ledgers on the frozen corpus, without new credit.

    Detect concurrent input changes rather than publishing an inconsistent report.
    No reference payloads, candidate source or receipt bytes enter this report.
    """
    snapshots = {}

    def load(path):
        data = path.read_bytes()
        snapshots[path] = data
        return json.loads(data)

    policy = load(root / 'progress/full_corpus01.json')
    queue_path = root / policy['queue']
    require(queue_path.resolve().is_relative_to(root.resolve()), 'Corpus path escapes project')
    queue = load(queue_path)
    require(sha256(snapshots[queue_path]) == policy['queue_sha256'], 'Frozen corpus changed')
    items = [dict(i) for i in queue['items']]
    require(len(items) == policy['known_items'], 'Corpus denominator changed')
    pins = load(root / 'reference/pins.json')
    ledger = load(root / 'progress/functions.json')
    by_native = {(i['binary'], int(i['rva'], 0)): i for i in items if i['kind'] == 'native-function'}
    for path in sorted((root / 'progress').glob('gptoss_batch*.json')):
        for function in load(path)['functions']:
            key = (function.get('binary', 'NWN2RulesLib.dll'), int(function['rva'], 0))
            if key not in by_native:
                continue
            item = by_native[key]
            status = function['status']
            if status == 'planned':
                item['status'] = 'reserved-unattempted'
                trial = f"gptoss_b{path.stem.removeprefix('gptoss_batch')}_{function['ordinal']:02}_{int(function['rva'], 0):x}"
                assessment_path = root / f'evidence/{trial}_assessment.json'
                if assessment_path.exists():
                    assessment = load(assessment_path)
                    if assessment.get('binary') is None:
                        item['status'] = 'legacy-assessment-identity-unconfirmed'
                    else:
                        require(assessment['binary'] == key[0] and int(assessment['rva'], 0) == key[1],
                                'Assessment identity disagreement')
                        item['status'] = ('output-token-exhausted' if assessment.get('error') == 'Output token budget exhausted'
                                          else 'existing-assessment-not-credited')
            elif status == 'needs-parent-intervention':
                item['status'] = 'attempted-needs-parent-intervention'
            elif status == 'ledger-promoted':
                # Only the ledger below, not the batch's own claim, grants credit.
                item['status'] = 'awaiting-ledger-confirmation'
            else:
                item['status'] = 'in-progress-or-unclassified-not-credited'
    ranges = []
    for function in ledger['functions']:
        if not function['raw_function_match']:
            continue
        require(function['binary_sha256'] == pins[function['binary']]['sha256'], 'Ledger pin mismatch')
        rva = int(function['rva'], 0)
        require((function['binary'], rva) in by_native, 'Ledger identity outside frozen corpus')
        by_native[(function['binary'], rva)]['status'] = 'independently-verified-function'
        ranges.append({'binary': function['binary'], 'artifact_sha256': function['binary_sha256'],
                       'rva': rva, 'size': function['reference_instruction_bytes'],
                       'kind': 'function', 'independently_verified': True})
    report = coverage(items, ranges)
    require(report['unique_function_entries'] == ledger['source_derived_exact_function_count'] and
            report['unique_bytes'] == ledger['source_derived_exact_instruction_bytes'],
            'Ledger duplicate/overlap/total disagreement')
    report['code_routines'] = sum(i['kind'] in {'native-function', 'managed-method'} for i in items)
    report['resource_entries'] = len(items) - report['code_routines']
    report['authority'] = 'existing-ledger-readback-not-new-verification'
    report['input_sha256'] = {str(p.relative_to(root)): sha256(v) for p, v in snapshots.items()}
    require(all(p.read_bytes() == content for p, content in snapshots.items()), 'Concurrent snapshot change; retry report only')
    return report
