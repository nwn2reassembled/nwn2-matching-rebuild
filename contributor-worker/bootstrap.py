"""Offline, no-installer-execution preparation of user-supplied private inputs."""
import hashlib
import json
from pathlib import Path
import shutil
import subprocess


def digest(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for block in iter(lambda: stream.read(4 * 1024 * 1024), b''):
            h.update(block)
    return h.hexdigest()


def checked_file(path, sha256, size=None):
    path = Path(path)
    if path.is_symlink() or not path.is_file():
        raise ValueError('Missing or symlinked private input')
    if size is not None and path.stat().st_size != size:
        raise ValueError('Private input size does not match pin')
    if digest(path) != sha256:
        raise ValueError('Private input hash does not match pin')
    return path


def run(argv, log, cwd=None, timeout=1800, env=None):
    """Private bounded logs; never put extraction/compiler output on public stdout."""
    with Path(log).open('xb') as output:
        result = subprocess.run(argv, cwd=cwd, env=env, stdout=output,
                                stderr=subprocess.STDOUT, timeout=timeout)
    if result.returncode:
        raise RuntimeError('Offline tool failed; inspect the private local log')


def validate_toolchain(directory, contract):
    for entry in contract['files']:
        name = Path(entry['path'])
        if name.is_absolute() or '..' in name.parts:
            raise ValueError('Unsafe toolchain member')
        checked_file(Path(directory) / name, entry['sha256'])


def extract_sdk(iso, destination, scratch, contract):
    checked_file(iso, contract['iso']['sha256'], contract['iso']['size'])
    destination, scratch = Path(destination), Path(scratch)
    destination.mkdir(); scratch.mkdir()
    cabinets = (
        'Setup/WinSDKCompiler-WinSDKCompiler_X86_VC8CppCompiler-common.0.cab',
        'Setup/WinSDK-WinSDK_BIN_VC8_Runtime_X86_CRT-common.0.cab')
    packages, raw = scratch / 'packages', scratch / 'raw'
    packages.mkdir(); raw.mkdir()
    run(['7z', 'x', '-y', '-o' + str(packages), str(iso),
         'License/License.htm', 'License/Redist.Txt', *cabinets], scratch / 'iso.log')
    for i, cabinet in enumerate(cabinets):
        run(['cabextract', '-q', '-d', str(raw), str(packages / cabinet)], scratch / f'cab{i}.log')
    for entry in contract['files']:
        name = Path(entry['path']); leaf = name.name
        if name.parts[0] == 'License':
            candidates = [packages / name]
        elif name.parts[0] == 'Microsoft.VC80.CRT':
            prefix = ('manifest.8.0.50727.762.98CB*' if leaf.endswith('.manifest')
                      else leaf + '.8.0.50727.762.*')
            candidates = list(raw.glob(prefix))
        else:
            candidates = list(raw.glob(leaf.replace('.', '_') + '.*'))
        if len(candidates) != 1:
            raise ValueError('SDK member is missing or ambiguous')
        checked_file(candidates[0], entry['sha256'])
        target = destination / name
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(candidates[0], target)
    validate_toolchain(destination, contract)


def extract_gog(directory, destination, pins, logs):
    directory, destination, logs = Path(directory), Path(destination), Path(logs)
    installers = list(directory.glob('*.exe'))
    if len(installers) != 1 or installers[0].is_symlink():
        raise ValueError('Put exactly one supported GOG offline setup .exe and its .bin companions in inputs/gog')
    run(['innoextract', '--extract', '--output-dir', str(destination), str(installers[0])],
        logs / 'gog-extraction.log', timeout=3600)
    return find_references(destination, pins)


def find_references(directory, pins):
    directory = Path(directory)
    result = {}
    for name, pin in pins.items():
        candidates = [p for p in directory.rglob('*') if p.name.casefold() == name.casefold()]
        if len(candidates) != 1:
            raise ValueError('Missing or ambiguous pinned reference; installer edition/version may not be supported')
        result[name] = checked_file(candidates[0], pin['sha256'], pin['size'])
    return result
