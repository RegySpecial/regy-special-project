#ifndef dynamicArraysHpp
#define dynamicArraysHpp
/*
*@description Header file where is defined the dynamic array data structure class of the dynamic array data structure library
*@author Regy Special
*@date (First version [Linux/Parrot OS]) 2026 March 7th Saturday, 16:12:08
*@license GNU General Public License to stop private corporation to not share source code
*/
#include<iostream>
#include<stdlib.h>
#include"../../../c/console.h"
template
<
  typename itemsDataType,
  typename sizeDataType = unsigned long long,
  typename capacityDataType = unsigned long long
>
class dynamicArray{
public:
  itemsDataType *items = NULL;
  sizeDataType size = 0;
  capacityDataType capacity = 32;
  itemsDataType operator [] (sizeDataType index);

  inline itemsDataType at(sizeDataType index)
  {
    return this->items[index % this->size];
  }

  void insert(itemsDataType item, sizeDataType index);

  void remove(sizeDataType index);

  void push(itemsDataType item);

  inline void pop()
  {
    this->remove(this->size-1);
  }

  dynamicArray();
  dynamicArray(capacityDataType capacity);
  dynamicArray(itemsDataType *items, capacityDataType capacity);
  dynamicArray(sizeDataType size, capacityDataType capacity);
  dynamicArray(itemsDataType *items, sizeDataType size, capacityDataType capacity);

  void forEach(void(*forEachFunction)(itemsDataType));
  void forEach(void(*forEachFunction)(itemsDataType), sizeDataType size);
  void forEach(void(*forEachFunction)(itemsDataType), sizeDataType left, sizeDataType right);

  void forEach(void(*forEachFunction)(itemsDataType, sizeDataType));
  void forEach(void(*forEachFunction)(itemsDataType, sizeDataType), sizeDataType size);
  void forEach(void(*forEachFunction)(itemsDataType, sizeDataType), sizeDataType left, sizeDataType right);

  void forEach(void(*forEachFunction)(itemsDataType, sizeDataType, dynamicArray<itemsDataType, sizeDataType, capacityDataType> *));
  void forEach(void(*forEachFunction)(itemsDataType, sizeDataType, dynamicArray<itemsDataType, sizeDataType, capacityDataType> *), sizeDataType size);
  void forEach(void(*forEachFunction)(itemsDataType, sizeDataType, dynamicArray<itemsDataType, sizeDataType, capacityDataType> *), sizeDataType left, sizeDataType right);

  dynamicArray<itemsDataType, sizeDataType, capacityDataType>
  filter(bool(*filterFunction)(itemsDataType));
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  filter(bool(*filterFunction)(itemsDataType), sizeDataType size);
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  filter(bool(*filterFunction)(itemsDataType), sizeDataType left, sizeDataType right);

  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  filter(bool(*filterFunction)(itemsDataType,sizeDataType));
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  filter(bool(*filterFunction)(itemsDataType,sizeDataType), sizeDataType size);
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  filter(bool(*filterFunction)(itemsDataType,sizeDataType), sizeDataType left, sizeDataType right);

  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  filter(bool(*filterFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*));
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  filter(bool(*filterFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*), sizeDataType size);
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  filter(bool(*filterFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*), sizeDataType left, sizeDataType right);
  
  bool every(bool(*everyFunction)(itemsDataType));
  bool every(bool(*everyFunction)(itemsDataType), sizeDataType size);
  bool every(bool(*everyFunction)(itemsDataType), sizeDataType left, sizeDataType right);

  bool every(bool(*everyFunction)(itemsDataType,sizeDataType));
  bool every(bool(*everyFunction)(itemsDataType,sizeDataType), sizeDataType size);
  bool every(bool(*everyFunction)(itemsDataType,sizeDataType), sizeDataType left, sizeDataType right);
  
  bool every(bool(*everyFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*));
  bool every(bool(*everyFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*), sizeDataType size);
  bool every(bool(*everyFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*), sizeDataType left, sizeDataType right);

  bool some(bool(*someFunction)(itemsDataType));
  bool some(bool(*someFunction)(itemsDataType), sizeDataType size);
  bool some(bool(*someFunction)(itemsDataType), sizeDataType left, sizeDataType right);

  bool some(bool(*someFunction)(itemsDataType,sizeDataType));
  bool some(bool(*someFunction)(itemsDataType,sizeDataType), sizeDataType size);
  bool some(bool(*someFunction)(itemsDataType,sizeDataType), sizeDataType left, sizeDataType right);
  
  bool some(bool(*someFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*));
  bool some(bool(*someFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*), sizeDataType size);
  bool some(bool(*someFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*), sizeDataType left, sizeDataType right);

  bool xsome(bool(*xsomeFunction)(itemsDataType));
  bool xsome(bool(*xsomeFunction)(itemsDataType), sizeDataType size);
  bool xsome(bool(*xsomeFunction)(itemsDataType), sizeDataType left, sizeDataType right);

  bool xsome(bool(*xsomeFunction)(itemsDataType,sizeDataType));
  bool xsome(bool(*xsomeFunction)(itemsDataType,sizeDataType), sizeDataType size);
  bool xsome(bool(*xsomeFunction)(itemsDataType,sizeDataType), sizeDataType left, sizeDataType right);
  
