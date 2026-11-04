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

void variableArguments_errorMessage(const char *errorMessageFormat, va_list variableArguments)
{
  fprintf(stderr, "\e[97m[\e[91mError\e[97m]\e[0m");
  vfprintf(stderr, errorMessageFormat, variableArguments);
}

void variableArguments_successMessage(const char *successMessageFormat, va_list variableArguments)
{ 
  printf("\e[97m[\e[92mSuccess\e[97m]\e[0m");
  vprintf(successMessageFormat, variableArguments);
}

void variableArguments_warningMessage(const char *warningMessageFormat, va_list variableArguments)
{ 
  printf("\e[97m[\e[93mWarning\e[97m]\e[0m");
  vprintf(warningMessageFormat, variableArguments);
}

void variableArguments_informationMessage(const char *informationMessageFormat, va_list variableArguments)
{
  printf("\e[97m[\e[94mInformation\e[97m]\e[0m");
  vprintf(informationMessageFormat, variableArguments);
}

void errorMessage(const char *errorMessageFormat, ...)
{
  va_list variableArguments;
  va_start(variableArguments, errorMessageFormat);
  variableArguments_errorMessage(errorMessageFormat, variableArguments);
  va_end(variableArguments);
}

void successMessage(const char *successMessageFormat, ...)
{
  va_list variableArguments;
  va_start(variableArguments, successMessageFormat);
  variableArguments_successMessage(successMessageFormat, variableArguments);
  va_end(variableArguments);
}

void warningMessage(const char *warningMessageFormat, ...)
{
  va_list variableArguments;
  va_start(variableArguments, warningMessageFormat);
  variableArguments_warningMessage(warningMessageFormat, variableArguments);
  va_end(variableArguments);
}

void informationMessage(const char *informationMessageFormat, ...)
{
  va_list variableArguments;
  va_start(variableArguments, informationMessageFormat);
  variableArguments_informationMessage(informationMessageFormat, variableArguments);
  va_end(variableArguments);
}
