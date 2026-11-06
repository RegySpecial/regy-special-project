#ifndef setsHpp
#define setsHpp
/*
*@description Header file where is defined the dynamic array data structure class of the dynamic array data structure library
*@author Regy Special
*@date (First version [Linux/Parrot OS]) 2026 March 7th Saturday, 16:12:08
*@license GNU General Public License to stop private corporation to not share source code
*/
template
<
  typename itemsDataType,
  typename sizeDataType = unsigned long long,
  typename capacityDataType = unsigned long long
>
class set
{
  public:
    typedef set<itemsDataType, sizeDataType, capacityDataType> setSelf;
    
    typedef void (*forEach_callback)(itemsDataType);
    typedef void (*forEach1_callback)(itemsDataType, sizeDataType);
    typedef void (*forEach2_callback)(itemsDataType, sizeDataType, setSelf *);
  
    typedef setSelf (*filter_predicate)(itemsDataType);
    typedef setSelf (*filter1_predicate)(itemsDataType, sizeDataType);
    typedef setSelf (*filter2_predicate)(itemsDataType, sizeDataType, setSelf *);
  
    typedef bool (*logicalPredicate_predicate)(itemsDataType);
    typedef bool (*logicalPredicate1_predicate)(itemsDataType, sizeDataType);
    typedef bool (*logicalPredicate2_predicate)(itemsDataType, sizeDataType, setSelf *);
  
    typedef itemsDataType (*valueModification_callback)(itemsDataType);
    typedef itemsDataType (*valueModification1_callback)(itemsDataType, sizeDataType);
    typedef itemsDataType (*valueModification2_callback)(itemsDataType, sizeDataType, setSelf *);
  
    template <typename accumulationValueDataType>
    using reduce_callback = accumulationValueDataType (*)(accumulationValueDataType, itemsDataType);
    template <typename accumulationValueDataType>
    using reduce1_callback = accumulationValueDataType (*)(accumulationValueDataType, itemsDataType, sizeDataType);
    template <typename accumulationValueDataType>
    using reduce2_callback = accumulationValueDataType (*)(accumulationValueDataType, itemsDataType, sizeDataType, setSelf *);
  
    typedef itemsDataType (*comparisonFunction)(itemsDataType, itemsDataType);
    
    itemsDataType *items = NULL;
    sizeDataType size = 0;
    capacityDataType capacity = 32;
  
    set()
    {
      this->items = (itemsDataType *) calloc(this->capacity, sizeof (itemsDataType));
      if (!this->items)
        return;
    }
  
    set(capacityDataType capacity)
    {
      this->capacity = capacity;
      this->items = (itemsDataType *) calloc(this->capacity, sizeof (itemsDataType));
      if (!this->items)
        return;
    }
  
    set(itemsDataType *items, capacityDataType capacity)
    {
      this->capacity = capacity;
      this->size = this->capacity;
      this->items = (itemsDataType *) calloc(this->capacity, sizeof (itemsDataType));
      if (!this->items)
        return;
      for (sizeDataType index = 0; index < this->size; index++)
        this->items[index] = items[index];
      
      for (sizeDataType i = 0; i < this->size - 1; i++)
        for (sizeDataType j = i + 1; j < this->size;)
          if (this->items[i] == this->items[j])
          {
            for (sizeDataType k = j; k < this->size - 1; k++)
              this->items[k] = this->items[k + 1];
            this->items[this->size - 1] = 0;
            --this->size;
          }
          else
            j++;
    }
    
    set(sizeDataType size, capacityDataType capacity)
    {
      this->size = size;
      this->capacity = capacity;
      this->items = (itemsDataType *) calloc(this->capacity, sizeof (itemsDataType));
      if (!this->items)
        return;

      for (sizeDataType i = 0; i < this->size; i++)
        this->items[i] = i;
    }
    
    set(itemsDataType *items, sizeDataType size, capacityDataType capacity)
    {
      this->capacity = capacity;
      this->size = size;
      this->items = (itemsDataType *) calloc(this->capacity,sizeof (itemsDataType));
      if (!this->items)
        return;
      for (sizeDataType index = 0; index < this->size; index++)
        this->items[index] = items[index];
      
      for (sizeDataType i = 0; i < this->size - 1; i++)
        for (sizeDataType j = i + 1; j < this->size;)
          if (this->items[i] == this->items[j])
          {
            for (sizeDataType k = j; k < this->size - 1; k++)
              this->items[k] = this->items[k + 1];
            this->items[this->size - 1] = 0;
            --this->size;
          }
          else
            j++;
    }
    
