#ifndef generalPurposeMaskBitsH
#define generalPurposeMaskBitsH
/*
*@description C header file about the definition of the beep C function
*@author Regy Special
*@date 2026 June 15th Monday, 12:09:12
*@license GNU General Public License to stop private corporation to not share source code
*/
#if defined __cplusplus || defined c_plusplus
extern "C"
#endif
typedef enum{
  generalPurposeMaskBits_debug,
  generalPurposeMaskBits_eventLoop,
  generalPurposeMaskBits_dialogBindToWindow
}generalPurposeMaskBits;
#endif