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

  for (unsigned char i = 0; i < sizeof cpuArchitectures / sizeof *cpuArchitectures; i++)
    if (argv[1] != cpuArchitectures[i])
    {
      failureMessage("Invalid cpu architecture\n");
      return 1;
    }
  int cmd = system("echo coso");
  return 0;
}