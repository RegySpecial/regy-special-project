/*
*@description Source code of the array manipulation library 
*@author Regy Special
*@date (First version [Linux/Parrot OS]) 2024 October 17th Thursday, 01:20:17
*@license GNU General Public License to stop private corporation to not share source code
*/
//verifies if all the elements in the array sastify the condition defined by the predicate function
template<typename itemsDataType,typename sizeDataType=unsigned long>
bool every(itemsDataType*array,bool(*everyFunction)(itemsDataType),sizeDataType size){
  bool everyValue=1;
  for(sizeDataType i=0;i<size;i++)everyValue&=everyFunction(array[i]);
  return everyValue;
}
template<typename itemsDataType,typename sizeDataType=unsigned long>
bool every(itemsDataType*array,bool(*everyFunction)(itemsDataType,sizeDataType),sizeDataType size){
  bool everyValue=1;
  for(sizeDataType i=0;i<size;i++)everyValue&=everyFunction(array[i],i);
  return everyValue;
}
template<typename itemsDataType,typename sizeDataType=unsigned long>
bool every(itemsDataType*array,bool(*everyFunction)(itemsDataType,sizeDataType,itemsDataType*),sizeDataType size){
  bool everyValue=1;
  for(sizeDataType i=0;i<size;i++)everyValue&=everyFunction(array[i],i,array);
  return everyValue;
}
//overloading of 'every' function
template<typename itemsDataType,typename sizeDataType=unsigned long>
bool every(itemsDataType*array,bool(*everyFunction)(itemsDataType),sizeDataType left,sizeDataType right){
  bool everyValue=1;
  for(;0<=left&&left<right;left++)everyValue&=everyFunction(array[left]);
  return everyValue;
}
template<typename itemsDataType,typename sizeDataType=unsigned long>
bool every(itemsDataType*array,bool(*everyFunction)(itemsDataType,sizeDataType),sizeDataType left,sizeDataType right){
  bool everyValue=1;
  for(;0<=left&&left<right;left++)everyValue&=everyFunction(array[left],left);
  return everyValue;
}
template<typename itemsDataType,typename sizeDataType=unsigned long>
bool every(itemsDataType*array,bool(*everyFunction)(itemsDataType,sizeDataType,itemsDataType*),sizeDataType left,sizeDataType right){
  bool everyValue=1;
  for(;0<=left&&left<right;left++)everyValue&=everyFunction(array[left],left,array);
  return everyValue;
}


//verifies if at least one element in the array sastify the condition defined by the predicate function
template<typename itemsDataType,typename sizeDataType=unsigned long>
bool some(itemsDataType*array,bool(*someFunction)(itemsDataType),sizeDataType size){
  bool someValue=0;
  for(sizeDataType i=0;i<size;i++)someValue|=someFunction(array[i]);
  return someValue;
}
template<typename itemsDataType,typename sizeDataType=unsigned long>
bool some(itemsDataType*array,bool(*someFunction)(itemsDataType,sizeDataType),sizeDataType size){
  bool someValue=0;
  for(sizeDataType i=0;i<size;i++)someValue|=someFunction(array[i],i);
  return someValue;
}
template<typename itemsDataType,typename sizeDataType=unsigned long>
bool some(itemsDataType*array,bool(*someFunction)(itemsDataType,sizeDataType,itemsDataType*),sizeDataType size){
  bool someValue=0;
  for(sizeDataType i=0;i<size;i++)someValue|=someFunction(array[i],i,array);
  return someValue;
}
//overloading of 'every' function
template<typename itemsDataType,typename sizeDataType=unsigned long>
bool some(itemsDataType*array,bool(*someFunction)(itemsDataType),sizeDataType left,sizeDataType right){
  bool someValue=0;
  for(;0<=left&&left<right;left++)someValue|=someFunction(array[left]);
  return someValue;
}
template<typename itemsDataType,typename sizeDataType=unsigned long>
bool some(itemsDataType*array,bool(*someFunction)(itemsDataType,sizeDataType),sizeDataType left,sizeDataType right){
  bool someValue=0;
  for(;0<=left&&left<right;left++)someValue|=someFunction(array[left],left);
  return someValue;
}
template<typename itemsDataType,typename sizeDataType=unsigned long>
bool some(itemsDataType*array,bool(*someFunction)(itemsDataType,sizeDataType,itemsDataType*),sizeDataType left,sizeDataType right){
  bool someValue=0;
  for(;0<=left&&left<right;left++)someValue|=someFunction(array[left],left,array);
  return someValue;
}


