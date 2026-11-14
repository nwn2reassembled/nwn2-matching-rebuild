"""Three-stage Compose worker; durable one-request budgets, no automatic upload."""
import argparse
import fcntl
import json
import os
from pathlib import Path
import re
import shutil
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
from matching import extract_function, sha256
from bootstrap import checked_file, digest, extract_gog, extract_sdk, find_references, validate_toolchain
from contribution import export, safe_source
from providers import generate, PROVIDERS

STATE = Path('/state')
EXCHANGE = Path('/exchange')
OUTPUT = Path('/out')
INPUTS = Path('/inputs')
WORK = Path('/work')


def read_json(path):
    return json.loads(Path(path).read_text())


def write_new(path, data):
    with Path(path).open('x') as stream:
        json.dump(data, stream, indent=2); stream.write('\n')


def canonical_hash(data):
    return sha256(json.dumps(data, sort_keys=True, separators=(',', ':')).encode())


def selected_task():
    identity = os.environ.get('TASK_ID', 'rules-03a90')
    if not re.fullmatch(r'[a-z0-9-]{1,64}', identity):
        raise ValueError('Invalid task identifier')
    tasks = read_json(ROOT / 'reference/tasks.json')['tasks']
    matches = [t for t in tasks if t['id'] == identity]
    if len(matches) != 1:
        raise ValueError('Choose a curated task from reference/tasks.json')
    task = matches[0]
    pins = read_json(ROOT / 'reference/pins.json')
    if task['binary'] not in pins or not 1 <= task['size'] <= 256 or not task['boundary_evidence']:
        raise ValueError('Malformed curated task')
    task = {**task, 'binary_sha256': pins[task['binary']]['sha256']}
    return task


def assembly_packet(reference, task):
    from capstone import Cs, CS_ARCH_X86, CS_MODE_32, CS_GRP_CALL, CS_GRP_JUMP, CS_GRP_RET
    from capstone.x86 import X86_OP_IMM, X86_OP_MEM
    md = Cs(CS_ARCH_X86, CS_MODE_32); md.detail = True
    start = int(task['rva'], 0); end = start + len(reference)
    instructions = list(md.disasm(reference, start))
    if not instructions or sum(i.size for i in instructions) != len(reference):
        raise ValueError('Incomplete reference decode')
    if CS_GRP_RET not in instructions[-1].groups:
        raise ValueError('Curated extent must end at return')
    entries = {i.address for i in instructions}
    for insn in instructions:
        if CS_GRP_CALL in insn.groups or insn.mnemonic in ('int', 'int3', 'syscall', 'sysenter'):
            raise ValueError('Calls/traps outside bounded leaf lane')
        if CS_GRP_JUMP in insn.groups:
            if len(insn.operands) != 1 or insn.operands[0].type != X86_OP_IMM or insn.operands[0].imm not in entries:
                raise ValueError('External, indirect or mid-instruction branch')
        if any(o.type == X86_OP_MEM and not o.mem.base and not o.mem.index for o in insn.operands):
            raise ValueError('Absolute memory dependencies outside bounded lane')
    return '\n'.join(f'{i.address - start:04x}: {i.mnemonic} {i.op_str}' for i in instructions)


def make_prompt(assembly):
    return ("Reconstruct readable header-free C++03 for one x86 MSVC 2005 SP1 /O2 function.\n"
            "Goal: identical complete instruction bytes, not just equivalent behavior.\n"
            "Return JSON with exactly source (full C++ source). Define one ordinary struct\n"
            "member, declared inside the struct and defined out of line. Infer calling convention,\n"
            "types and field offsets. No includes, inline assembly, byte payloads, comments,\n"
            "strings, pragmas, forced codegen attributes or external dependencies.\n"
            "Compiler flags: /c /O2 /GS- /GR- /Zl /Gy. Never execute code or request tools.\n"
            "Target instruction offsets are relative to function start:\n" + assembly)


def source_check(source):
    safe_source(source)
    if not source.isascii() or '\x00' in source or '\\' in source:
        raise ValueError('Bounded source must be ASCII without escapes')
    if re.search(r'\b(?:sk-[A-Za-z0-9_-]{20,}|gh[pousr]_[A-Za-z0-9]{20,}|github_pat_[A-Za-z0-9_]+)\b', source):
        raise ValueError('Credential-like content in source')
    if re.search(r'/var/home/|/home/|\b192\.168\.|\b10\.\d+\.\d+\.\d+', source):
        raise ValueError('Private infrastructure in source')
    # Keep model comments out of public source instead of silently rewriting them.
    if '/*' in source or '//' in source:
        raise ValueError('This bounded submission lane requires comment-free source')


