/*
*@description Header file where is defined the dynamic array data structure class of the dynamic array data structure library
*@author Regy Special
*@date (First version [Linux/Parrot OS]) 2026 March 7th Saturday, 16:12:08
*@license GNU General Public License to stop private corporation to not share source code
*/
#ifndef dynamicArraysHpp
#define dynamicArraysHpp
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
template<
  typename itemsDataType,
  typename sizeDataType=unsigned long,
  typename capacityDataType=unsigned long
>
class dynamicArray{
public:
  itemsDataType*items=NULL;
  sizeDataType size=0;
  capacityDataType capacity=32;
  inline itemsDataType operator[](sizeDataType index){
    return*(this->items+index);
  }
  inline itemsDataType at(sizeDataType index){
    return*(this->items+index);
  }
  void insert(itemsDataType item,sizeDataType index){
    if(index<this->size){
      if(this->size==this->capacity){
        this->capacity*=2;
        itemsDataType*oldItems=this->items;
        this->items=(itemsDataType*)malloc(sizeof(itemsDataType)*this->capacity);
        if(this->items==NULL){
          perror("Failed to reallocate memory for the dynamic array");
          return;
        }
        free(oldItems);
        oldItems=NULL;
      }
      for(unsigned int i=this->size;i>index;i--)
        this[i]=this[i-1];
      this->items[index]=item;
      this->size+=1;
    }else{
      perror("Index of out range");
      return;
    }
  }
  void remove(sizeDataType index){
    if(index<this->size){
      for(;index<this->size;index++)
        this->items[index]=this[index+1];
      this->size-=1;
    }
  }
  inline void push(itemsDataType item){
    this->insert(item,this->size);
  }
  inline void pop(){
    this->remove(this->size-1);
  }
  dynamicArray(){
    this->size=0;
    this->capacity=32;
    this->items=(itemsDataType*)calloc(this->capacity,sizeof(itemsDataType));
    if(this->items==NULL)
      perror("Failed to allocate memory for the dynamic array");
  }
  dynamicArray(itemsDataType items,capacityDataType capacity){
    this->size=(this->capacity=capacity);
    this->items=(itemsDataType*)calloc(this->capacity,sizeof(itemsDataType));
    if(this->items==NULL)
      perror("Failed to allocate memory for the dynamic array");
    else for(sizeDataType index=0;index<this->size;index++)
      this->items[index]=items[index];
  }
  dynamicArray(itemsDataType items,sizeDataType size,capacityDataType capacity){
    this->capacity=capacity;
    this->size=size;
    this->items=(itemsDataType*)malloc(sizeof(itemsDataType)*this->capacity);
    if(this->items==NULL)
      perror("Failed to allocate memory for the dynamic array");
    else for(sizeDataType index=0;index<this->size;index++)
      this->items[index]=items[index];
  }
  dynamicArray(capacityDataType capacity){
    this->size=0;
    this->capacity=capacity;
    this->items=(itemsDataType*)calloc(this->capacity,sizeof(itemsDataType));
    if(this->items==NULL)
      perror("Failed to allocate memory for the dynamic array");
  }
  dynamicArray(sizeDataType size,capacityDataType capacity){
    this->size=size;
    this->capacity=capacity;
    this->items=(itemsDataType*)malloc(sizeof(itemsDataType)*this->capacity);
    if(this->items==NULL)
      perror("Failed to reallocate memory for the dynamic array");
    else for(sizeDataType index=0;index<this->size;index++)
      this->items[index]=0;
  }
  //do an action for each element
  void forEach(void(*forEachFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*)){
    for(sizeDataType index=0;index<this->size;index++)forEachFunction(this->items[index],index,this);
  }
  //dynamicArray::foreach 1st overload
  void forEach(void(*forEachFunction)(itemsDataType,sizeDataType)){
    for(sizeDataType index=0;index<this->size;index++)forEachFunction(this->items[index],index);
  }
  //dynamicArray::foreach 2st overload
  void forEach(void(*forEachFunction)(itemsDataType)){
    for(sizeDataType index=0;index<this->size;index++)forEachFunction(this->items[index]);
  }
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>filter(bool(*filterFunction)(itemsDataType,sizeDataType,dynamicArray<itemsDataType,sizeDataType,capacityDataType>*)){
    dynamicArray<itemsDataType,sizeDataType,capacityDataType>filteredDynamicArray(0,5);
    for(sizeDataType index=0;index<this->size;index++)
      if(filterFunction(this->items[index],index,this)==1)
        filteredDynamicArray.push(this->items[index]);
  }
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>filter(bool(*filterFunction)(itemsDataType,unsigned int)){
    dynamicArray<itemsDataType,sizeDataType,capacityDataType>filteredDynamicArray(0,5);
    for(sizeDataType index=0;index<this->size;index++)
      if(filterFunction(this->items[index],index)==1)
        filteredDynamicArray.push(this->items[index]);
  }
  dynamicArray<itemsDataType,sizeDataType,capacityDataType>filter(bool(*filterFunction)(itemsDataType)){
    dynamicArray<itemsDataType,sizeDataType,capacityDataType>filteredDynamicArray(0,5);
    for(sizeDataType index=0;index<this->size;index++)
      if(filterFunction(this->items[index])==1)
        filteredDynamicArray.push(this->items[index]);
  }
  void sort(unsigned int left,unsigned int right,int(*comparisonFunction)(itemsDataType,itemsDataType)){
    if(left<right){
      int j=left,i=j-1,pivot=right;
      itemsDataType temp;
      for(;j<pivot;j++){
        if(comparisonFunction(this[j],this[pivot])<0){
          i+=1;
          temp=this[i];
          this[i]=this[j];
          this[j]=temp;
        }
      }
      i+=1;
      temp=this[i];
      this[i]=this[pivot];
      this[pivot]=this[i];
      this->sort(0,i-1,comparisonFunction);
      this->sort(i+1,right,comparisonFunction);
    }
  }
  void reverse(){
    for(sizeDataType index=0;index<this->size/2;index++){
      itemsDataType tmp=this->items[index];
      this->items[index]=this[this->size-index-1];
      this[this->size-index-1]=tmp;
    }
  }
  dynamicArray<itemsDataType,sizeDataType,capacityDataType> join(dynamicArray<itemsDataType,sizeDataType,capacityDataType>*sourceDynamicArray){
    sourceDynamicArray->forEach([this](itemsDataType item){
      this->push(item);//do not change, it prevents risk of method overload undefined behavior!
    });
    return this;
  }
  dynamicArray<itemsDataType,sizeDataType,capacityDataType> copy(dynamicArray<itemsDataType,sizeDataType,capacityDataType>*sourceDynamicArray){
    sourceDynamicArray->forEach([this](itemsDataType item,sizeDataType index){
      this->items[index]=item;
    });
    return this;
  }
  dynamicArray<itemsDataType,sizeDataType,capacityDataType> njoin(dynamicArray<itemsDataType,sizeDataType,capacityDataType>*sourceDynamicArray){
    sourceDynamicArray->forEach([this](itemsDataType item){
      this->push(item);//do not change, it prevents risk of method overload undefined behavior!
    });
    return this;
  }
  dynamicArray<itemsDataType,sizeDataType,capacityDataType> ncopy(dynamicArray<itemsDataType,sizeDataType,capacityDataType>*sourceDynamicArray){
    sourceDynamicArray->forEach([this](itemsDataType item,sizeDataType index){
      this->items[index]=item;
    });
    return this;
  }
  ~dynamicArray(){
    free(this->items);
    this->items=NULL;
  }
};
#endif