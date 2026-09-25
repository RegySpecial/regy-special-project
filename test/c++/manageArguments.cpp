#include "../src/include/main/c/manageArguments.h"
int main(int argc,char*argv[],char*envp[])
{
  gameContextStructure structure = manageCommandLineArguments(argc,argv);
  printf("user name:%s errno:%d general purpose bit mask:%u\n",structure.userName,structure.exitStatus,structure.generalPurposeMask);
  return 0;
}