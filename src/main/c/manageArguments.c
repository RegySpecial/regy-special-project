/*
*@description Header file where is defined the dynamic array data structure class of the dynamic array data structure library
*@author Regy Special
*@date (First version [Linux/Parrot OS]) 2026 March 7th Saturday, 16:12:08
*@license GNU General Public License to stop private corporation to not share source code
*/
#include "../../include/main/c/manageArguments.h"

gameContextStructure manageUserFlag(int argc, char *argv[])
{
  gameContextStructure gCtxtStruct = {
    .exitStatus = 0,
    .backgroundColor = 0,
    .userName = "",
    .userId = ""
  };

  int flagArgs = 0;

  char *const userSuboptions[] = {
    "name",
    "idenitifier"
  };

  const char *userExplanation[] = {
    "a string of max 40 characters that will be the user name at account login",
    "a positive integer number that identifies the account login"
  };
  
  char *suboptionValue;

  while ((flagArgs = getsubopt(&optarg,userSuboptions,&suboptionValue)) != -1)
  {
    switch (flagArgs)
    {
      case argumentOptionUserFlagSuboptions_name:
        for (unsigned char i = 0; suboptionValue[i]; i++)
          if (!isprint(suboptionValue[i]))
          {
            gCtxtStruct.exitStatus = exitStatus_userNameInvalidCode;
            failureMessage("Invalide characted code in the user name");
            return gCtxtStruct;
          }
        
        strlen(suboptionValue) > 40
        ? failureMessage("Name rejected: the user name character number must lower than or equal to 40 characters!")
        : informationMessage("Ottienimento informazioni non disponibile al momento");

        gCtxtStruct.exitStatus = strlen(suboptionValue) > 40;
        break;
      case argumentOptionUserFlagSuboptions_identifier:
        regex_t regularExpression;

        int regularExpressionCompilation = regcomp(&regularExpression, "^[0-9]$", REG_EXTENDED),
            regularExpressionExecution;
        
        if (regularExpressionCompilation)
        {
          gCtxtStruct.exitStatus = exitStatus_regularExpressionCompilationFailure;
          failureMessage("Could not compile the following regular expression: /^\\d$/");
          return gCtxtStruct;
        }

        if ((regularExpressionExecution = regexec(&regularExpression, suboptionValue, 0, NULL, REG_EXTENDED)))
        {
          regfree(&regularExpression);
          for (unsigned char i = *suboptionValue == '-'; suboptionValue[i]; i++)
          {
            if (*suboptionValue == '-')
              if ('0' <= suboptionValue[i] && suboptionValue[i] <= '9')
              {
                if (strchr(suboptionValue, '.'))
                {
                  gCtxtStruct.exitStatus = exitStatus_userIdentifierSignedFloatingPoint;
                  failureMessage("User indentifier cannot be a negative floating point number!");
                  return gCtxtStruct;
                }
                gCtxtStruct.exitStatus = exitStatus_userIdentifierSigned;
                failureMessage("User indentifier cannot be a negative number!");
                return gCtxtStruct;
              }
            if ('0' <= suboptionValue[i] && suboptionValue[i] <= '9')
            {
              if (strchr(suboptionValue, '.'))
              {
                gCtxtStruct.exitStatus = exitStatus_userIdentifierUnsignedFloatingPoint;
                failureMessage("User indentifier cannot be a positive floating point number!");
                return gCtxtStruct;
              }
              gCtxtStruct.exitStatus = exitStatus_userIdentifierNotANumber;
              failureMessage("User identifier is not a number!");
              return gCtxtStruct;
            }
            gCtxtStruct.exitStatus = exitStatus_userIdentifierNotANumber;
            failureMessage("User identifier is not a number!");
            return gCtxtStruct;
          }
          return gCtxtStruct;
        }
        regfree(&regularExpression);
        break;
    }
  }
  return gCtxtStruct;
}

