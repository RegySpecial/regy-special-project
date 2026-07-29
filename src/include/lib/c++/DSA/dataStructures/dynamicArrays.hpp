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
template<
  typename itemsDataType,
  typename sizeDataType=unsigned long,
  typename capacityDataType=unsigned long
>
class dynamicArray{
public:
  itemsDataType*items = NULL;
  sizeDataType size = 0;
  capacityDataType capacity = 32;
  itemsDataType operator[](sizeDataType index){
    if(0<=index&&index<=this->capacity)return this->items[index];
    else failureMessage("Index out of range\n");
  }
  inline itemsDataType at(sizeDataType index){
    return this->items[index%this->size];
  }
  void insert(itemsDataType item,sizeDataType index){
    if (index >= this->size)
      failureMessage("Index out of range");
    else {
      if (this->size == this->capacity) {
        this->capacity *= 2;
        this->items = (itemsDataType*) realloc(this->items,this->capacity*sizeof(itemsDataType));
        if (this->items)
          for (sizeDataType i = this->size + 1;i < this->capacity;i++)
            this->items[i] = 0;
        else {
          itemsDataType *oldItems = this->items;
          this->items = (itemsDataType*) calloc(this->capacity,sizeof(itemsDataType));
          if (!this->items) {
            failureMessage("Failed to reallocate memory for the dynamic array");
            return;
          }
          free(oldItems);
          oldItems = NULL;
        }
      }
      for (sizeDataType i = this->size;i > index;i--)
        this->items[i] = this->items[i - 1];
      this->items[index] = item;
      this->size += 1;
    }
  }
  void remove(sizeDataType index){
    if ( index < this->size) {
      for (;index < this->size;index++)
        this->items[index] = this->items[index + 1];
      this->size -= 1;
    }
  }
  void push(itemsDataType item){
    if (this->size == this->capacity) {
      this->capacity *= 2;
      this->items = (itemsDataType*) realloc(this->items,this->capacity*sizeof(itemsDataType));
      if (this->items)
        for (sizeDataType i = this->size + 1;i < this->capacity;i++)
          this->items[i] = 0;
      else {
        itemsDataType *oldItems = this->items;
        this->items = (itemsDataType*) calloc(this->capacity,sizeof(itemsDataType));
        if (!this->items) {
          failureMessage("Failed to reallocate memory for the dynamic array");
          return;
        }
        free(oldItems);
        oldItems = NULL;
      }
    }
    this->items[this->size] = item;
    this->size += 1;
  }
  inline void pop(){
    this->remove(this->size-1);
  }
  dynamicArray(){
    this->items = (itemsDataType*) calloc(this->capacity,sizeof(itemsDataType));
    if (!this->items) {
      failureMessage("Failed to reallocate memory for the dynamic array");
      return;
    }
  }
  dynamicArray(capacityDataType capacity){
    this->capacity = capacity;
    this->items = (itemsDataType*) calloc(this->capacity,sizeof(itemsDataType));
    if (!this->items) {
      failureMessage("Failed to reallocate memory for the dynamic array");
      return;
    }
  }
  dynamicArray(itemsDataType*items,capacityDataType capacity){
    this->size = (this->capacity=capacity);
    this->items = (itemsDataType*)calloc(this->capacity,sizeof(itemsDataType));
    if (!this->items) {
      failureMessage("Failed to reallocate memory for the dynamic array");
      return;
    }
    for (sizeDataType index=0;index < this->size;index++)
      this->items[index]=items[index];
  }
  dynamicArray(sizeDataType size,capacityDataType capacity){
    this->size = size;
    this->capacity = capacity;
    this->items = (itemsDataType*) calloc(this->capacity,sizeof(itemsDataType));
    if (!this->items) {
      failureMessage("Failed to reallocate memory for the dynamic array");
      return;
    }
  }
  dynamicArray(itemsDataType*items,sizeDataType size,capacityDataType capacity){
    this->capacity = capacity;
    this->size = size;
    this->items = (itemsDataType*) calloc(this->capacity,sizeof(itemsDataType));
    if (!this->items) {
      failureMessage("Failed to reallocate memory for the dynamic array");
      return;
    }
    for (sizeDataType index = 0;index < this->size;index++)
      this->items[index] = items[index];
  }

