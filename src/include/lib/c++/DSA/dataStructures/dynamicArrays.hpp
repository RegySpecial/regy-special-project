#ifndef dynamicArraysHpp
#define dynamicArraysHpp
/*
*@description Header file where is defined the dynamic array data structure class of the dynamic array data structure library
*@author Regy Special
*@date (First version [Linux/Parrot OS]) 2026 March 7th Saturday, 16:12:08
*@license GNU General Public License to stop private corporation to not share source code
*/
#include <iostream>
#include <stdlib.h>
#include "../../../c/console.h"

template
<
  typename itemsDataType,
  typename sizeDataType = unsigned long long,
  typename capacityDataType = unsigned long long
>
class dynamicArray{
public:
  typedef dynamicArray<itemsDataType, sizeDataType, capacityDataType> dynamicArraySelf;
  typedef dynamicArraySelf *dynamicArrayPointer;
  
  typedef void (*forEach_callback)(itemsDataType);
  typedef void (*forEach1_callback)(itemsDataType, sizeDataType);
  typedef void (*forEach2_callback)(itemsDataType, sizeDataType, dynamicArrayPointer);

  typedef dynamicArraySelf (*filter_predicate)(itemsDataType);
  typedef dynamicArraySelf (*filter1_predicate)(itemsDataType, sizeDataType);
  typedef dynamicArraySelf (*filter2_predicate)(itemsDataType, sizeDataType, dynamicArrayPointer);

  typedef bool (*logicalPredicate_predicate)(itemsDataType);
  typedef bool (*logicalPredicate1_predicate)(itemsDataType, sizeDataType);
  typedef bool (*logicalPredicate2_predicate)(itemsDataType, sizeDataType, dynamicArrayPointer);

  typedef itemsDataType (*valueModification_callback)(itemsDataType);
  typedef itemsDataType (*valueModification1_callback)(itemsDataType, sizeDataType);
  typedef itemsDataType (*valueModification2_callback)(itemsDataType, sizeDataType, dynamicArrayPointer);

  template <typename accumulationValueDataType>
  using reduce_callback = accumulationValueDataType (*)(accumulationValueDataType, itemsDataType);
  template <typename accumulationValueDataType>
  using reduce1_callback = accumulationValueDataType (*)(accumulationValueDataType, itemsDataType, sizeDataType);
  template <typename accumulationValueDataType>
  using reduce2_callback = accumulationValueDataType (*)(accumulationValueDataType, itemsDataType, sizeDataType, dynamicArrayPointer);

  typedef itemsDataType (*comparisonFunction)(itemsDataType, itemsDataType);
  
  itemsDataType *items = NULL;
  sizeDataType size = 0;
  capacityDataType capacity = 32;

  dynamicArray()
  {
    this->items = (itemsDataType *) calloc(this->capacity, sizeof (itemsDataType));
    if (!this->items)
    {
      errorMessage("Failed to reallocate memory for the dynamic array");
      return;
    }
  }

  dynamicArray(capacityDataType capacity)
  {
    this->capacity = capacity;
    this->items = (itemsDataType *) calloc(this->capacity, sizeof (itemsDataType));
    if (!this->items)
    {
      errorMessage("Failed to allocate memory for the dynamic array");
      return;
    }
  }

  dynamicArray(itemsDataType *items, capacityDataType capacity)
  {
    this->capacity = capacity;
    this->size = this->capacity;
    this->items = (itemsDataType *) calloc(this->capacity, sizeof (itemsDataType));
    if (!this->items)
    {
      errorMessage("Failed to allocate memory for the dynamic array");
      return;
    }
    for (sizeDataType index = 0; index < this->size; index++)
      this->items[index] = items[index];
  }
  
  dynamicArray(sizeDataType size, capacityDataType capacity)
  {
    this->size = size;
    this->capacity = capacity;
    this->items = (itemsDataType *) calloc(this->capacity, sizeof (itemsDataType));
    if (!this->items)
    {
      errorMessage("Failed to allocate memory for the dynamic array");
      return;
    }
  }
  
  dynamicArray(itemsDataType *items, sizeDataType size, capacityDataType capacity)
  {
    this->capacity = capacity;
    this->size = size;
    this->items = (itemsDataType *) calloc(this->capacity,sizeof (itemsDataType));
    if (!this->items)
    {
      errorMessage("Failed to allocate memory for the dynamic array");
      return;
    }
    for (sizeDataType index = 0; index < this->size; index++)
      this->items[index] = items[index];
  }
  
