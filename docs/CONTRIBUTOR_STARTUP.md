# Contributor startup

## Requirements

An x86-64 Linux host with Docker Engine and Compose v2 or newer, Internet access
to build open-source dependency images and call your chosen model provider, and
enough free disk space for the installer, extracted game and Wine runtime.
Docker access is a prerequisite; this repository does not install Docker or
change your machine's security settings. No Windows VM is required.

## 1. Supply your own licensed inputs

Create `private/inputs/gog/` and `private/inputs/compiler/` in the checkout.
Place **one classic GOG offline setup `.exe` and all its `.bin` companions** in
`private/inputs/gog/`. Do not use the GOG Galaxy downloader or Enhanced Edition.
The installer is extracted with `innoextract`, never executed. Unsupported Inno
formats or reference hashes stop preparation before any model request.

The compiler input is **Microsoft Windows SDK Update for Windows Vista,
February 2007**, containing MSVC 2005 SP1 x86 compiler `14.00.50727.762`:

- Publisher page: https://www.microsoft.com/en-us/download/details.aspx?id=14477
- Supply the complete ISO locally as
  `private/inputs/compiler/windows_sdk_vista_2007.iso`.
- Expected size: 1,237,436,416 bytes. Expected SHA-256 is in
  `reference/toolchain.json`. Only pinned CAB members are extracted; the SDK
  installer is never run and tools are not installed on the host.
- Read the SDK license before use. The project's MIT license does not grant rights
  to the SDK. No compiler files are downloaded automatically or put in image layers.

**A Visual C++ Redistributable is not the compiler and will not work.** Do not
substitute a different compiler version to make the setup pass.

Optional existing-file input: instead of the installer, copy the six exact pinned
reference files into `private/inputs/references/`. Instead of the ISO, supply all
19 pinned toolchain/license members, with their relative paths, under
`private/inputs/compiler/`. These are input alternatives, not symlinks into a live
game installation. Pins are always validated and inputs are mounted read-only.

## 2. Configure one model provider

Copy `.env.example` to `.env`, then edit it locally:

```dotenv
PROVIDER=deepseek
MODEL=deepseek-chat
DEEPSEEK_API_KEY=your-key-here
MAX_TOKENS=4096
TASK_ID=rules-03a90
ACCEPT_INPUT_LICENSES=yes
SEND_REFERENCE_TO_PROVIDER=yes
```

Use an explicit model available in your account. Alternatives are `PROVIDER=openai`
with `OPENAI_API_KEY`, or `PROVIDER=anthropic` with `ANTHROPIC_API_KEY` and a suitable
model. Leave unused keys empty. `.env` is Git-ignored and excluded from image builds.
Set permissions on it appropriately for your workstation; do not share it.

`SEND_REFERENCE_TO_PROVIDER=yes` consents to sending the **selected function's
disassembly** to that external provider under its terms and data-handling policy.
No full game/compiler files or credentials enter the prompt. If you cannot authorize
that disclosure, do not run the drafting stage. Provider usage costs money.

## 3. Start

```sh
docker compose up --build
```

The worker runs one curated task with **one model request maximum**, not an
unbounded grind:

1. **prepare**, offline: verify/extract local inputs, perform a real compiler smoke,
   verify the selected function's boundaries/relocations and prepare private assembly.
2. **draft**, networked: consume one durable request slot and ask the selected model
   for ordinary, bounded C++03 source. No original/compiler mounts or Docker socket.
3. **verify**, offline: compile the candidate twice with pinned flags, compare the
   complete function bytes without masks, and export an archive only on two matches.

Compiler containers have no provider keys, no network, read-only root filesystems,
dropped capabilities, resource limits and fresh disposable Wine prefixes. Candidate
programs are never run. This is defense in depth, not a guarantee that a legacy
compiler or container runtime is immune to malicious inputs.
The private `/work` tmpfs is capped at 2 GiB and executable because VC80 maps its
intermediate files executable; Docker's default `noexec` tmpfs causes C1083 errors.
This mount option is local to these containers, not a host security-policy change.

Preparation of a new volume is deliberately one-shot. A partial extraction or
failed compiler smoke leaves a durable started marker, not an implicit reinstall.
Paid requests are reserved **before** HTTP. Re-running Compose cannot reset a
request after errors, output exhaustion, interruptions or changed model settings.
A successful saved draft can be reused without another paid call. Verification
also preserves its first result and does not overwrite it on restart.

## 4. Collect and review a result

```sh
docker compose cp verify:/out ./private/output
```

On success, `private/output/<task-id>/contribution.zip` contains **only** source,
allowlisted task metadata, hashes and provenance. Review those contents yourself
before sharing. `result.json` and `private-logs/` alongside it are local diagnostics,
not files to upload. Extraction/preflight logs are in the private `state` volume;
you can copy them from `prepare:/state`. Do not publish that volume or dump it to
an issue: it contains proprietary files and reference data.

Open a fork/PR manually with the archive's four files. No GitHub token is needed to
run this worker and it never pushes automatically. A receipt is an untrusted claim;
the project must independently rebuild before accepting credit. A mismatch or
compiler/source error creates no archive and earns no match credit. The separately
selectable `rules-smoke-04270` task is already solved and can never add new credit.

Each task has its own durable folder. To select another listed task, change
`TASK_ID` explicitly and rerun Compose. Do not erase volumes to retry an exhausted
task or silently increase its budget. No automatic project-ledger changes occur.

## Troubleshooting and current limits

- `stopped / prepare`: check input licenses, ISO/reference hashes, supported installer
  format, and private extraction/preflight logs. No provider call has occurred.
- `stopped / draft`: check key/model/consent before starting. An existing
  `request-started.json` with no draft is closed and will not retry automatically.
- `stopped / verify`: inspect local failure category and private compiler logs;
  source diagnostics are not evidence of a matching function.
- Inputs are cached once in named volumes. Changing the host input directory does
  not replace prepared files. The cached toolchain and references are rehashed.
- This is a bounded native leaf/object-only lane. No linking, managed code, asset
  reconstruction, whole-file identity, playable replacement or runtime identity.
- Installer-format support is provided by the image's `innoextract` version. A
  complete GOG-installer extraction test requires that exact installer; passing
  copied-reference tests is not evidence for every installer edition or release.
- Base image digest and Python dependency versions are pinned; Debian packages are
  resolved at image build time and recorded in `/runtime-packages.txt`. The build
  is not claimed to be bit-for-bit reproducible across package repository updates.

## Offline synthetic tests

After building, these make no paid requests and need no game/compiler files:

```sh
docker compose run --rm --no-deps verify python3 -m unittest discover -s tests
docker compose run --rm --no-deps verify python3 -m unittest discover -s contributor-worker/tests
```

Compose still requires its provider/model/consent variables to parse the project;
use an explicit test model and leave keys empty when running synthetic tests.
