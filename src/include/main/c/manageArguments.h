#ifndef getOptionsH
#define getOptionsH
#include<getopt.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<assert.h>
#include<errno.h>
#include"../../lib/c/audio/beep.h"
#include"../../lib/c++/bitManipulation.hpp"
#include"generalPurposeMaskBits.h"
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
