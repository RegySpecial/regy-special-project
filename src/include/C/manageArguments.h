#ifndef getOptionsH
#define getOptionsH
#include<getopt.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<assert.h>
#include<errno.h>
#include"../../include/C/audio/beep.h"
#include"../../include/C++/bitManipulation.hpp"
#include"../../include/C/generalPurposeMaskBits.h"
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