  ~dynamicArray()
  {
    this->capacity = 0;
    this->size = 0;
    free(this->items);
    this->items = NULL;
  }
  
  void insert(itemsDataType item, sizeDataType index)
  {
    if (index >= this->size)
    {
      errorMessage("Index out of range");
      return;
    }
  
    if (this->size == this->capacity)
    {
      this->capacity *= 2;
      this->items = (itemsDataType *) realloc(this->items, this->capacity * sizeof (itemsDataType));
      if (this->items)
        for (sizeDataType i = this->size + 1; i < this->capacity; i++)
          this->items[i] = 0;
      else
      {
        itemsDataType *oldItems = this->items;
        this->items = (itemsDataType *) calloc(this->capacity, sizeof (itemsDataType));
        if (!this->items)
        {
          errorMessage("Failed to reallocate memory for the dynamic array");
          return;
        }
        free(oldItems);
        oldItems = NULL;
      }
    }
    for (sizeDataType i = this->size; i > index; i--)
      this->items[i] = this->items[i - 1];
    this->items[index] = item;
    ++this->size;
  }
  
  void remove(sizeDataType index)
  {
    if (index < this->size)
    {
      for (; index < this->size - 1; index++)
        this->items[index] = this->items[index + 1];
      this->items[this->size - 1] = 0;
      --this->size;
    }
    else
      errorMessage("Index out of range!");
  }
  
  void push(itemsDataType item)
  {
    if (this->size == this->capacity)
    {
      this->capacity *= 2;
      this->items = (itemsDataType *) realloc(this->items, this->capacity * sizeof (itemsDataType));
      if (this->items)
        for (sizeDataType i = this->size + 1; i < this->capacity; i++)
          this->items[i] = 0;
      else
      {
        itemsDataType *oldItems = this->items;
        this->items = (itemsDataType *) calloc(this->capacity,sizeof (itemsDataType));
        if (!this->items)
        {
          errorMessage("Failed to reallocate memory for the dynamic array");
          return;
        }
        free(oldItems);
        oldItems = NULL;
      }
    }
    this->items[this->size] = item;
    ++this->size;
  }
  
  inline void pop()
  {
    this->remove(this->size - 1);
  }
  
  itemsDataType at(sizeDataType index)
  {
    if (0 <= index && index < this->size)
      return this->items[index];
    else
      errorMessage("Index out of range!");
  }
  
  void forEach(forEach_callback forEachFunction)
  {
    for (sizeDataType index = 0; index < this->size; index++)
      forEachFunction(this->at(index));
  }
  
  void forEach(forEach_callback forEachFunction, sizeDataType size)
  {
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      forEachFunction(this->at(index));
  }
  
  void forEach(forEach_callback forEachFunction, sizeDataType left, sizeDataType right)
  {
    for (; 0 <= left && left < right && right <= this->size; left++)
      forEachFunction(this->at(left));
  }
  
  void forEach(forEach1_callback forEachFunction)
  {
    for (sizeDataType index = 0; index < this->size; index++)
      forEachFunction(this->at(index), index);
  }
  
  void forEach(forEach1_callback forEachFunction, sizeDataType size)
  {
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      forEachFunction(this->at(index), index);
  }
  
  void forEach(forEach1_callback forEachFunction, sizeDataType left, sizeDataType right)
  {
    for (; 0 <= left && left < right && right <= this->size; left++)
      forEachFunction(this->at(left), left);
  }
  
  void forEach(forEach2_callback forEachFunction)
  {
    for (sizeDataType index = 0; index < this->size; index++)
      forEachFunction(this->at(index), index, this);
  }
  
  void forEach(forEach2_callback forEachFunction, sizeDataType size)
  {
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      forEachFunction(this->at(index), index, this);
  }
  
  void forEach(forEach2_callback forEachFunction, sizeDataType left, sizeDataType right)
  {
    for (; 0 <= left && left < right && right <= this->size; left++)
      forEachFunction(this->at(left), left, this);
  }
  
  dynamicArraySelf filter(filter_predicate filterFunction)
  {
    dynamicArray<itemsDataType, sizeDataType, capacityDataType> filteredDynamicArray(0, this->capacity);
    for (sizeDataType index = 0; index < this->size; index++)
      if (filterFunction(this->at(index)))
        filteredDynamicArray->push(this->at(index));
    return filteredDynamicArray;
  }
  
