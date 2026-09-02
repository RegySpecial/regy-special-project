#ifndef manageArgumentsH
#define manageArgumentsH
/*
*@description C header file about the definition of the beep C function
*@author Regy Special
*@date 2026 June 15th Monday, 12:09:12
*@license GNU General Public License to stop private corporation to not share source code
*/
#include <getopt.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <assert.h>
#include <errno.h>
#include <regex.h>
#include <ctype.h>
#include "../../lib/c/audio/beep.h"
#include "../../lib/c/console.h"
#include "generalPurposeMaskBits.h"
#include "../../lib/c/colors.h"

#define colorFunctionsRegularExpression "\\s*((hsl|rgb)\\s*\\((\\s*[0-9]{1,3}\\s*\\,){2}\\s*[0-9]{1,3}\\s*\\)|((hsl|rgb)a|cymk)\\s*\\((\\s*[0-9]{1,3}\\s*\\,){3}\\s*[0-9]{1,3}\\s*\\)|cmyka\\s*\\((\\s*[0-9]{1,3}\\s*\\,){4}\\s*[0-9]{1,3}\\s*\\))\\s*"

#if defined __cplusplus || defined c_plusplus
extern "C"{
#endif
  typedef enum
  {
    argumentOptionFlag_help,
    argumentOptionFlag_user,
    argumentOptionFlag_background,
    argumentOptionFlag_audio,
    argumentOptionFlag_debug,
    argumentOptionFlag_0
  } argumentOptionFlag;

  typedef enum
  {
    argumentOptionFlagSuboptionsIndex_user,
    argumentOptionFlagSuboptionsIndex_background,
    argumentOptionFlagSuboptionsIndex_help
  } argumentOptionFlagSuboptionsIndex;
  
  typedef enum
  {
    argumentOptionUserFlagSuboptions_name,
    argumentOptionUserFlagSuboptions_identifier
  } argumentOptionUserFlagSuboptions;

  typedef enum
  {
    argumentOptionHelpFlagSuboptions_user,
    argumentOptionHelpFlagSuboptions_background,
    argumentOptionHelpFlagSuboptions_audio
  } argumentOptionHelpFlagSuboptions;

  typedef enum
  {
    argumentOptionBackgroundFlagSuboptions_color,
    argumentOptionBackgroundFlagSuboptions_pixelmap,
    argumentOptionBackgroundFlagSuboptions_path
  } argumentOptionBackgroundFlagSuboptions;

  typedef enum
  {
    argumentOptionAudioFlagSuboptions_path,
    argumentOptionAudioFlagSuboptions_beepmap,
    argumentOptionAudioFlagSuboptions_volume
  } argumentOptionAudioFlagSuboptions;

  typedef enum
  {
    exitStatus_success,
    exitStatus_userNameTooBig,
    exitStatus_userNameInvalidCode,
    exitStatus_userIdentifierSigned,
    exitStatus_userIdentifierUnsignedFloatingPoint,
    exitStatus_userIdentifierSignedFloatingPoint,
    exitStatus_userIdentifierNotANumber,
    exitStatus_userNotFound,
    exitStatus_invalidColorFunction,
    exitStatus_invalidColorNumber,
    exitStatus_pixelmapTooBig,
    exitStatus_backgroundFileNotFound,
    exitStatus_backgroundFileNotAllowed,
    exitStatus_audioFileNotFound,
    exitStatus_audioFileNotAllowed,
    exitStatus_invalidHelp,
    exitStatus_extraArgumentsNotAllowed,
    exitStatus_regularExpressionCompilationFailure,
    exitStatus_forkFailure,
    exitStatus_execFailure
  } exitStatus;

  typedef struct
  {
    char userName[41],
         userId[10],
         *backgroundPath;
    unsigned char generalPurposeMask,
                  exitStatus;
    unsigned long backgroundColor:24,
                  *backgroundPixelmap;
  } gameContextStructure;
  gameContextStructure manageHelpFlag(int argc, char *argv[]);
  gameContextStructure manageUserFlag(int argc, char *argv[]);
  gameContextStructure manageUserFlag(int argc, char *argv[]);
  gameContextStructure manageCommandLineArguments(int argc, char *argv[]);
#if defined __cplusplus || defined c_plusplus
}
#endif
#endif
