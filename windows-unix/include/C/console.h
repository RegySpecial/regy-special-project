/*
*@description C source code of console messages
*@role main file source code definition
*@type C Header File
*@author Regy Special
*@date (First version [Linux/Parrot OS]) 2026 June 11th Thursday, 13:37:16
*@license GNU General Public License to stop private corporation to not share source code
*/
#ifndef consoleH
#define consoleH
#include<stdio.h>/*fprintf stderr printf sprintf*/
#if defined __cplusplus || defined c_plusplus
extern "C"{
#endif
  typedef enum{
    textStyleMaskBit_reset,
    textStyleMaskBit_bold,
    textStyleMaskBit_faint,
    textStyleMaskBit_italic,
    textStyleMaskBit_underline,
    textStyleMaskBit_slowBlink,
    textStyleMaskBit_rapidBlink,
    textStyleMaskBit_invert,
    textStyleMaskBit_hide,
    textStyleMaskBit_strike,
    textStyleMaskBit_backgroundColorEnabled,
    textStyleMaskBit_textColorEnabled
  }textStyleMaskBit;
  typedef struct{
    const char*messageTypeString,
              *messageString;
    struct textColor{
      unsigned char red,
                    green,
                    blue;
    }textColor;
    struct backgroundColor{
      unsigned char red,
                    green,
                    blue;
    }backgroundColor;
    unsigned long long textStyleMask;
  }messageStructure;
  int customizedMessage(messageStructure*messageStructureReference);
  static inline int failureMessage(const char*messageString){
    return fprintf(stderr,"\e[38;255;255;255m[\e[38;2;255;0;0mFailed\e[38;2;255;255;255m]%s\e[0m",messageString);
  }
  static inline int OKMessage(const char*messageString){
    return printf("\e[38;255;255;255m[\e[38;2;0;255;0mOK\e[38;2;255;255;255m]%s\e[0m\n",messageString);
  }
  static inline int warningMessage(const char*messageString){
    return printf("\e[38;255;255;255m[\e[38;2;255;255;0mWarning\e[38;2;255;255;255m]%s\e[0m\n",messageString);
  }
  static inline int informationMessage(const char*messageString){
    return printf("\e[38;255;255;255m[\e[38;2;0;0;255mInfo\e[38;2;255;255;255m]%s\e[0m\n",messageString);
  }
#if defined __cplusplus || defined c_plusplus
}
#endif
#endif