gameContextStructure manageHelpFlag(int argc, char *argv[])
{

  gameContextStructure gCtxtStruct = {
    .exitStatus = 0,
    .backgroundColor = 0,
    .userName = "",
    .userId = ""
  };

  int flagArgs = 0;

  char
    *const helpSuboptions[] = {
      "user",
      "debug",
      "background",
      "audio"
    },
    *const userSuboptions[] = {
      "name",
      "idenitifier"
    },
    *const backgroundSuboptions [] = {
      "color",
      "pixelmap",
      "path"
    },
    *const audioSuboptions [] = {
      "path",
      "beepmap",
      "volume"
    },
    *suboptionValue;

  const char
    *const trueHelp[] = {
      "-user [name=<userName>][,identifier=<userIdentifier>]",
      "-debug [assertions=[0|1]][,shell=[0|1]]",
      "-background [color=<backgroundColor>][,pixelmap=<backgroundPixelmap>][,path=<backgroundPath>]",
      "-audio [path=<audioPath>][,beepmap=<audioBeepmap>][,volume=<audioVolume>]"
    },
    *userExplanation[] = {
      "a string of max 40 characters that will be the user name at account login",
      "a positive integer number that identifies the account login"
    },
    *backgroundExplanation[] = {
      "the color of the main screen videogame background in RGB format",
      "the pixelmap of the main screen videogame background in RGB format",
      "the path of the main screen videogame background in RGB format"
    },
    *helpExplanation[] = {
      "login in the videogame through <userName> and <userIdentifier>",
      "display debug informations",
      "set the background of the videogame main screen in the following order (<backgroundColor>,<backgroundPixelmap>,<backgroundPath>)",
      "set the audio of the videogame main music in the following order (<audioPath>,<audioBeepmap>) at volume <audioVolume>"
    };

  while ((flagArgs = getsubopt(&optarg, helpSuboptions, &suboptionValue)) != -1)
  {
    switch (flagArgs)
    {
      case argumentOptionHelpFlagSuboptions_user:
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
      case argumentOptionHelpFlagSuboptions_background:
        if (suboptionValue)
          for (unsigned char index = 0; index < sizeof backgroundSuboptions / sizeof *backgroundSuboptions; index++)
            if (!strcmp(suboptionValue, backgroundSuboptions[index])) 
            {
              char* const suboptionCopy = backgroundSuboptions[index];
              *suboptionCopy -= 'z' + 'Z';//lowerCase = upperCase + 'z' - 'Z' , upperCase = lowerCase + 'Z' - 'z'
              printf("Usage: %s [-b|--background=]%s=<background%s>\n",*argv,backgroundSuboptions[index],suboptionCopy);
              printf("\t%s=<background%s> %s\n",backgroundSuboptions[index],suboptionCopy,backgroundExplanation[index]);
            }
            else
            {
              printf("Usage: %s [-b|--background=]name=<userName>,identifier=<userIdentifier>\n",*argv);
              puts("Subflags:");
              for (unsigned char index = 0; index < sizeof helpSuboptions / sizeof *helpSuboptions; index++){
                char* const suboptionCopy = backgroundSuboptions[index];
                            *suboptionCopy-='z'+'Z';//lowerCase = upperCase + 'z' - 'Z' , upperCase = lowerCase + 'Z' - 'z'
                printf("\t%s=<user%s> %s\n",helpSuboptions[index],suboptionCopy,helpExplanation[index]);
              }
              puts("Description:");
              puts("\tIt searches in the videogame database for an account named with <userName> and identified by <userIdentifier>.");
              puts("\tif <userName> is empty, when the videogame boots, it will be display a form to input it; then the name must be not empty.");
              puts("\tif there is an another name in the database that is equal to <userName>, the form will require instead that you input the identifier of that account (that is not redondant).");
            }
        break;
      default:
        if (!suboptionValue)
        {
          printf("Usage: %s [options]\nOptions:\n", *argv);
          for (unsigned char i = 0; i < sizeof helpSuboptions / sizeof *helpSuboptions; i++)
            printf("\t%s %s\n", helpSuboptions[i], helpExplanation[i]);
          gCtxtStruct.exitStatus = exitStatus_success;
        }
        break;
    }
  }
  return gCtxtStruct;
}

