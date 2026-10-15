#ifndef buildSystemH
#define buildSystemH
#include <stdlib.h>
#include "../../lib/c/console.h"

#if defined __cplusplus || defined c_plusplus
extern "C"{
#endif
  typedef enum
  {
    cpuArchitecture_i386,
    cpuArchitecture_amd64,
    cpuArchitecture_arm,
    cpuArchitecture_arm64,
    cpuArchitecture_loong64,
    cpuArchitecture_mips,
    cpuArchitecture_mips64,
    cpuArchitecture_mipsle,
    cpuArchitecture_mips64le,
    cpuArchitecture_ppc64,
    cpuArchitecture_ppc64le,
    cpuArchitecture_riscv64,
    cpuArchitecture_s390
  }
  cpuArchitecture;
  
  typedef enum
  {
    operatingSystem_aix,
    operatingSystem_android,
    operatingSystem_darwin,
    operatingSystem_dragonflybsd,
    operatingSystem_freebsd,
    operatingSystem_illumos,
    operatingSystem_ios,
    operatingSystem_linux,
    operatingSystem_netbsd,
    operatingSystem_openbsd,
    operatingSystem_plan9,
    operatingSystem_solaris,
    operatingSystem_windows
  }
  operatingSystem;

  typedef enum
  {
    executable,
    staticLibrary,
    dynamicLibrary
  }
  outputBinaryType;
  
  
  typedef struct
  {
    unsigned char sanitizeMask;
    unsigned char otherMask; 
  }
  controlFlags;
  

  static const char
    cConsoleLibrary[] = "src/lib/c/console.c",
    cAudioBeepLibrary[] = "src/lib/c/audio/beep.c",
    cColorsLibrary[] = "src/lib/c/colors.c",
    cManageArguments[] = "src/main/c/manageArguments.c",
    testCppManageArguments[] = "test/c++/manageArguments.cpp",
    amd64_testManageArguments[] = "/home/$USER/Scrivania/testManageArguments",
    amd64_testVideoGame[] = "/home/regyspecial/Scrivania/testVideoGame";
  
    //"bin/lib/static/a/go/elf/linux/386/CImage.a"
  
  void build(unsigned char arch, unsigned char os);
#if defined __cplusplus || defined c_plusplus
}
#endif
#endif