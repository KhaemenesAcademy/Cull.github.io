# Roadmap

## Alpha1
Contract, parser proof, deterministic diagnostics, target abstraction, no-delegation law.

## Alpha2
x86_64 encoder and direct Mach-O executable writer; functions, calls, stack frames, arithmetic, conditionals, loops.

## Alpha3
Pointers, arrays, structs/unions/enums, typedef, static/extern, data/string sections, function pointers, preprocessing subset, relocations, multiple translation units, internal symbol resolution/linking.

## Alpha4
Inventory every construct used by certified STOS C sources. Compile Loyer, Avouch, then bounded ABBY/ABIE test artifacts.

## Beta
CULL builds CULL. Generation N builds N+1. Reproducibility/equivalence passes with zero clang/gcc/cc/as/ld invocation. Linux parity.

## Production
Switch Piston build plans to CULL only after every replacement gate passes; certify each STOS component separately.
