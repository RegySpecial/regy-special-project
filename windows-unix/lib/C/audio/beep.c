#if defined __WIN32||defined __WIN64
#include<windows.h>
#elifdef __linux__
#include <linux/kd.h>
#endif
#include<fcntl.h>
#include<sys/ioctl.h>
#include"../../../include/C/console.h"
#include<unistd.h>
//open driver /dev/tty0 to produce beep sound using ioctl system call
void beep(unsigned long frequency,unsigned long time){
  #if defined __WIN32||defined __WIN64
  Beep(frequency,time);
  #else
  int tty0=open("/dev/tty0",O_RDONLY);
  if(tty0==-1)failureMessage("Cannot interact with /dev/tty0 to use beep!");
  ioctl(tty0,KDMKTONE,(time<<16)+(1193180/frequency));
  close(tty0);
  #endif
}