  dynamicArraySelf filter(filter_predicate filterFunction, sizeDataType size)
  {
    dynamicArray<itemsDataType, sizeDataType, capacityDataType> filteredDynamicArray(0,this->capacity);
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      if (filterFunction(this->at(index)))
        filteredDynamicArray->push(this->at(index));
    return filteredDynamicArray;
  }
  
  dynamicArraySelf filter(filter_predicate filterFunction, sizeDataType left, sizeDataType right)
  {
    dynamicArray<itemsDataType, sizeDataType, capacityDataType> filteredDynamicArray(0, this->capacity);
    for (; 0 <= left && left < right && right <= this->size; left++)
      if (filterFunction(this->at(left)))
        filteredDynamicArray->push(this->at(left));
    return filteredDynamicArray;
  }
  
  dynamicArraySelf filter(filter1_predicate filterFunction)
  {
    dynamicArray<itemsDataType, sizeDataType, capacityDataType>filteredDynamicArray(0,this->capacity);
    for (sizeDataType index = 0; index < this->size; index++)
      if (filterFunction(this->at(index), index))
        filteredDynamicArray->push(this->at(index));
    return filteredDynamicArray;
  }
  
  dynamicArraySelf filter(filter1_predicate filterFunction, sizeDataType size)
  {
    dynamicArray<itemsDataType, sizeDataType, capacityDataType>filteredDynamicArray(0,this->capacity);
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      if (filterFunction(this->at(index), index))
        filteredDynamicArray->push(this->at(index));
    return filteredDynamicArray;
  }
  
  dynamicArraySelf filter(filter1_predicate filterFunction, sizeDataType left, sizeDataType right)
  {
    dynamicArray<itemsDataType, sizeDataType, capacityDataType>filteredDynamicArray(0,this->capacity);
    for (; 0 <= left && left < right && right <= this->size; left++)
      if (filterFunction(this->at(left), left))
        filteredDynamicArray->push(this->at(left));
    return filteredDynamicArray;
  }
  
  dynamicArraySelf filter(filter2_predicate filterFunction)
  {
    dynamicArray<itemsDataType, sizeDataType, capacityDataType>filteredDynamicArray(0,this->capacity);
    for (sizeDataType index = 0; index < this->size; index++)
      if (filterFunction(this->at(index), index, this))
        filteredDynamicArray->push(this->at(index));
    return filteredDynamicArray;
  }
  
  dynamicArraySelf filter(filter2_predicate filterFunction, sizeDataType size)
  {
      dynamicArray<itemsDataType, sizeDataType, capacityDataType>filteredDynamicArray(0,this->capacity);
      for (sizeDataType index = 0; index < size && size <= this->size; index++)
        if (filterFunction(this->at(index), index, this))
          filteredDynamicArray->push(this->at(index));
      return filteredDynamicArray;
    }
  
  dynamicArraySelf filter(filter2_predicate filterFunction, sizeDataType left, sizeDataType right)
  {
    dynamicArray<itemsDataType, sizeDataType, capacityDataType>filteredDynamicArray(0,this->capacity);
    for (; 0 <= left && left < right && right <= this->size; left++)
      if (filterFunction(this->at(left), left, this))
        filteredDynamicArray->push(this->at(left));
    return filteredDynamicArray;
  }
  
  bool every(logicalPredicate_predicate everyFunction)
  {
    bool everyCondition = 1;
    for (sizeDataType index = 0; index < this->size; index++)
      everyCondition &= everyFunction(this->at(index));
    return everyCondition;
  }
  
  bool every(logicalPredicate_predicate everyFunction, sizeDataType size)
  {
    bool everyCondition = 1;
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      everyCondition &= everyFunction(this->at(index));
    return everyCondition;
  }
  
  bool every(logicalPredicate_predicate everyFunction, sizeDataType left, sizeDataType right)
  {
    bool everyCondition = 1;
    for (; 0 <= left && left < right && right <= this->size; left++)
      everyCondition &= everyFunction(this->at(left));
    return everyCondition;
  }
  
  
  bool every(logicalPredicate1_predicate everyFunction)
  {
    bool everyCondition = 1;
    for (sizeDataType index = 0; index < this->size; index++)
      everyCondition &= everyFunction(this->at(index), index);
    return everyCondition;
  }
  