gameContextStructure manageDebugFlag(int argc, char *argv[])
{
  gameContextStructure gCtxtStruct = {
    .exitStatus = 0,
    .backgroundColor = 0,
    .userName = "",
    .userId = ""
  };

  int flagArgs = 0;

  char *const debugSuboptions[] = {
    "assert",
    "shell"
  },
  *suboptionValue;

  while ((flagArgs = getsubopt(&optarg, debugSuboptions, &suboptionValue)) != -1)
  {
    gCtxtStruct.generalPurposeMask |= 1 << generalPurposeMaskBits_debug;
    gCtxtStruct.exitStatus = exitStatus_success;
  }

  return gCtxtStruct;
}

gameContextStructure manageBackgroundFlag(int argc, char *argv[])
{
  gameContextStructure gCtxtStruct = {
    .exitStatus = 0,
    .backgroundColor = 0,
    .userName = "",
    .userId = ""
  };

  int flagArgs = 0;

  char *const backgroundSuboptions [] = {
    "color",
    "pixelmap",
    "path"
  },
  *suboptionValue;

  while((flagArgs = getsubopt(&optarg, backgroundSuboptions, &suboptionValue)) != -1)
  {
    switch (flagArgs)
    {
      case argumentOptionBackgroundFlagSuboptions_color:
        regex_t regularExpression;
        regmatch_t occurrency;
        int regularExpressionCompilation,
            regularExpressionExecution;
        assert(!(regularExpressionCompilation = regcomp(&regularExpression, colorFunctionsRegularExpression, REG_ICASE | REG_EXTENDED)));
        if (!(regularExpressionExecution = regexec(&regularExpression, suboptionValue, 1, &occurrency, REG_ICASE | REG_EXTENDED)))
        {
          unsigned char functionIndex = 0;
          char colorFuntionString[5 + 1 + 4 * (3 + 1) + 1] = {};
          for (unsigned long suboptionValueIndex = 0; suboptionValueIndex < suboptionValue[suboptionValueIndex]; suboptionValueIndex++)
            if (!isspace(suboptionValue[suboptionValueIndex]))
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
          else if (!strcmp(colorFuntionString,"rgb"))
          {
            rgb RGB={};
            for (char* paramGet = strtok(colorFuntionString + 4, ","), index = 0; paramGet; paramGet = strtok(NULL, ","), index++)
              ((unsigned char*) &RGB)[index] = atoi(paramGet);
            gCtxtStruct.backgroundColor = RGB.red << 16 | RGB.green << 8 | RGB.blue;
          }
          else if (!strcmp(colorFuntionString,"rgba"))
          {
            rgba RGBA={};
            for (char* paramGet = strtok(colorFuntionString + 5, ","), index = 0; paramGet; paramGet = strtok(NULL, ","), index++)
              ((unsigned char*) &RGBA)[index] = atoi(paramGet);
            gCtxtStruct.backgroundColor = RGBA.red << 16 | RGBA.green << 8 | RGBA.blue;
          }
          else if (!strcmp(colorFuntionString,"cmyk"))
          {
            cmyk CMYK={};
            for (char* paramGet = strtok(colorFuntionString + 5, ","), index = 0; paramGet; paramGet = strtok(NULL, ","), index++)
              ((unsigned char*) &CMYK)[index] = atoi(paramGet);
            
            rgb trueColor = cmykToRgb(CMYK);
            gCtxtStruct.backgroundColor = trueColor.red << 16 | trueColor.green << 8 | trueColor.blue;
          }
          else if (!strcmp(colorFuntionString,"cmyka"))
          {
            cmyka CMYKA={};
            for (char* paramGet = strtok(colorFuntionString + 5, ","), index = 0; paramGet; paramGet = strtok(NULL, ","), index++)
              ((unsigned char*) &CMYKA)[index] = atoi(paramGet);
            
            rgba trueColor = cmykaToRgba(CMYKA);
            gCtxtStruct.backgroundColor = trueColor.red << 16 | trueColor.green << 8 | trueColor.blue;
          }
          else
          {
            failureMessage("Invalid color function or color code");
            gCtxtStruct.exitStatus = 1;
          }
        }
        gCtxtStruct.exitStatus = regularExpressionExecution;
        regfree(&regularExpression);
        break;
      case argumentOptionBackgroundFlagSuboptions_pixelmap:
        informationMessage("Ottienimento informazioni non disponibile al momento");
        gCtxtStruct.exitStatus = 0;
        break;
      case argumentOptionBackgroundFlagSuboptions_path:
        informationMessage("Ottienimento informazioni non disponibile al momento");
        gCtxtStruct.exitStatus = 0;
        break;
    }
  }

  return gCtxtStruct;
}

