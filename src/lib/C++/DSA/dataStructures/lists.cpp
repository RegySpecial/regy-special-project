/*
*@description Source code the linked list data structure class of the linked list data structure library
*@author Regy Special
*@date (First version [Linux/Parrot OS]) 2026 March 7th Saturday, 16:12:08
*@license GNU General Public License to stop private corporation to not share source code
*/
template<typename dataType>
class linkedList{
public:
  dataType value;
  linkedList*next;
  linkedList(dataType value){
    this=new linkedList(value);
    this->value=value;
    this->next=NULL;
  }
  void forEach(void(*callbackFunction)(dataType)){
    unsigned long nodeIndex=0;
    if(this->next!=NULL){
      callbackFunction(this->value,nodeIndex++);
      this->forEach(callbackFunction);
    }
  }
  void forEach(void(*callbackFunction)(dataType,unsigned long)){
    unsigned long nodeIndex=0;
    if(this->next!=NULL){
      callbackFunction(this->value,nodeIndex++);
      this->forEach(callbackFunction);
    }
  }
  void forEach(void(*callbackFunction)(dataType,unsigned long,linkedList<dataType>*)){
    unsigned long nodeIndex=0;
    if(this->next!=NULL){
      callbackFunction(this->value,nodeIndex++,this);
      this->forEach(callbackFunction);
    }
  }
  linkedList<dataType>filter(unsigned char(*filterFunction)(dataType,unsigned int)){
    linkedList filterLinkedList;
    this->forEach([&](dataType element,unsigned int index){
      if(filterFunction(element,index)>0)filterLinkedList.add(head->value,nodeIndex);
    });
  }
  dataType at(unsigned long index){
    dataType valueAtIndex;
    this->forEach([&](dataType item,unsigned long i,linkedList<dataType>*original){
      if(i==index)valueAtIndex=item;
    });
    return valueAtIndex;
  }
  linkedList<dataType>push(dataType value){
    linkedList<dataType>newNode(value);
    this->next=&newNode;
    return newNode;
  }
  linkedList<dataType>pop(){
    this->value=0;
    this->next=NULL;
    return*this;
  }
  linkedList<dataType>insert(dataType value,unsigned long long position){
    if(position==1)this->push(value);
    linkedList<dataType>newNode(value);
    for(unsigned int index=0;index<position;index++){
      if(index==position){
        this->next=&newNode;
        return newNode;
      }
    }
  }
  char remove(dataType value){
    linkedList<dataType>newNode(value);
    this->next=&newNode;
    return &newNode!=NULL;
  }
  ~linkedList(){
    this->value=0;
    this->next=NULL;
  }
};

template<typename dataType>
class doubleLinkedList{
public:
  dataType value;
  doubleLinkedList*prev,
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