def prepare():
    if os.environ.get('ACCEPT_INPUT_LICENSES') != 'yes':
        raise ValueError('Review your input licenses and set ACCEPT_INPUT_LICENSES=yes')
    task = selected_task(); contract = read_json(ROOT / 'reference/toolchain.json')
    pins = read_json(ROOT / 'reference/pins.json')
    identity = canonical_hash({'task': task, 'contract': contract, 'pins': pins})
    toolchain = STATE / 'toolchain'; references = STATE / 'references'
    if (STATE / 'ready.json').exists():
        # Private inputs are immutable once prepared. Rehash cached content every run.
        validate_toolchain(toolchain, contract)
        for name, pin in pins.items():
            checked_file(references / name, pin['sha256'], pin['size'])
    else:
        write_new(STATE / 'preparation-started.json', {'schema': 1})
        if (INPUTS / 'compiler/cl.exe').exists():
            validate_toolchain(INPUTS / 'compiler', contract)
            toolchain.mkdir()
            for entry in contract['files']:
                target = toolchain / entry['path']; target.parent.mkdir(parents=True, exist_ok=True)
                shutil.copyfile(INPUTS / 'compiler' / entry['path'], target)
        else:
            iso = INPUTS / 'compiler' / contract['iso']['filename']
            extract_sdk(iso, toolchain, STATE / 'sdk-extraction', contract)
        if (INPUTS / 'references').is_dir():
            found = find_references(INPUTS / 'references', pins)
        else:
            found = extract_gog(INPUTS / 'gog', STATE / 'gog-extracted', pins, STATE)
        references.mkdir()
        for name, original in found.items():
            shutil.copyfile(original, references / name)
        # The success marker appears only after a real compiler smoke, before paid calls.
        from compile_lane import smoke
        try:
            smoke(toolchain, contract, WORK / 'preflight')
        finally:
            save_logs(WORK / 'preflight', STATE / 'preflight-logs')
        write_new(STATE / 'ready.json', {'toolchain_manifest_sha256': canonical_hash(contract)})
    if read_json(STATE / 'ready.json')['toolchain_manifest_sha256'] != canonical_hash(contract):
        raise ValueError('Prepared toolchain contract changed; preserve volume and investigate')
    code, metadata = extract_function(references / task['binary'], pins[task['binary']],
        int(task['rva'], 0), task['size'], task['boundary_evidence'])
    if metadata['relocations']:
        raise ValueError('Curated reference has overlapping relocations')
    packet = {'schema': 1, 'identity': identity, 'task': task,
              'prompt': make_prompt(assembly_packet(code, task))}
    folder = EXCHANGE / task['id']; folder.mkdir(exist_ok=True)
    if (folder / 'packet.json').exists():
        if read_json(folder / 'packet.json') != packet:
            raise ValueError('Task packet changed; never reset existing attempt')
    else:
        write_new(folder / 'packet.json', packet)
    return {'status': 'ready', 'task': task['id']}


def draft():
    task = selected_task(); folder = EXCHANGE / task['id']
    packet = read_json(folder / 'packet.json')
    if packet['task'] != task:
        raise ValueError('Prepared task differs from selected queue entry')
    if os.environ.get('SEND_REFERENCE_TO_PROVIDER') != 'yes':
        raise ValueError('Explicit consent required before sending selected disassembly to a provider')
    provider = os.environ.get('PROVIDER', '')
    model = os.environ.get('MODEL', '')
    tokens = int(os.environ.get('MAX_TOKENS', '4096'))
    if provider not in ('openai', 'anthropic', 'deepseek') or not model.strip() or not 256 <= tokens <= 16384:
        raise ValueError('Choose a provider/model and MAX_TOKENS between 256 and 16384')
    config = {'identity': packet['identity'], 'provider': provider, 'model': model, 'max_tokens': tokens}
    with (folder / 'draft.lock').open('a') as lock:
        fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
        if (folder / 'request-started.json').exists():
            if read_json(folder / 'request-started.json') != config:
                raise ValueError('Attempt configuration changed; cannot reset its budget')
            if (folder / 'draft.json').exists():
                saved = read_json(folder / 'draft.json')
                if digest(folder / 'candidate.cpp') != saved['source_sha256']:
                    raise ValueError('Saved source changed')
                return {'status': 'saved-draft-reused-no-request', 'task': task['id']}
            raise ValueError('Request already consumed or interrupted; no automatic retry or continuation')
        if not os.environ.get(PROVIDERS[provider][1], '').strip():
            raise ValueError('Selected provider key is missing; no request reserved or sent')
        # Reserve BEFORE HTTP. Even a crash or connection error cannot trigger a paid retry.
        write_new(folder / 'request-started.json', config)
        try:
            submission = generate(provider, model, packet['prompt'], tokens)
            source_check(submission['source'])
            with (folder / 'candidate.cpp').open('x') as stream:
                stream.write(submission['source'])
            write_new(folder / 'draft.json', {'provider': provider, 'model': model,
                'source_sha256': digest(folder / 'candidate.cpp'), 'usage': submission['usage'],
                'identity': packet['identity']})
        except Exception as exc:
            # No exception text/provider response is persisted; it could contain secrets.
            write_new(folder / 'draft-failure.json', {'status': 'closed-no-retry', 'exception_type': type(exc).__name__})
            raise RuntimeError('Draft attempt closed; no automatic retry; see private failure category') from None
    return {'status': 'drafted', 'task': task['id'], 'requests': 1}


