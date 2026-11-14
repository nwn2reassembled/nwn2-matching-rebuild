# Evidence-gated native unit pipeline

## Purpose and activation boundary

This is the independently authored, **offline** implementation of the transferable
Fallout reconstruction findings. It introduces no Fallout code, classes, layouts,
compiler files, manifests or game payloads. Source-study provenance is
`momusdigital/fnv_decomp@91e1b6e8d8bb0f9a33e8cf88e77268757449e0a6` and the public
f3decomp field manual observed 2026-11-14. Sources:
[FNV repository](https://github.com/momusdigital/fnv_decomp/tree/91e1b6e8d8bb0f9a33e8cf88e77268757449e0a6)
and [f3decomp field manual](https://f3decomp.com/how.html).
This is not represented as a legal clean room.

The pipeline can validate a reviewed unit, materialize supplied object ranges,
compare against a **whole-file-pinned** PE, emit context and consistency receipts,
plan conservative regressions and report existing corpus coverage. It cannot build,
dispatch, promote, deploy, publish or earn matching credit. It changes no existing
controllers, compiler backends, ledgers, frozen queue or submission histories.
There is no automatic continuation of token-exhausted work.

An independently approved original-site address contract is legitimate relocation
evaluation, **not masking or normalization**: the candidate operand is computed from
the object and binding evidence without reading the reference operand. The final
comparison still checks every byte. This does not reproduce an entire COFF object,
PE linker output, behavioral semantics, EH runtime behavior or complete artifact.

## Implementation map

| Research finding | Implementation | Deliberate limit |
| --- | --- | --- |
| Per-unit compiler/context recipes | `tools/native_unit.py::validate_unit`, `validate_inputs` | Ordered allowlisted flags; hash every declared compiler/SDK/backend/source/header/evidence file; no claim that declared inputs exhaust an actual build environment |
| Evidence and naming provenance | Same module, binding scopes and optional `names` | Parent review plus exact approved unit digest; free-text review fields alone are not authentication; guesses never resolve addresses |
| Bounded relocation resolution | `tools/native_placement.py::materialize` | DIR32, REL32, DIR32NB only; unowned local targets, ambiguous symbols and unsupported relocations block |
| Honest boundaries/aliases | Explicit object and original ranges; every alias body separately compared | No padding trimming, next-entry guesses, nearest-earlier ownership, pooled-literal equivalence or inferred placements |
| EH ownership and closure | Unit role graph and `tools/native_verify.py` closure results | Explicit parent/handler/funclet/table/runtime/destructor/cookie ownership or reviewed nonapplicability; no automatic EH discovery |
| Immutable task packets | `tools/native_workflow.py::context_pack` | Hashes and metadata, not function bodies; no remote MCP service or uploads |
| Dependency-aware regression | `regression_plan`, `assess_plan` | Recipe/context changes rebuild all units; unknown includes rebuild all; never accepts by baseline equality alone |
| Pin-bound verification receipts | `tools/native_verify.py` | Includes object, unit, input, target, verifier and pefile version identities; consistency hashes, not signatures/independent compiler attestations |
| Cost/readiness-based routing | `tools/native_workflow.py::route` | Advisory only; readiness and spent/uncertain history take priority; no automatic larger-model escalation |
| Durable no-reset budgets | `attempt_transition`, `tools/native_journal.py` | Opt-in new histories only; no migration/replay of previous controllers; three requests maximum; pause on operational/context failure |
| Logical vs physical progress | `coverage`, `project_scope` | Distinct tokens remain logical items; physical union bytes deduplicate aliases/overlaps; existing ledger is authority, not a fresh verification |
| Integration baseline safety | `assess_plan` returns a report, never mutates baseline | Actual independent repeat-build promotion and atomic production integration remain in the existing trusted parent chain |

## Version 1 manifest contract

The executable validator is `tools/native_unit.py`; the complete independent
synthetic example builder is `tests/test_native_pipeline.py::unit_fixture`.
Integer addresses and sizes are JSON numbers, not expressions or strings.

Top-level fields:

- `schema_version: 1`, globally unique `id`.
- `target`: `name`, whole-file `size` and `sha256`, expected PE `image_base`.
  Verification also requires **parent-supplied trusted pins**; a candidate cannot
  choose a new image merely by changing its manifest.
- `files`: map from input identity to `{path, sha256, role}`. Roles are `source`,
  `header`, `evidence`, `compiler`, `sdk`, `backend`. Paths are relative regular files
  within an explicit input root: no symlink hops, absolute paths, backslashes or
  traversal. Large SDK/backend trees should use curated inventory files as their
  identity input, then be independently checked by the actual build envelope.
  Hashing an inventory is **not** proof that a future compiler used those files.
- `recipe`: identities for `compiler`, `sdk`, `backend`; ordered `flags`;
  `environment: isolated-no-network-no-secrets`. This is a required policy label,
  **not evidence that a sandbox exists**. No compiler execution is exposed here.
- `evidence`: map from evidence ID to `kind`, `review_state: reviewed`, `reviewer`,
  `derivation`, `description`, evidence `file`, `line_start`, `line_end`. Kinds are
  `boundary`, `abi`, `binding`, `placement`, `not-applicable`. Derivations are
  `independent-observation` or `synthetic-specification`; reference-operand-only
  inference/hypotheses are not valid acceptance evidence. Review must establish
  independence; strings cannot prove it.
- `bindings`: symbol to `{va, artifact_sha256, scope, kind, evidence}`. Scope must
  equal this unit's ID and artifact pin must match. Kinds distinguish `function`,
  `data`, `iat-slot`, `runtime`, `vtable`, `tls`. An IAT slot is not interchangeable
  with its implementation. Different artifacts/scopes never merge by name.
- `regions`: explicit `{id, symbol, section, object_offset, rva, size, kind,
  boundary_evidence, placement_evidence, abi_evidence, dependencies}`. ABI evidence
  is required for code; dependencies name region IDs or external binding symbols.
  Code/data/EH tables can be separately owned and noncontiguous. Object ranges
  cannot overlap. Original ranges cannot overlap except explicit exact-size folded
  aliases with `alias_of` pointing to the primary region. Each emitted alias is
  materialized and compared, not assumed equal because the primary passes.
- `eh_closures`: list of `{id, roles}`. Declare every role: `parent`, `handler`,
  `funclets`, `unwind`, `types`, `catches`, `destructors`, `runtime`, `cookie`.
  Each is `{regions: [IDs]}` of the correct kinds or
  `{not_applicable: [evidence IDs]}`. Parent cannot be exempt and is one function.
  All closure-owned regions must be reachable in the parent's dependency graph.
  Missing tables, unrelated pieces or mismatching tails block closure exactness.
  Roles that refer to external runtime code need independently owned proof ranges
  for full closure verification; a binding alone is not dependency identity proof.
- Optional `names`: `{name, rva, source, confidence, evidence}`. Sources:
  `OBSERVED_ORIGINAL`, `INDEPENDENT_ABI`, `COMPILER_GENERATED`, `COMMUNITY_NAME`,
  `GUESS`; confidence `high`, `medium`, `low`. Names are annotations only.

## Relocation semantics and rejection gates

For an external ordinary undefined COFF symbol, a reviewed binding and an explicit
dependency entry are mandatory. For a defined local symbol, symbol value plus
addend must fall within exactly one owned object range, and the source must depend
on that owner (or be the owner). No discovery from reference bytes is performed.

- DIR32 encodes `target VA + raw unsigned addend`.
- REL32 encodes `target VA + signed addend - (original field VA + 4)`.
- DIR32NB encodes `target VA + raw unsigned addend - pinned image base`.

For local symbols the addend first locates the target inside the owned object
range, whose original placement supplies the final VA. Enforce signed/unsigned
32-bit arithmetic bounds; never silently wrap overflowing placement arithmetic.
ABSOLUTE relocation entries are no-ops. TLS/SECREL, SECTION, unsupported formats,
common/debug/absolute targets without a supported evidence path, invalid auxiliary
symbol references, duplicate symbols, structural-table overlap, field overlap,
straddling ranges, conflicting auxiliary sizes and nested function boundaries are
rejected. `CoffObject.extract` and `coff_link_context.resolve_function` are unchanged.

## Read-only commands

All commands write JSON to stdout only; callers may redirect it to an exclusive
scratch output. Use the project's `.venv/bin/python` and an explicit working
directory. No downloaded tools are executed.

```sh
.venv/bin/python tools/native_tools.py validate --unit UNIT.json --input-root INPUTS
.venv/bin/python tools/native_tools.py context --unit UNIT.json --input-root INPUTS
.venv/bin/python tools/native_tools.py verify --unit UNIT.json --input-root INPUTS \
  --object CANDIDATE.obj --reference PINNED.dll --trusted-pins reference/pins.json \
  --approved-unit-sha256 PARENT_REVIEWED_UNIT_DIGEST
.venv/bin/python tools/native_tools.py plan --before OLD_UNITS.json --after NEW_UNITS.json \
  --changed include/example.h
.venv/bin/python tools/native_tools.py assess --plan PLAN.json --units NEW_UNITS.json \
  --receipts RECEIPTS_BY_UNIT.json
.venv/bin/python tools/native_tools.py project-scope --root "$PWD"
```

The before/after files map unit IDs to manifests. `--discovery-uncertain` forces a
full rebuild plan. Recipe, ABI, EH, binding, evidence or toolchain changes already
force a full rebuild; no comment-only bypass is present. An exact shard set is
required, with current plan/context/verifier hashes. Successful assessment means
**ready for independent parent review**, never integrated. Failed assessment has
no ability to overwrite the accepted baseline. Reports are replay-idempotent and
cannot add credit. A hash is an integrity stamp, not proof of trustworthy execution.

`project-scope` verifies frozen queue identity and overlays current batch/ledger
states. It retains legacy assessments with missing binary identity as unconfirmed,
rather than inventing provenance; explicit token exhaustion remains spent. Batch
promotion claims do not override the ledger. Concurrent input changes reject the
snapshot. It does not change the site's published reporting or its timer.

The `project-scope` adapter is optional research-workspace tooling: it requires
private `progress/`, frozen corpus and evidence records, which are deliberately
not distributed. The public synthetic tests need none of those records. General
unit validation, context, verification, planning and receipt assessment work with
your own reviewed inputs. Use `python3` or your own virtual environment; the
`.venv/bin/python` examples name a conventional local project environment.

## Attempt state and integration rollout

`native_journal.create_journal` exclusively creates a new attempt; existing files
are never overwritten. `append_event` locks, replays the hash chain, checks the
expected prior state, applies a legal transition, appends and fsyncs. The initial
creation fsyncs the containing directory. A torn append is a blocker to investigate,
not a rollback permission. `request-sent` must be persisted **before** network I/O;
an outstanding request cannot be replayed after a crash. Waiting consumes no budget.
Output-token exhaustion, lost/uncertain responses, infrastructure failure, checker
disagreement, stale context and dependency defects pause; no reset event exists.
This does not retroactively change any existing history or install a scheduler.

For a future production adapter, persist the outcome then invoke the existing
serialized `refresh_after_attempt` with an exclusive event and verified readback
after **each** model/compiler/repair/failure event. Abort on global RAG blocker.
Use the existing idle-only endpoint lock and maximum-three-drafts policy, trusted
compiler control code, a no-network/no-secrets scratch build with resource limits,
independent repeat builds and parent promotion. No candidate executable is run.
All emitted receipts explicitly state that compiler execution and independent
verification were **not** attested by this offline checker.

### Remaining gates, not hidden completion claims

1. Establish real reviewed NWN2 boundary/ABI/binding/EH evidence and exact compiler
   input inventories. The 34,684 general-native items remain blocked/unattempted;
   a new verifier does not establish their facts.
2. Validate an isolated compiler envelope and negative compiler/preprocessor tests
   (`#import`, escaping includes, malicious flags, crashes, memory/output limits)
   before connecting this path to live drafting. Python metadata/path validation
   is **not** a compiler sandbox or exhaustive preprocessing dependency discovery.
3. Run a small evidence-ready, independently repeated cohort through the existing
   per-attempt RAG gates before changing dispatch. Preserve every exhausted budget.
4. Only then add an atomic production integration adapter and optional scheduled
   revalidation. No service/timer changes, remote contributor service, paid model
   activation, GitHub publication or automatic expanded dispatch is installed here.
5. Managed IL, resources, deterministic whole-file layout and artifact assembly are
   separate capabilities; none is unlocked by native relocation handling.

## Synthetic validation

Run `python -m unittest discover -s tests -p 'test_native_pipeline.py'` using the
project environment. Fixtures are independently authored COFF/PE data, not compiler
output or original game bytes. Tests cover positive DIR32/REL32/DIR32NB/local
placement, negative arithmetic and ownership, every-byte pin/equality failures,
aliases/EH, scope/provenance, stale receipts, missing shards, persistent budget
state, input paths and physical/logical accounting. Passing synthetic gates earns
**zero** matching credit and does not independently reproduce a Fallout build.
