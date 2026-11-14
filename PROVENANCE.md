# Provenance and release boundaries

## Project-authored material

The tools, tests and contributor-worker components in this release were developed
within this reconstruction project with AI assistance. They are not represented
as recovered original game source. Synthetic tests construct their own PE/COFF
fixtures, including a deliberately trivial NOP/NOP/NOP/RET sequence; that fixture
is not extracted original game code. Test credentials are explicit dummy strings.

The three `src/ruleslib/` implementations are readable, instruction-informed
reconstruction hypotheses, with inferred types and descriptive names. Their
comments identify the target RVAs. They contain arithmetic, field declarations
and ABI annotations, not copied instruction payloads. They are not clean-room
implementations: original instructions were examined during the research.
No third-party license headers or attribution notices were found in these selected
source files. That observation does not establish legal ownership or provide a
jurisdiction-specific copyright, contractual or reverse-engineering clearance.

`reference/pins.json` contains filenames, file sizes and SHA-256 hashes only.
It identifies the intended reference inputs without redistributing those inputs.

## Dependencies and excluded property

`pefile==2024.8.26` is a separately installed third-party dependency distributed
under its own MIT license. Capstone 5.0.3 is a separately installed disassembly
dependency under its own BSD license and third-party notices. Their sources are
not vendored or relicensed by this release. Debian, Wine, innoextract, 7-Zip and
cabextract are image dependencies under their respective licenses; package license
notices remain in the image. No proprietary software is added during image builds.
Python, model providers and any locally supplied compiler/runtime are separate
dependencies subject to their own terms. Model output is not a guarantee of
originality or non-infringement; contributors must review provenance before PRs.

MIT applies only to rights the project can grant in its own contributions.
No game/compiler executables, DLLs, object files, recovered assets, proprietary
headers/libraries, decompilation dumps or original assembly/byte dumps are included.
No rights to such material or to third-party names/trademarks are granted.

Private logs, internal evidence, machine/network configuration, RAG data and
unreviewed probe history are deliberately excluded. Public-source changes to the
reference-root default and origin description remove private workstation details;
the active private tools were not modified for this export.