def verify():
    from compile_lane import verify_source
    task = selected_task(); folder = EXCHANGE / task['id']
    packet = read_json(folder / 'packet.json'); drafted = read_json(folder / 'draft.json')
    contract = read_json(ROOT / 'reference/toolchain.json'); pins = read_json(ROOT / 'reference/pins.json')
    if packet['task'] != task or drafted['identity'] != packet['identity']:
        raise ValueError('Task/draft identity changed')
    if read_json(STATE / 'ready.json')['toolchain_manifest_sha256'] != canonical_hash(contract):
        raise ValueError('Prepared compiler contract changed')
    source_path = folder / 'candidate.cpp'; source = source_path.read_text()
    source_check(source)
    if digest(source_path) != drafted['source_sha256']:
        raise ValueError('Source differs from saved draft')
    reference, meta = extract_function(STATE / 'references' / task['binary'], pins[task['binary']],
        int(task['rva'], 0), task['size'], task['boundary_evidence'])
    if meta['relocations']:
        raise ValueError('Reference relocations outside bounded lane')
    destination = OUTPUT / task['id']; destination.mkdir(exist_ok=True)
    with (destination / 'verify.lock').open('a') as lock:
        fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
        if (destination / 'attempt-started.json').exists():
            raise ValueError('Verification already consumed; preserve previous result, no overwrite')
        write_new(destination / 'attempt-started.json', {'source_sha256': drafted['source_sha256']})
        try:
            runs = verify_source(source, reference, task, STATE / 'toolchain', contract, WORK / 'verify')
            result = {'status': 'pass' if all(r['exact'] for r in runs) else 'mismatch',
                'normalization': 'none', 'source_sha256': drafted['source_sha256'],
                'compiler_arguments': contract['flags'], 'runs': runs,
                'toolchain_manifest_sha256': canonical_hash(contract),
                'generation': drafted['provider'], 'assisted_context': False,
                'task_kind': task['kind'], 'automatic_project_credit': False}
            write_new(destination / 'result.json', result)
            if result['status'] == 'pass':
                export(source_path, task, result, destination / 'contribution.zip')
            return {'status': result['status'], 'task': task['id'], 'whole_file_identity': False,
                    'archive_created': result['status'] == 'pass', 'automatic_project_credit': False}
        except Exception as exc:
            write_new(destination / 'failure.json', {'status': 'closed-no-retry', 'exception_type': type(exc).__name__})
            raise RuntimeError('Verification closed; inspect private logs/results; no upload or credit') from None
        finally:
            save_logs(WORK / 'verify', destination / 'private-logs')


def save_logs(work, destination):
    """Only local diagnostic logs, never public archives; preserve on failures too."""
    destination = Path(destination)
    destination.mkdir(exist_ok=True)
    for path in Path(work).rglob('*.log'):
        if not path.is_symlink() and path.stat().st_size < 4_000_000:
            target = destination / ('-'.join(path.relative_to(work).parts))
            if not target.exists():
                shutil.copyfile(path, target)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('stage', choices=('prepare', 'draft', 'verify'))
    args = parser.parse_args()
    os.umask(0o077)
    try:
        print(json.dumps(globals()[args.stage]()))
    except Exception as exc:
        # Avoid leaking paths, reference assembly or secrets through Compose logs.
        print(json.dumps({'status': 'stopped', 'stage': args.stage, 'category': type(exc).__name__}), file=sys.stderr)
        raise SystemExit(1)


if __name__ == '__main__':
    main()