  //void(*forEachFunction)(itemsDataType)
  void forEach(void(*forEachFunction)(itemsDataType)){
    for (sizeDataType index = 0;index < this->size;index++)
      forEachFunction(this->items[index]);
  }
  void forEach(void(*forEachFunction)(itemsDataType),sizeDataType size){
    for (sizeDataType index = 0;index < size && size <= this->size;index++)
      forEachFunction(this->items[index]);
  }
  void forEach(void(*forEachFunction)(itemsDataType),sizeDataType left,sizeDataType right){
    for (;0 <= left && left < right && right <= this->size;left++)
      forEachFunction(this->items[left]);
  }

  //void(*forEachFunction)(itemsDataType,sizeDataType)
  void forEach(void(*forEachFunction)(itemsDataType,sizeDataType)){
    for (sizeDataType index = 0;index < this->size;index++)
      forEachFunction(this->items[index],index);
  }
  void forEach(void(*forEachFunction)(itemsDataType,sizeDataType),sizeDataType size){
    for (sizeDataType index = 0;index < size && size <= this->size;index++)
      forEachFunction(this->items[index],index);
  }
  void forEach(void(*forEachFunction)(itemsDataType,sizeDataType),sizeDataType left,sizeDataType right){
    for (;0 <= left && left < right && right <= this->size;left++)
      forEachFunction(this->items[left],left);
  }

  //void(*forEachFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*)
  void forEach(void(*forEachFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*)){
    for (sizeDataType index = 0;index < this->size;index++)
      forEachFunction(this->items[index],index,this);
  }
  void forEach(void(*forEachFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*),sizeDataType size){
    for (sizeDataType index = 0;index < size && size <= this->size;index++)
      forEachFunction(this->items[index],index,this);
  }
  void forEach(void(*forEachFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*),sizeDataType left,sizeDataType right){
    for (;0 <= left && left < right && right <= this->size;left++)
      forEachFunction(this->items[left],left,this);
  }

  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  filter(bool(*filterFunction)(itemsDataType)){
    dynamicArray<itemsDataType,sizeDataType,capacityDataType>filteredDynamicArray(0,this->capacity);
    for (sizeDataType index = 0;index < this->size;index++)
      if (filterFunction(this->items[index]))
        filteredDynamicArray->push(this->items[index]);
    return filteredDynamicArray;
  }
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  filter(bool(*filterFunction)(itemsDataType),sizeDataType size){
    dynamicArray<itemsDataType,sizeDataType,capacityDataType>filteredDynamicArray(0,this->capacity);
    for (sizeDataType index = 0;index < size && size <= this->size;index++)
      if (filterFunction(this->items[index]))
        filteredDynamicArray->push(this->items[index]);
    return filteredDynamicArray;
  }
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  filter(bool(*filterFunction)(itemsDataType),sizeDataType left,sizeDataType right){
    dynamicArray<itemsDataType,sizeDataType,capacityDataType>filteredDynamicArray(0,this->capacity);
    for (;0 <= left && left < right && right <= this->size;left++)
      if (filterFunction(this->items[left]))
        filteredDynamicArray->push(this->items[left]);
    return filteredDynamicArray;
  }

  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  filter(bool(*filterFunction)(itemsDataType,sizeDataType)){
    dynamicArray<itemsDataType,sizeDataType,capacityDataType>filteredDynamicArray(0,this->capacity);
    for (sizeDataType index = 0;index < this->size;index++)
      if (filterFunction(this->items[index],index))
        filteredDynamicArray->push(this->items[index]);
    return filteredDynamicArray;
  }
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  filter(bool(*filterFunction)(itemsDataType,sizeDataType),sizeDataType size){
    dynamicArray<itemsDataType,sizeDataType,capacityDataType>filteredDynamicArray(0,this->capacity);
    for (sizeDataType index = 0;index < size && size <= this->size;index++)
      if (filterFunction(this->items[index],index))
        filteredDynamicArray->push(this->items[index]);
    return filteredDynamicArray;
  }
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  filter(bool(*filterFunction)(itemsDataType,sizeDataType),sizeDataType left,sizeDataType right){
    dynamicArray<itemsDataType,sizeDataType,capacityDataType>filteredDynamicArray(0,this->capacity);
    for (;0 <= left && left < right && right <= this->size;left++)
      if (filterFunction(this->items[left],left))
        filteredDynamicArray->push(this->items[left]);
    return filteredDynamicArray;
  }

  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  filter(bool(*filterFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*)){
    dynamicArray<itemsDataType,sizeDataType,capacityDataType>filteredDynamicArray(0,this->capacity);
    for (sizeDataType index = 0;index < this->size;index++)
      if (filterFunction(this->items[index],index,this))
        filteredDynamicArray->push(this->items[index]);
    return filteredDynamicArray;
  }
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  filter(bool(*filterFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*),sizeDataType size){
    dynamicArray<itemsDataType,sizeDataType,capacityDataType>filteredDynamicArray(0,this->capacity);
    for (sizeDataType index = 0;index < size && size <= this->size;index++)
      if (filterFunction(this->items[index],index,this))
        filteredDynamicArray->push(this->items[index]);
    return filteredDynamicArray;
  }
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  filter(bool(*filterFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*),sizeDataType left,sizeDataType right){
    dynamicArray<itemsDataType,sizeDataType,capacityDataType>filteredDynamicArray(0,this->capacity);
    for (;0 <= left && left < right && right <= this->size;left++)
      if (filterFunction(this->items[left],left,this))
        filteredDynamicArray->push(this->items[left]);
    return filteredDynamicArray;
  }
  
