#include<stdlib.h>
template<
  typename key,
  typename value
>
struct hashTableItems{
  key key;
  value value;
  struct hashTableItems<key,value>*next;
};

template<
  typename keyDataType,
  typename valueDataType,
  typename capacityDataType=unsigned long
>
class hashTable{
public:
  struct hashTableItems<keyDataType,valueDataType>**items;
  capacityDataType capacity;
  static unsigned long long hash(keyDataType key){
    unsigned long long hash=0;
    for(unsigned long long i=0;key+i!=0;i++)hash+=31*key[i]
    return hash%this->capacity;
  }
  hashTable(hashTableItems<keyDataType,valueDataType>*items,capacityDataType capacity){
    this->items=(hashTableItems<keyDataType,valueDataType>*)malloc(sizeof(hashTableItems<keyDataType,valueDataType>)*capacity);
    for(capacityDataType index=0;index<capacity;index++){
      if(this->items[hashTable::hash(index)]){
        this->items[hashTable::hash(index)].next=NULL;
      }else{
        this->items[hashTable::hash(index)]=items[hashTable::hash(index)];
      }
    }
  }
  inline valueDataType operator[](keyDataType key){
    return this->next[hashTable::hash(key)];
  }
  void insert(keyDataType key,valueDataType value){
    if(this->items[hashTable::hash(key)]){

    }else{
      this->items[hashTable::hash(key)].key=key;
      this->items[hashTable::hash(key)].value=value;
      this->items[hashTable::hash(key)].next=NULL;
    }
  }
  ~hashTable(){
    free(this->items);
    this->items=NULL;
  }
};