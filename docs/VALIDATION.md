# Contributor worker validation

## What was tested

The candidate release images were built from the Dockerfile on three x86-64
Debian 12 machines. Synthetic suites passed on each: 25 comparison/COFF tests
and 29 provider/export/workflow tests, **54 per machine**. Compose versions in
the test set were 2.29.7, 5.1.0 and 5.1.4.

The workflow tests cover one-request persistence, exhausted/interrupted request
closure, changed-model rejection, missing-key and consent gates, source hash
checks, malformed source rejection, reference pins, symlink rejection, mismatch
non-export, failure persistence and allowlisted pass archives. Provider responses
are mocked; no paid model request is claimed by these tests.

Real compiler validation uses user-supplied private inputs, a fresh Wine prefix,
the pinned compiler/flags and a deterministic **human-source fixture** for the
already-solved 13-byte address-arithmetic leaf. This does not measure model
accuracy, discover new source, or award reconstruction credit. The test-only
Compose override replaces the networked draft command with an offline fixture;
it is not an undocumented production-worker option.

That fixture pipeline passed on **all three hosts**: offline preparation and
compiler smoke, Compose dependency handoffs, two complete 13-byte unmasked function
matches and source/hash-only archive creation. Runtime inspection confirmed the
verifier had no network, a read-only root filesystem and no provider-key environment
variables. Whole COFF object hashes differed; no whole-object identity is claimed.

The official pinned SDK ISO extraction path was tested on one Debian host:
ISO size/hash verification, selected CAB extraction, all 19 toolchain/license
member hashes, and a real synthetic compiler smoke passed. The normal curated
79-byte reconstruction task also passed local reference extraction and bounded
disassembly checks without spending a model request.

## Important remaining limits

- A complete GOG-installer extraction test has **not** been performed for this
  release. Reference-file validation used the documented copied-reference input
  alternative. `innoextract` handles the installer path, but support for a user's
  exact installer edition/format and pinned contents is checked locally, not assumed.
- No real paid-provider end-to-end run was performed. Provider protocol behavior
  is covered with mocked responses, not live account/model availability checks.
- All tested hosts are Debian 12. Other Linux distributions, Docker Desktop,
  Windows/macOS hosts, ARM64 and rootless Docker remain unvalidated.
- This is object-only compilation with no game execution, linking, full-artifact
  identity or behavioral-equivalence claim. Receipt files remain untrusted until
  independently reverified by project maintainers.
- The first preflight exposed Docker tmpfs sizing and `noexec` incompatibilities.
  The candidate now uses a bounded 2 GiB executable private `/work` tmpfs and a
  3 GiB container memory limit. Failed test runs were preserved; no paid requests
  were retried or budgets reset to obtain the passing tests.

Private input files, original instruction data, container logs, test host details,
failed operational records and contribution fixtures are not part of this release.