//verifies if only even elements in the array sastify the condition defined by the predicate function
template<typename itemsDataType,typename sizeDataType=unsigned long>
bool xsome(itemsDataType*array,bool(*xsomeFunction)(itemsDataType),sizeDataType size){
  bool xsomeValue=0;
  for(sizeDataType i=0;i<size;i++)xsomeValue^=xsomeFunction(array[i]);
  return xsomeValue;
}
template<typename itemsDataType,typename sizeDataType=unsigned long>
bool xsome(itemsDataType*array,bool(*xsomeFunction)(itemsDataType,sizeDataType),sizeDataType size){
  bool xsomeValue=0;
  for(sizeDataType i=0;i<size;i++)xsomeValue^=xsomeFunction(array[i],i);
  return xsomeValue;
}
template<typename itemsDataType,typename sizeDataType=unsigned long>
bool xsome(itemsDataType*array,bool(*xsomeFunction)(itemsDataType,sizeDataType,itemsDataType*),sizeDataType size){
  bool xsomeValue=0;
  for(sizeDataType i=0;i<size;i++)xsomeValue^=xsomeFunction(array[i],i,array);
  return xsomeValue;
}
//overloading of 'every' function
template<typename itemsDataType,typename sizeDataType=unsigned long>
bool xsome(itemsDataType*array,bool(*xsomeFunction)(itemsDataType),sizeDataType left,sizeDataType right){
  bool xsomeValue=0;
  for(;0<=left&&left<right;left++)xsomeValue^=xsomeFunction(array[left]);
  return xsomeValue;
}
template<typename itemsDataType,typename sizeDataType=unsigned long>
bool xsome(itemsDataType*array,bool(*xsomeFunction)(itemsDataType,sizeDataType),sizeDataType left,sizeDataType right){
  bool xsomeValue=0;
  for(;0<=left&&left<right;left++)xsomeValue^=xsomeFunction(array[left],left);
  return xsomeValue;
}
template<typename itemsDataType,typename sizeDataType=unsigned long>
bool xsome(itemsDataType*array,bool(*xsomeFunction)(itemsDataType,sizeDataType,itemsDataType*),sizeDataType left,sizeDataType right){
  bool xsomeValue=0;
  for(;0<=left&&left<right;left++)xsomeValue^=xsomeFunction(array[left],left,array);
  return xsomeValue;
}
//compare to arrays
template<typename itemsDataType,typename sizeDataType=unsigned long>
sizeDataType compare(itemsDataType*array1,itemsDataType*array2){
  return*array1!=*array2?*array1-*array2:compare<itemsDataType,sizeDataType>(array1+1,array2+1);
}
//compare n elements of 2 arrays
template<typename itemsDataType,typename sizeDataType=unsigned long>
sizeDataType compare(itemsDataType*array1,itemsDataType*array2,sizeDataType size){
  return*array1!=*array2||size==1?*array1-*array2:compare<itemsDataType,sizeDataType>(array1+1,array2+1,size-1);
}
template<typename itemsDataType,typename sizeDataType=unsigned long>
sizeDataType compare(itemsDataType*array1,itemsDataType*array2,sizeDataType left,sizeDataType right){
  return*array1!=*array2||0<=left&&left<right?*array1-*array2:compare<itemsDataType,sizeDataType>(array1+1,array2+1,left+1,right);
}
//return the length of a string checking if it ends with \0 character
template<typename itemsDataType,typename sizeDataType=unsigned long>
sizeDataType stringLength(itemsDataType*array){
  return*array?1+stringLength<itemsDataType,sizeDataType>(array+1):0;
}
//return the length of a numbered string checking if it ends with \0 character
template<typename itemsDataType,typename sizeDataType=unsigned long>
sizeDataType stringLength(itemsDataType*array,sizeDataType size){
  return!*array||size==1?0:1+stringLength<itemsDataType,sizeDataType>(array+1,size-1);
}
template<typename itemsDataType,typename sizeDataType=unsigned long>
sizeDataType stringLength(itemsDataType*array,sizeDataType left,sizeDataType right){
  return!*array||0<=left&&left<right?0:1+stringLength<itemsDataType,sizeDataType>(array+1,left+1,right);
}

