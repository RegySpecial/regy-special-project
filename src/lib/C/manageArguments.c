#include<getopt.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<assert.h>
#include<errno.h>
#include"../../include/C/audio/beep.h"
#include"../../include/C++/bitManipulation.hpp"
#include"../../include/C/generalPurposeMaskBits.h"
typedef struct{
  char userName[41];
  unsigned char generalPurposeMask,
                errorNumber;
}gameContextStructure;
int manageArguments(int argc,char*argv[],gameContextStructure*gCtxtStruct){
  int flag,flagArgs;
  const struct option options[]={
    {"help",optional_argument,NULL,'h'},
    {"user",required_argument,NULL,'u'},
    {"background",required_argument,NULL,'b'},
    {"audio",required_argument,NULL,'a'},
    {"debug",no_argument,NULL,'d'},
    {NULL,0,NULL,0}
  };
  while((flag=getopt_long(argc,argv,"h::u:b:a:d",options,NULL))!=-1){
    char*userSuboptions[]={
          "user",
          "idenitifier"
        },
        *backgroundSuboptions[]={
          "color",
          "pixelmap",
          "path"
        },
        *suboptionValue;
    switch(flag){
      default:
        failureMessage(strcat("Invalid flag ",optarg));
        gCtxtStruct->errorNumber=1;
        abort();
        break;
      case 'd':
        gCtxtStruct->generalPurposeMask=setBit(gCtxtStruct->generalPurposeMask,generalPurposeMaskBits_debug);
        break;
      case 'h':
        if(optarg!=0){
          if(strncmp(optarg,"user",4)==0){
            puts("Aiuto utente");
            return (gCtxtStruct->errorNumber=0);
          }
          if(strncmp(optarg,"debug",5)==0){
            puts("Aiuto debug");
            return (gCtxtStruct->errorNumber=0);
          }
          if(strncmp(optarg,"background",10)==0){
            puts("Aiuto background");
            return (gCtxtStruct->errorNumber=0);
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
              failureMessage(strerror(errno));
              return (gCtxtStruct->errorNumber=errno);
              break;
            case 0:
              executionImage=execl(argv[0],argv[0],newArgv[i],0);
              if(executionImage==-1){
                failureMessage(strerror(errno));
                return (gCtxtStruct->errorNumber=errno);
              }
              break;
           }
        }
        wait(0);
        return (gCtxtStruct->errorNumber=0);
        break;
      case 'u':
        while((flagArgs=getsubopt(&optarg,userSuboptions,&suboptionValue))!=-1){
          switch(flagArgs){
            case 0://handle name suboption case
              if(strlen(suboptionValue)>40){
                failureMessage("Name rejected: the user name character number must lower than or equal to 40 characters!");
                gCtxtStruct->errorNumber=1;
                abort();
              }
              //connect to the database and check if name is redondant or not
              informationMessage("Ottienimento informazioni non disponibile al momento");
              break;
            case 1://handle identifier suboption case
              if(atoi(suboptionValue)<0){
                failureMessage("Identifier rejected: the user identifier must be positive!");
                gCtxtStruct->errorNumber=1;
                abort();
              }
              //connect to the database and check if the user is identified or not
              informationMessage("Ottienimento informazioni non disponibile al momento");
              return 0;
              break;
          }
        }
        break;
      case 'b':
        while((flagArgs=getsubopt(&optarg,backgroundSuboptions,&suboptionValue))!=-1){
          switch(flagArgs){
            case 0://handle name suboption case
              if(strlen(suboptionValue)>40){
                failureMessage("Name rejected: the user name character number must lower than or equal to 40 characters!");
                gCtxtStruct->errorNumber=1;
                abort();
              }
              //connect to the database and check if name is redondant or not
              informationMessage("Ottienimento informazioni non disponibile al momento");
              break;
            case 1://handle identifier suboption case
              if(atoi(suboptionValue)<0){
                failureMessage("Identifier rejected: the user identifier must be positive!");
                gCtxtStruct->errorNumber=1;
                abort();
              }
              //connect to the database and check if the user is identified or not
              informationMessage("Ottienimento informazioni non disponibile al momento");
              break;
          }
        }
        break;
    }
  }
  return 0;
}
