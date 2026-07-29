/*
*@description Header file where is defined the dynamic array data structure class of the dynamic array data structure library
*@author Regy Special
*@date (First version [Linux/Parrot OS]) 2026 March 7th Saturday, 16:12:08
*@license GNU General Public License to stop private corporation to not share source code
*/
#include "../../include/main/c/manageArguments.h"
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
    char* const userSuboptions[]={
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
      case 'u':
        while((flagArgs=getsubopt(&optarg,userSuboptions,&suboptionValue))!=-1){
          switch(flagArgs){
            case 0://handle name suboption case
              if(strlen(suboptionValue)>40){
                failureMessage("Name rejected: the user name character number must lower than or equal to 40 characters!");
                return (gCtxtStruct->errorNumber=1);
              }
              //connect to the database and check if name is redondant or not
              informationMessage("Ottienimento informazioni non disponibile al momento");
              break;
            case 1://handle identifier suboption case
              if(atoi(suboptionValue)<0){
                failureMessage("Identifier rejected: the user identifier must be positive!");
                return (gCtxtStruct->errorNumber=1);
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
                return (gCtxtStruct->errorNumber=1);
              }
              //connect to the database and check if name is redondant or not
              informationMessage("Ottienimento informazioni non disponibile al momento");
              break;
            case 1://handle identifier suboption case
              if(atoi(suboptionValue)<0){
                failureMessage("Identifier rejected: the user identifier must be positive!");
                return (gCtxtStruct->errorNumber=1);
              }
              //connect to the database and check if the user is identified or not
              informationMessage("Ottienimento informazioni non disponibile al momento");
              break;
          }
        }
        break;
      default:
        failureMessage(strcat("Invalid flag ",optarg));
        gCtxtStruct->errorNumber=1;
        return 1;
        break;
      case 'd':
        gCtxtStruct->generalPurposeMask |= 1<<generalPurposeMaskBits_debug;
        break;
      case 'h':
        if(optarg){
          if(!strncmp(optarg,"user",4)){
            puts("Aiuto utente");
            return (gCtxtStruct->errorNumber=0);
          }
          if(!strncmp(optarg,"debug",5)){
            puts("Aiuto debug");
            return (gCtxtStruct->errorNumber=0);
          }
          if(!strncmp(optarg,"background",10)){
            puts("Aiuto background");
            return (gCtxtStruct->errorNumber=0);
          }
        }
        const char*newArgv[]={
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
        waitpid(-1,NULL,0);
        return (gCtxtStruct->errorNumber=0);
        break;
    }
  }
  return 0;
}