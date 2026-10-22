/*
*@description Header file where is defined the dynamic array data structure class of the dynamic array data structure library
*@author Regy Special
*@date (First version [Linux/Parrot OS]) 2026 March 7th Saturday, 16:12:08
*@license GNU General Public License to stop private corporation to not share source code
*/

#include "../../../../include/lib/c++/DSA/dataStructures/dynamicArrays.hpp"

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::dynamicArray()
{
  this->items = (itemsDataType *) calloc(this->capacity, sizeof (itemsDataType));
  if (!this->items)
  {
    errorMessage("Failed to reallocate memory for the dynamic array");
    return;
  }
}

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::dynamicArray(capacityDataType capacity)
{
  this->capacity = capacity;
  this->items = (itemsDataType *) calloc(this->capacity, sizeof (itemsDataType));
  if (!this->items)
  {
    errorMessage("Failed to allocate memory for the dynamic array");
    return;
  }
}

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::dynamicArray(itemsDataType *items, capacityDataType capacity)
{
  this->capacity = capacity;
  this->size = this->capacity;
  this->items = (itemsDataType *)calloc(this->capacity, sizeof (itemsDataType));
  if (!this->items)
  {
    errorMessage("Failed to allocate memory for the dynamic array");
    return;
  }
  for (sizeDataType index = 0; index < this->size; index++)
    this->items[index] = items[index];
}

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::dynamicArray(sizeDataType size, capacityDataType capacity)
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

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::dynamicArray(itemsDataType *items, sizeDataType size, capacityDataType capacity)
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

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::~dynamicArray()
{
  this->capacity = 0;
  this->size = 0;
  free(this->items);
  this->items = NULL;
}

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void dynamicArray<itemsDataType, sizeDataType, capacityDataType>::insert(itemsDataType item, sizeDataType index)
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

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void dynamicArray<itemsDataType, sizeDataType, capacityDataType>::remove(sizeDataType index)
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

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void dynamicArray<itemsDataType, sizeDataType, capacityDataType>::push(itemsDataType item)
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

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
itemsDataType dynamicArray<itemsDataType, sizeDataType, capacityDataType>::at(sizeDataType index)
{
  if (0 <= index && index < this->size)
    return this->items[index];
  else
    errorMessage("Index out of range!");
}

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void dynamicArray<itemsDataType, sizeDataType, capacityDataType>::forEach(void (*forEachFunction)(itemsDataType))
{
  for (sizeDataType index = 0; index < this->size; index++)
    forEachFunction(this->at(index));
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void dynamicArray<itemsDataType, sizeDataType, capacityDataType>::forEach(void (*forEachFunction)(itemsDataType), sizeDataType size)
{
  for (sizeDataType index = 0; index < size && size <= this->size; index++)
    forEachFunction(this->at(index));
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void dynamicArray<itemsDataType, sizeDataType, capacityDataType>::forEach(void (*forEachFunction)(itemsDataType), sizeDataType left, sizeDataType right)
{
  for (; 0 <= left && left < right && right <= this->size; left++)
    forEachFunction(this->at(left));
}

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void dynamicArray<itemsDataType, sizeDataType, capacityDataType>::forEach(void (*forEachFunction)(itemsDataType, sizeDataType))
{
  for (sizeDataType index = 0; index < this->size; index++)
    forEachFunction(this->at(index), index);
}

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void dynamicArray<itemsDataType, sizeDataType, capacityDataType>::forEach(void (*forEachFunction)(itemsDataType, sizeDataType), sizeDataType size)
{
  for (sizeDataType index = 0; index < size && size <= this->size; index++)
    forEachFunction(this->at(index), index);
}

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void dynamicArray<itemsDataType, sizeDataType, capacityDataType>::forEach(void (*forEachFunction)(itemsDataType, sizeDataType), sizeDataType left, sizeDataType right)
{
  for (; 0 <= left && left < right && right <= this->size; left++)
    forEachFunction(this->at(left), left);
}

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void dynamicArray<itemsDataType, sizeDataType, capacityDataType>::forEach(void (*forEachFunction)(itemsDataType, sizeDataType, dynamicArray<itemsDataType, sizeDataType, capacityDataType> *))
{
  for (sizeDataType index = 0; index < this->size; index++)
    forEachFunction(this->at(index), index, this);
}
  
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void dynamicArray<itemsDataType, sizeDataType, capacityDataType>::forEach(void (*forEachFunction)(itemsDataType, sizeDataType, dynamicArray<itemsDataType, sizeDataType, capacityDataType> *), sizeDataType size)
{
  for (sizeDataType index = 0; index < size && size <= this->size; index++)
    forEachFunction(this->at(index), index, this);
}
  
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void dynamicArray<itemsDataType, sizeDataType, capacityDataType>::forEach(void (*forEachFunction)(itemsDataType, sizeDataType, dynamicArray<itemsDataType, sizeDataType, capacityDataType> *), sizeDataType left, sizeDataType right)
{
  for (; 0 <= left && left < right && right <= this->size; left++)
    forEachFunction(this->at(left), left, this);
}

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::filter(bool (*filterFunction)(itemsDataType))
{
  dynamicArray<itemsDataType, sizeDataType, capacityDataType> filteredDynamicArray(0, this->capacity);
  for (sizeDataType index = 0; index < this->size; index++)
    if (filterFunction(this->at(index)))
      filteredDynamicArray->push(this->at(index));
  return filteredDynamicArray;
}

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::filter(bool (*filterFunction)(itemsDataType), sizeDataType size)
{
  dynamicArray<itemsDataType, sizeDataType, capacityDataType> filteredDynamicArray(0,this->capacity);
  for (sizeDataType index = 0; index < size && size <= this->size; index++)
    if (filterFunction(this->at(index)))
      filteredDynamicArray->push(this->at(index));
  return filteredDynamicArray;
}

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::filter(bool (*filterFunction)(itemsDataType), sizeDataType left, sizeDataType right)
{
  dynamicArray<itemsDataType, sizeDataType, capacityDataType> filteredDynamicArray(0, this->capacity);
  for (; 0 <= left && left < right && right <= this->size; left++)
    if (filterFunction(this->at(left)))
      filteredDynamicArray->push(this->at(left));
  return filteredDynamicArray;
}

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::filter(bool (*filterFunction)(itemsDataType,sizeDataType))
{
  dynamicArray<itemsDataType, sizeDataType, capacityDataType>filteredDynamicArray(0,this->capacity);
  for (sizeDataType index = 0; index < this->size; index++)
    if (filterFunction(this->at(index), index))
      filteredDynamicArray->push(this->at(index));
  return filteredDynamicArray;
}

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::filter(bool (*filterFunction)(itemsDataType,sizeDataType), sizeDataType size)
{
  dynamicArray<itemsDataType, sizeDataType, capacityDataType>filteredDynamicArray(0,this->capacity);
  for (sizeDataType index = 0; index < size && size <= this->size; index++)
    if (filterFunction(this->at(index), index))
      filteredDynamicArray->push(this->at(index));
  return filteredDynamicArray;
}
  
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::filter(bool (*filterFunction)(itemsDataType,sizeDataType), sizeDataType left, sizeDataType right)
{
  dynamicArray<itemsDataType, sizeDataType, capacityDataType>filteredDynamicArray(0,this->capacity);
  for (; 0 <= left && left < right && right <= this->size; left++)
    if (filterFunction(this->at(left), left))
      filteredDynamicArray->push(this->at(left));
  return filteredDynamicArray;
}

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::filter(bool (*filterFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType, sizeDataType, capacityDataType> *))
{
  dynamicArray<itemsDataType, sizeDataType, capacityDataType>filteredDynamicArray(0,this->capacity);
  for (sizeDataType index = 0; index < this->size; index++)
    if (filterFunction(this->at(index), index, this))
      filteredDynamicArray->push(this->at(index));
  return filteredDynamicArray;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::filter(bool (*filterFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType, sizeDataType, capacityDataType> *), sizeDataType size)
{
    dynamicArray<itemsDataType, sizeDataType, capacityDataType>filteredDynamicArray(0,this->capacity);
    for (sizeDataType index = 0; index < size && size <= this->size; index++)
      if (filterFunction(this->at(index), index, this))
        filteredDynamicArray->push(this->at(index));
    return filteredDynamicArray;
  }
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::filter(bool (*filterFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType, sizeDataType, capacityDataType> *), sizeDataType left, sizeDataType right)
{
  dynamicArray<itemsDataType, sizeDataType, capacityDataType>filteredDynamicArray(0,this->capacity);
  for (; 0 <= left && left < right && right <= this->size; left++)
    if (filterFunction(this->at(left), left, this))
      filteredDynamicArray->push(this->at(left));
  return filteredDynamicArray;
}

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::every(bool (*everyFunction)(itemsDataType))
{
  bool everyCondition = 1;
  for (sizeDataType index = 0; index < this->size; index++)
    everyCondition &= everyFunction(this->at(index));
  return everyCondition;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::every(bool (*everyFunction)(itemsDataType), sizeDataType size)
{
  bool everyCondition = 1;
  for (sizeDataType index = 0; index < size && size <= this->size; index++)
    everyCondition &= everyFunction(this->at(index));
  return everyCondition;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::every(bool (*everyFunction)(itemsDataType), sizeDataType left, sizeDataType right)
{
  bool everyCondition = 1;
  for (; 0 <= left && left < right && right <= this->size; left++)
    everyCondition &= everyFunction(this->at(left));
  return everyCondition;
}

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::every(bool (*everyFunction)(itemsDataType,sizeDataType))
{
  bool everyCondition = 1;
  for (sizeDataType index = 0; index < this->size; index++)
    everyCondition &= everyFunction(this->at(index), index);
  return everyCondition;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::every(bool (*everyFunction)(itemsDataType,sizeDataType), sizeDataType size)
{
  bool everyCondition = 1;
  for (sizeDataType index = 0; index < size && size <= this->size; index++)
    everyCondition &= everyFunction(this->at(index), index);
  return everyCondition;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::every(bool (*everyFunction)(itemsDataType,sizeDataType), sizeDataType left, sizeDataType right)
{
  bool everyCondition = 1;
  for (; 0 <= left && left < right && right <= this->size; left++)
    everyCondition &= everyFunction(this->at(left), left);
  return everyCondition;
}
  
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::every(bool (*everyFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType, sizeDataType, capacityDataType> *))
{
  bool everyCondition = 1;
  for (sizeDataType index = 0; index < this->size; index++)
    everyCondition &= everyFunction(this->at(index), index, this);
  return everyCondition;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::every(bool (*everyFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType, sizeDataType, capacityDataType> *), sizeDataType size)
{
  bool everyCondition = 1;
  for (sizeDataType index = 0; index < size && size <= this->size; index++)
    everyCondition &= everyFunction(this->at(index), index, this);
  return everyCondition;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::every(bool (*everyFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType, sizeDataType, capacityDataType> *), sizeDataType left, sizeDataType right)
{
  bool everyCondition = 1;
  for (; 0 <= left && left < right && right <= this->size; left++)
    everyCondition &= everyFunction(this->at(left), left, this);
  return everyCondition;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::some(bool (*someFunction)(itemsDataType))
{
  bool someCondition = 0;
  for (sizeDataType index = 0; index < this->size; index++)
    someCondition |= someFunction(this->at(index));
  return someCondition;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::some(bool (*someFunction)(itemsDataType), sizeDataType size)
{
  bool someCondition = 0;
  for (sizeDataType index = 0; index < size && size <= this->size; index++)
    someCondition |= someFunction(this->at(index));
  return someCondition;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::some(bool (*someFunction)(itemsDataType), sizeDataType left, sizeDataType right)
{
  bool someCondition = 0;
  for (; 0 <= left && left < right && right <= this->size; left++)
    someCondition |= someFunction(this->at(left));
  return someCondition;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::some(bool (*someFunction)(itemsDataType,sizeDataType))
{
  bool someCondition = 0;
  for (sizeDataType index = 0; index < this->size; index++)
    someCondition |= someFunction(this->at(index), index);
  return someCondition;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::some(bool (*someFunction)(itemsDataType,sizeDataType), sizeDataType size)
{
  bool someCondition = 0;
  for (sizeDataType index = 0; index < size && size <= this->size; index++)
    someCondition |= someFunction(this->at(index), index);
  return someCondition;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::some(bool (*someFunction)(itemsDataType,sizeDataType), sizeDataType left, sizeDataType right)
{
  bool someCondition = 0;
  for (; 0 <= left && left < right && right <= this->size; left++)
    someCondition |= someFunction(this->at(left), left);
  return someCondition;
}

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::some(bool (*someFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType, sizeDataType, capacityDataType> *))
{
  bool someCondition = 0;
  for (sizeDataType index = 0; index < this->size; index++)
    someCondition |= someFunction(this->at(index), index, this);
  return someCondition;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::some(bool (*someFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType, sizeDataType, capacityDataType> *), sizeDataType size)
{
  bool someCondition = 0;
  for (sizeDataType index = 0; index < size && size <= this->size; index++)
    someCondition |= someFunction(this->at(index), index, this);
  return someCondition;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::some(bool (*someFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType, sizeDataType, capacityDataType> *), sizeDataType left, sizeDataType right)
{
  bool someCondition = 0;
  for (; 0 <= left && left < right && right <= this->size; left++)
    someCondition |= someFunction(this->at(left), left, this);
  return someCondition;
}
//xsome region
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::xsome(bool (*xsomeFunction)(itemsDataType))
{
  bool xsomeCondition = 0;
  for (sizeDataType index = 0; index < this->size; index++)
    xsomeCondition ^= xsomeFunction(this->at(index));
  return xsomeCondition;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::xsome(bool (*xsomeFunction)(itemsDataType), sizeDataType size)
{
  bool xsomeCondition = 0;
  for (sizeDataType index = 0; index < size && size <= this->size; index++)
    xsomeCondition ^= xsomeFunction(this->at(index));
  return xsomeCondition;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::xsome(bool (*xsomeFunction)(itemsDataType), sizeDataType left, sizeDataType right)
{
  bool xsomeCondition = 0;
  for (; 0 <= left && left < right && right <= this->size; left++)
    xsomeCondition ^= xsomeFunction(this->at(left));
  return xsomeCondition;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::xsome(bool (*xsomeFunction)(itemsDataType,sizeDataType))
{
  bool xsomeCondition = 0;
  for (sizeDataType index = 0; index < this->size; index++)
    xsomeCondition ^= xsomeFunction(this->at(index), index);
  return xsomeCondition;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::xsome(bool (*xsomeFunction)(itemsDataType,sizeDataType), sizeDataType size)
{
  bool xsomeCondition = 0;
  for (sizeDataType index = 0; index < size && size <= this->size; index++)
    xsomeCondition ^= xsomeFunction(this->at(index), index);
  return xsomeCondition;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::xsome(bool (*xsomeFunction)(itemsDataType,sizeDataType), sizeDataType left, sizeDataType right)
{
  bool xsomeCondition = 0;
  for (; 0 <= left && left < right && right <= this->size; left++)
    xsomeCondition ^= xsomeFunction(this->at(left), left);
  return xsomeCondition;
}

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::xsome(bool (*xsomeFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType, sizeDataType, capacityDataType> *))
{
  bool xsomeCondition = 0;
  for (sizeDataType index = 0; index < this->size; index++)
    xsomeCondition ^= xsomeFunction(this->at(index), index, this);
  return xsomeCondition;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::xsome(bool (*xsomeFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType, sizeDataType, capacityDataType> *), sizeDataType size)
{
  bool xsomeCondition = 0;
  for (sizeDataType index = 0; index < size && size <= this->size; index++)
    xsomeCondition ^= xsomeFunction(this->at(index), index, this);
  return xsomeCondition;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
bool dynamicArray<itemsDataType, sizeDataType, capacityDataType>::xsome(bool (*xsomeFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType, sizeDataType, capacityDataType> *), sizeDataType left, sizeDataType right)
{
  bool xsomeCondition = 0;
  for (; 0 <= left && left < right && right <= this->size; left++)
    xsomeCondition ^= xsomeFunction(this->at(left), left, this);
  return xsomeCondition;
}

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::map(itemsDataType (*mapFunction)(itemsDataType))
{
  dynamicArray<itemsDataType, sizeDataType, capacityDataType>mapDynamicArray(0,this->capacity);
  for (sizeDataType index = 0; index < this->size; index++)
    mapDynamicArray->push(mapFunction(this->at(index)));
  return mapDynamicArray;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::map(itemsDataType (*mapFunction)(itemsDataType), sizeDataType size)
{
  dynamicArray<itemsDataType, sizeDataType, capacityDataType>mapDynamicArray(0,this->capacity);
  for (sizeDataType index = 0; index < size && size <= this->size; index++)
    mapDynamicArray->push(mapFunction(this->at(index)));
  return mapDynamicArray;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::map(itemsDataType (*mapFunction)(itemsDataType), sizeDataType left, sizeDataType right)
{
  dynamicArray<itemsDataType, sizeDataType, capacityDataType>mapDynamicArray(0,this->capacity);
  for (; 0 <= left && left < right && right <= this->size; left++)
    mapDynamicArray->push(mapFunction(this->at(left)));
  return mapDynamicArray;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::map(itemsDataType (*mapFunction)(itemsDataType,sizeDataType))
{
  dynamicArray<itemsDataType, sizeDataType, capacityDataType>mapDynamicArray(0,this->capacity);
  for (sizeDataType index = 0; index < this->size; index++)
    mapDynamicArray->push(mapFunction(this->at(index), index));
  return mapDynamicArray;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::map(itemsDataType (*mapFunction)(itemsDataType,sizeDataType), sizeDataType size)
{
  dynamicArray<itemsDataType, sizeDataType, capacityDataType>mapDynamicArray(0,this->capacity);
  for (sizeDataType index = 0; index < size && size <= this->size; index++)
    mapDynamicArray->push(mapFunction(this->at(index), index));
  return mapDynamicArray;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::map(itemsDataType (*mapFunction)(itemsDataType,sizeDataType), sizeDataType left, sizeDataType right)
{
  dynamicArray<itemsDataType, sizeDataType, capacityDataType>mapDynamicArray(0,this->capacity);
  for (; 0 <= left && left < right && right <= this->size; left++)
    mapDynamicArray->push(mapFunction(this->at(left), left));
  return mapDynamicArray;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::map(itemsDataType (*mapFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType, sizeDataType, capacityDataType> *))
{
  dynamicArray<itemsDataType, sizeDataType, capacityDataType>mapDynamicArray(0,this->capacity);
  for (sizeDataType index = 0; index < this->size; index++)
    mapDynamicArray->push(mapFunction(this->at(index), index, this));
  return mapDynamicArray;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::map(itemsDataType (*mapFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType, sizeDataType, capacityDataType> *), sizeDataType size)
{
  dynamicArray<itemsDataType, sizeDataType, capacityDataType>mapDynamicArray(0,this->capacity);
  for (sizeDataType index = 0; index < size && size <= this->size; index++)
    mapDynamicArray->push(mapFunction(this->at(index), index, this));
  return mapDynamicArray;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::map(itemsDataType (*mapFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType, sizeDataType, capacityDataType> *), sizeDataType left, sizeDataType right)
{
  dynamicArray<itemsDataType, sizeDataType, capacityDataType>mapDynamicArray(0,this->capacity);
  for (; 0 <= left && left < right && right <= this->size; left++)
    mapDynamicArray->push(mapFunction(this->at(left), left, this));
  return mapDynamicArray;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
template<typename accumulationValueDataType>
accumulationValueDataType
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::reduce(itemsDataType (*reduceFunction)(itemsDataType), accumulationValueDataType accumulationValue)
{
  for (sizeDataType index = 0; index < this->size; index++)
    accumulationValue = reduceFunction(this->at(index));
  return accumulationValue;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
template<typename accumulationValueDataType>
accumulationValueDataType
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::reduce(itemsDataType (*reduceFunction)(itemsDataType), accumulationValueDataType accumulationValue, sizeDataType size)
{
  for (sizeDataType index = 0; index < size && size <= this->size; index++)
    accumulationValue = reduceFunction(this->at(index));
  return accumulationValue;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
template<typename accumulationValueDataType>
accumulationValueDataType
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::reduce(itemsDataType (*reduceFunction)(itemsDataType), accumulationValueDataType accumulationValue, sizeDataType left, sizeDataType right)
{
  for (; 0 <= left && left < right && right <= this->size; left++)
    accumulationValue = reduceFunction(this->at(left));
  return accumulationValue;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
template<typename accumulationValueDataType>
accumulationValueDataType
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::reduce(itemsDataType (*reduceFunction)(itemsDataType,sizeDataType), accumulationValueDataType accumulationValue)
{
  for (sizeDataType index = 0; index < this->size; index++)
    accumulationValue = reduceFunction(this->at(index), index);
  return accumulationValue;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
template<typename accumulationValueDataType>
accumulationValueDataType
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::reduce(itemsDataType (*reduceFunction)(itemsDataType,sizeDataType), accumulationValueDataType accumulationValue, sizeDataType size)
{
  for (sizeDataType index = 0; index < size && size <= this->size; index++)
    accumulationValue = reduceFunction(this->at(index), index);
  return accumulationValue;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
template<typename accumulationValueDataType>
accumulationValueDataType
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::reduce(itemsDataType (*reduceFunction)(itemsDataType,sizeDataType), accumulationValueDataType accumulationValue, sizeDataType left, sizeDataType right)
{
  for (; 0 <= left && left < right && right <= this->size; left++)
    accumulationValue = reduceFunction(this->at(left), left);
  return accumulationValue;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
template<typename accumulationValueDataType>
accumulationValueDataType
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::reduce(itemsDataType (*reduceFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType, sizeDataType, capacityDataType> *), accumulationValueDataType accumulationValue)
{
  for (sizeDataType index = 0; index < this->size; index++)
    accumulationValue = reduceFunction(this->at(index), index, this);
  return accumulationValue;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
template<typename accumulationValueDataType>
accumulationValueDataType
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::reduce(itemsDataType (*reduceFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType, sizeDataType, capacityDataType> *), accumulationValueDataType accumulationValue, sizeDataType size)
{
  for (sizeDataType index = 0; index < size && size <= this->size; index++)
    accumulationValue = reduceFunction(this->at(index), index, this);
  return accumulationValue;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
template<typename accumulationValueDataType>
accumulationValueDataType
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::reduce(itemsDataType (*reduceFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType, sizeDataType, capacityDataType> *), accumulationValueDataType accumulationValue, sizeDataType left, sizeDataType right)
{
  for (; 0 <= left && left < right && right <= this->size; left++)
    accumulationValue = reduceFunction(this->at(left), left, this);
  return accumulationValue;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void dynamicArray<itemsDataType, sizeDataType, capacityDataType>::sort(itemsDataType (*comparisonFunction)(itemsDataType, itemsDataType), sizeDataType left, sizeDataType right)
{
  if (0 <= left && left < right && right <= this->size)
  {
    sizeDataType i = left - 1;
    itemsDataType tmp;
    for (;left < right; left++)
    {
      if (comparisonFunction(this->at(left), this->at(right)) < 0)
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
    this->sort(comparisonFunction, 0, i - 1);
    this->sort(comparisonFunction, i + 1, right);
  }
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void dynamicArray<itemsDataType, sizeDataType, capacityDataType>::reverse()
{
  for (sizeDataType index = 0; index < this->size / 2; index++)
{
    itemsDataType tmp = this->items[index];
    this->items[index] = this->items[this->size - index-1];
    this->items[this->size - index-1] = tmp;
  }
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void dynamicArray<itemsDataType, sizeDataType, capacityDataType>::reverse(sizeDataType size)
{
  for (sizeDataType index = 0; index < size / 2 && size <= this->size; index++)
{
    itemsDataType tmp = this->items[index];
    this->items[index] = this->items[this->size - index - 1];
    this->items[this->size - index - 1]=tmp;
  }
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void dynamicArray<itemsDataType, sizeDataType, capacityDataType>::reverse(sizeDataType left, sizeDataType right)
{
  for(;0 <= left && left < right / 2 && right <= this->size; left++)
{
    itemsDataType tmp = this->items[left];
    this->items[left] = this->items[this->size - left - 1];
    this->items[this->size - left - 1] = tmp;
  }
}

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void dynamicArray<itemsDataType, sizeDataType, capacityDataType>::merge(dynamicArray<itemsDataType, sizeDataType, capacityDataType> *sourceDynamicArray)
{
  for (sizeDataType index = 0; index < this->size; index++)
    this->push(sourceDynamicArray->items[index]);
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void dynamicArray<itemsDataType, sizeDataType, capacityDataType>::merge(dynamicArray<itemsDataType, sizeDataType, capacityDataType> *sourceDynamicArray, sizeDataType size)
{
  for (sizeDataType index = 0; index < size && size <= this->size; index++)
    this->push(sourceDynamicArray->items[index]);
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void dynamicArray<itemsDataType, sizeDataType, capacityDataType>::merge(dynamicArray<itemsDataType, sizeDataType, capacityDataType> *sourceDynamicArray, sizeDataType left, sizeDataType right)
{
  for (; 0 <= left && left < right && right <= this->size; left++)
    this->push(sourceDynamicArray->items[left]);
}

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void dynamicArray<itemsDataType, sizeDataType, capacityDataType>::copy(dynamicArray<itemsDataType, sizeDataType, capacityDataType> *sourceDynamicArray)
{
  for (sizeDataType index = 0; index < this->size; index++)
    this->items[index] = sourceDynamicArray->items[index];
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void dynamicArray<itemsDataType, sizeDataType, capacityDataType>::copy(dynamicArray<itemsDataType, sizeDataType, capacityDataType> *sourceDynamicArray, sizeDataType size)
{
  for (sizeDataType index = 0; index < size && size <= this->size; index++)
    this->items[index] = sourceDynamicArray->items[index];
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void dynamicArray<itemsDataType, sizeDataType, capacityDataType>::copy(dynamicArray<itemsDataType, sizeDataType, capacityDataType> *sourceDynamicArray, sizeDataType left, sizeDataType right)
{
  for (; 0 <= left && left < right && right <= this->size; left++)
    this->items[left] = sourceDynamicArray->items[left];
}

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void dynamicArray<itemsDataType, sizeDataType, capacityDataType>::join(dynamicArray<itemsDataType, sizeDataType, capacityDataType> *sourceDynamicArray)
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
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void dynamicArray<itemsDataType, sizeDataType, capacityDataType>::join(dynamicArray<itemsDataType, sizeDataType, capacityDataType> *sourceDynamicArray, sizeDataType size)
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
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void dynamicArray<itemsDataType, sizeDataType, capacityDataType>::join(dynamicArray<itemsDataType, sizeDataType, capacityDataType> *sourceDynamicArray, sizeDataType left, sizeDataType right)
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

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::intersect(dynamicArray<itemsDataType, sizeDataType, capacityDataType> *sourceDynamicArray)
{
  dynamicArray<itemsDataType, sizeDataType, capacityDataType> resultDynamicArray;
  for (sizeDataType thisIndex = 0; thisIndex < this->size; thisIndex++)
    for (sizeDataType sourceIndex = 0; sourceIndex < sourceDynamicArray->size; sourceIndex++)
      if (sourceDynamicArray->items[sourceIndex] == this->items[thisIndex])
        resultDynamicArray.push(sourceDynamicArray->items[sourceIndex]);
  return resultDynamicArray;
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::intersect(dynamicArray<itemsDataType, sizeDataType, capacityDataType> *sourceDynamicArray, sizeDataType size)
{
  for (sizeDataType index = 0; index < size && size <= this->size; index++)
    this->push(sourceDynamicArray->items[index]);
}
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>
dynamicArray<itemsDataType, sizeDataType, capacityDataType>::intersect(dynamicArray<itemsDataType, sizeDataType, capacityDataType> *sourceDynamicArray, sizeDataType left, sizeDataType right)
{
  for (; 0 <= left && left < right && right <= this->size; left++)
    this->push(sourceDynamicArray->items[left]);
}