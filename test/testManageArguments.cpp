#include "../src/include/main/c/manageArguments.h"
int main(int argc,char*argv[],char*envp[])
{
  gameContextStructure structure;
  manageArguments(argc,argv,&structure);
  printf("user name:%s errno:%d general purpose bit mask:%u",structure.userName,structure.errorNumber,structure.generalPurposeMask);
  return 0;
}