  bool every(bool(*everyFunction)(itemsDataType)){
    bool everyCondition=1;
    for (sizeDataType index = 0;index < this->size;index++)
      everyCondition &= everyFunction(this->items[index]);
    return everyCondition;
  }
  bool every(bool(*everyFunction)(itemsDataType),sizeDataType size){
    bool everyCondition=1;
    for (sizeDataType index = 0;index < size && size <= this->size;index++)
      everyCondition &= everyFunction(this->items[index]);
    return everyCondition;
  }
  bool every(bool(*everyFunction)(itemsDataType),sizeDataType left,sizeDataType right){
    bool everyCondition=1;
    for (;0 <= left && left < right && right <= this->size;left++)
      everyCondition &= everyFunction(this->items[left]);
    return everyCondition;
  }

  bool every(bool(*everyFunction)(itemsDataType,sizeDataType)){
    bool everyCondition=1;
    for (sizeDataType index = 0;index < this->size;index++)
      everyCondition &= everyFunction(this->items[index],index);
    return everyCondition;
  }
  bool every(bool(*everyFunction)(itemsDataType,sizeDataType),sizeDataType size){
    bool everyCondition=1;
    for (sizeDataType index = 0;index < size && size <= this->size;index++)
      everyCondition &= everyFunction(this->items[index],index);
    return everyCondition;
  }
  bool every(bool(*everyFunction)(itemsDataType,sizeDataType),sizeDataType left,sizeDataType right){
    bool everyCondition=1;
    for (;0 <= left && left < right && right <= this->size;left++)
      everyCondition &= everyFunction(this->items[left],left);
    return everyCondition;
  }
  
