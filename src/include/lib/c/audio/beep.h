#ifndef beepH
#define beepH
/*
*@description C header file about the definition of the beep C function
*@author Regy Special
*@date 2026 June 25th Thursday, 20:07:59
*@license GNU General Public License to stop private corporation to not share source code
*/

#if defined __WIN32||defined __WIN64
#include <windows.h>
#elifdef __linux__
#include <linux/kd.h>
#define beepDevice "/dev/tty0"
#elifdef __FreeBSD__
#include <dev/speaker/speaker.h>
#define beepDevice "/dev/speaker"
#endif
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#if defined __cplusplus || defined c_plusplus
extern "C"
#endif
bool beep(unsigned long frequency,unsigned long time);
#endif