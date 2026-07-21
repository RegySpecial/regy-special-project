#ifndef beepH
#define beepH
/*
*@description C header file about the definition of the beep C function
*@author Regy Special
*@date 2026 June 25th Thursday, 20:07:59
*@license GNU General Public License to stop private corporation to not share source code
*/
#if defined __WIN32||defined __WIN64
#include<windows.h>
#elifdef __linux__
#include <linux/kd.h>
#endif
#include<fcntl.h>
#include<sys/ioctl.h>
#include"../console.h"
#include<unistd.h>
#if defined __cplusplus || defined c_plusplus
extern "C"
#endif
void beep(unsigned long frequency,unsigned long time);
#endif