  bool every(bool(*everyFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*)){
    bool everyCondition=1;
    for (sizeDataType index = 0;index < this->size;index++)
      everyCondition &= everyFunction(this->items[index],index,this);
    return everyCondition;
  }
  bool every(bool(*everyFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*),sizeDataType size){
    bool everyCondition=1;
    for (sizeDataType index = 0;index < size && size <= this->size;index++)
      everyCondition &= everyFunction(this->items[index],index,this);
    return everyCondition;
  }
  bool every(bool(*everyFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*),sizeDataType left,sizeDataType right){
    bool everyCondition=1;
    for (;0 <= left && left < right && right <= this->size;left++)
      everyCondition &= everyFunction(this->items[left],left,this);
    return everyCondition;
  }

  bool some(bool(*someFunction)(itemsDataType)){
    bool someCondition=0;
    for (sizeDataType index = 0;index < this->size;index++)
      someCondition |= someFunction(this->items[index]);
    return someCondition;
  }
  bool some(bool(*someFunction)(itemsDataType),sizeDataType size){
    bool someCondition=0;
    for (sizeDataType index = 0;index < size && size <= this->size;index++)
      someCondition |= someFunction(this->items[index]);
    return someCondition;
  }
  bool some(bool(*someFunction)(itemsDataType),sizeDataType left,sizeDataType right){
    bool someCondition=0;
    for (;0 <= left && left < right && right <= this->size;left++)
      someCondition |= someFunction(this->items[left]);
    return someCondition;
  }

  bool some(bool(*someFunction)(itemsDataType,sizeDataType)){
    bool someCondition=0;
    for (sizeDataType index = 0;index < this->size;index++)
      someCondition |= someFunction(this->items[index],index);
    return someCondition;
  }
  bool some(bool(*someFunction)(itemsDataType,sizeDataType),sizeDataType size){
    bool someCondition=0;
    for (sizeDataType index = 0;index < size && size <= this->size;index++)
      someCondition |= someFunction(this->items[index],index);
    return someCondition;
  }
  bool some(bool(*someFunction)(itemsDataType,sizeDataType),sizeDataType left,sizeDataType right){
    bool someCondition=0;
    for (;0 <= left && left < right && right <= this->size;left++)
      someCondition |= someFunction(this->items[left],left);
    return someCondition;
  }
  
  bool some(bool(*someFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*)){
    bool someCondition=0;
    for (sizeDataType index = 0;index < this->size;index++)
      someCondition |= someFunction(this->items[index],index,this);
    return someCondition;
  }
  bool some(bool(*someFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*),sizeDataType size){
    bool someCondition=0;
    for (sizeDataType index = 0;index < size && size <= this->size;index++)
      someCondition |= someFunction(this->items[index],index,this);
    return someCondition;
  }
  bool some(bool(*someFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*),sizeDataType left,sizeDataType right){
    bool someCondition=0;
    for (;0 <= left && left < right && right <= this->size;left++)
      someCondition |= someFunction(this->items[left],left,this);
    return someCondition;
  }

  //xsome region
  bool xsome(bool(*xsomeFunction)(itemsDataType)){
    bool xsomeCondition = 0;
    for (sizeDataType index = 0;index < this->size;index++)
      xsomeCondition ^= xsomeFunction(this->items[index]);
    return xsomeCondition;
  }
  bool xsome(bool(*xsomeFunction)(itemsDataType),sizeDataType size){
    bool xsomeCondition=0;
    for (sizeDataType index = 0;index < size && size <= this->size;index++)
      xsomeCondition ^= xsomeFunction(this->items[index]);
    return xsomeCondition;
  }
  bool xsome(bool(*xsomeFunction)(itemsDataType),sizeDataType left,sizeDataType right){
    bool xsomeCondition=0;
    for (;0 <= left && left < right && right <= this->size;left++)
      xsomeCondition ^= xsomeFunction(this->items[left]);
    return xsomeCondition;
  }

