/*
*@description Header file where are defined the functions of the array manipulation library 
*@author Regy Special
*@date (First version [Windows]) 2024 October 17th Thursday, 01:20:17
*@license GNU General Public License to stop private corporation to not share source code
*/
#ifndef arraysHpp
#define arraysHpp
template<typename itemsDataType,typename sizeDataType = unsigned long long>
bool every(itemsDataType*array,bool(*everyFunction)(itemsDataType),sizeDataType size){
  bool everyCondition = 1;
  for (sizeDataType i = 0; i < size; i++)
    everyCondition &= everyFunction(array[i]);
  return everyCondition;
}
template<typename itemsDataType,typename sizeDataType = unsigned long long>
bool every(itemsDataType*array,bool(*everyFunction)(itemsDataType,sizeDataType),sizeDataType size){
  bool everyCondition = 1;
  for (sizeDataType i = 0; i < size; i++)
    everyCondition &= everyFunction(array[i], i);
  return everyCondition;
}
template<typename itemsDataType,typename sizeDataType = unsigned long long>
bool every(itemsDataType*array,bool(*everyFunction)(itemsDataType,sizeDataType,itemsDataType*),sizeDataType size){
  bool everyCondition = 1;
  for (sizeDataType i = 0; i < size; i++)
    everyCondition &= everyFunction(array[i], i, array);
  return everyCondition;
}

template<typename itemsDataType,typename sizeDataType = unsigned long long>
bool every(itemsDataType*array,bool(*everyFunction)(itemsDataType),sizeDataType left,sizeDataType right){
  bool everyCondition = 1;
  for(;0<=left&&left<right;left++)everyCondition &= everyFunction(array[left]);
  return everyCondition;
}
template<typename itemsDataType,typename sizeDataType = unsigned long long>
bool every(itemsDataType*array,bool(*everyFunction)(itemsDataType,sizeDataType),sizeDataType left,sizeDataType right){
  bool everyCondition = 1;
  for(;0<=left&&left<right;left++)everyCondition &= everyFunction(array[left],left);
  return everyCondition;
}
template<typename itemsDataType,typename sizeDataType = unsigned long long>
bool every(itemsDataType*array,bool(*everyFunction)(itemsDataType,sizeDataType,itemsDataType*),sizeDataType left,sizeDataType right){
  bool everyCondition = 1;
  for(;0<=left&&left<right;left++)everyCondition &= everyFunction(array[left],left,array);
  return everyCondition;
}

template<typename itemsDataType,typename sizeDataType = unsigned long long>
bool some(itemsDataType*array,bool(*someFunction)(itemsDataType),sizeDataType size){
  bool someCondition=0;
  for(sizeDataType i=0;i<size;i++)someCondition |= someFunction(array[i]);
  return someCondition;
}
template<typename itemsDataType,typename sizeDataType = unsigned long long>
bool some(itemsDataType*array,bool(*someFunction)(itemsDataType,sizeDataType),sizeDataType size){
  bool someCondition=0;
  for(sizeDataType i=0;i<size;i++)someCondition |= someFunction(array[i],i);
  return someCondition;
}
template<typename itemsDataType,typename sizeDataType = unsigned long long>
bool some(itemsDataType*array,bool(*someFunction)(itemsDataType,sizeDataType,itemsDataType*),sizeDataType size){
  bool someCondition=0;
  for(sizeDataType i=0;i<size;i++)someCondition |= someFunction(array[i],i,array);
  return someCondition;
}

