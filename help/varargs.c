#include <stdarg.h>
#include <stdio.h>

void errorMessage(const char *string, ...)
{
  va_list varArgs;
  va_start(varArgs, string);
  fprintf(stderr, "\e[38;2;255;255;255m[\e[38;2;255;0;0mFailed\e[38;2;255;255;255m]\e[0m");
  vfprintf(stderr, string, varArgs);
  va_end(varArgs);
}

int main()
{
  errorMessage("%i\n", 5);
  return 0;
}
