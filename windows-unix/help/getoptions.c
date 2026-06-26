#include<getopt.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<assert.h>
#include"../include/C/audio/beep.h"
typedef struct{
  char userName[41];
  unsigned char generalPurposeMask,
                errorNumber;
};
void manageArguments(int argc,char*argv[]){
  int flag;
  const struct option options[]={
    {"help",optional_argument,NULL,'h'},
    {"user",required_argument,NULL,'u'},
    {"background",required_argument,NULL,'b'},
    {"debug",no_argument,NULL,'d'},
    {NULL,0,NULL,0}
  };
  while((flag=getopt_long(argc,argv,"h::u:b:d",options,NULL))!=-1){
    switch(flag){
      case 'd':
        break;
      case ':':
        puts("Fanculo i 2 punti");
        break;
      case '?':
        puts("Fanculo bho?!");
        break;
      case 'h':
        if(optarg!=0){
          if(strncmp(optarg,"user",4)==0){
            puts("Aiuto utente");
            exit(0);
          }
          if(strncmp(optarg,"debug",5)==0){
            puts("Aiuto debug");
            exit(0);
          }
          if(strncmp(optarg,"background",10)==0){
            puts("Aiuto background");
            exit(0);
          }
        }
        char*newArgv[]={
          "--help=user",
          "--help=debug",
          "--help=background"
        };
        for(unsigned char i=0;i<sizeof newArgv/sizeof *newArgv;i++){
          int processId=fork(),executionImage;
          switch(processId){
            case -1:
              perror("errore fork");
              exit(1);
              break;
            case 0:
              executionImage=execl(argv[0],argv[0],newArgv[i],0);
              if(executionImage==-1){
                perror("errore execl");
                exit(1);
              }
              break;
           }
        }
        wait(0);
        exit(0);
        break;
      case 'u':
        printf("user with: %s\n",optarg);
        break;
      case 'b':
        printf("background with: %s\n",optarg);
        break;
      case 'd':
        printf("debug with: %s\n",optarg);
        break;
      default:
        puts("DIS IS DI END");
        break;
    }
  }
  for(;optind<argc;optind++)
    printf("Extra arg %s\n",argv[optind]);
}