template<typename itemsDataType,typename sizeDataType=unsigned long>
void sort(itemsDataType*array,itemsDataType(*comparisonFunction)(itemsDataType,itemsDataType),sizeDataType left,sizeDataType right){
  if(0<=left&&left<right){
    sizeDataType i=left-1;
    itemsDataType tmp;
    for(;left<right;left++){
      if(comparisonFunction(array[left],array[right])<0){
        i+=1;
        tmp=array[i];
        array[i]=array[left];
        array[left]=tmp;
      }
    }
    i+=1;
    tmp=array[i];
    array[i]=array[right];
    array[right]=tmp;
    sort<itemsDataType,sizeDataType>(array,comparisonFunction,0,i-1);
    sort<itemsDataType,sizeDataType>(array,comparisonFunction,i+1,right);
  }
}
template<typename itemsDataType,typename sizeDataType=unsigned long>
void sort(itemsDataType*array,itemsDataType(*comparisonFunction)(itemsDataType,itemsDataType),sizeDataType size){
  sort<itemsDataType,sizeDataType>(array,comparisonFunction,0,size);
}

template<typename itemsDataType,typename sizeDataType=unsigned long>
sizeDataType search(itemsDataType*array,itemsDataType item,sizeDataType(*predicate)(itemsDataType,itemsDataType),sizeDataType left,sizeDataType right){
  if(0<=left&&left<right){
    sort<itemsDataType,sizeDataType>(array,left,right,predicate);
    const sizeDataType middle=(right-left)/2;
    return !predicate(item,array[middle])
           ?middle
           :search<itemsDataType,sizeDataType>(
              array,
              item,
              predicate,
              predicate(item,array[middle])<0?0:middle+1,
              predicate(item,array[middle])<0?middle:right
            );
  }
}

//execute an action for each element in the array
template<typename itemsDataType,typename sizeDataType=unsigned long>
void forEach(itemsDataType*array,void(*forEachFunction)(itemsDataType),sizeDataType size){
  for(sizeDataType index=0;index<size;index++)
    forEachFunction(array[index]);
}
//second overload of forEach
template<typename itemsDataType,typename sizeDataType=unsigned long>
void forEach(itemsDataType*array,void(*forEachFunction)(itemsDataType,sizeDataType),sizeDataType size){
  for(sizeDataType index=0;index<size;index++)
    forEachFunction(array[index],index);
}
//third overload of forEach
template<typename itemsDataType,typename sizeDataType=unsigned long>
void forEach(itemsDataType*array,void(*forEachFunction)(itemsDataType,sizeDataType,itemsDataType*),sizeDataType size){
  for(sizeDataType index=0;index<size;index++)
    forEachFunction(array[index],index,array);
}
template<typename itemsDataType,typename sizeDataType=unsigned long>
void forEach(itemsDataType*array,void(*forEachFunction)(itemsDataType),sizeDataType left,sizeDataType right){
  for(;0<=left&&left<right;left++)
    forEachFunction(array[left]);
}
//second overload of forEach
template<typename itemsDataType,typename sizeDataType=unsigned long>
void forEach(itemsDataType*array,void(*forEachFunction)(itemsDataType,sizeDataType),sizeDataType left,sizeDataType right){
  for(;0<=left&&left<right;left++)
    forEachFunction(array[left],left);
}
//third overload of forEach
template<typename itemsDataType,typename sizeDataType=unsigned long>
void forEach(itemsDataType*array,void(*forEachFunction)(itemsDataType,sizeDataType,itemsDataType*),sizeDataType left,sizeDataType right){
  for(;0<=left&&left<right;left++)
    forEachFunction(array[left],left,array);
}