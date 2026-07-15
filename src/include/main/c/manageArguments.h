#ifndef manageArgumentsH
#define manageArgumentsH
/*
*@description C header file about the definition of the beep C function
*@author Regy Special
*@date 2026 June 15th Monday, 12:09:12
*@license GNU General Public License to stop private corporation to not share source code
*/
#include<getopt.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<assert.h>
#include<errno.h>
#include"../../lib/c/audio/beep.h"
#include"../c/generalPurposeMaskBits.h"
#if defined __cplusplus || defined c_plusplus
extern "C"{
#endif
  typedef struct{
    char userName[41];
    unsigned char generalPurposeMask,
                  errorNumber;
  }gameContextStructure;
  int manageArguments(int argc,char*argv[],gameContextStructure*gCtxtStruct);
#if defined __cplusplus || defined c_plusplus
}
#endif
#endif
