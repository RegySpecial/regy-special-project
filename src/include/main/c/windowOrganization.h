#ifndef windowOrganizationH
#define windowOrganizationH
/*
*@description C header file about the definition of the beep C function
*@author Regy Special
*@date 2026 June 15th Monday, 12:09:12
*@license GNU General Public License to stop private corporation to not share source code
*/
#if defined __WIN32||defined __WIN64
typedef enum{
  MainWindow_MainWindow,
  MainWindow_UsernameTextView,
  MainWindow_PlayButton,
  MainWindow_ExitButton,
  MainWindow_OptionsButton,
  MainWindow_MoreInformationButton
}MainWindowElementId;
typedef enum{
  PlayDialog_Title,
  PlayDialog_EasyDifficultyButton,
  PlayDialog_IntermediateDifficultyButton,
  PlayDialog_AdvancedDifficultyButton,
  PlayDialog_ExtremeDifficultyButton,
  PlayDialog_DifficultyExplaination,
  PlayDialog_ConfirmButton,
  PlayDialog_DoNotConfirmButton
}PlayDialogElementId;
typedef enum{
  OptionsDialog_Title,
  OptionsDialog_EasyDifficultyButton,
  OptionsDialog_IntermediateDifficultyButton,
  OptionsDialog_AdvancedDifficultyButton,
  OptionsDialog_ExtremeDifficultyButton,
  OptionsDialog_DifficultyExplaination,
  OptionsDialog_ConfirmButton,
  OptionsDialog_DoNotConfirmButton
}OptionsDialogElementId;
#else
typedef enum{
  windowIdentifier_mainWindow,
  
}windowIdentifier;
#endif
typedef enum{
  windowMode_main,
  windowMode_user,
  windowMode_scene
}windowType;
#endif