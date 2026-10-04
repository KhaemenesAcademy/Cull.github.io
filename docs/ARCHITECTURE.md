# Architecture

Pipeline: bounded source intake → lex/parse → semantic analysis → typed CULL IR → target lowering → direct native image writer → CULL-owned artifact fingerprint/receipt.

Target order: x86_64 Mach-O (current Mac), x86_64 ELF (Linux), AArch64 ELF, AArch64 Mach-O, then PE/COFF as required.

CULL must eventually own the needed assembler/linker-equivalent emission internally; replacing Clang while delegating to `as` or `ld` would not close the dependency.
