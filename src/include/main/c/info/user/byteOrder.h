#ifndef byteOrderH
#define byteOrderH
#ifdef __LITTLE_ENDIAN__
#define byteOrder "Byte order: Little endian"
#elifdef __BIG_ENDIAN__
#define byteOrder "Byte order: Big Endian"
#else
#define byteOrder "Byte order: Unknown"
#endif
#endif