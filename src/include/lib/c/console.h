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
#include "colors.h" /*rgb*/
#include <stdio.h>  /*fprintf stderr printf sprintf*/
#include <stdarg.h> /*va_list va_start va_end*/
#if defined __cplusplus || defined c_plusplus
extern "C" {
#endif
  typedef enum
  : unsigned char
  {
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
  }
  textStyleMaskBit;

  typedef struct
  {
    const char*messageTypeString,
              *messageString;
    rgb textColor,
        backgroundColor;
    unsigned long long textStyleMask;
  }
  messageStructure;

  int customizedMessage(messageStructure *messageStructureReference);

  void errorMessage(const char *errorMessageFormat, ...);
  
  void successMessage(const char *successMessageFormat, ...);
  
  void warningMessage(const char *warningMessageFormat, ...);
  
  void informationMessage(const char *informationMessageFormat, ...);
#if defined __cplusplus || defined c_plusplus
}
#endif
#endif