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
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <locale.h>
#if defined __cplusplus || defined c_plusplus
extern "C" {
#endif
  void variableArguments_errorMessage(const char *errorMessageFormat, va_list variableArguments);

  void variableArguments_successMessage(const char *successMessageFormat, va_list variableArguments);

  void variableArguments_warningMessage(const char *warningMessageFormat, va_list variableArguments);

  void variableArguments_informationMessage(const char *informationMessageFormat, va_list variableArguments);

  void errorMessage(const char *errorMessageFormat, ...);

  void successMessage(const char *successMessageFormat, ...);

  void warningMessage(const char *warningMessageFormat, ...);

  void informationMessage(const char *informationMessageFormat, ...);
#if defined __cplusplus || defined c_plusplus
}
#endif
#endif