template<typename itemsDataType,typename sizeDataType = unsigned long long>
bool some(itemsDataType*array,bool(*someFunction)(itemsDataType),sizeDataType left,sizeDataType right){
  bool someCondition=0;
  for(;0<=left&&left<right;left++)someCondition |= someFunction(array[left]);
  return someCondition;
}
template<typename itemsDataType,typename sizeDataType = unsigned long long>
bool some(itemsDataType*array,bool(*someFunction)(itemsDataType,sizeDataType),sizeDataType left,sizeDataType right){
  bool someCondition=0;
  for(;0<=left&&left<right;left++)someCondition |= someFunction(array[left],left);
  return someCondition;
}
template<typename itemsDataType,typename sizeDataType = unsigned long long>
bool some(itemsDataType*array,bool(*someFunction)(itemsDataType,sizeDataType,itemsDataType*),sizeDataType left,sizeDataType right){
  bool someCondition=0;
  for(;0<=left&&left<right;left++)someCondition |= someFunction(array[left],left,array);
  return someCondition;
}

template<typename itemsDataType,typename sizeDataType = unsigned long long>
bool xsome(itemsDataType*array,bool(*xsomeFunction)(itemsDataType),sizeDataType size){
  bool xsomeCondition=0;
  for(sizeDataType i=0;i<size;i++)xsomeCondition^=xsomeFunction(array[i]);
  return xsomeCondition;
}
template<typename itemsDataType,typename sizeDataType = unsigned long long>
bool xsome(itemsDataType*array,bool(*xsomeFunction)(itemsDataType,sizeDataType),sizeDataType size){
  bool xsomeCondition=0;
  for(sizeDataType i=0;i<size;i++)xsomeCondition^=xsomeFunction(array[i],i);
  return xsomeCondition;
}
template<typename itemsDataType,typename sizeDataType = unsigned long long>
bool xsome(itemsDataType*array,bool(*xsomeFunction)(itemsDataType,sizeDataType,itemsDataType*),sizeDataType size){
  bool xsomeCondition=0;
  for(sizeDataType i=0;i<size;i++)xsomeCondition^=xsomeFunction(array[i],i,array);
  return xsomeCondition;
}

template<typename itemsDataType,typename sizeDataType = unsigned long long>
bool xsome(itemsDataType*array,bool(*xsomeFunction)(itemsDataType),sizeDataType left,sizeDataType right){
  bool xsomeCondition=0;
  for(;0<=left&&left<right;left++)xsomeCondition^=xsomeFunction(array[left]);
  return xsomeCondition;
}
template<typename itemsDataType,typename sizeDataType = unsigned long long>
bool xsome(itemsDataType*array,bool(*xsomeFunction)(itemsDataType,sizeDataType),sizeDataType left,sizeDataType right){
  bool xsomeCondition=0;
  for(;0<=left&&left<right;left++)xsomeCondition^=xsomeFunction(array[left],left);
  return xsomeCondition;
}
template<typename itemsDataType,typename sizeDataType = unsigned long long>
bool xsome(itemsDataType*array,bool(*xsomeFunction)(itemsDataType,sizeDataType,itemsDataType*),sizeDataType left,sizeDataType right){
  bool xsomeCondition=0;
  for(;0<=left&&left<right;left++)xsomeCondition^=xsomeFunction(array[left],left,array);
  return xsomeCondition;
}

template<typename itemsDataType,typename sizeDataType = unsigned long long>
sizeDataType compare(itemsDataType*array1,itemsDataType*array2){
  return*array1!=*array2?*array1-*array2:compare<itemsDataType,sizeDataType>(array1+1,array2+1);
}
//compare n elements of 2 arrays
template<typename itemsDataType,typename sizeDataType = unsigned long long>
sizeDataType compare(itemsDataType*array1,itemsDataType*array2,sizeDataType size){
  return*array1!=*array2||size==1?*array1-*array2:compare<itemsDataType,sizeDataType>(array1+1,array2+1,size-1);
}
template<typename itemsDataType,typename sizeDataType = unsigned long long>
sizeDataType compare(itemsDataType*array1,itemsDataType*array2,sizeDataType left,sizeDataType right){
  return*array1!=*array2||0<=left&&left<right?*array1-*array2:compare<itemsDataType,sizeDataType>(array1+1,array2+1,left+1,right);
}

