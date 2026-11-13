#ifndef audioCoreH
#define audioCoreH
#if defined __WIN32 || defined __WIN64
#error This library is not meant to work on Windows/Windows-like operating systems!
#else
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#ifdef __linux__
#include <sound/asound.h>
#elif defined __FreeBSD__ || defined __OpenBSD__ || defined __NetBSD__
#include <sys/audioio.h>
#endif
#endif
#endif