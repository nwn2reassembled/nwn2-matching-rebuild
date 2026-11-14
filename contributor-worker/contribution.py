"""Create a source-and-hashes-only GitHub contribution; never ship originals."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import zipfile

FLAGS = ['/c', '/O2', '/GS-', '/GR-', '/Zl', '/Gy']


def digest(data):
    return hashlib.sha256(data).hexdigest()


def hash_field(value):
    if not isinstance(value, str) or not re.fullmatch(r'[0-9a-f]{64}', value):
        raise ValueError('Expected a lowercase SHA256 digest')
    return value


def safe_source(source):
    if not source or len(source) > 12000:
        raise ValueError('Source outside bounded lane')
    plain = re.sub(r'/\*.*?\*/|//[^\n]*', '', source, flags=re.S)
    if re.search(r'#|\b(?:__asm|asm|__declspec|__emit|volatile|register|main|system|fopen|LoadLibrary|WinExec|CreateProcess)\b', plain):
        raise ValueError('Ordinary header-free C++03 only; no instruction emission or forced codegen')
    if not re.search(r'\b\w+::\w+\s*\(', plain):
        raise ValueError('Bounded lane requires an out-of-line member function')
    if re.search(r'["\']', plain):
        raise ValueError('String/character payloads are outside this bounded integer/pointer lane')
    if (re.search(r'\b(?:[0-9a-fA-F]{2}\s+){4,}[0-9a-fA-F]{2}\b', source) or
            re.search(r'^\s*//\s*(?:[0-9a-fA-F]{4,}:|L[0-9a-fA-F]+:)', source, re.M)):
        raise ValueError('Remove original instruction dumps through a separately verified source change before export')
    for name in ('OPENAI_API_KEY', 'ANTHROPIC_API_KEY', 'DEEPSEEK_API_KEY'):
        secret = os.environ.get(name, '').strip()
        if secret and secret in source:
            raise ValueError('Credential detected in source; refusing export')


def export(source_path, task, result, destination):
    source_bytes = Path(source_path).read_bytes()
    source = source_bytes.decode('utf-8')
    safe_source(source)
    if result.get('status') != 'pass' or result.get('normalization') != 'none':
        raise ValueError('Only unmasked locally reported passes can be exported as pass submissions')
    if result.get('source_sha256') != digest(source_bytes):
        raise ValueError('Source changed since local verification')
    binary = task['binary']
    if binary not in ('NWN2RulesLib.dll', 'nwn2main.exe', 'nwn2server.exe'):
        raise ValueError('Binary not in the native contribution lane')
    rva = int(task['rva'], 0)
    size = task['size']
    if rva < 0 or not isinstance(size, int) or isinstance(size, bool) or not 1 <= size <= 256:
        raise ValueError('Invalid bounded function extent')
    # Allowlist every exported field: assembly, logs, paths and provider responses
    # are deliberately never copied from the task or local result.
    public_task = {'binary': binary, 'binary_sha256': hash_field(task['binary_sha256']),
                   'rva': hex(rva), 'size': size}
    task_id = digest(json.dumps(public_task, sort_keys=True).encode())[:24]
    runs = result['runs']
    if len(runs) != 2 or result['compiler_arguments'] != FLAGS:
        raise ValueError('Pinned flags and two independent compile results required')
    checks = []
    for run in runs:
        if run.get('exact') is not True or run.get('size') != size or run.get('relocations') != []:
            raise ValueError('Every complete function must match without unresolved relocations')
        checks.append({'exact': True, 'size': size, 'relocations': [],
                       'function_sha256': hash_field(run['function_sha256']),
                       'object_sha256': hash_field(run['object_sha256'])})
    if checks[0]['function_sha256'] != checks[1]['function_sha256']:
        raise ValueError('Repeat function bytes differ')
    public_result = {'schema': 1, 'task_id': task_id,
        'status': 'contributor-reported-pass-requires-project-reverification',
        'source_sha256': digest(source_bytes), 'normalization': 'none',
        'compiler_arguments': FLAGS, 'runs': checks,
        'toolchain_manifest_sha256': hash_field(result['toolchain_manifest_sha256']),
        'credit_requested': 'complete-function-only', 'whole_file_identity': False,
        'behavioral_identity': 'not-claimed'}
    public_provenance = {'schema': 1, 'task_id': task_id,
        'generation': result.get('generation', 'unspecified'),
        'assisted_context': bool(result.get('assisted_context', False)),
        'secrets_or_original_payloads_included': False,
        'note': 'Local receipts are claims, not trusted CI results. Rebuild against project pins before merge/credit.'}
    if public_provenance['generation'] not in ('openai', 'anthropic', 'deepseek', 'local-model', 'human', 'unspecified'):
        raise ValueError('Unknown generation provenance')
    contents = {'source.cpp': source_bytes,
        'task.json': (json.dumps(public_task, indent=2)+'\n').encode(),
        'result.json': (json.dumps(public_result, indent=2)+'\n').encode(),
        'provenance.json': (json.dumps(public_provenance, indent=2)+'\n').encode()}
    for content in contents.values():
        for name in ('OPENAI_API_KEY', 'ANTHROPIC_API_KEY', 'DEEPSEEK_API_KEY'):
            secret = os.environ.get(name, '').strip()
            if secret and secret.encode() in content:
                raise ValueError('Credential detected in export; refusing to write archive')
    with zipfile.ZipFile(destination, 'x', compression=zipfile.ZIP_DEFLATED) as archive:
        for filename, data in contents.items():
            entry = zipfile.ZipInfo(f'contributions/{task_id}/{filename}', date_time=(1980,1,1,0,0,0))
            entry.compress_type = zipfile.ZIP_DEFLATED
            entry.external_attr = 0o100644 << 16
            archive.writestr(entry, data)
    return {'task_id': task_id, 'files': len(contents), 'sha256': digest(Path(destination).read_bytes())}


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--source', type=Path, required=True)
    parser.add_argument('--task', type=Path, required=True)
    parser.add_argument('--result', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    print(json.dumps(export(args.source, json.loads(args.task.read_text()),
                            json.loads(args.result.read_text()), args.output), indent=2))
