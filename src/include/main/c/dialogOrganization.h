#ifndef dialogOrganizationH
#define dialogOrganizationH
/*
*@description C header file about the definition of the beep C function
*@author Regy Special
*@date 2026 June 15th Monday, 12:09:12
*@license GNU General Public License to stop private corporation to not share source code
*/
#if defined __cplusplus || defined c_plusplus
extern "C"{
#endif
  typedef enum{
    dialogViewType_ask,
    dialogViewType_root,
    dialogViewType_unroot
  }dialogViewType;
  typedef enum{
    dialogType_layoutMode,
    dialogType_play,
    dialogType_exit,
    dialogType_options,
    dialogType_moreInformation
  }dialogType;
  typedef enum{
    gameMode_simple,
    gameMode_intermediate,
    gameMode_advanced,
    gameMode_extreme,
    gameMode_customized
  }gameMode;
  typedef enum{
    dialogConfirm_OK,
    dialogConfirm_Cancel
  }dialogConfirm;
#if defined __cplusplus || defined c_plusplus
}
#endif
#endif