gameContextStructure manageAudioFlag(int argc, char *argv[])
{
  gameContextStructure gCtxtStruct = {
    .exitStatus = 0,
    .backgroundColor = 0,
    .userName = "",
    .userId = ""
  };

  int flagArgs = 0;

  char *const audioSuboptions [] = {
    "path",
    "beepmap",
    "volume"
  },
  *suboptionValue;

  while((flagArgs = getsubopt(&optarg, audioSuboptions, &suboptionValue)) != -1)
  {
    switch (flagArgs)
    {
      case argumentOptionAudioFlagSuboptions_path:
        break;
      case argumentOptionAudioFlagSuboptions_beepmap:
        break;
      case argumentOptionAudioFlagSuboptions_volume:
        break;
    }
  }

  return gCtxtStruct;
}

gameContextStructure manageCommandLineArguments(int argc, char *argv[])
{
  gameContextStructure gCtxtStruct = {
    .exitStatus = 0,
    .backgroundColor = 0,
    .userName = "",
    .userId = ""
  };

  int flag,flagArgs;
  
  const struct option options[]={
    {"help",optional_argument,NULL,argumentOptionFlag_help},
    {"user",required_argument,NULL,argumentOptionFlag_user},
    {"background",required_argument,NULL,argumentOptionFlag_background},
    {"audio",required_argument,NULL,argumentOptionFlag_audio},
    {"debug",no_argument,NULL,argumentOptionFlag_debug},
    {NULL,no_argument,NULL,argumentOptionFlag_0}
  };
  
  char
    *const userSuboptions[] = {
      "name",
      "idenitifier"
    },
    *const backgroundSuboptions [] = {
      "color",
      "pixelmap",
      "path"
    },
    *const helpSuboptions[] = {
      "user",
      "debug",
      "background"
    },
    *suboptionValue;
  
  const char
    *userExplanation[] = {
      "a string of max 40 characters that will be the user name at account login",
      "a positive integer number that identifies the account login"
    },
    *backgroundExplanation[] = {
      "the color of the main screen videogame background in RGB format",
      "the pixelmap of the main screen videogame background in RGB format",
      "the path of the main screen videogame background in RGB format"
    },
    *helpExplanation[] = {
      "login in the videogame through <userName> and <userIdentifier>",
      "display debug informations",
      "set the background of the videogame main screen in the following order (<backgroundColor>,<backgroundPixelmap>,<backgroundPath>)"
    };

  if (argc == 1)
    for (unsigned char i = 0; i < 3; i++)
    {
      int cloneId = fork(),
          executionImage = -1;
      
      switch (cloneId)
      {
        case -1:
          gCtxtStruct.exitStatus = exitStatus_forkFailure;
          failureMessage("Failed to execute fork() system call: fork return = -1");
          return gCtxtStruct;
          break;
        
        case 0:
          executionImage = execl(*argv, *argv, "-help", 0);
          if (executionImage == -1)
          {
            gCtxtStruct.exitStatus = exitStatus_forkFailure;
            failureMessage("Failed to execute execl(*argv, *argv, \"-help\", 0) system call: execl return = -1");
            return gCtxtStruct;
          }
          break;
      }

      wait(NULL);
    }
  
  while ((flag = getopt_long_only(argc, argv, "h::u:b:a:d", options, NULL)) != -1)
  {
    gameContextStructure (*argumentManagementFunction[])(int, char**) = {manageHelpFlag,manageUserFlag,manageBackgroundFlag,manageAudioFlag,manageDebugFlag};
    gCtxtStruct = argumentManagementFunction[flag](argc, argv);
    switch (flag)
    {
      case 'u':
        gCtxtStruct = manageHelpFlag(argc,argv);
        break;
      case 'b':
        while ((flagArgs = getsubopt(&optarg,backgroundSuboptions,&suboptionValue)) != -1)
        {
          switch (flagArgs)
          {
            case argumentOptionBackgroundFlagSuboptions_color:
              regex_t regularExpression;
              regmatch_t occurrency;
              int regularExpressionCompilation,
                  regularExpressionExecution;
              assert(!(regularExpressionCompilation = regcomp(&regularExpression, colorFunctionsRegularExpression, REG_ICASE | REG_EXTENDED)));
              if (!(regularExpressionExecution = regexec(&regularExpression, suboptionValue, 1, &occurrency, REG_ICASE | REG_EXTENDED)))
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
                else if (!strcmp(colorFuntionString,"rgb"))
                {
                  rgb RGB={};
                  for (char* paramGet = strtok(colorFuntionString + 4, ","), index = 0; paramGet; paramGet = strtok(NULL, ","), index++)
                    ((unsigned char*) &RGB)[index] = atoi(paramGet);
                  gCtxtStruct.backgroundColor = RGB.red << 16 | RGB.green << 8 | RGB.blue;
                }
                else if (!strcmp(colorFuntionString,"rgba"))
                {
                  rgba RGBA={};
                  for (char* paramGet = strtok(colorFuntionString + 5, ","), index = 0; paramGet; paramGet = strtok(NULL, ","), index++)
                    ((unsigned char*) &RGBA)[index] = atoi(paramGet);
                  gCtxtStruct.backgroundColor = RGBA.red << 16 | RGBA.green << 8 | RGBA.blue;
                }
                else if (!strcmp(colorFuntionString,"cmyk"))
                {
                  cmyk CMYK={};
                  for (char* paramGet = strtok(colorFuntionString + 5, ","), index = 0; paramGet; paramGet = strtok(NULL, ","), index++)
                    ((unsigned char*) &CMYK)[index] = atoi(paramGet);
                  
                  rgb trueColor = cmykToRgb(CMYK);
                  gCtxtStruct.backgroundColor = trueColor.red << 16 | trueColor.green << 8 | trueColor.blue;
                }
                else if (!strcmp(colorFuntionString,"cmyka"))
                {
                  cmyka CMYKA={};
                  for (char* paramGet = strtok(colorFuntionString + 5, ","), index = 0; paramGet; paramGet = strtok(NULL, ","), index++)
                    ((unsigned char*) &CMYKA)[index] = atoi(paramGet);
                  
                  rgba trueColor = cmykaToRgba(CMYKA);
                  gCtxtStruct.backgroundColor = trueColor.red << 16 | trueColor.green << 8 | trueColor.blue;
                }
                else
                {
                  failureMessage("Invalid color function or color code");
                  gCtxtStruct.exitStatus = 1;
                }
              }
              gCtxtStruct.exitStatus = regularExpressionExecution;
              regfree(&regularExpression);
              break;
            case argumentOptionBackgroundFlagSuboptions_pixelmap:
              informationMessage("Ottienimento informazioni non disponibile al momento");
              gCtxtStruct.exitStatus = 0;
              break;
            case argumentOptionBackgroundFlagSuboptions_path:
              informationMessage("Ottienimento informazioni non disponibile al momento");
              gCtxtStruct.exitStatus = 0;
              break;
          }
        }
        break;
      case 'd':
        gCtxtStruct.generalPurposeMask |= 1 << generalPurposeMaskBits_debug;
        gCtxtStruct.exitStatus = 0;
      case 'h':
        while ((flagArgs = getsubopt(&optarg,helpSuboptions,&suboptionValue)) != -1)
        {
          switch (flagArgs)
          {
            case argumentOptionHelpFlagSuboptions_user:
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
            case argumentOptionHelpFlagSuboptions_background:
              if (suboptionValue)
                for (unsigned char index = 0; index < sizeof backgroundSuboptions / sizeof *backgroundSuboptions; index++)
                  if (!strcmp(suboptionValue, backgroundSuboptions[index])) 
                  {
                    char* const suboptionCopy = backgroundSuboptions[index];
                    *suboptionCopy -= 'z' + 'Z';//lowerCase = upperCase + 'z' - 'Z' , upperCase = lowerCase + 'Z' - 'z'
                    printf("Usage: %s [-b|--background=]%s=<background%s>\n",*argv,backgroundSuboptions[index],suboptionCopy);
                    printf("\t%s=<background%s> %s\n",backgroundSuboptions[index],suboptionCopy,backgroundExplanation[index]);
                  }
                  else
                  {
                    printf("Usage: %s [-b|--background=]name=<userName>,identifier=<userIdentifier>\n",*argv);
                    puts("Subflags:");
                    for (unsigned char index = 0; index < sizeof helpSuboptions / sizeof *helpSuboptions; index++){
                      char* const suboptionCopy = backgroundSuboptions[index];
                                  *suboptionCopy-='z'+'Z';//lowerCase = upperCase + 'z' - 'Z' , upperCase = lowerCase + 'Z' - 'z'
                      printf("\t%s=<user%s> %s\n",helpSuboptions[index],suboptionCopy,helpExplanation[index]);
                    }
                    puts("Description:");
                    puts("\tIt searches in the videogame database for an account named with <userName> and identified by <userIdentifier>.");
                    puts("\tif <userName> is empty, when the videogame boots, it will be display a form to input it; then the name must be not empty.");
                    puts("\tif there is an another name in the database that is equal to <userName>, the form will require instead that you input the identifier of that account (that is not redondant).");
                  }
              break;
            default:
              if (!suboptionValue)
                printf("Usage: %s [options]\nOptions:\n",*argv);
                for (unsigned char i = 0;i < sizeof helpSuboptions / sizeof *helpSuboptions; i++)
                  printf("\t%s %s\n", helpSuboptions[i], helpExplanation[i]);
                for (unsigned char i = 0;i < sizeof helpSuboptions / sizeof *helpSuboptions; i++)
                {
                  int processId = fork(),
                      executionImage = 0,
                      waitId;
                  char helpFlag[] = "--help=";
                  switch (processId)
                  {
                    case -1:
                      failureMessage(strerror(errno));
                      gCtxtStruct.exitStatus = errno;
                      break;
                    case 0:
                      executionImage = execl(*argv, *argv, strcat(helpFlag, helpSuboptions[i]), 0);
                      if (executionImage == -1) {
                        failureMessage(strerror(errno));
                        gCtxtStruct.exitStatus = errno;
                      }
                      break;
                    default:
                      waitId = waitpid(processId, NULL, 0);
                      if (waitId == -1) {
                        failureMessage(strerror(errno));
                        gCtxtStruct.exitStatus = errno;
                      }
                      break;
                  }
                  wait(NULL);
                }
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
        gCtxtStruct.exitStatus = 0;
        break;
      default:
        if (optarg)
        {
          failureMessage("Invalid flag");
          gCtxtStruct.exitStatus = 1;
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
                gCtxtStruct.exitStatus = errno;
                break;
              case 0:
                executionImage = execl(*argv, *argv, strcat(helpFlag, helpSuboptions[i]), 0);
                if (executionImage == -1) {
                  failureMessage(strerror(errno));
                  gCtxtStruct.exitStatus = errno;
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