  bool every(logicalPredicate1_predicate everyFunction, sizeDataType size)
  {
    bool everyCondition = 1;
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      everyCondition &= everyFunction(this->at(index), index);
    return everyCondition;
  }
  
  bool every(logicalPredicate1_predicate everyFunction, sizeDataType left, sizeDataType right)
  {
    bool everyCondition = 1;
    for (; 0 <= left && left < right && right <= this->size; left++)
      everyCondition &= everyFunction(this->at(left), left);
    return everyCondition;
  }
    
  
  bool every(logicalPredicate2_predicate everyFunction)
  {
    bool everyCondition = 1;
    for (sizeDataType index = 0; index < this->size; index++)
      everyCondition &= everyFunction(this->at(index), index, this);
    return everyCondition;
  }
  
  bool every(logicalPredicate2_predicate everyFunction, sizeDataType size)
  {
    bool everyCondition = 1;
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      everyCondition &= everyFunction(this->at(index), index, this);
    return everyCondition;
  }
  
  bool every(logicalPredicate2_predicate everyFunction, sizeDataType left, sizeDataType right)
  {
    bool everyCondition = 1;
    for (; 0 <= left && left < right && right <= this->size; left++)
      everyCondition &= everyFunction(this->at(left), left, this);
    return everyCondition;
  }
  
  bool some(logicalPredicate_predicate someFunction)
  {
    bool someCondition = 0;
    for (sizeDataType index = 0; index < this->size; index++)
      someCondition |= someFunction(this->at(index));
    return someCondition;
  }
  
  bool some(logicalPredicate_predicate someFunction, sizeDataType size)
  {
    bool someCondition = 0;
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      someCondition |= someFunction(this->at(index));
    return someCondition;
  }
  
  bool some(logicalPredicate_predicate someFunction, sizeDataType left, sizeDataType right)
  {
    bool someCondition = 0;
    for (; 0 <= left && left < right && right <= this->size; left++)
      someCondition |= someFunction(this->at(left));
    return someCondition;
  }
  
  bool some(logicalPredicate1_predicate someFunction)
  {
    bool someCondition = 0;
    for (sizeDataType index = 0; index < this->size; index++)
      someCondition |= someFunction(this->at(index), index);
    return someCondition;
  }
  
  bool some(logicalPredicate1_predicate someFunction, sizeDataType size)
  {
    bool someCondition = 0;
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      someCondition |= someFunction(this->at(index), index);
    return someCondition;
  }
  
  bool some(logicalPredicate1_predicate someFunction, sizeDataType left, sizeDataType right)
  {
    bool someCondition = 0;
    for (; 0 <= left && left < right && right <= this->size; left++)
      someCondition |= someFunction(this->at(left), left);
    return someCondition;
  }
  
  bool some(logicalPredicate2_predicate someFunction)
  {
    bool someCondition = 0;
    for (sizeDataType index = 0; index < this->size; index++)
      someCondition |= someFunction(this->at(index), index, this);
    return someCondition;
  }
  
  bool some(logicalPredicate2_predicate someFunction, sizeDataType size)
  {
    bool someCondition = 0;
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      someCondition |= someFunction(this->at(index), index, this);
    return someCondition;
  }
  
  bool some(logicalPredicate2_predicate someFunction, sizeDataType left, sizeDataType right)
  {
    bool someCondition = 0;
    for (; 0 <= left && left < right && right <= this->size; left++)
      someCondition |= someFunction(this->at(left), left, this);
    return someCondition;
  }
  //xsome region
  
  bool xsome(logicalPredicate_predicate xsomeFunction)
  {
    bool xsomeCondition = 0;
    for (sizeDataType index = 0; index < this->size; index++)
      xsomeCondition ^= xsomeFunction(this->at(index));
    return xsomeCondition;
  }
  
  bool xsome(logicalPredicate_predicate xsomeFunction, sizeDataType size)
  {
    bool xsomeCondition = 0;
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      xsomeCondition ^= xsomeFunction(this->at(index));
    return xsomeCondition;
  }
  
  bool xsome(logicalPredicate_predicate xsomeFunction, sizeDataType left, sizeDataType right)
  {
    bool xsomeCondition = 0;
    for (; 0 <= left && left < right && right <= this->size; left++)
      xsomeCondition ^= xsomeFunction(this->at(left));
    return xsomeCondition;
  }
  
