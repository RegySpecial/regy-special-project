/*
*@description Source code of the bit manipulation library
*@author Regy Special
*@date (First version [Linux/Parrot OS]) 2026 March 7th Saturday, 16:12:08
*@license GNU General Public License to stop private corporation to not share source code
*/
//set the bit on a specific position to 1 from right to left
template<typename numberType>
inline numberType setBit(numberType data,unsigned char bitPosition){
  return data|1<<bitPosition;
}
//clear the bit on a specific position to 0 from right to left
template<typename numberType>
inline numberType clearBit(numberType data,unsigned char bitPosition){
  return data&~(1<<bitPosition);
}
//toggle the bit from a specific position from right to left
template<typename numberType>
inline numberType toggleBit(numberType data,unsigned char bitPosition){
  return data^1<<bitPosition;
}
//read the bit from a specific position from right to left
template<typename numberType>
inline bool readBit(numberType data,unsigned char bitPosition){
  return data>>bitPosition&1;
}
