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
  const char*newArgv[]={
    "--help=user",
    "--help=debug",
    "--help=background"
  };
  char
    * const userSuboptions[]={
      "name",
      "idenitifier"
    },
    * const backgroundSuboptions[]={
      "color",
      "pixelmap",
      "path"
    },
    * const helpSuboptions[]={
      "user",
      "debug",
      "background"
    },
    *suboptionValue;
  const char
    *userExplanation[]={
      "a string of max 40 characters that will be the user name at account login",
      "a positive integer number that identifies the account login"
    },
    *backgroundExplanation[]={
      "the color of the main screen videogame background in RGB format",
      "the pixelmap of the main screen videogame background in RGB format",
      "the path of the main screen videogame background in RGB format"
    },
    *helpExplanation[]={
      "login in the videogame through <userName> and <userIdentifier>",
      "display debug informations",
      "set the background of the videogame main screen in the following order (<backgroundColor>,<backgroundPixelmap>,<backgroundPath>)"
    };
  while ((flag = getopt_long(argc,argv,"h::u:b:a:d",options,NULL)) != -1)
  {
    switch (flag)
    {
      case 'u':
        while ((flagArgs = getsubopt(&optarg,userSuboptions,&suboptionValue)) != -1)
        {
          switch (flagArgs)
          {
            case userFlagSuboptions_name:
              if (strlen(suboptionValue) > 40)
              {
                failureMessage("Name rejected: the user name character number must lower than or equal to 40 characters!");
                return (gCtxtStruct->errorNumber = 1);
              }
              //connect to the database and check if name is redondant or not
              informationMessage("Ottienimento informazioni non disponibile al momento");
              return (gCtxtStruct->errorNumber = 0);
            case userFlagSuboptions_identifier:
              if (atoi(suboptionValue) < 0)
              {
                failureMessage("Identifier rejected: the user identifier must be positive!");
                return (gCtxtStruct->errorNumber = 1);
              }
              //connect to the database and check if the user is identified or not
              informationMessage("Ottienimento informazioni non disponibile al momento");
              return (gCtxtStruct->errorNumber = 0);
          }
        }
        break;
      case 'b':
        while ((flagArgs = getsubopt(&optarg,backgroundSuboptions,&suboptionValue)) != -1)
        {
          switch (flagArgs)
          {
            case 0://handle name suboption case
              if(strlen(suboptionValue)>40){
                failureMessage("Name rejected: the user name character number must lower than or equal to 40 characters!");
                return (gCtxtStruct->errorNumber = 1);
              }
              //connect to the database and check if name is redondant or not
              informationMessage("Ottienimento informazioni non disponibile al momento");
              return (gCtxtStruct->errorNumber = 0);
            case 1://handle identifier suboption case
              if(atoi(suboptionValue)<0){
                failureMessage("Identifier rejected: the user identifier must be positive!");
                return (gCtxtStruct->errorNumber = 1);
              }
              //connect to the database and check if the user is identified or not
              informationMessage("Ottienimento informazioni non disponibile al momento");
              return (gCtxtStruct->errorNumber = 0);
          }
        }
        break;
      case 'd':
        gCtxtStruct->generalPurposeMask |= 1 << generalPurposeMaskBits_debug;
        return (gCtxtStruct->errorNumber = 0);
      case 'h':
        //what if he use subopt
        while ((flagArgs = getsubopt(&optarg,helpSuboptions,&suboptionValue)) != -1) {
          switch (flagArgs) {
            case helpFlagSuboptions_user:
              for (unsigned char index = 0; index < sizeof helpSuboptions / sizeof *helpSuboptions; index++)
                if (!strncmp(suboptionValue,helpSuboptions[index],strlen(helpSuboptions[index]))) {
                  char* const suboptionCopy = helpSuboptions[index];
                  *suboptionCopy-='z'+'Z';//lowerCase = upperCase + 'z' - 'Z' , upperCase = lowerCase + 'Z' - 'z'
                  printf("Usage: %s [-u|--user=]%s=<user%s>\n",argv[0],helpSuboptions[index],suboptionCopy);
                  printf("\t%s=<user%s> %s\n",helpSuboptions[index],suboptionCopy,userExplanation[index]);
                  return (gCtxtStruct->errorNumber = 0);
                }
              break;
            case helpFlagSuboptions_background:
              for (unsigned char index = 0; index < sizeof backgroundSuboptions / sizeof *backgroundSuboptions; index++)
                if (!strncmp(suboptionValue,backgroundSuboptions[index],strlen(backgroundSuboptions[index]))) {
                  char* const suboptionCopy = backgroundSuboptions[index];
                  *suboptionCopy-='z'+'Z';//lowerCase = upperCase + 'z' - 'Z' , upperCase = lowerCase + 'Z' - 'z'
                  printf("Usage: %s [-u|--user=]%s=<user%s>\n",argv[0],backgroundSuboptions[index],suboptionCopy);
                  printf("\t%s=<user%s> %s\n",backgroundSuboptions[index],suboptionCopy,backgroundExplanation[index]);
                  return (gCtxtStruct->errorNumber = 0);
                }
            default:
              printf("Usage: %s [-u|--user=]name=<userName>,identifier=<userIdentifier>\n",argv[0]);
              puts("Subflags:");
              for (unsigned char index = 0; index < sizeof helpSuboptions / sizeof *helpSuboptions; index++){
                char* const suboptionCopy = helpSuboptions[index];
                            *suboptionCopy-='z'+'Z';//lowerCase = upperCase + 'z' - 'Z' , upperCase = lowerCase + 'Z' - 'z'
                printf("\t%s=<user%s> %s\n",helpSuboptions[index],suboptionCopy,helpExplanation[index]);
              }
              puts("Description:");
              puts("\tIt searches in the videogame database for an account named with <userName> and identified by <userIdentifier>.");
              puts("\tif <userName> is empty, when the videogame boots, it will be display a form to input it; then the name must be not empty.");
              puts("\tif there is an another name in the database that is equal to <userName>, the form will require instead that you input the identifier of that account (that is not redondant).");
              return (gCtxtStruct->errorNumber = 0);
              break;
          }
        }
        if (optarg) {
          if(!strncmp(optarg,"user",4)){
            printf("Usage: %s [-u|--user=]name=<userName>,identifier=<userIdentifier>\n",argv[0]);
            puts("Subflags:");
            puts("\tname=<userName> a string of max 40 characters that will be the user name at account login");
            puts("\tidentifier=<userIdentifier> a positive integer number that identifies the account login");
            puts("Description:");
            puts("\tIt searches in the videogame database for an account named with <userName> and identified by <userIdentifier>.");
            puts("\tif <userName> is empty, when the videogame boots, it will be display a form to input it; then the name must be not empty.");
            puts("\tif there is an another name in the database that is equal to <userName>, the form will require instead that you input the identifier of that account (that is not redondant).");
            return (gCtxtStruct->errorNumber = 0);
          }
          if(!strncmp(optarg,"debug",5)){
            printf("Usage: %s [-d|--debug]\n",argv[0]);
            puts("Description:");
            puts("\tWhen the game boots, it is possible to see of the specific output messages on the terminal");
            return (gCtxtStruct->errorNumber = 0);
          }
          if(!strncmp(optarg,"background",10)){
            puts("Aiuto background");
            return (gCtxtStruct->errorNumber = 0);
          }
        }
        for(unsigned char i=0;i<sizeof newArgv/sizeof *newArgv;i++){
          int processId=fork(),executionImage;
          switch (processId) {
            case -1:
              failureMessage(strerror(errno));
              return (gCtxtStruct->errorNumber=errno);
              break;
            case 0:
              executionImage = execl(argv[0],argv[0],newArgv[i],0);
              if (executionImage == -1) {
                failureMessage(strerror(errno));
                return (gCtxtStruct->errorNumber = errno);
              }
              break;
           }
        }
        wait(NULL);
        return (gCtxtStruct->errorNumber = 0);
      default:
        failureMessage("Invalid flag");
        return (gCtxtStruct->errorNumber = 1);
    }
  }
  return 0;
}