  bool xsome(logicalPredicate1_predicate xsomeFunction)
  {
    bool xsomeCondition = 0;
    for (sizeDataType index = 0; index < this->size; index++)
      xsomeCondition ^= xsomeFunction(this->at(index), index);
    return xsomeCondition;
  }
  
  bool xsome(logicalPredicate1_predicate xsomeFunction, sizeDataType size)
  {
    bool xsomeCondition = 0;
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      xsomeCondition ^= xsomeFunction(this->at(index), index);
    return xsomeCondition;
  }
  
  bool xsome(logicalPredicate1_predicate xsomeFunction, sizeDataType left, sizeDataType right)
  {
    bool xsomeCondition = 0;
    for (; 0 <= left && left < right && right <= this->size; left++)
      xsomeCondition ^= xsomeFunction(this->at(left), left);
    return xsomeCondition;
  }
  
  bool xsome(logicalPredicate2_predicate xsomeFunction)
  {
    bool xsomeCondition = 0;
    for (sizeDataType index = 0; index < this->size; index++)
      xsomeCondition ^= xsomeFunction(this->at(index), index, this);
    return xsomeCondition;
  }
  
  bool xsome(logicalPredicate2_predicate xsomeFunction, sizeDataType size)
  {
    bool xsomeCondition = 0;
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      xsomeCondition ^= xsomeFunction(this->at(index), index, this);
    return xsomeCondition;
  }
  
  bool xsome(logicalPredicate2_predicate xsomeFunction, sizeDataType left, sizeDataType right)
  {
    bool xsomeCondition = 0;
    for (; 0 <= left && left < right && right <= this->size; left++)
      xsomeCondition ^= xsomeFunction(this->at(left), left, this);
    return xsomeCondition;
  }
  
  dynamicArraySelf map(valueModification_callback mapFunction)
  {
    dynamicArray<itemsDataType, sizeDataType, capacityDataType>mapDynamicArray(0,this->capacity);
    for (sizeDataType index = 0; index < this->size; index++)
      mapDynamicArray->push(mapFunction(this->at(index)));
    return mapDynamicArray;
  }
  
  dynamicArraySelf map(valueModification_callback mapFunction, sizeDataType size)
  {
    dynamicArray<itemsDataType, sizeDataType, capacityDataType>mapDynamicArray(0,this->capacity);
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      mapDynamicArray->push(mapFunction(this->at(index)));
    return mapDynamicArray;
  }
  
  dynamicArraySelf map(valueModification_callback mapFunction, sizeDataType left, sizeDataType right)
  {
    dynamicArray<itemsDataType, sizeDataType, capacityDataType>mapDynamicArray(0,this->capacity);
    for (; 0 <= left && left < right && right <= this->size; left++)
      mapDynamicArray->push(mapFunction(this->at(left)));
    return mapDynamicArray;
  }
  
  dynamicArraySelf map(valueModification1_callback mapFunction)
  {
    dynamicArray<itemsDataType, sizeDataType, capacityDataType>mapDynamicArray(0,this->capacity);
    for (sizeDataType index = 0; index < this->size; index++)
      mapDynamicArray->push(mapFunction(this->at(index), index));
    return mapDynamicArray;
  }
  
  dynamicArraySelf map(valueModification1_callback mapFunction, sizeDataType size)
  {
    dynamicArray<itemsDataType, sizeDataType, capacityDataType>mapDynamicArray(0,this->capacity);
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      mapDynamicArray->push(mapFunction(this->at(index), index));
    return mapDynamicArray;
  }
  
  dynamicArraySelf map(valueModification1_callback mapFunction, sizeDataType left, sizeDataType right)
  {
    dynamicArray<itemsDataType, sizeDataType, capacityDataType>mapDynamicArray(0,this->capacity);
    for (; 0 <= left && left < right && right <= this->size; left++)
      mapDynamicArray->push(mapFunction(this->at(left), left));
    return mapDynamicArray;
  }
  
  dynamicArraySelf map(valueModification2_callback mapFunction)
  {
    dynamicArray<itemsDataType, sizeDataType, capacityDataType>mapDynamicArray(0,this->capacity);
    for (sizeDataType index = 0; index < this->size; index++)
      mapDynamicArray->push(mapFunction(this->at(index), index, this));
    return mapDynamicArray;
  }
  