  bool xsome(bool(*xsomeFunction)(itemsDataType,sizeDataType)){
    bool xsomeCondition=0;
    for (sizeDataType index = 0;index < this->size;index++)
      xsomeCondition ^= xsomeFunction(this->items[index],index);
    return xsomeCondition;
  }
  bool xsome(bool(*xsomeFunction)(itemsDataType,sizeDataType),sizeDataType size){
    bool xsomeCondition=0;
    for (sizeDataType index = 0;index < size && size <= this->size;index++)
      xsomeCondition ^= xsomeFunction(this->items[index],index);
    return xsomeCondition;
  }
  bool xsome(bool(*xsomeFunction)(itemsDataType,sizeDataType),sizeDataType left,sizeDataType right){
    bool someCondition=0;
    for (;0 <= left && left < right && right <= this->size;left++)
      xsomeCondition ^= xsomeFunction(this->items[left],left);
    return xsomeCondition;
  }
  
  bool xsome(bool(*xsomeFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*)){
    bool xsomeCondition=0;
    for (sizeDataType index = 0;index < this->size;index++)
      xsomeCondition ^= xsomeFunction(this->items[index],index,this);
    return xsomeCondition;
  }
  bool xsome(bool(*xsomeFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*),sizeDataType size){
    bool someCondition=0;
    for (sizeDataType index = 0;index < size && size <= this->size;index++)
      xsomeCondition ^= xsomeFunction(this->items[index],index,this);
    return xsomeCondition;
  }
  bool xsome(bool(*xsomeFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*),sizeDataType left,sizeDataType right){
    bool someCondition=0;
    for (;0 <= left && left < right && right <= this->size;left++)
      xsomeCondition ^= xsomeFunction(this->items[left],left,this);
    return xsomeCondition;
  }

  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  map(itemsDataType(*mapFunction)(itemsDataType)){
    dynamicArray<itemsDataType,sizeDataType,capacityDataType>mapDynamicArray(0,this->capacity);
    for (sizeDataType index = 0;index < this->size;index++)
      mapDynamicArray->push(mapFunction(this->items[index]));
    return mapDynamicArray;
  }
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  map(itemsDataType(*mapFunction)(itemsDataType),sizeDataType size){
    dynamicArray<itemsDataType,sizeDataType,capacityDataType>mapDynamicArray(0,this->capacity);
    for (sizeDataType index = 0;index < size && size <= this->size;index++)
      mapDynamicArray->push(mapFunction(this->items[index]));
    return mapDynamicArray;
  }
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  map(itemsDataType(*mapFunction)(itemsDataType),sizeDataType left,sizeDataType right){
    dynamicArray<itemsDataType,sizeDataType,capacityDataType>mapDynamicArray(0,this->capacity);
    for (;0 <= left && left < right && right <= this->size;left++)
      mapDynamicArray->push(mapFunction(this->items[left]));
    return mapDynamicArray;
  }

  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  map(itemsDataType(*mapFunction)(itemsDataType,sizeDataType)){
    dynamicArray<itemsDataType,sizeDataType,capacityDataType>mapDynamicArray(0,this->capacity);
    for (sizeDataType index = 0;index < this->size;index++)
      mapDynamicArray->push(mapFunction(this->items[index],index));
    return mapDynamicArray;
  }
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  map(itemsDataType(*mapFunction)(itemsDataType,sizeDataType),sizeDataType size){
    dynamicArray<itemsDataType,sizeDataType,capacityDataType>mapDynamicArray(0,this->capacity);
    for (sizeDataType index = 0;index < size && size <= this->size;index++)
      mapDynamicArray->push(mapFunction(this->items[index],index));
    return mapDynamicArray;
  }
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  map(itemsDataType(*mapFunction)(itemsDataType,sizeDataType),sizeDataType left,sizeDataType right){
    dynamicArray<itemsDataType,sizeDataType,capacityDataType>mapDynamicArray(0,this->capacity);
    for (;0 <= left && left < right && right <= this->size;left++)
      mapDynamicArray->push(mapFunction(this->items[left],left));
    return mapDynamicArray;
  }

  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  map(itemsDataType(*mapFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*)){
    dynamicArray<itemsDataType,sizeDataType,capacityDataType>mapDynamicArray(0,this->capacity);
    for (sizeDataType index = 0;index < this->size;index++)
      mapDynamicArray->push(mapFunction(this->items[index],index,this));
    return mapDynamicArray;
  }
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  map(itemsDataType(*mapFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*),sizeDataType size){
    dynamicArray<itemsDataType,sizeDataType,capacityDataType>mapDynamicArray(0,this->capacity);
    for (sizeDataType index = 0;index < size && size <= this->size;index++)
      mapDynamicArray->push(mapFunction(this->items[index],index,this));
    return mapDynamicArray;
  }
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>
  map(itemsDataType(*mapFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*),sizeDataType left,sizeDataType right){
    dynamicArray<itemsDataType,sizeDataType,capacityDataType>mapDynamicArray(0,this->capacity);
    for (;0 <= left && left < right && right <= this->size;left++)
      mapDynamicArray->push(mapFunction(this->items[left],left,this));
    return mapDynamicArray;
  }

