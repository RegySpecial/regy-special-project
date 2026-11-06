/*
*@description C header file about the definition of the beep C function
*@author Regy Special
*@date 2026 June 15th Monday, 12:09:12
*@license GNU General Public License to stop private corporation to not share source code
*/
#include "../../../include/lib/c/audio/beep.h"
//open driver /dev/tty0 to produce beep sound using ioctl system call
bool beep(unsigned long frequency,unsigned long time)
{
  #if defined __WIN32||defined __WIN64
  return Beep(frequency, time);
  #else
  int tty0 = open("/dev/tty0", O_RDONLY);

  if(tty0 == -1)
    return 0;
  
  if (ioctl(tty0, KDMKTONE, (time << 16) + (1193180 / frequency)) == -1)
    return 0;
  
  if (close(tty0) == -1)
    return 0;
  
  return 1;
  #endif
}