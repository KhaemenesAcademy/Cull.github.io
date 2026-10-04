# CULL — STOS Sovereign Compiler

CULL is the STOS-owned compiler project intended to remove Apple Clang from the STOS build authority chain.

Version: **0.1.0-alpha1**

## Sovereignty boundary

CULL's target pipeline is:

STOS C source → CULL parser/semantic layer → CULL typed IR → CULL target backend → CULL direct object/executable writer → STOS native artifact.

CULL must not delegate compilation, assembly, or linking to clang, gcc, cc, as, ld, make, cmake, ninja, Python, Node, Perl, Ruby, or another external build system after sovereign bootstrap certification.

## Alpha1 status

This ZIP is the source-controlled bootstrap/contract baseline. It includes a dependency-free C source tree, a fail-closed parser for the first bounded C slice, CULL-owned SHA-256, target/backend interfaces, and STOS integration/replacement contracts.

**Alpha1 is not production-ready and is not authorized to replace Clang.**

The first accepted language slice is deliberately small:

    int main(void) { return INTEGER; }

Unsupported syntax is rejected rather than silently delegated.

## Authority separation

CULL compiles; it does not authorize deployment. Loyer writes bounded candidates. Avouch validates request shape. Piston owns verified execution plans. ABBY owns portable authority. ABIE owns native realization. Buddy/Klik/Daisy/Brij participate only where their actual identity/authorization/watchdog/lineage boundaries require them. Gaffer owns service lifecycle.
