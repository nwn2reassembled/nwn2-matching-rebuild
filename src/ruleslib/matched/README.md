# Matching source snapshot

**357 functions · 355 source files · 8,543 exact instruction bytes**

Frozen 14 November 2026; all targets are in the pinned `NWN2RulesLib.dll`.
[`index.json`](index.json) maps each target RVA to source, emitted symbol, source
SHA-256 and a [verification record](../../../verification/ruleslib).
File names use the first credited RVA; shared translation units appear once.

## What this is

These are the unchanged C/C++ translation units used by historical verification.
They are independent probes, **not** a coherent class hierarchy, complete original
source tree, linked DLL, playable replacement or portable behavioral implementation.
Repeated hypothetical names such as `Legacy` must not be combined into one program.
Some units contain additional, nonmatching functions; only indexed symbols receive
exact-match credit. The three exploratory C files in the parent directory remain
separate and are not added again to the count.

The published source hashes were checked against the historical receipts. No source
edits were needed, and no new compilation or reconstruction credit is claimed by
publication. Hash records are auditable claims, not substitutes for independent
verification using licensed pinned inputs. Original binary/compiler inputs and
disassembly are not distributed.

## Rebuilding and checking

Most units use pinned x86 VC80 `14.00.50727.762`, usually with
`/c /O2 /GS- /GR- /Zl /Gy`; consult the individual record rather than assuming
one recipe applies to every file. One historical C lane uses GCC/ELF32.
Compile each unit separately; changing file/output names can change object hashes
without changing function bytes. Compare the specified complete function against
the pinned reference: no masking or normalization. Explicit address-bound relocation
evaluation, when used, is recorded and is not a whole linked-image match.
Some historical receipt summaries lack direct compiler fields; null means unknown,
not permission to assume the default recipe. The bounded contributor worker has its
own curated tasks and does not automatically bulk-build this source collection.

Run `python3 -m unittest discover -s tests` to check the published source/index
integrity alongside the existing synthetic tests. This check does not invoke the
proprietary compiler or prove byte identity anew.

Whole-file identity remains **0 / 6**. See [provenance](../../../PROVENANCE.md)
for instruction-informed/AI-assisted origin and licensing limits.
