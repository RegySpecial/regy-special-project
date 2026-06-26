#ifndef dialogOrganizationH
#define dialogOrganizationH
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
#endif