# Clang Replacement Gate

CULL replaces Apple Clang only after all applicable gates PASS:

- source candidate identity sealed
- no clang/gcc/cc delegation
- no external assembler or linker delegation
- direct x86_64 Mach-O emission
- actual STOS C-language inventory coverage
- malformed/unsupported source fails closed
- ABI/integer/pointer/aggregate tests
- multi-unit symbol resolution
- Loyer compiles and passes behavior tests
- Avouch compiles and passes contract tests
- CULL builds CULL
- reproducible self-host generation
- Piston fingerprints exact CULL artifact
- ABBY/ABIE execution boundary passes
- separate production promotion authorization passes

Until then: `CLANG_REPLACEMENT=HOLD`.
