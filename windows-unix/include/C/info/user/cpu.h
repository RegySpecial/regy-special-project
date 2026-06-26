#ifndef cpuH
#define cpuH
#if defined __i386__||defined _M_IX86
#define cpu "CPU: x86 32 bit"
#elif defined __x86_64__||defined _M_X64
#define cpu "CPU: x86 64 bit"
#elifdef __arm__
#define cpu "CPU: ARM 32 bit"
#elifdef __aarch64__
#define cpu "CPU: ARM 64 bit (AArch64)"
#elifdef __mips__
#define cpu "CPU: MIPS"
#elifdef __mips64
#define cpu "CPU: MIPS 64 bit"
#elif defined __powerpc__||defined __ppc__
#define cpu "CPU: PowerPC 32 bit"
#elif defined __powerpc64__||defined __ppc64__
#define cpu "CPU: PowerPC 64 bit"
#elifdef __sparc__
#define cpu "CPU: SPARC"
#elifdef __sparc64__
#define cpu "CPU: SPARC 64 bit"
#elifdef __riscv
#define cpu "CPU: RISC-V"
#elifdef __s390__
#define cpu "CPU: IBM S/390"
#elifdef __s390x__
#define cpu "CPU: IBM z/Architecture 64 bit"
#elifdef __alpha__
#define "CPU: DEC Alpha"
#elif defined __ia64__||defined _M_IA64
#define "CPU: Intel Itanium"
#elifdef __m68k__
#define cpu "CPU: Motorola 68000"
#else
#define cpu "CPU: Unknown"
#endif
#endif