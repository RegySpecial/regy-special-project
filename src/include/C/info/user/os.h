#ifndef osH
#define osH
#ifdef _WIN32
#define os "OS: Windows (32 o 64 bit)"
#elifdef _WIN64
#define os "OS: Windows 64 bit"
#elifdef __linux__
#define os "OS: Linux Kernel Operating System"
#elifdef __FreeBSD__
#define os "OS: FreeBSD"
#elifdef __OpenBSD__
#define os "OS: OpenBSD"
#elifdef __NetBSD__
#define os "OS: NetBSD"
#elifdef __sun
#define os "OS: Solaris/SunOS"
#elifdef __hpux
#define os "OS: HP-UX"
#elifdef _AIX
#define os "OS: AIX"
#elifdef __HAIKU__
#define os "OS: Haiku OS"
#else
#define os "OS: Unknown"
#endif
#endif