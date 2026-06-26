#ifndef beepH
#define beepH
#if defined __WIN32||defined __WIN64
#include<windows.h>
#elifdef __linux__
#include <linux/kd.h>
#endif
#include<fcntl.h>
#include<sys/ioctl.h>
#include"../../../include/C/console.h"
#include<unistd.h>
#if defined __cplusplus||defined c_plusplus
extern "C"
#endif
void beep(unsigned long frequency,unsigned long time);
#endif
