/*
*@description C source code of console messages
*@role main file source code
*@type C file
*@author Regy Special
*@date (First version [Linux/Parrot OS]) 2026 June 11th Thursday, 13:47:47
*@license GNU General Public License to stop private corporation to not share source code
*/
#include "../../include/lib/c/console.h"
int customizedMessage(messageStructure*messageStructureReference)
{
  char backgroundColorFormat[20],
       textColorFormat[20];
  sprintf(
    backgroundColorFormat,
    "\e[48;2;%3u;%3u;%3um",
    messageStructureReference->backgroundColor.red,
    messageStructureReference->backgroundColor.green,
    messageStructureReference->backgroundColor.blue
  );
  sprintf(
    textColorFormat,
    "\e[38;2;%3u;%3u;%3um",
    messageStructureReference->textColor.red,
    messageStructureReference->textColor.green,
    messageStructureReference->textColor.blue
  );
  return printf(
    "\e[38;2;255;255;255m[%s%s%s%s%s%s%s%s%s%s%s%s%s\e[38;255;255;255m]%s\e[0m",
    messageStructureReference->textStyleMask>>textStyleMaskBit_backgroundColorEnabled?backgroundColorFormat:"",
    messageStructureReference->textStyleMask>>textStyleMaskBit_textColorEnabled?textColorFormat:"",
    messageStructureReference->textStyleMask>>textStyleMaskBit_reset?"\e[0m":"",
    messageStructureReference->textStyleMask>>textStyleMaskBit_bold?"\e[1m":"",
    messageStructureReference->textStyleMask>>textStyleMaskBit_faint?"\e[2m":"",
    messageStructureReference->textStyleMask>>textStyleMaskBit_italic?"\e[3m":"",
    messageStructureReference->textStyleMask>>textStyleMaskBit_underline?"\e[4m":"",
    messageStructureReference->textStyleMask>>textStyleMaskBit_slowBlink?"\e[5m":"",
    messageStructureReference->textStyleMask>>textStyleMaskBit_rapidBlink?"\e[6m":"",
    messageStructureReference->textStyleMask>>textStyleMaskBit_invert?"\e[7m":"",
    messageStructureReference->textStyleMask>>textStyleMaskBit_hide?"\e[8m":"",
    messageStructureReference->textStyleMask>>textStyleMaskBit_strike?"\e[9m":"",
    messageStructureReference->messageTypeString,
    messageStructureReference->messageString
  );
}

void errorMessage(const char *errorMessageFormat, ...)
{
  va_list varArgs;
  va_start(varArgs, errorMessageFormat);
  fprintf(stderr, "\e[38;2;255;255;255m[\e[38;2;255;0;0mError\e[38;2;255;255;255m]\e[0m");
  vfprintf(stderr, errorMessageFormat, varArgs);
  va_end(varArgs);
}

void successMessage(const char *successMessageFormat, ...)
{
  va_list varArgs;
  va_start(varArgs, successMessageFormat);
  printf("\e[38;2;255;255;255m[\e[38;2;0;255;0mSuccess\e[38;2;255;255;255m]\e[0m");
  vprintf(successMessageFormat, varArgs);
  va_end(varArgs);
}

void warningMessage(const char *warningMessageFormat, ...)
{
  va_list varArgs;
  va_start(varArgs, warningMessageFormat);
  printf("\e[38;2;255;255;255m[\e[38;2;255;255;0mWarning\e[38;2;255;255;255m]\e[0m");
  vprintf(warningMessageFormat, varArgs);
  va_end(varArgs);
}

void informationMessage(const char *informationMessageFormat, ...)
{
  va_list varArgs;
  va_start(varArgs, informationMessageFormat);
  printf("\e[38;2;255;255;255m[\e[38;2;0;0;255mInformation\e[38;2;255;255;255m]\e[0m");
  vprintf(informationMessageFormat, varArgs);
  va_end(varArgs);
}