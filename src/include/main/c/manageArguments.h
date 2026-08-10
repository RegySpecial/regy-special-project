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
#include "../../lib/c/console.h"
#include "generalPurposeMaskBits.h"
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
  
  int manageArguments(int argc,char*argv[],gameContextStructure*gCtxtStruct);
#if defined __cplusplus || defined c_plusplus
}
#endif
#endif