  bool xsome(bool(*xsomeFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*));
  bool xsome(bool(*xsomeFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*), sizeDataType size);
  bool xsome(bool(*xsomeFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*), sizeDataType left, sizeDataType right);

  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  map(itemsDataType(*mapFunction)(itemsDataType));
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  map(itemsDataType(*mapFunction)(itemsDataType), sizeDataType size);
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  map(itemsDataType(*mapFunction)(itemsDataType), sizeDataType left, sizeDataType right);

  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  map(itemsDataType(*mapFunction)(itemsDataType,sizeDataType));
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  map(itemsDataType(*mapFunction)(itemsDataType,sizeDataType), sizeDataType size);
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  map(itemsDataType(*mapFunction)(itemsDataType,sizeDataType), sizeDataType left, sizeDataType right);

  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  map(itemsDataType(*mapFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*));
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  map(itemsDataType(*mapFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*), sizeDataType size);
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  map(itemsDataType(*mapFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*), sizeDataType left, sizeDataType right);

  template<typename accumulationValueDataType>
  accumulationValueDataType reduce(itemsDataType(*reduceFunction)(itemsDataType),accumulationValueDataType accumulationValue);
  template<typename accumulationValueDataType>
  accumulationValueDataType reduce(itemsDataType(*reduceFunction)(itemsDataType),accumulationValueDataType accumulationValue, sizeDataType size);
  template<typename accumulationValueDataType>
  accumulationValueDataType reduce(itemsDataType(*reduceFunction)(itemsDataType),accumulationValueDataType accumulationValue, sizeDataType left, sizeDataType right);

  template<typename accumulationValueDataType>
  accumulationValueDataType reduce(itemsDataType(*reduceFunction)(itemsDataType,sizeDataType),accumulationValueDataType accumulationValue);
  template<typename accumulationValueDataType>
  accumulationValueDataType reduce(itemsDataType(*reduceFunction)(itemsDataType,sizeDataType),accumulationValueDataType accumulationValue, sizeDataType size);
  template<typename accumulationValueDataType>
  accumulationValueDataType reduce(itemsDataType(*reduceFunction)(itemsDataType,sizeDataType),accumulationValueDataType accumulationValue, sizeDataType left, sizeDataType right);

  template<typename accumulationValueDataType>
  accumulationValueDataType reduce(itemsDataType(*reduceFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*),accumulationValueDataType accumulationValue);
  template<typename accumulationValueDataType>
  accumulationValueDataType reduce(itemsDataType(*reduceFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*),accumulationValueDataType accumulationValue, sizeDataType size);
  template<typename accumulationValueDataType>
  accumulationValueDataType reduce(itemsDataType(*reduceFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*),accumulationValueDataType accumulationValue, sizeDataType left, sizeDataType right);

  void sort(itemsDataType(*comparisonFunction)(itemsDataType,itemsDataType), sizeDataType left, sizeDataType right);
  inline void sort(itemsDataType(*comparisonFunction)(itemsDataType,itemsDataType), sizeDataType size){
    this->sort(comparisonFunction,0,size);
  }
  inline void sort(itemsDataType(*comparisonFunction)(itemsDataType,itemsDataType)){
    this->sort(comparisonFunction,this->size);
  }

  void reverse();
  void reverse(sizeDataType size);
  void reverse(sizeDataType left,sizeDataType right);
  void merge(dynamicArray<itemsDataType,sizeDataType,capacityDataType>*sourceDynamicArray);
  void merge(dynamicArray<itemsDataType,sizeDataType,capacityDataType>*sourceDynamicArray, sizeDataType size);
  void merge(dynamicArray<itemsDataType,sizeDataType,capacityDataType>*sourceDynamicArray, sizeDataType left, sizeDataType right);
  void copy(dynamicArray<itemsDataType,sizeDataType,capacityDataType>*sourceDynamicArray);
  void copy(dynamicArray<itemsDataType,sizeDataType,capacityDataType>*sourceDynamicArray, sizeDataType size);
  void copy(dynamicArray<itemsDataType,sizeDataType,capacityDataType>*sourceDynamicArray, sizeDataType left, sizeDataType right);

  void join(dynamicArray<itemsDataType,sizeDataType,capacityDataType>*sourceDynamicArray);
  void join(dynamicArray<itemsDataType,sizeDataType,capacityDataType>*sourceDynamicArray, sizeDataType size);
  void join(dynamicArray<itemsDataType,sizeDataType,capacityDataType>*sourceDynamicArray, sizeDataType left, sizeDataType right);

  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  intersect(dynamicArray<itemsDataType,sizeDataType,capacityDataType>*sourceDynamicArray);
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  intersect(dynamicArray<itemsDataType,sizeDataType,capacityDataType>*sourceDynamicArray, sizeDataType size);
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  intersect(dynamicArray<itemsDataType,sizeDataType,capacityDataType>*sourceDynamicArray, sizeDataType left, sizeDataType right);

  ~dynamicArray();
};
#endif