#ifndef manageArgumentsH
#define manageArgumentsH
/*
*@description C header file about the definition of the beep C function
*@author Regy Special
*@date 2026 June 15th Monday, 12:09:12
*@license GNU General Public License to stop private corporation to not share source code
*/
#include <getopt.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <assert.h>
#include <errno.h>
#include <regex.h>
#include "../../lib/c/console.h"
#include "generalPurposeMaskBits.h"
#include "../../lib/c/colors.h"

#define colorFunctionsRegularExpression "\\s*((hsl|rgb)\\s*\\((\\s*[0-9]{1,3}\\s*\\,){2}\\s*[0-9]{1,3}\\s*\\)|((hsl|rgb)a|cymk)\\s*\\((\\s*[0-9]{1,3}\\s*\\,){3}\\s*[0-9]{1,3}\\s*\\)|cmyka\\s*\\((\\s*[0-9]{1,3}\\s*\\,){4}\\s*[0-9]{1,3}\\s*\\))\\s*"

#if defined __cplusplus || defined c_plusplus
extern "C"{
#endif
  typedef enum{
    flagSuboptionsIndex_user,
    flagSuboptionsIndex_background,
    flagSuboptionsIndex_help
  }flagSuboptionsIndex;
  
  typedef enum{
    userFlagSuboptions_name,
    userFlagSuboptions_identifier
  }userFlagSuboptions;

  typedef enum{
    helpFlagSuboptions_user,
    helpFlagSuboptions_background,
    helpFlagSuboptions_audio
  }helpFlagSuboptions;

  typedef enum{
    backgroundFlagSuboptions_color,
    backgroundFlagSuboptions_pixelmap,
    backgroundFlagSuboptions_path
  }backgroundFlagSuboptions;

  typedef struct{
    char userName[41],
         userId[10],
         *backgroundPath;
    unsigned char generalPurposeMask,
                  errorNumber;
    unsigned long backgroundColor:24,
                  *backgroundPixelmap
  }gameContextStructure;
  
  gameContextStructure manageArguments(int argc,char*argv[]);
#if defined __cplusplus || defined c_plusplus
}
#endif
#endif
