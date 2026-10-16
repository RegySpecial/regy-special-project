#ifndef setsHpp
#define setsHpp
/*
*@description Header file where is defined the dynamic array data structure class of the dynamic array data structure library
*@author Regy Special
*@date (First version [Linux/Parrot OS]) 2026 March 7th Saturday, 16:12:08
*@license GNU General Public License to stop private corporation to not share source code
*/
#include "dynamicArrays.hpp"
template
<
  typename itemsDataType,
  typename sizeDataType = unsigned long long,
  typename capacityDataType = unsigned long long
>
class set
:
public dynamicArray<itemsDataType, sizeDataType, capacityDataType>
{
  public:
    set() : dynamicArray<itemsDataType, sizeDataType, capacityDataType>::dynamicArray() {};
    set(capacityDataType capacity) : dynamicArray<itemsDataType, sizeDataType, capacityDataType>::dynamicArray(capacity) {};
    set(itemsDataType *items, capacityDataType capacity);
  
    set(sizeDataType size, capacityDataType capacity);
  
    set(itemsDataType *items, sizeDataType size, capacityDataType capacity);

    void insert(itemsDataType item, sizeDataType index);

    void remove(sizeDataType index);

    void push(itemsDataType item);
};
#endif