template<typename itemsDataType,typename sizeDataType = unsigned long long>
sizeDataType stringLength(itemsDataType*array){
  return *array
         ? 1 + stringLength<itemsDataType,sizeDataType>(++array)
         : 0;
}
//return the length of a numbered string checking if it ends with \0 character
template<typename itemsDataType,typename sizeDataType = unsigned long long>
sizeDataType stringLength(itemsDataType*array,sizeDataType size){
  return !*array || size == 1
         ? 0
         : 1 + stringLength<itemsDataType,sizeDataType>(++array,--size);
}
template<typename itemsDataType,typename sizeDataType = unsigned long long>
sizeDataType stringLength(itemsDataType*array,sizeDataType left,sizeDataType right){
  return !*array || 0 <= left && left < right
         ? 0
         : 1 + stringLength<itemsDataType,sizeDataType>(++array,++left,right);
}

template<typename itemsDataType,typename sizeDataType = unsigned long long>
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
template<typename itemsDataType,typename sizeDataType = unsigned long long>
void sort(itemsDataType*array,itemsDataType(*comparisonFunction)(itemsDataType,itemsDataType),sizeDataType size){
  sort<itemsDataType,sizeDataType>(array,comparisonFunction,0,size);
}

template<typename itemsDataType,typename sizeDataType = unsigned long long>
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

template<typename itemsDataType,typename sizeDataType = unsigned long long>
void forEach(itemsDataType*array,void(*forEachFunction)(itemsDataType),sizeDataType size){
  for(sizeDataType index=0;index<size;index++)
    forEachFunction(array[index]);
}
template<typename itemsDataType,typename sizeDataType = unsigned long long>
void forEach(itemsDataType*array,void(*forEachFunction)(itemsDataType,sizeDataType),sizeDataType size){
  for(sizeDataType index=0;index<size;index++)
    forEachFunction(array[index],index);
}
template<typename itemsDataType,typename sizeDataType = unsigned long long>
void forEach(itemsDataType*array,void(*forEachFunction)(itemsDataType,sizeDataType,itemsDataType*),sizeDataType size){
  for(sizeDataType index=0;index<size;index++)
    forEachFunction(array[index],index,array);
}

template<typename itemsDataType,typename sizeDataType = unsigned long long>
void forEach(itemsDataType*array,void(*forEachFunction)(itemsDataType),sizeDataType left,sizeDataType right){
  for(;0<=left&&left<right;left++)
    forEachFunction(array[left]);
}
template<typename itemsDataType,typename sizeDataType = unsigned long long>
void forEach(itemsDataType*array,void(*forEachFunction)(itemsDataType,sizeDataType),sizeDataType left,sizeDataType right){
  for(;0<=left&&left<right;left++)
    forEachFunction(array[left],left);
}
template<typename itemsDataType,typename sizeDataType = unsigned long long>
void forEach(itemsDataType*array,void(*forEachFunction)(itemsDataType,sizeDataType,itemsDataType*),sizeDataType left,sizeDataType right){
  for(;0<=left&&left<right;left++)
    forEachFunction(array[left],left,array);
}

template<typename accumulationValueDataType,typename itemsDataType,typename sizeDataType = unsigned long long>
accumulationValueDataType reduce
(
  itemsDataType*array,
  void(*reduceFunction)
  (
    itemsDataType,
    sizeDataType,
    itemsDataType*
  ),
  sizeDataType size,
  accumulationValueDataType accumulationValue
)
{
  for(sizeDataType index=0;index<size;index++)
    accumulationValue = reduceFunction(array[index],index,array);
  return accumulationValue;
}
template<typename accumulationValueDataType,typename itemsDataType,typename sizeDataType = unsigned long long>
accumulationValueDataType reduce(itemsDataType*array,void(*forEachFunction)(itemsDataType,sizeDataType,itemsDataType*),sizeDataType left,sizeDataType right){
  for(;0<=left&&left<right;left++)
    forEachFunction(array[left],left,array);
}
#endif