  dynamicArraySelf map(valueModification2_callback mapFunction, sizeDataType size)
  {
    dynamicArray<itemsDataType, sizeDataType, capacityDataType>mapDynamicArray(0,this->capacity);
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      mapDynamicArray->push(mapFunction(this->at(index), index, this));
    return mapDynamicArray;
  }
  
  dynamicArraySelf map(valueModification2_callback mapFunction, sizeDataType left, sizeDataType right)
  {
    dynamicArray<itemsDataType, sizeDataType, capacityDataType>mapDynamicArray(0,this->capacity);
    for (; 0 <= left && left < right && right <= this->size; left++)
      mapDynamicArray->push(mapFunction(this->at(left), left, this));
    return mapDynamicArray;
  }
  
  template <typename accumulationValueDataType>
  accumulationValueDataType reduce(reduce_callback<accumulationValueDataType> reductionFunction, accumulationValueDataType accumulationValue)
  {
    for (sizeDataType index = 0; index < this->size; index++)
      accumulationValue = reductionFunction(this->at(index));
    return accumulationValue;
  }
  
  template <typename accumulationValueDataType>
  accumulationValueDataType reduce(reduce_callback<accumulationValueDataType> reductionFunction, accumulationValueDataType accumulationValue, sizeDataType size)
  {
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      accumulationValue = reductionFunction(this->at(index));
    return accumulationValue;
  }
  
  template <typename accumulationValueDataType>
  accumulationValueDataType reduce(reduce_callback<accumulationValueDataType> reductionFunction, accumulationValueDataType accumulationValue, sizeDataType left, sizeDataType right)
  {
    for (; 0 <= left && left < right && right <= this->size; left++)
      accumulationValue = reductionFunction(this->at(left));
    return accumulationValue;
  }
  
  template <typename accumulationValueDataType>
  accumulationValueDataType
  reduce(reduce1_callback<accumulationValueDataType> reductionFunction, accumulationValueDataType accumulationValue)
  {
    for (sizeDataType index = 0; index < this->size; index++)
      accumulationValue = reductionFunction(this->at(index), index);
    return accumulationValue;
  }
  
  template <typename accumulationValueDataType>
  accumulationValueDataType
  reduce(reduce1_callback<accumulationValueDataType> reductionFunction, accumulationValueDataType accumulationValue, sizeDataType size)
  {
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      accumulationValue = reductionFunction(this->at(index), index);
    return accumulationValue;
  }
  
  template <typename accumulationValueDataType>
  accumulationValueDataType reduce(reduce1_callback<accumulationValueDataType> reductionFunction, accumulationValueDataType accumulationValue, sizeDataType left, sizeDataType right)
  {
    for (; 0 <= left && left < right && right <= this->size; left++)
      accumulationValue = reductionFunction(this->at(left), left);
    return accumulationValue;
  }
  
  template <typename accumulationValueDataType>
  accumulationValueDataType reduce(reduce2_callback<accumulationValueDataType> reductionFunction, accumulationValueDataType accumulationValue)
  {
    for (sizeDataType index = 0; index < this->size; index++)
      accumulationValue = reductionFunction(this->at(index), index, this);
    return accumulationValue;
  }
  
  template <typename accumulationValueDataType>
  accumulationValueDataType reduce(reduce2_callback<accumulationValueDataType> reductionFunction, accumulationValueDataType accumulationValue, sizeDataType size)
  {
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      accumulationValue = reductionFunction(this->at(index), index, this);
    return accumulationValue;
  }
  
  template <typename accumulationValueDataType>
  accumulationValueDataType reduce(reduce2_callback<accumulationValueDataType> reductionFunction, accumulationValueDataType accumulationValue, sizeDataType left, sizeDataType right)
  {
    for (; 0 <= left && left < right && right <= this->size; left++)
      accumulationValue = reductionFunction(this->at(left), left, this);
    return accumulationValue;
  }

  itemsDataType find(logicalPredicate_predicate searchFunction)
  {
    for (sizeDataType index = 0; index < this->size; index++)
      if (searchFunction(this->at(index)))
        return this->at(index);
    return;
  }

  itemsDataType find(logicalPredicate_predicate searchFunction, sizeDataType size)
  {
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      if (searchFunction(this->at(index)))
        return this->at(index);
    return;
  }

  itemsDataType find(logicalPredicate_predicate searchFunction, sizeDataType left, sizeDataType right)
  {
    for (; 0 <= left && left < right && right <= this->size; left++)
      if (searchFunction(this->at(left)))
        return this->at(left);
    return;
  }

