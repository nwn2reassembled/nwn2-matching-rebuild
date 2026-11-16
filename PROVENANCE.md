# Provenance and release boundaries

## Project-authored material

The tools, tests and contributor-worker components in this release were developed
within this reconstruction project with AI assistance. They are not represented
as recovered original game source. Synthetic tests construct their own PE/COFF
fixtures, including a deliberately trivial NOP/NOP/NOP/RET sequence; that fixture
is not extracted original game code. Test credentials are explicit dummy strings.

The `src/ruleslib/`, `src/client/` and `src/server/` implementations are readable, instruction-informed
reconstruction hypotheses, with inferred types and descriptive names. Their
index and verification records identify the target RVAs. They contain arithmetic, field declarations
and ABI annotations, not copied instruction payloads. They are not clean-room
implementations: original instructions were examined during the research.
The 16 November 2026 `matched/` snapshot contains 520 byte-for-byte unchanged source
files covering 522 verified functions (502 rules-library, 16 server and 4 client),
including AI-drafted and parent-repaired candidates. The combined index is
`src/matched/index.json`; the earlier 357-function publication remains included.
Per-function records retain available repair/model provenance; missing historical
fields are not evidence of unaided model success. Compiler flags/version fields
may be null where the selected historical receipt did not record them directly.
The source was not renamed internally, reformatted or stripped for publication.
The normalized public receipts contain hashes and comparison metadata, not the
original instruction payloads or private operational logs. They summarize historical
verification, not a fresh compilation at publication time.
No third-party license headers or attribution notices were found in these selected
source files. That observation does not establish legal ownership or provide a
jurisdiction-specific copyright, contractual or reverse-engineering clearance.

`reference/pins.json` contains filenames, file sizes and SHA-256 hashes only.
It identifies the intended reference inputs without redistributing those inputs.

## Dependencies and excluded property

The native-unit tools and `tests/test_native_pipeline.py` were independently
authored after studying public reconstruction methods in
`momusdigital/fnv_decomp@91e1b6e8d8bb0f9a33e8cf88e77268757449e0a6` and f3decomp's
public field manual. No third-party implementation, reconstructed declarations,
game payloads or manifests were copied or translated into these tools. This is
source-study provenance, not a clean-room claim or a grant of rights in those
projects. The public guide removes private workspace paths. New tests use only
independently authored synthetic COFF/PE fixtures; publishing these tools adds no
verified game-function or whole-file claim to the frozen source snapshot above.

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
