#ifndef compilerH
#define compilerH
#ifdef __GNUC__
#define compiler "compiler: GNU C Compiler (versione major)"
#elifdef __GNUC_MINOR__
#define compiler "compiler: GNU C Compiler (versione minor)"
#elifdef __GNUC_PATCHLEVEL__
#define compiler "compiler: GNU C Compiler (livello patch)"
#elifdef __clang__
#ifdef __clang_major__
#define compiler "compiler: Low Level Virtual Machine Clang Compiler (versione major)"
#elifdef __clang_minor__
#define compiler "compiler: Low Level Virtual Machine Clang Compiler (versione minor)"
#endif
#elifdef _MSC_VER
#define compiler "compiler: Microsoft Visual Studio C++ Compiler"
#elifdef _MSC_FULL_VER
#define compiler "compiler: Microsoft Visual Studio Compiler (complete version)"
#elifdef __INTEL_COMPILER
#define compiler "compiler: Intel C++ Compiler (ICC)"
#elifdef __INTEL_LLVM_COMPILER
#define compiler "compiler: Intel oneAPI DPC++/C++ Compiler"
#elifdef __BORLANDC__
#define compiler "compiler: Borland / Embarcadero C++ Compiler"
#elifdef __TURBOC__ 
#define compiler "compiler: Turbo C Compiler"
#elifdef __WATCOMC__ 
#define compiler "compiler: Watcom C"
#elifdef __TINYC__
#define compiler "compiler: Tiny C Compiler (TCC)" |
#elifdef __PGI
#define compiler "compiler: PGI / NVIDIA HPC Compiler"
#elifdef __NVCC__
#define compiler "compiler: NVIDIA CUDA Compiler"
#elifdef __ARMCC_VERSION
#define compiler "compiler: ARM Compiler (armcc)"
#elifdef __CC_ARM
#define compiler "compiler: ARM Compiler legacy"
#endif
#endif