  itemsDataType find(logicalPredicate1_predicate searchFunction)
  {
    for (sizeDataType index = 0; index < this->size; index++)
      if (searchFunction(this->at(index), index))
        return this->at(index);
    return;
  }

  itemsDataType find(logicalPredicate1_predicate searchFunction, sizeDataType size)
  {
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      if (searchFunction(this->at(index), index))
        return this->at(index);
    return;
  }

  itemsDataType find(logicalPredicate1_predicate searchFunction, sizeDataType left, sizeDataType right)
  {
    for (; 0 <= left && left < right && right <= this->size; left++)
      if (searchFunction(this->at(left), left))
        return this->at(left);
    return;
  }

  itemsDataType find(logicalPredicate2_predicate searchFunction)
  {
    for (sizeDataType index = 0; index < this->size; index++)
      if (searchFunction(this->at(index), index, this))
        return this->at(index);
    return;
  }

  itemsDataType find(logicalPredicate2_predicate searchFunction, sizeDataType size)
  {
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      if (searchFunction(this->at(index), index, this))
        return this->at(index);
    return;
  }

  itemsDataType find(logicalPredicate2_predicate searchFunction, sizeDataType left, sizeDataType right)
  {
    for (; 0 <= left && left < right && right <= this->size; left++)
      if (searchFunction(this->at(left), left, this))
        return this->at(left);
    return;
  }

  sizeDataType findIndex(logicalPredicate_predicate searchFunction)
  {
    for (sizeDataType index = 0; index < this->size; index++)
      if (searchFunction(this->at(index)))
        return index;
    return;
  }

  sizeDataType findIndex(logicalPredicate_predicate searchFunction, sizeDataType size)
  {
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      if (searchFunction(this->at(index)))
        return index;
    return;
  }

  sizeDataType findIndex(logicalPredicate_predicate searchFunction, sizeDataType left, sizeDataType right)
  {
    for (; 0 <= left && left < right && right <= this->size; left++)
      if (searchFunction(this->at(left)))
        return left;
    return;
  }

  sizeDataType findIndex(logicalPredicate1_predicate searchFunction)
  {
    for (sizeDataType index = 0; index < this->size; index++)
      if (searchFunction(this->at(index), index))
        return index;
    return;
  }

  sizeDataType findIndex(logicalPredicate1_predicate searchFunction, sizeDataType size)
  {
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      if (searchFunction(this->at(index), index))
        return index;
    return;
  }

  sizeDataType findIndex(logicalPredicate1_predicate searchFunction, sizeDataType left, sizeDataType right)
  {
    for (; 0 <= left && left < right && right <= this->size; left++)
      if (searchFunction(this->at(left), left))
        return left;
    return;
  }

  sizeDataType findIndex(logicalPredicate2_predicate searchFunction)
  {
    for (sizeDataType index = 0; index < this->size; index++)
      if (searchFunction(this->at(index), index, this))
        return index;
    return;
  }

  sizeDataType findIndex(logicalPredicate2_predicate searchFunction, sizeDataType size)
  {
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      if (searchFunction(this->at(index), index, this))
        return index;
    return;
  }

  sizeDataType findIndex(logicalPredicate2_predicate searchFunction, sizeDataType left, sizeDataType right)
  {
    for (; 0 <= left && left < right && right <= this->size; left++)
      if (searchFunction(this->at(left), left, this))
        return left;
    return;
  }
  
  void sort(comparisonFunction comparison, sizeDataType left, sizeDataType right)
  {
    if (0 <= left && left < right && right <= this->size)
    {
      sizeDataType i = left - 1;
      itemsDataType tmp;
      for (; left < right; left++)
      {
        if (comparison(this->at(left), this->at(right)))
        {
          i++;
          tmp = this->items[i];
          this->items[i] = this->items[left];
          this->items[left] = tmp;
        }
      }
      i++;
      tmp = this->items[i];
      this->items[i] = this->at(right);
      this->at(right) = tmp;
      this->sort(comparison, 0, i - 1);
      this->sort(comparison, i + 1, right);
    }
  }
  
  inline void sort(comparisonFunction comparison, sizeDataType size)
  {
    this->sort(comparison, 0, size);
  }
  
  inline void sort(comparisonFunction comparison)
  {
    this->sort(comparison, this->size);
  }
  
