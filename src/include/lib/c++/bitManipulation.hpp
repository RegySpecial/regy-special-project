#ifndef bitManipulationHpp
#define bitManipulationHpp
/*
*@description Header file where are defined the functions of the bit manipulation library
*@author Regy Special
*@date (First version [Linux/Parrot OS]) 2026 March 7th Saturday, 16:12:08
*@license GNU General Public License to stop private corporation to not share source code
*/

//set the bit on a specific position to 1 from right to left
template <typename numberType>
inline numberType setBit(numberType data,unsigned char bitPosition)
{
  return data | 1 << bitPosition;
}

//clear the bit on a specific position to 0 from right to left
template <typename numberType>
inline numberType clearBit(numberType data,unsigned char bitPosition)
{
  return data & ~(1 << bitPosition);
}

//toggle the bit from a specific position from right to left
template <typename numberType>
inline numberType toggleBit(numberType data,unsigned char bitPosition)
{
  return data ^ 1 << bitPosition;
}

//read the bit from a specific position from right to left
template <typename numberType>
inline bool readBit(numberType data,unsigned char bitPosition)
{
  return data >> bitPosition & 1;
}

template <typename firstNumberType, typename secondNumberType>
firstNumberType bitSizedAddition(firstNumberType firstData, secondNumberType secondData, unsigned char size)
{
  firstNumberType temporaryBitMask = firstData + secondData;
  for (unsigned char bitPosition = 0; bitPosition < size && size < sizeof firstData; bitPosition++)
    firstData |= readBit<firstData>(firstData, bitPosition);
  return firstData;
}

template <typename firstNumberType, typename secondNumberType>
firstNumberType bitRangedAddition(firstNumberType firstData, secondNumberType secondData, unsigned char right, unsigned char left)
{
  firstNumberType temporaryBitMask = firstData + (secondData << left);
  for (unsigned char bitPosition = left; bitPosition < right && right < sizeof firstData; bitPosition++)
    firstData |= readBit<firstData>(firstData, bitPosition);
  return firstData;
}

template <typename firstNumberType, typename secondNumberType>
firstNumberType bitSizedSubtraction(firstNumberType firstData, secondNumberType secondData, unsigned char size)
{
  firstNumberType temporaryBitMask = firstData - secondData;
  for (unsigned char bitPosition = 0; bitPosition < size && size < sizeof firstData; bitPosition++)
    firstData |= readBit<firstData>(firstData, bitPosition);
  return firstData;
}

template <typename firstNumberType, typename secondNumberType>
firstNumberType bitRangedSubtraction(firstNumberType firstData, secondNumberType secondData, unsigned char right, unsigned char left)
{
  firstNumberType temporaryBitMask = firstData - (secondData << left);
  for (unsigned char bitPosition = left; bitPosition < right && right < sizeof firstData; bitPosition++)
    firstData |= readBit<firstData>(firstData, bitPosition);
  return firstData;
}

template <typename firstNumberType, typename secondNumberType>
firstNumberType bitSizedMoltiplication(firstNumberType firstData, secondNumberType secondData, unsigned char size)
{
  firstNumberType temporaryBitMask = firstData * secondData;
  for (unsigned char bitPosition = 0; bitPosition < size && size < sizeof firstData; bitPosition++)
    firstData |= readBit<firstData>(firstData, bitPosition);
  return firstData;
}

template <typename firstNumberType, typename secondNumberType>
firstNumberType bitRangedMoltiplication(firstNumberType firstData, secondNumberType secondData, unsigned char right, unsigned char left)
{
  firstNumberType temporaryBitMask = firstData * (secondData << left);
  for (unsigned char bitPosition = left; bitPosition < right && right < sizeof firstData; bitPosition++)
    firstData |= readBit<firstData>(firstData, bitPosition);
  return firstData;
}

template <typename coso>
class a
{
public:
  using typeDefinition = a<coso> *;
  void fuck()
  {
    puts("Fuck!");
  }
};
#endif