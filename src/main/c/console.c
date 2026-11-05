/*
*@description C source code of console messages
*@role main file source code
*@type C file
*@author Regy Special
*@date (First version [Linux/Parrot OS]) 2026 June 11th Thursday, 13:47:47
*@license GNU General Public License to stop private corporation to not share source code
*/
#include "../../include/main/c/console.h"

void variableArguments_errorMessage(const char *errorMessageFormat, va_list variableArguments)
{
  const time_t Now = time(0);
  const struct tm *timeStructure = localtime(&Now);
  char timeStamp[1024],
       *locality = setlocale(LC_TIME, "");
  strftime(timeStamp, 1024, "%Y %B %d %A %H:%M:%S %p %Z");
  fprintf(stderr, "\e[97m[\e[91mError\e[97m]\e[0m%s, %s, at %d of %s, ", timeStamp, locality, __LINE__, __FILE__);
  vfprintf(stderr, errorMessageFormat, variableArguments);
}

void variableArguments_successMessage(const char *successMessageFormat, va_list variableArguments)
{
  const time_t Now = time(0);
  const struct tm *timeStructure = localtime(&Now);
  char timeStamp[1024],
       *locality = setlocale(LC_TIME, "");
  strftime(timeStamp, 1024, "%Y %B %d %A %H:%M:%S %p %Z");
  printf("\e[97m[\e[92mSuccess\e[97m]\e[0m%s, %s, at %d of %s, ", timeStamp, locality, __LINE__, __FILE__);
  vprintf(successMessageFormat, variableArguments);
}

void variableArguments_warningMessage(const char *warningMessageFormat, va_list variableArguments)
{
  const time_t Now = time(0);
  const struct tm *timeStructure = localtime(&Now);
  char timeStamp[1024],
       *locality = setlocale(LC_TIME, "");
  strftime(timeStamp, 1024, "%Y %B %d %A %H:%M:%S %p %Z");
  fprintf(stderr, "\e[97m[\e[93mWarning\e[97m]\e[0m%s, %s, at %d of %s, ", timeStamp, locality, __LINE__, __FILE__);
  vfprintf(stderr, warningMessageFormat, variableArguments);
}

void variableArguments_informationMessage(const char *informationMessageFormat, va_list variableArguments)
{
  const time_t Now = time(0);
  const struct tm *timeStructure = localtime(&Now);
  char timeStamp[1024],
       locality = setlocale(LC_TIME, "");
  strftime(timeStamp, 1024, "%Y %B %d %A %H:%M:%S %p %Z");
  printf("\e[97m[\e[94mInformation\e[97m]\e[0m%s, %s, at %d of %s, ", timeStamp, locality, __LINE__, __FILE__);
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