    ~set()
    {
      this->capacity = 0;
      this->size = 0;
      free(this->items);
      this->items = NULL;
    }
  
    itemsDataType at(sizeDataType index)
    {
      if (0 <= index && index < this->size)
        return this->items[index];
    }
    
    bool insert(itemsDataType item, sizeDataType index)
    {
      if (index >= this->size)
        return 0;

      bool itemIsAlreadyInTheSet = 0;
      for (sizeDataType i = 0; i < this->size; i++)
        itemIsAlreadyInTheSet |= item == this->items[i];
      if (itemIsAlreadyInTheSet)
        return 0;
    
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
            return 0;
          free(oldItems);
          oldItems = NULL;
        }
      }
      for (sizeDataType i = this->size; i > index; i--)
        this->items[i] = this->at(i - 1);
      this->items[index] = item;
      ++this->size;
      return 1;
    }
    
    bool remove(sizeDataType index)
    {
      if (index >= this->size)
        return 0;
      for (; index < this->size - 1; index++)
        this->items[index] = this->at(index + 1);
      this->items[this->size - 1] = 0;
      --this->size;
      return 1;
    }
    
    bool push(itemsDataType item)
    {
      bool itemIsAlreadyInTheSet = 0;
      for (sizeDataType i = 0; i < this->size; i++)
        itemIsAlreadyInTheSet |= item == this->items[i];
      if (itemIsAlreadyInTheSet)
        return 0;
      
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
            return 0;
          free(oldItems);
          oldItems = NULL;
        }
      }
      this->items[this->size] = item;
      ++this->size;
      return 1;
    }
    
    inline bool pop()
    {
      return this->remove(this->size - 1);
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
    
    setSelf filter(filter_predicate filterFunction)
    {
      setSelf filteredSet(0, this->capacity);
      for (sizeDataType index = 0; index < this->size; index++)
        if (filterFunction(this->at(index)))
          filteredSet->push(this->at(index));
      return filteredSet;
    }
    
    setSelf filter(filter_predicate filterFunction, sizeDataType size)
    {
      setSelf filteredSet;
      for (sizeDataType index = 0; index < size && size <= this->size; index++)
        if (filterFunction(this->at(index)))
          filteredSet->push(this->at(index));
      return filteredSet;
    }
    
    setSelf filter(filter_predicate filterFunction, sizeDataType left, sizeDataType right)
    {
      setSelf filteredSet(0, this->capacity);
      for (; 0 <= left && left < right && right <= this->size; left++)
        if (filterFunction(this->at(left)))
          filteredSet->push(this->at(left));
      return filteredSet;
    }
    
    setSelf filter(filter1_predicate filterFunction)
    {
      setSelf filteredSet;
      for (sizeDataType index = 0; index < this->size; index++)
        if (filterFunction(this->at(index), index))
          filteredSet->push(this->at(index));
      return filteredSet;
    }
    
    setSelf filter(filter1_predicate filterFunction, sizeDataType size)
    {
      setSelf filteredSet;
      for (sizeDataType index = 0; index < size && size <= this->size; index++)
        if (filterFunction(this->at(index), index))
          filteredSet->push(this->at(index));
      return filteredSet;
    }
    
    setSelf filter(filter1_predicate filterFunction, sizeDataType left, sizeDataType right)
    {
      setSelf filteredSet;
      for (; 0 <= left && left < right && right <= this->size; left++)
        if (filterFunction(this->at(left), left))
          filteredSet->push(this->at(left));
      return filteredSet;
    }
    
    setSelf filter(filter2_predicate filterFunction)
    {
      setSelf filteredSet;
      for (sizeDataType index = 0; index < this->size; index++)
        if (filterFunction(this->at(index), index, this))
          filteredSet->push(this->at(index));
      return filteredSet;
    }
    
    setSelf filter(filter2_predicate filterFunction, sizeDataType size)
    {
      setSelf filteredSet;
      for (sizeDataType index = 0; index < size && size <= this->size; index++)
        if (filterFunction(this->at(index), index, this))
          filteredSet->push(this->at(index));
      return filteredSet;
    }
    
    setSelf filter(filter2_predicate filterFunction, sizeDataType left, sizeDataType right)
    {
      setSelf filteredSet;
      for (; 0 <= left && left < right && right <= this->size; left++)
        if (filterFunction(this->at(left), left, this))
          filteredSet->push(this->at(left));
      return filteredSet;
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
    
    setSelf map(valueModification_callback mapFunction)
    {
      setSelf mapSet;
      for (sizeDataType index = 0; index < this->size; index++)
        mapSet->push(mapFunction(this->at(index)));
      return mapSet;
    }
    
    setSelf map(valueModification_callback mapFunction, sizeDataType size)
    {
      setSelf mapSet;
      for (sizeDataType index = 0; index < size && size <= this->size; index++)
        mapSet->push(mapFunction(this->at(index)));
      return mapSet;
    }
    
    setSelf map(valueModification_callback mapFunction, sizeDataType left, sizeDataType right)
    {
      setSelf mapSet;
      for (; 0 <= left && left < right && right <= this->size; left++)
        mapSet->push(mapFunction(this->at(left)));
      return mapSet;
    }
    
    setSelf map(valueModification1_callback mapFunction)
    {
      setSelf mapSet;
      for (sizeDataType index = 0; index < this->size; index++)
        mapSet->push(mapFunction(this->at(index), index));
      return mapSet;
    }
    
    setSelf map(valueModification1_callback mapFunction, sizeDataType size)
    {
      setSelf mapSet;
      for (sizeDataType index = 0; index < size && size <= this->size; index++)
        mapSet->push(mapFunction(this->at(index), index));
      return mapSet;
    }
    
    setSelf map(valueModification1_callback mapFunction, sizeDataType left, sizeDataType right)
    {
      setSelf mapSet;
      for (; 0 <= left && left < right && right <= this->size; left++)
        mapSet->push(mapFunction(this->at(left), left));
      return mapSet;
    }
    
    setSelf map(valueModification2_callback mapFunction)
    {
      setSelf mapSet;
      for (sizeDataType index = 0; index < this->size; index++)
        mapSet->push(mapFunction(this->at(index), index, this));
      return mapSet;
    }
    
    setSelf map(valueModification2_callback mapFunction, sizeDataType size)
    {
      setSelf mapSet;
      for (sizeDataType index = 0; index < size && size <= this->size; index++)
        mapSet->push(mapFunction(this->at(index), index, this));
      return mapSet;
    }
    
    setSelf map(valueModification2_callback mapFunction, sizeDataType left, sizeDataType right)
    {
      setSelf mapSet;
      for (; 0 <= left && left < right && right <= this->size; left++)
        mapSet->push(mapFunction(this->at(left), left, this));
      return mapSet;
    }
    
    template <typename accumulationValueDataType>
    accumulationValueDataType reduce(reduce_callback<accumulationValueDataType> reductionFunction, accumulationValueDataType accumulationValue)
    {
      for (sizeDataType index = 0; index < this->size; index++)
        accumulationValue = reductionFunction(this->at(index));
      return accumulationValue;
    }
    
    template <typename accumulationValueDataType>
    accumulationValueDataType reduce(reduce_callback<accumulationValueDataType> reductionFunction, sizeDataType size, accumulationValueDataType accumulationValue)
    {
      for (sizeDataType index = 0; index < size && size <= this->size; index++)
        accumulationValue = reductionFunction(this->at(index));
      return accumulationValue;
    }
    
    template <typename accumulationValueDataType>
    accumulationValueDataType reduce(reduce_callback<accumulationValueDataType> reductionFunction, sizeDataType left, sizeDataType right, accumulationValueDataType accumulationValue)
    {
      for (; 0 <= left && left < right && right <= this->size; left++)
        accumulationValue = reductionFunction(this->at(left));
      return accumulationValue;
    }
    
    template <typename accumulationValueDataType>
    accumulationValueDataType reduce(reduce1_callback<accumulationValueDataType> reductionFunction, accumulationValueDataType accumulationValue)
    {
      for (sizeDataType index = 0; index < this->size; index++)
        accumulationValue = reductionFunction(this->at(index), index);
      return accumulationValue;
    }
    
    template <typename accumulationValueDataType>
    accumulationValueDataType reduce(reduce1_callback<accumulationValueDataType> reductionFunction, sizeDataType size, accumulationValueDataType accumulationValue)
    {
      for (sizeDataType index = 0; index < size && size <= this->size; index++)
        accumulationValue = reductionFunction(this->at(index), index);
      return accumulationValue;
    }
    
    template <typename accumulationValueDataType>
    accumulationValueDataType reduce(reduce1_callback<accumulationValueDataType> reductionFunction, sizeDataType left, sizeDataType right, accumulationValueDataType accumulationValue)
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
    accumulationValueDataType reduce(reduce2_callback<accumulationValueDataType> reductionFunction, sizeDataType size, accumulationValueDataType accumulationValue)
    {
      for (sizeDataType index = 0; index < size && size <= this->size; index++)
        accumulationValue = reductionFunction(this->at(index), index, this);
      return accumulationValue;
    }
    
    template <typename accumulationValueDataType>
    accumulationValueDataType reduce(reduce2_callback<accumulationValueDataType> reductionFunction, sizeDataType left, sizeDataType right, accumulationValueDataType accumulationValue)
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
            tmp = this->at(i);
            this->items[i] = this->at(left);
            this->items[left] = tmp;
          }
        }
        i++;
        tmp = this->at(i);
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
        itemsDataType tmp = this->at(index);
        this->items[index] = this->at(this->size - index - 1);
        this->items[this->size - index-1] = tmp;
      }
    }
    
    void reverse(sizeDataType size)
    {
      for (sizeDataType index = 0; index < size / 2 && size <= this->size; index++)
      {
        itemsDataType tmp = this->at(index);
        this->items[index] = this->at(this->size - index - 1);
        this->items[this->size - index - 1] = tmp;
      }
    }
    
    void reverse(sizeDataType left, sizeDataType right)
    {
      for (;0 <= left && left < right / 2 && right <= this->size; left++)
      {
        itemsDataType tmp = this->at(left);
        this->items[left] = this->items[this->size - left - 1];
        this->items[this->size - left - 1] = tmp;
      }
    }
    
    void copy(setSelf *sourceSet)
    {
      for (sizeDataType index = 0; index < this->size && index < sourceSet->size; index++)
        this->items[index] = sourceSet->at(index);
    }
    
    void copy(setSelf *sourceSet, sizeDataType size)
    {
      for (sizeDataType index = 0; index < size && size <= this->size && size <= sourceSet->size; index++)
        this->items[index] = sourceSet->at(index);
    }
    
    void copy(setSelf *sourceSet, sizeDataType left, sizeDataType right)
    {
      for (; 0 <= left && left < right && right <= this->size && right <= sourceSet->size; left++)
        this->items[left] = sourceSet->at(left);
    }
    
    setSelf join(setSelf *sourceSet)
    {
      setSelf returnSet(this->items, this->size, this->capacity);

      for (sizeDataType sourceSetIndex = 0; sourceSetIndex < sourceSet->size; sourceSetIndex++)
      {
        bool itemIsNotInTheSet = 1;
        for (sizeDataType returnSetIndex = 0; returnSetIndex < returnSet.size; returnSetIndex++)
          itemIsNotInTheSet &= sourceSet->at(sourceSetIndex) != returnSet.at(returnSetIndex);
        
        if (itemIsNotInTheSet)
          returnSet.push(sourceSet->at(sourceSetIndex));
      }
      
      return returnSet;
    }
    
    setSelf join(setSelf *sourceSet, sizeDataType size)
    {
      setSelf returnSet(this->items, this->size, this->capacity);

      for (sizeDataType sourceSetIndex = 0; sourceSetIndex < size && size <= sourceSet->size; sourceSetIndex++)
      {
        bool itemIsNotInTheSet = 1;
        for (sizeDataType returnSetIndex = 0; returnSetIndex < returnSet.size; returnSetIndex++)
          itemIsNotInTheSet &= sourceSet->at(sourceSetIndex) != returnSet.at(returnSetIndex);
        
        if (itemIsNotInTheSet)
          returnSet.push(sourceSet->at(sourceSetIndex));
      }
      
      return returnSet;
    }
    
    setSelf join(setSelf *sourceSet, sizeDataType left, sizeDataType right)
    {
      setSelf returnSet(this->items, this->size, this->capacity);

      for (; 0 <= left && left < right && right <= sourceSet->size; left++)
      {
        bool itemIsNotInTheSet = 1;
        for (sizeDataType returnSetIndex = 0; returnSetIndex < returnSet.size; returnSetIndex++)
          itemIsNotInTheSet &= sourceSet->at(left) != returnSet.at(returnSetIndex);
        
        if (itemIsNotInTheSet)
          returnSet.push(sourceSet->at(left));
      }
      
      return returnSet;
    }
    
    setSelf intersect(setSelf *sourceSet)
    {
      setSelf returnSet;

      for (sizeDataType sourceSetIndex = 0; sourceSetIndex < sourceSet->size; sourceSetIndex++)
      {
        bool itemIsInTheSet = 0;
        for (sizeDataType thisIndex = 0; thisIndex < returnSet.size; thisIndex++)
          itemIsNotInTheSet |= sourceSet->at(sourceSetIndex) == this->at(thisIndex);
        
        if (itemIsInTheSet)
          returnSet.push(sourceSet->at(sourceSetIndex));
      }
      
      return returnSet;
    }
    
    setSelf intersect(setSelf *sourceSet, sizeDataType size)
    {
      setSelf returnSet;

      for (sizeDataType sourceSetIndex = 0; sourceSetIndex < size && size sourceSet->size; sourceSetIndex++)
      {
        bool itemIsInTheSet = 0;
        for (sizeDataType returnSetIndex = 0; returnSetIndex < returnSet.size; returnSetIndex++)
          itemIsNotInTheSet |= sourceSet->at(sourceSetIndex) == returnSet.at(returnSetIndex);
        
        if (itemIsInTheSet)
          returnSet.push(sourceSet->at(sourceSetIndex));
      }
      
      return returnSet;
    }
    
    setSelf intersect(setSelf *sourceSet, sizeDataType left, sizeDataType right)
    {
      setSelf returnSet;

      for (; 0 <= left && left < right && right <= sourceSet->size; left++)
      {
        bool itemIsInTheSet = 0;
        for (sizeDataType returnSetIndex = 0; returnSetIndex < returnSet.size; returnSetIndex++)
          itemIsNotInTheSet |= sourceSet->at(left) == returnSet.at(returnSetIndex);
        
        if (itemIsInTheSet)
          returnSet.push(sourceSet->at(left));
      }
      
      return returnSet;
    }
  
    setSelf discrimate(setSelf *sourceSet)
    {
      setSelf returnSet = this->join(sourceSet),
              intersectionSet = this->intersect(sourceSet);

      for (sizeDataType intersectionSetIndex = 0; intersectionSetIndex < intersectionSet.size; intersectionSetIndex++)
        for (sizeDataType returnSetIndex = 0; returnSetIndex < returnSet.size; returnSetIndex++)
          if (intersectionSet.at(intersectionSetIndex) == returnSet.at(returnSetIndex))
            returnSet.remove(returnSetIndex)
      return returnSet;
    }
    
    setSelf discrimate(setSelf *sourceSet, sizeDataType size)
    {
      setSelf returnSet;
      for (sizeDataType thisIndex = 0; thisIndex < size && size <= this->size; thisIndex++)
        for (sizeDataType sourceIndex = 0; sourceIndex < size && size <= sourceSet->size; sourceIndex++)
          if (sourceSet->at(sourceIndex) == this->at(thisIndex))
            returnSet.push(sourceSet->at(sourceIndex));
      
      for (sizeDataType i = 0; i < returnSet.size - 1; i++)
        for (sizeDataType j = i + 1; j < returnSet.size;)
          if (returnSet.at(i) == returnSet.at(j))
            returnSet.remove(j);
          else
            j++;
      
      return returnSet;
    }
    
    setSelf discrimate(setSelf *sourceSet, sizeDataType left, sizeDataType right)
    {
      setSelf returnSet;
      for (sizeDataType thisIndex = left; 0 <= thisIndex && thisIndex < right && right <= this->size; thisIndex++)
        for (; 0 <= left && left < right && right <= sourceSet->size; sourceIndex++)
          if (sourceSet->at(left) == this->at(thisIndex))
            returnSet.push(sourceSet->at(sourceIndex));
  
      for (sizeDataType i = 0; i < returnSet.size - 1; i++)
        for (sizeDataType j = i + 1; j < returnSet.size;)
          if (returnSet.at(i) == returnSet.at(j))
            returnSet.remove(j);
          else
            j++;
      
      return returnSet;
    }
};
#endif