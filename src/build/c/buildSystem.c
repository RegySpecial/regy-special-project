#include "../../include/build/c/buildSystem.h"

void build(unsigned char arch, unsigned char os)
{
  const char
    *operatingSystems[] = {
       "aix",
       "android",
       "darwin",
       "dragonflybsd",
       "freebsd",
       "illumos",
       "ios",
       "linux",
       "netbsd",
       "openbsd",
       "plan9",
       "solaris",
       "windows"
     },
    *cpuArchitectures[] = {
      "i386",
      "amd64",
      "arm",
      "arm64",
      "loong64",
      "mips",
      "mips64",
      "mipsle",
      "mips64le",
      "ppc64",
      "ppc64le",
      "riscv64",
      "s390"
     };
}

int main(int argc, char *argv[], char *envp[])
{
  const char
    *operatingSystems[] = {
       "aix",
       "android",
       "darwin",
       "dragonflybsd",
       "freebsd",
       "illumos",
       "ios",
       "linux",
       "netbsd",
       "openbsd",
       "plan9",
       "solaris",
       "windows"
     },
    *cpuArchitectures[] = {
      "i386",
      "amd64",
      "arm",
      "arm64",
      "loong64",
      "mips",
      "mips64",
      "mipsle",
      "mips64le",
      "ppc64",
      "ppc64le",
      "riscv64",
      "s390"
     };
  
  bool invalideCpuArchitecture = 1,
       invalideOperatingSystem = 1;
  for (unsigned char i = 0; i < sizeof cpuArchitectures / sizeof *cpuArchitectures; i++)
    invalideCpuArchitecture = argv[1] != cpuArchitectures[i]; 
  
  if (invalideCpuArchitecture)
  {
    errorMessage("%s is an invalid cpu architecture\n", argv[1]);
    return 1;
  }

  for (unsigned char i = 0; i < sizeof operatingSystems / sizeof *operatingSystems; i++)
    invalideOperatingSystem = argv[2] != operatingSystems[i]; 
  
  if (invalideOperatingSystem)
  {
    errorMessage("%s is an invalid operating system\n", argv[1]);
    return 1;
  }
  
  int cmd = system("echo coso");
  return 0;
}