  //reduce

  template<typename accumulationValueDataType>
  accumulationValueDataType reduce(itemsDataType(*reduceFunction)(itemsDataType),accumulationValueDataType accumulationValue){
    for (sizeDataType index = 0;index < this->size;index++)
      accumulationValue = reduceFunction(this->items[index]);
    return accumulationValue;
  }
  template<typename accumulationValueDataType>
  accumulationValueDataType reduce(itemsDataType(*reduceFunction)(itemsDataType),accumulationValueDataType accumulationValue,sizeDataType size){
    for (sizeDataType index = 0;index < size && size <= this->size;index++)
      accumulationValue = reduceFunction(this->items[index]);
    return accumulationValue;
  }
  template<typename accumulationValueDataType>
  accumulationValueDataType reduce(itemsDataType(*reduceFunction)(itemsDataType),accumulationValueDataType accumulationValue,sizeDataType left,sizeDataType right){
    for (;0 <= left && left < right && right <= this->size;left++)
      accumulationValue = reduceFunction(this->items[left]);
    return accumulationValue;
  }

  template<typename accumulationValueDataType>
  accumulationValueDataType reduce(itemsDataType(*reduceFunction)(itemsDataType,sizeDataType),accumulationValueDataType accumulationValue){
    for (sizeDataType index = 0;index < this->size;index++)
      accumulationValue = reduceFunction(this->items[index],index);
    return accumulationValue;
  }
  template<typename accumulationValueDataType>
  accumulationValueDataType reduce(itemsDataType(*reduceFunction)(itemsDataType,sizeDataType),accumulationValueDataType accumulationValue,sizeDataType size){
    for (sizeDataType index = 0;index < size && size <= this->size;index++)
      accumulationValue = reduceFunction(this->items[index],index);
    return accumulationValue;
  }
  template<typename accumulationValueDataType>
  accumulationValueDataType reduce(itemsDataType(*reduceFunction)(itemsDataType,sizeDataType),accumulationValueDataType accumulationValue,sizeDataType left,sizeDataType right){
    for (;0 <= left && left < right && right <= this->size;left++)
      accumulationValue = reduceFunction(this->items[left],left);
    return accumulationValue;
  }

  template<typename accumulationValueDataType>
  accumulationValueDataType reduce(itemsDataType(*reduceFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*),accumulationValueDataType accumulationValue){
    for (sizeDataType index = 0;index < this->size;index++)
      accumulationValue = reduceFunction(this->items[index],index,this);
    return accumulationValue;
  }
  template<typename accumulationValueDataType>
  accumulationValueDataType reduce(itemsDataType(*reduceFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*),accumulationValueDataType accumulationValue,sizeDataType size){
    for (sizeDataType index = 0;index < size && size <= this->size;index++)
      accumulationValue = reduceFunction(this->items[index],index,this);
    return accumulationValue;
  }
  template<typename accumulationValueDataType>
  accumulationValueDataType reduce(itemsDataType(*reduceFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*),accumulationValueDataType accumulationValue,sizeDataType left,sizeDataType right){
    for (;0 <= left && left < right && right <= this->size;left++)
      accumulationValue = reduceFunction(this->items[left],left,this);
    return accumulationValue;
  }

