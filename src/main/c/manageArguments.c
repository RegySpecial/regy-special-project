/*
*@description Header file where is defined the dynamic array data structure class of the dynamic array data structure library
*@author Regy Special
*@date (First version [Linux/Parrot OS]) 2026 March 7th Saturday, 16:12:08
*@license GNU General Public License to stop private corporation to not share source code
*/
#include "../../include/main/c/manageArguments.h"
gameContextStructure manageArguments(int argc,char*argv[]){
  gameContextStructure gCtxtStruct = {
    .errorNumber = 0,
    .backgroundColor = 0,
    .userName = "",
    .userId = ""
  };
  int flag,flagArgs;
  const struct option options[]={
    {"help",optional_argument,NULL,'h'},
    {"user",required_argument,NULL,'u'},
    {"background",required_argument,NULL,'b'},
    {"audio",required_argument,NULL,'a'},
    {"debug",no_argument,NULL,'d'},
    {NULL,0,NULL,0}
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
              int print = strlen(suboptionValue) > 40
                          ? failureMessage("Name rejected: the user name character number must lower than or equal to 40 characters!")
                          : informationMessage("Ottienimento informazioni non disponibile al momento");
              gCtxtStruct.errorNumber = strlen(suboptionValue) <= 40;
              break;
            case userFlagSuboptions_identifier:
              int print = atoi(suboptionValue) < 0
                          ? failureMessage("Identifier rejected: the user identifier must be positive!")
                          : informationMessage("Ottienimento informazioni non disponibile al momento");
              gCtxtStruct.errorNumber = atoi(suboptionValue) < 0;
              break;
          }
        }
        break;
      case 'b':
        while ((flagArgs = getsubopt(&optarg,backgroundSuboptions,&suboptionValue)) != -1)
        {
          switch (flagArgs)
          {
            case backgroundFlagSuboptions_color:
              regex_t regularExpression;
              regmatch_t occurrency;
              assert(!regcomp(&regularExpression, colorFunctionsRegularExpression, REG_ICASE | REG_EXTENDED));
              if (!regexec(&regularExpression, suboptionValue, 1, &occurrency, REG_ICASE | REG_EXTENDED))
              {
                unsigned char functionIndex = 0;
                char colorFuntionString[5+1+4*(3+1)+1]={};
                for (unsigned long suboptionValueIndex = 0; suboptionValueIndex < suboptionValue[suboptionValueIndex]; suboptionValueIndex++)
                  for(unsigned char spaceIndex = 0; spaceIndex < sizeof "\n\t\v\f\r " / sizeof *"\n\t\v\f\r "; spaceIndex++)
                    if (suboptionValue[suboptionValueIndex] != "\n\t\v\f\r "[spaceIndex])
                    {
                      colorFuntionString[functionIndex] = suboptionValue[suboptionValueIndex];
                      functionIndex += 1;
                    }
                if (!strcmp(colorFuntionString,"hsl"))
                {
                  hsl HSL={};
                  for (char* paramGet = strtok(colorFuntionString + 4, ","), index = 0; paramGet; paramGet = strtok(NULL, ","), index++)
                    ((unsigned char*) &HSL)[index] = atoi(paramGet);
                  
                  rgb trueColor = hslToRgb(HSL);
                  gCtxtStruct.backgroundColor = trueColor.red << 16 | trueColor.green << 8 | trueColor.blue;
                }
                else if (!strcmp(colorFuntionString,"hsla"))
                {
                  hsla HSLA={};
                  for (char* paramGet = strtok(colorFuntionString + 5, ","), index = 0; paramGet; paramGet = strtok(NULL, ","), index++)
                    ((unsigned char*) &HSLA)[index] = atoi(paramGet);
                  
                  rgba trueColor = hslaToRgba(HSLA);
                  gCtxtStruct.backgroundColor = trueColor.red << 16 | trueColor.green << 8 | trueColor.blue;
                }
              }
              gCtxtStruct.errorNumber = 0;
              regfree(&regularExpression);
              break;
            case backgroundFlagSuboptions_pixelmap://handle name suboption case
              if (strlen(suboptionValue) > 40)
              {
                failureMessage("Name rejected: the user name character number must lower than or equal to 40 characters!");
                gCtxtStruct.errorNumber = 1;
              }
              //connect to the database and check if name is redondant or not
              informationMessage("Ottienimento informazioni non disponibile al momento");
              gCtxtStruct.errorNumber = 0;
              break;
            case backgroundFlagSuboptions_path://handle identifier suboption case
              if(atoi(suboptionValue)<0){
                failureMessage("Identifier rejected: the user identifier must be positive!");
                gCtxtStruct.errorNumber = 1;
              }
              //connect to the database and check if the user is identified or not
              informationMessage("Ottienimento informazioni non disponibile al momento");
              gCtxtStruct.errorNumber = 0;
              break;
          }
        }
        break;
      case 'd':
        gCtxtStruct.generalPurposeMask |= 1 << generalPurposeMaskBits_debug;
        gCtxtStruct.errorNumber = 0;
      case 'h':

        while ((flagArgs = getsubopt(&optarg,helpSuboptions,&suboptionValue)) != -1)
        {
          switch (flagArgs)
          {
            case helpFlagSuboptions_user:
              if (suboptionValue)
                for (unsigned char index = 0; index < sizeof helpSuboptions / sizeof *helpSuboptions; index++)
                  if (!strcmp(suboptionValue, helpSuboptions[index]))
                  {
                    char* const suboptionCopy = helpSuboptions[index];
                    *suboptionCopy -= 'z' + 'Z';//lowerCase = upperCase + 'z' - 'Z' , upperCase = lowerCase + 'Z' - 'z'
                    printf("Usage: %s -[u|-user=]%s=<user%s>\n",*argv,helpSuboptions[index],suboptionCopy);
                    printf("\t%s=<user%s> %s\n",helpSuboptions[index],suboptionCopy,userExplanation[index]);
                  }
              else
              {
                printf("Usage: %s [-u|--user=]name=<userName>,identifier=<userIdentifier>\n",*argv);
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
              }
              break;
            case helpFlagSuboptions_background:
              if (suboptionValue)
                for (unsigned char index = 0; index < sizeof backgroundSuboptions / sizeof *backgroundSuboptions; index++)
                  if (!strcmp(suboptionValue, backgroundSuboptions[index])) 
                  {
                    char* const suboptionCopy = backgroundSuboptions[index];
                    *suboptionCopy -= 'z' + 'Z';//lowerCase = upperCase + 'z' - 'Z' , upperCase = lowerCase + 'Z' - 'z'
                    printf("Usage: %s [-b|--background=]%s=<background%s>\n",*argv,backgroundSuboptions[index],suboptionCopy);
                    printf("\t%s=<background%s> %s\n",backgroundSuboptions[index],suboptionCopy,backgroundExplanation[index]);
                  }
              break;
            default:
              if (!suboptionValue)
                
              
              break;
          }
        }
        if (optarg) {
          if(!strcmp(optarg,"user")){
            printf("Usage: %s [-u|--user=]name=<userName>,identifier=<userIdentifier>\n",*argv);
            puts("Subflags:");
            puts("\tname=<userName> a string of max 40 characters that will be the user name at account login");
            puts("\tidentifier=<userIdentifier> a positive integer number that identifies the account login");
            puts("Description:");
            puts("\tIt searches in the videogame database for an account named with <userName> and identified by <userIdentifier>.");
            puts("\tif <userName> is empty, when the videogame boots, it will be display a form to input it; then the name must be not empty.");
            puts("\tif there is an another name in the database that is equal to <userName>, the form will require instead that you input the identifier of that account (that is not redondant).");
          }else if(!strcmp(optarg,"debug")){
            printf("Usage: %s [-d|--debug]\n",*argv);
            puts("Description:");
            puts("\tWhen the game boots, it is possible to see of the specific output messages on the terminal");
          }else if(!strcmp(optarg,"background")){
            puts("Aiuto background");
          }
        }
        gCtxtStruct.errorNumber = 0;
        break;
      default:
        if (optarg)
        {
          failureMessage("Invalid flag");
          gCtxtStruct.errorNumber = 1;
        }
        else
        {
          printf("Usage: %s [options]\nOptions:\n",*argv);
          for (unsigned char i = 0;i < sizeof helpSuboptions / sizeof *helpSuboptions; i++)
            printf("\t%s %s\n", helpSuboptions[i], helpExplanation[i]);
          for (unsigned char i = 0;i < sizeof helpSuboptions / sizeof *helpSuboptions; i++)
          {
            int processId=fork(),executionImage;
            char helpFlag[] = "--help=";
            switch (processId)
            {
              case -1:
                failureMessage(strerror(errno));
                gCtxtStruct.errorNumber = errno;
                break;
              case 0:
                executionImage = execl(*argv, *argv, strcat(helpFlag, helpSuboptions[i]), 0);
                if (executionImage == -1) {
                  failureMessage(strerror(errno));
                  gCtxtStruct.errorNumber = errno;
                }
                break;
            }
          }
        }
        break;
    }
  }
  return gCtxtStruct;
}