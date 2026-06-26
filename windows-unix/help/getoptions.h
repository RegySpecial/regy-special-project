#ifndef getOptionsH
#define getOptionsH
#include<getopt.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#if defined __cplusplus || defined c_plusplus
extern "C"
#endif
void manageArguments(int argc,char*argv[]);
#endif
