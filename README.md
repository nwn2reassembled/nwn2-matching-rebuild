# NWN2 matching rebuild

Research toward rebuilding six pinned classic GOG Neverwinter Nights 2 files
byte for byte from readable source. This is not a source port, a patched game,
or a playable replacement. No complete artifact is claimed to match.

The current source snapshot publishes **357 verified functions in 355 source files**
from `NWN2RulesLib.dll`, covering **8,543 exact instruction bytes**.
Browse the [reconstructed C/C++ source](src/ruleslib/matched) and its
[RVA-to-source index](src/ruleslib/matched/index.json).
The bounded Compose contributor worker is described below; validation limits are
recorded in the startup guide.

## Reconstruction progress

**357 / 53,853 known items exactly matched** — published snapshot, 14 November 2026.
These are complete function matches across an unweighted worklist, not a percentage
of rebuilt file bytes. **Whole-file identity: 0 / 6.**

See [the project website](https://nwn2reassembled.fyi/#reconstruction) for newer
aggregate snapshots, refreshed every three hours. This count covers the research
project. This release includes source for all 357 functions in its frozen ledger;
later private progress is not automatically published. The earlier README snapshot
was 288 / 53,853.

## Included

- Strict, unnormalized byte comparison and read-only PE inspection.
- Conventional i386 COFF function extraction with explicit boundary evidence
  and rejection of unresolved overlapping relocations.
- Three exploratory C implementations reconstructed from instruction-level
  analysis. They contain no embedded original instruction bytes. These particular
   C files are not a claim of pinned-compiler exactness or complete-game behavior.
- 355 unchanged matching C/C++ source files with 357 per-function hash-only
  verification records. These are independent compilation probes, not a combined
  DLL build; names/types are hypotheses. See the [source guide](src/ruleslib/matched/README.md).
- OpenAI, Anthropic and DeepSeek drafting adapters, plus a source-and-hashes-only
  contribution exporter and a one-task Compose workflow.
- Synthetic tests and hash/size-only reference pins; no original game files.

## Local checks

Use Python 3.10 or newer. Install `requirements.txt` in your own environment:

```sh
python3 -m pip install -r requirements.txt
python3 -m unittest discover -s tests
python3 -m unittest discover -s contributor-worker/tests
```

Supply your own lawfully obtained reference files. Set `NWN2_REFERENCE_ROOT` to
their directory or pass `--references` explicitly. The default is the ignored
`private/references/` directory. Verify pins without changing your files:

```sh
python3 tools/matching.py verify --references private/references
```

Inventory/extraction commands can write proprietary data or local paths to their
outputs. Keep those outputs private; never commit or attach them to issues or PRs.
Tests use synthetic fixtures and need no game, compiler, provider key or network.

## Exactness and contributions

Successful compilation, behavioral equivalence, function equality, image-region
equality and full-file identity are different results. Only complete unmasked
stored-byte equality within justified boundaries earns the corresponding claim.
Do not add overlapping ranges or count historical matches twice.

Contributor receipts are untrusted claims requiring project-side rebuild and
verification. The exporter does not establish that its input receipts are true.
Source filters are not a compiler sandbox or an exhaustive secret detector.
Never execute untrusted source/scripts with credentials, writable original files
or privileged CI permissions. No automatic PR-submission or privileged CI workflow
is included. Provider calls incur charges and require an explicit model and a
process-environment API key; tests mock all provider requests.

The contributor Wine lane uses only user-supplied, hash-pinned toolchain files
mounted at runtime. Compiler files, game files, proprietary headers/libraries,
assets, assembly dumps and private operational records are not distributed.

## Contributor startup

Supply a supported classic GOG offline installer and the pinned compiler SDK ISO,
copy `.env.example` to `.env`, select a provider/model and enter its key, confirm
input licenses and provider-disassembly consent, then run:

```sh
docker compose up --build
```

The Visual C++ Redistributable alone is insufficient: the compiler is required.
See [the startup guide](docs/CONTRIBUTOR_STARTUP.md) for exact inputs, one-request
budget, isolation, result collection and known validation limits. It does not
install host packages, run the game, or automatically push to GitHub.
See [validation results and limitations](docs/VALIDATION.md) before treating this
as a fully validated installer-to-contribution path; GOG-installer extraction and
live paid-provider end-to-end validation remain outstanding.

## License and provenance

Project-authored code is offered under MIT; see `LICENSE` and `PROVENANCE.md`.
This license grants no rights to the original game, compiler, trademarks or other
third-party material, and is not a legal opinion about reverse engineering.