  void sort(itemsDataType(*comparisonFunction)(itemsDataType,itemsDataType),sizeDataType left,sizeDataType right){
    if (0 <= left && left < right && right <= this->size) {
      sizeDataType i = left - 1;
      itemsDataType tmp;
      for (;left < right;left++) {
        if (comparisonFunction(this->items[left],this->items[right]) < 0) {
          i++;
          tmp = this->items[i];
          this->items[i] = this->items[left];
          this->items[left] = tmp;
        }
      }
      i++;
      tmp = this->items[i];
      this->items[i] = this->items[right];
      this->items[right] = tmp;
      this->sort(comparisonFunction,0,i - 1);
      this->sort(comparisonFunction,i + 1,right);
    }
  }
  inline void sort(itemsDataType(*comparisonFunction)(itemsDataType,itemsDataType),sizeDataType size){
    this->sort(comparisonFunction,0,size);
  }
  inline void sort(itemsDataType(*comparisonFunction)(itemsDataType,itemsDataType)){
    this->sort(comparisonFunction,this->size);
  }

  void reverse(){
    for (sizeDataType index = 0;index < this->size / 2;index++){
      itemsDataType tmp = this->items[index];
      this->items[index] = this->items[this->size-index-1];
      this->items[this->size-index-1] = tmp;
    }
  }
  void reverse(sizeDataType size){
    for (sizeDataType index = 0;index < size / 2 && size <= this->size;index++){
      itemsDataType tmp = this->items[index];
      this->items[index] = this->items[this->size - index - 1];
      this->items[this->size - index - 1]=tmp;
    }
  }
  void reverse(sizeDataType left,sizeDataType right){
    for(;0 <= left && left < right / 2 && right <= this->size;left++){
      itemsDataType tmp = this->items[left];
      this->items[left] = this->items[this->size - left - 1];
      this->items[this->size - left - 1] = tmp;
    }
  }

  void concat(dynamicArray<itemsDataType,sizeDataType,capacityDataType>*sourceDynamicArray){
    for(sizeDataType index = 0;index < this->size;index++)
      this->push(sourceDynamicArray->items[index]);
  }
  void concat(dynamicArray<itemsDataType,sizeDataType,capacityDataType>*sourceDynamicArray,sizeDataType size){
    for (sizeDataType index = 0;index < size && size <= this->size;index++)
      this->push(sourceDynamicArray->items[index]);
  }
  void concat(dynamicArray<itemsDataType,sizeDataType,capacityDataType>*sourceDynamicArray,sizeDataType left,sizeDataType right){
    for (;0 <= left && left < right && right <= this->size;left++)
      this->push(sourceDynamicArray->items[left]);
  }

  void copy(dynamicArray<itemsDataType,sizeDataType,capacityDataType>*sourceDynamicArray){
    for (sizeDataType index = 0; index < this->size;index++)
      this->items[index] = sourceDynamicArray->items[index];
  }
  void copy(dynamicArray<itemsDataType,sizeDataType,capacityDataType>*sourceDynamicArray,sizeDataType size){
    for (sizeDataType index = 0;index < size && size <= this->size;index++)
      this->items[index] = sourceDynamicArray->items[index];
  }
  void copy(dynamicArray<itemsDataType,sizeDataType,capacityDataType>*sourceDynamicArray,sizeDataType left,sizeDataType right){
    for (;0 <= left && left < right && right <= this->size;left++)
      this->items[left] = sourceDynamicArray->items[left];
  }

  ~dynamicArray(){
    free(this->items);
    this->items = NULL;
  }
};
#endif