  void reverse()
  {
    for (sizeDataType index = 0; index < this->size / 2; index++)
    {
      itemsDataType tmp = this->items[index];
      this->items[index] = this->items[this->size - index-1];
      this->items[this->size - index-1] = tmp;
    }
  }
  
  void reverse(sizeDataType size)
  {
    for (sizeDataType index = 0; index < size / 2 && size <= this->size; index++)
    {
      itemsDataType tmp = this->items[index];
      this->items[index] = this->items[this->size - index - 1];
      this->items[this->size - index - 1]=tmp;
    }
  }
  
  void reverse(sizeDataType left, sizeDataType right)
  {
    for (;0 <= left && left < right / 2 && right <= this->size; left++)
    {
      itemsDataType tmp = this->items[left];
      this->items[left] = this->items[this->size - left - 1];
      this->items[this->size - left - 1] = tmp;
    }
  }
  
  
  void merge(dynamicArrayPointer sourceDynamicArray)
  {
    for (sizeDataType index = 0; index < this->size; index++)
      this->push(sourceDynamicArray->items[index]);
  }
  
  void merge(dynamicArrayPointer sourceDynamicArray, sizeDataType size)
  {
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      this->push(sourceDynamicArray->items[index]);
  }
  
  void merge(dynamicArrayPointer sourceDynamicArray, sizeDataType left, sizeDataType right)
  {
    for (; 0 <= left && left < right && right <= this->size; left++)
      this->push(sourceDynamicArray->items[left]);
  }
  
  
  void copy(dynamicArrayPointer sourceDynamicArray)
  {
    for (sizeDataType index = 0; index < this->size; index++)
      this->items[index] = sourceDynamicArray->items[index];
  }
  
  void copy(dynamicArrayPointer sourceDynamicArray, sizeDataType size)
  {
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      this->items[index] = sourceDynamicArray->items[index];
  }
  
  void copy(dynamicArrayPointer sourceDynamicArray, sizeDataType left, sizeDataType right)
  {
    for (; 0 <= left && left < right && right <= this->size; left++)
      this->items[left] = sourceDynamicArray->items[left];
  }
  
  
  void join(dynamicArrayPointer sourceDynamicArray)
  {
    this->merge(sourceDynamicArray);
    repeat:
      for (sizeDataType i = 0; i < this->size - 1; i++)
        for (sizeDataType j = i + 1; j < this->size; j++)
          if (this->at(i) == this->at(j))
          {
            this->remove(j);
            goto repeat;
          }
  }
  
  void join(dynamicArrayPointer sourceDynamicArray, sizeDataType size)
  {
    this->merge(sourceDynamicArray, size);
    repeat:
      for (sizeDataType i = 0; i < this->size - 1; i++)
        for (sizeDataType j = i + 1; j < this->size; j++)
          if (this->at(i) == this->at(j))
          {
            this->remove(j);
            goto repeat;
          }
  }
  
  void join(dynamicArrayPointer sourceDynamicArray, sizeDataType left, sizeDataType right)
  {
    this->merge(sourceDynamicArray, left, right);
    repeat:
      for (sizeDataType i = 0; i < this->size - 1; i++)
        for (sizeDataType j = i + 1; j < this->size; j++)
          if (this->at(i) == this->at(j))
          {
            this->remove(j);
            goto repeat;
          }
  }
  
  
  dynamicArraySelf intersect(dynamicArrayPointer sourceDynamicArray)
  {
    dynamicArray<itemsDataType, sizeDataType, capacityDataType> resultDynamicArray;
    for (sizeDataType thisIndex = 0; thisIndex < this->size; thisIndex++)
      for (sizeDataType sourceIndex = 0; sourceIndex < sourceDynamicArray->size; sourceIndex++)
        if (sourceDynamicArray->items[sourceIndex] == this->items[thisIndex])
          resultDynamicArray.push(sourceDynamicArray->items[sourceIndex]);
    return resultDynamicArray;
  }
  
  dynamicArraySelf intersect(dynamicArrayPointer sourceDynamicArray, sizeDataType size)
  {
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      this->push(sourceDynamicArray->items[index]);
  }
  
  dynamicArraySelf intersect(dynamicArrayPointer sourceDynamicArray, sizeDataType left, sizeDataType right)
  {
    for (; 0 <= left && left < right && right <= this->size; left++)
      this->push(sourceDynamicArray->items[left]);
  }
};
#endif