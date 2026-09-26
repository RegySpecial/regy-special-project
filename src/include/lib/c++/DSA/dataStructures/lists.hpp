/*
*@description Header file where is defined the dynamic array data structure class of the dynamic array data structure library
*@author Regy Special
*@date (First version [Linux/Parrot OS]) sab 7 mar 2026, 16:12:08 | 2026 March 7th Saturday, 16:12:08
*@license GNU General Public License to stop private corporation to not share source code
*/
#ifndef listsHpp
#define listsHpp
#include <stdlib.h>
template<typename dataType>
class linkedList{
public:
  dataType value;
  linkedList *next;

  linkedList(dataType value)
  {
    this->value = value;
    this->next = NULL;
  }

  void forEach(void(*callbackFunction)(dataType))
  {
    for (linkedList<dataType> *node = this; node; node = node->next)
      callbackFunction(node->value);
  }

  template<typename sizeDataType = unsigned long long>
  void forEach(void(*callbackFunction)(dataType), sizeDataType size)
  {
    sizeDataType index = 0;
    for (linkedList<dataType> *node = this; node && index < size; node = node->next, index++)
      callbackFunction(node->value);
  }

  template<typename sizeDataType = unsigned long long>
  void forEach(void(*callbackFunction)(dataType), sizeDataType left, sizeDataType right)
  {
    for (linkedList<dataType> *node = this; node && 0 <= left && left < right; node = node->next, left++)
      callbackFunction(node->value);
  }

  template<typename sizeDataType = unsigned long long>
  void forEach(void(*callbackFunction)(dataType, sizeDataType))
  {
    sizeDataType index = 0;
    for (linkedList<dataType> *node = this; node; node = node->next, index++)
      callbackFunction(node->value, index);
  }

  template<typename sizeDataType = unsigned long long>
  void forEach(void(*callbackFunction)(dataType, sizeDataType), sizeDataType size)
  {
    sizeDataType index = 0;
    for (linkedList<dataType> *node = this; node && index < size; node = node->next, index++)
      callbackFunction(node->value, index);
  }

  template<typename sizeDataType = unsigned long long>
  void forEach(void(*callbackFunction)(dataType, sizeDataType), sizeDataType left, sizeDataType right)
  {
    for (linkedList<dataType> *node = this; node && 0 <= left && left < right; node = node->next, left++)
      callbackFunction(node->value, left);
  }

  template<typename sizeDataType = unsigned long long>
  void forEach(void(*callbackFunction)(dataType, sizeDataType, linkedList<dataType> *))
  {
    sizeDataType index = 0;
    for (linkedList<dataType> *node = this; node; node = node->next, index++)
      callbackFunction(node->value, index, this);
  }

  template<typename sizeDataType = unsigned long long>
  void forEach(void(*callbackFunction)(dataType, sizeDataType, linkedList<dataType> *), sizeDataType size)
  {
    sizeDataType index = 0;
    for (linkedList<dataType> *node = this; node && index < size; node = node->next, index++)
      callbackFunction(node->value, index, this);
  }

  template<typename sizeDataType = unsigned long long>
  void forEach(void(*callbackFunction)(dataType, sizeDataType, linkedList<dataType> *), sizeDataType left, sizeDataType right)
  {
    for (linkedList<dataType> *node = this; node && 0 <= left && left < right; node = node->next, left++)
      callbackFunction(node->value, index, this);
  }

  //filter

  linkedList<dataType> filter(void(*filterFunction)(dataType))
  {
    linkedList<dataType> filterLinkedList;

    for (linkedList<dataType> *node = this; node; node = node->next)
      if (filterFunction(node->value))
      {
        filterLinkedList->value = node->value;
        filterLinkedList->next = node->next;
      }
  }

  template<typename sizeDataType = unsigned long long>
  void filter(void(*callbackFunction)(dataType), sizeDataType size)
  {
    sizeDataType index = 0;
    for (linkedList<dataType> *node = this; node && index < size; node = node->next, index++)
      callbackFunction(node->value);
  }

  template<typename sizeDataType = unsigned long long>
  void filter(void(*callbackFunction)(dataType), sizeDataType left, sizeDataType right)
  {
    for (linkedList<dataType> *node = this; node && 0 <= left && left < right; node = node->next, left++)
      callbackFunction(node->value);
  }

