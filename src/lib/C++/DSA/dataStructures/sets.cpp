/*
*@description Header file where is defined the dynamic array data structure class of the dynamic array data structure library
*@author Regy Special
*@date (First version [Linux/Parrot OS]) 2026 March 7th Saturday, 16:12:08
*@license GNU General Public License to stop private corporation to not share source code
*/
#include "../../../../include/lib/c++/DSA/dataStructures/sets.hpp"

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
set<itemsDataType, sizeDataType, capacityDataType>::set()
: dynamicArray<itemsDataType, sizeDataType, capacityDataType>::dynamicArray()
{
  this->items = (itemsDataType *) calloc(this->capacity, sizeof (itemsDataType));
  if (!this->items)
  {
    failureMessage("Failed to reallocate memory for the dynamic set");
    return;
  }
}
  
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
set<itemsDataType, sizeDataType, capacityDataType>::set(capacityDataType capacity)
: dynamicArray<itemsDataType, sizeDataType, capacityDataType>::dynamicArray(capacity)
{
  this->capacity = capacity;
  this->items = (itemsDataType *) calloc(this->capacity, sizeof (itemsDataType));
  if (!this->items)
  {
    failureMessage("Failed to reallocate memory for the dynamic set");
    return;
  }
}

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
set<itemsDataType, sizeDataType, capacityDataType>::set(itemsDataType *items, capacityDataType capacity)
: dynamicArray<itemsDataType, sizeDataType, capacityDataType>::dynamicArray(items, capacity)
{
  this->capacity = capacity;
  this->size = this->capacity;
  this->items = (itemsDataType *) calloc(this->capacity, sizeof (itemsDataType));
  if (!this->items)
  {
    failureMessage("Failed to allocate memory for the dynamic set");
    return;
  }

  for (sizeDataType index = 0; index < this->size - 1; index++)
    for (sizeDataType subIndex = index + 1; subIndex < this->size; subIndex++)
      if (items[index] == items[subIndex])
      {
        for (sizeDataType remotionIndex = subIndex; remotionIndex < this->size - 1; remotionIndex++)
          items[remotionIndex] = items[remotionIndex + 1];
        --this->size;
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
set<itemsDataType, sizeDataType, capacityDataType>::set(sizeDataType size, capacityDataType capacity)
: dynamicArray<itemsDataType, sizeDataType, capacityDataType>::dynamicArray(size, capacity)
{
  this->size = size;
  this->capacity = capacity;
  this->items = (itemsDataType *) calloc(this->capacity, sizeof (itemsDataType));
  if (!this->items)
  {
    failureMessage("Failed to allocate memory for the dynamic array");
    return;
  }
}

template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
set<itemsDataType, sizeDataType, capacityDataType>::set(itemsDataType *items, sizeDataType size, capacityDataType capacity)
: dynamicArray<itemsDataType, sizeDataType, capacityDataType>::dynamicArray(items, size, capacity)
{
  this->capacity = capacity;
  this->size = size;
  this->items = (itemsDataType *) calloc(this->capacity, sizeof (itemsDataType));
  if (!this->items)
  {
    failureMessage("Failed to allocate memory for the dynamic array");
    return;
  }

  for (sizeDataType index = 0; index < this->size - 1; index++)
    for (sizeDataType subIndex = index + 1; subIndex < this->size; subIndex++)
      if (items[index] == items[subIndex])
      {
        for (sizeDataType remotionIndex = subIndex; remotionIndex < this->size - 1; remotionIndex++)
          items[remotionIndex] = items[remotionIndex + 1];
        --this->size;
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
void set<itemsDataType, sizeDataType, capacityDataType>::insert(itemsDataType item, sizeDataType index)
{
  if (index >= this->size)
  {
    failureMessage("Index out of range");
    return;
  }

  bool itemAlreadyInTheSet = 0;
  for (sizeDataType index = 0; index < this->size; index++)
    itemNotInTheSet |= item == this->items[index];
  
  if (itemAlreadyInTheSet)
  {
    failureMessage("Cannot push the element because is already in the set");
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
      this->items = (itemsDataType *) calloc(this->capacity,sizeof (itemsDataType));
      if (!this->items)
      {
        failureMessage("Failed to reallocate memory for the dynamic array");
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
void set<itemsDataType, sizeDataType, capacityDataType>::remove(sizeDataType index)
{
  if (index < this->size)
  {
    for (; index < this->size; index++)
      this->items[index] = this->items[index + 1];
    --this->size;
  }
  else
    failureMessage("Index out of range!");
}
  
template
<
  typename itemsDataType,
  typename sizeDataType,
  typename capacityDataType
>
void set<itemsDataType, sizeDataType, capacityDataType>::push(itemsDataType item)
{
  bool itemAlreadyInTheSet = 0;
  for (sizeDataType index = 0; index < this->size; index++)
    itemNotInTheSet |= item == this->items[index];
  
  if (itemAlreadyInTheSet)
  {
    failureMessage("Cannot push the element because is already in the set");
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
      this->items = (itemsDataType *) calloc(this->capacity,sizeof (itemsDataType));
      if (!this->items)
      {
        failureMessage("Failed to reallocate memory for the dynamic array");
        return;
      }
      free(oldItems);
      oldItems = NULL;
    }
  }
  this->items[this->size] = item;
  ++this->size;
}