"""Offline object-only Wine lane. Never execute model-generated programs."""
from pathlib import Path
import re
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from coff_object import CoffObject
from matching import compare_bytes, sha256
from bootstrap import run, validate_toolchain
from contribution import FLAGS, safe_source


def wine_environment(work):
    # Deliberately allowlist, rather than copy the host/container environment.
    work = Path(work)
    return {'PATH': '/usr/local/bin:/usr/bin:/bin', 'HOME': str(work / 'home'),
            'WINEPREFIX': str(work / 'prefix'), 'WINEARCH': 'win32', 'WINEDEBUG': '-all',
            'TMPDIR': str(work / 'linux-temp'), 'TEMP': 'Z:' + str(work / 'temp').replace('/', '\\'),
            'TMP': 'Z:' + str(work / 'temp').replace('/', '\\'),
            'CL': '', '_CL_': '', 'INCLUDE': '', 'LIB': '', 'LC_ALL': 'C'}


def initialize(work):
    work = Path(work)
    work.mkdir(parents=True, exist_ok=True)
    if (work / 'prefix').exists():
        raise ValueError('Fresh owned Wine prefix required')
    for name in ('home', 'linux-temp', 'temp'):
        (work / name).mkdir(mode=0o700)
    env = wine_environment(work)
    run(['sh', '-c', 'wineboot -u; code=$?; wineserver -w; exit "$code"'],
        work / 'wineboot.log', timeout=180, env=env)
    if not all((work / 'prefix' / n).is_file() for n in ('system.reg', 'user.reg', 'userdef.reg')):
        raise RuntimeError('Wine registry initialization incomplete')
    return env


def compile_once(source, toolchain, directory, env):
    """Fixed names and arguments only: source never enters a shell command."""
    safe_source(source)
    directory = Path(directory); directory.mkdir()
    (directory / 'probe.cpp').write_text(source)
    compiler = 'Z:' + str(Path(toolchain).resolve() / 'cl.exe').replace('/', '\\')
    if not re.fullmatch(r'Z:[A-Za-z0-9_\\/.:-]+', compiler):
        raise ValueError('Compiler mount path outside fixed bounded lane')
    batch = ('@echo off\r\nset "TEMP=' + env['TEMP'] + '"\r\nset "TMP=' + env['TMP'] + '"\r\n'
             'set "CL="\r\nset "_CL_="\r\nset "INCLUDE="\r\nset "LIB="\r\n' +
             compiler + ' ' + ' '.join(FLAGS) + ' /Foprobe.obj probe.cpp\r\nexit /b %errorlevel%\r\n')
    (directory / 'invoke.cmd').write_bytes(batch.encode('ascii'))
    windows_batch = 'Z:' + str(directory.resolve() / 'invoke.cmd').replace('/', '\\')
    run(['sh', '-c', 'wine cmd /d /c "$1"; code=$?; wineserver -w; exit "$code"',
         'sh', windows_batch], directory / 'compiler.log', cwd=directory, timeout=120, env=env)
    if not re.search(rb'Compiler Version 14\.00\.50727\.762\b', (directory / 'compiler.log').read_bytes()):
        raise RuntimeError('Pinned compiler banner absent')
    data = (directory / 'probe.obj').read_bytes()
    return CoffObject(data), data


def verify_source(source, reference, task, toolchain, contract, work):
    if contract['flags'] != FLAGS:
        raise ValueError('Compiler flags disagree with public contract')
    validate_toolchain(toolchain, contract)
    work = Path(work); env = initialize(work)
    checks = []
    for i in (1, 2):
        obj, data = compile_once(source, toolchain, work / f'run{i}', env)
        functions = [s for s in obj.symbols if s['section_number'] > 0 and s['type'] & 0x30 == 0x20]
        if len(functions) != 1:
            raise ValueError('Bounded task must emit exactly one function')
        code, metadata = obj.extract(functions[0]['name'], task['size'], task['boundary_evidence'])
        comparison = compare_bytes(reference, code)
        checks.append({'exact': comparison['exact'], 'size': len(code), 'relocations': [],
                       'function_sha256': sha256(code), 'object_sha256': sha256(data)})
    validate_toolchain(toolchain, contract)
    return checks


def smoke(toolchain, contract, work):
    """No original code: compile a simple project-authored member before paid calls."""
    validate_toolchain(toolchain, contract)
    env = initialize(work)
    source = 'struct Smoke { int value(); };\nint Smoke::value() { return 1; }\n'
    obj, _ = compile_once(source, toolchain, Path(work) / 'smoke', env)
    if not any(s['section_number'] > 0 and s['type'] & 0x30 == 0x20 for s in obj.symbols):
        raise RuntimeError('Compiler smoke produced no typed function')
