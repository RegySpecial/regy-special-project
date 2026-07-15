#ifndef byteOrderH
#define byteOrderH
/*
*@description C header file about the definition of the beep C function
*@author Regy Special
*@date 2026 June 15th Monday, 12:09:12
*@license GNU General Public License to stop private corporation to not share source code
*/
#ifdef __LITTLE_ENDIAN__
#define byteOrder "Byte order: Little endian"
#elifdef __BIG_ENDIAN__
#define byteOrder "Byte order: Big Endian"
#else
#define byteOrder "Byte order: Unknown"
#endif
#endif