  template<typename sizeDataType = unsigned long long>
  void filter(void(*callbackFunction)(dataType, sizeDataType))
  {
    sizeDataType index = 0;
    for (linkedList<dataType> *node = this; node; node = node->next, index++)
      callbackFunction(node->value, index);
  }

  template<typename sizeDataType = unsigned long long>
  void filter(void(*callbackFunction)(dataType, sizeDataType), sizeDataType size)
  {
    sizeDataType index = 0;
    for (linkedList<dataType> *node = this; node && index < size; node = node->next, index++)
      callbackFunction(node->value, index);
  }

  template<typename sizeDataType = unsigned long long>
  void filter(void(*callbackFunction)(dataType, sizeDataType), sizeDataType left, sizeDataType right)
  {
    for (linkedList<dataType> *node = this; node && 0 <= left && left < right; node = node->next, left++)
      callbackFunction(node->value, left);
  }

  template<typename sizeDataType = unsigned long long>
  void filter(void(*callbackFunction)(dataType, sizeDataType, linkedList<dataType> *))
  {
    sizeDataType index = 0;
    for (linkedList<dataType> *node = this; node; node = node->next, index++)
      callbackFunction(node->value, index, this);
  }

  template<typename sizeDataType = unsigned long long>
  void filter(void(*callbackFunction)(dataType, sizeDataType, linkedList<dataType> *), sizeDataType size)
  {
    sizeDataType index = 0;
    for (linkedList<dataType> *node = this; node && index < size; node = node->next, index++)
      callbackFunction(node->value, index, this);
  }

  template<typename sizeDataType = unsigned long long>
  void filter(void(*callbackFunction)(dataType, sizeDataType, linkedList<dataType> *), sizeDataType left, sizeDataType right)
  {
    for (linkedList<dataType> *node = this; node && 0 <= left && left < right; node = node->next, left++)
      callbackFunction(node->value, index, this);
  }

  template<typename indexDataType = unsigned long long>
  dataType at(indexDataType index)
  {
    this->forEach([&](dataType item, indexDataType i,linkedList<dataType> *original){
      if(i == index)
        return item;
    });
  }

  void push(dataType value){
    linkedList<dataType> newNode(value);
    this->next = &newNode;
  }

  void pop(){
    this->value = 0;
    this->next = NULL;
  }

  void insert(dataType value,unsigned long long position){
    if(position==1)this->push(value);
    linkedList<dataType>newNode(value);
    for(unsigned int index=0;index<position;index++){
      if(index==position)
        this->next = &newNode;
    }
  }
  char remove(dataType value){
    linkedList<dataType>newNode(value);
    this->next=&newNode;
    return &newNode!=NULL;
  }

  ~linkedList(){
    this->value = 0;
    this->next = NULL;
  }
};

template<typename dataType>
class doubleLinkedList{
public:
  dataType value;
  doubleLinkedList
    *prev,
    *next;
  
  linkedList(dataType value){
    this->value=value;
    this->next=NULL;
    this->prev=NULL;
  }

  void forEach(void(*callbackFunction)(dataType,unsigned int)){
    unsigned long nodeIndex=0;
    for(linkedList*head=this->node;head!=NULL;nodeIndex++){
      callback(*head,nodeIndex);
      head=head->node;
    }
  }
  linkedList<dataType>filter(unsigned char(*filterFunction)(dataType,unsigned int)){
    linkedList filterLinkedList;
    this->forEach([&](dataType element,unsigned int index){
      if(filterFunction(element,index)>0)filterLinkedList.add(head->value,nodeIndex);
    });
  }
  linkedList<dataType>push(dataType value){
    linkedList<dataType>newNode(value);
    this->node=&newNode;
    return newNode;
  }
  linkedList<dataType>pop(){
    this->value=0;
    this->node=NULL;
    return*this;
  }
  linkedList<dataType>insert(dataType value,unsigned long long position){
    if(position==1)this->push(value);
    linkedList<dataType>newNode(value);
    for(unsigned int index=0;index<position;index++){
      if(index==position){
        this->node=&newNode;
        return newNode;
      }
    }
  }
  char remove(dataType value){
    linkedList<dataType>newNode(value);
    this->node=&newNode;
    return &newNode!=NULL;
  }
  void traverse(){
    for(linkedList<dataType>*head=this;head!=NULL;){
      std::cout<<"Value "<<head->value<<'\n';
      head=head->node;
    }
  }
  ~linkedList(){
    this->value=0;
    this->node=NULL;
  }
};
#endif