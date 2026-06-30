/*
*@description Source code of the array manipulation library 
*@author Regy Special
*@date (First version [Linux/Parrot OS]) 2024 October 17th Thursday, 01:20:17
*@license GNU General Public License to stop private corporation to not share source code
*/
//verifies if all the elements in the array sastify the condition defined by the predicate function
template<typename itemsDataType,typename sizeDataType=unsigned long>
bool every(itemsDataType array[],unsigned int size,bool(*predicate)(itemsDataType)){
  bool everyValue=1;
  for(size_t i=0;i<size;i++)everyValue&=predicate(array[i])==1;
  return everyValue;
}
//overloading of 'every' function
template<typename itemsDataType,typename sizeDataType=unsigned long>
bool every(itemsDataType array[],unsigned int start,unsigned int end,bool(*predicate)(itemsDataType)){
  bool everyValue=1;
  for(;start<end;start++)everyValue&=predicate(array[start])==1;
  return everyValue;
}
//verifies if at least one element in the array sastify the condition defined by the predicate function
template<typename itemsDataType,typename sizeDataType=unsigned long>
bool some(itemsDataType array[],unsigned int size,bool(*predicate)(itemsDataType)){
  bool someValue=0;
  for(unsigned int i=0;i<size;i++)someValue|=predicate(array[i])==1;
  return someValue;
}
//overloading of 'some' function
template<typename itemsDataType,typename sizeDataType=unsigned long>
bool some(itemsDataType array[],unsigned int start,unsigned int end,bool(*predicate)(itemsDataType)){
  bool someValue=0;
  for(;start<end;start++)someValue|=predicate(array[start])==1;
  return someValue;
}
//verifies if only even elements in the array sastify the condition defined by the predicate function
template<typename itemsDataType,typename sizeDataType=unsigned long>
bool xsome(itemsDataType array[],unsigned int size,bool(*predicate)(itemsDataType)){
  bool xsomeValue=0;
  for(unsigned int i=0;i<size;i++)xsomeValue^=predicate(array[i])==1;
  return xsomeValue;
}
//overloading of 'xsome' function
template<typename itemsDataType,typename sizeDataType=unsigned long>
bool xsome(itemsDataType array[],unsigned int start,unsigned int end,bool(*predicate)(itemsDataType)){
  bool xsomeValue=0;
  for(;start<end;start++)xsomeValue^=predicate(array[start])==1;
  return xsomeValue;
}
//compare to arrays
template<typename itemsDataType,typename sizeDataType=unsigned long>
sizeDataType compare(itemsDataType*array1,itemsDataType*array2){
  return*array1!=*array2?*array1-*array2:compare<itemsDataType,sizeDataType>(array1+1,array2+1);
}
//compare n elements of 2 arrays
template<typename itemsDataType,typename sizeDataType=unsigned long>
sizeDataType compare(itemsDataType*array1,itemsDataType*array2,sizeDataType number){
  return*array1!=*array2||number==1?*array1-*array2:compare<itemsDataType,sizeDataType>(array1+1,array2+1,number-1);
}
//return the length of a string checking if it ends with \0 character
template<typename itemsDataType,typename sizeDataType=unsigned long>
sizeDataType stringLength(itemsDataType*array){
  return*array==0?0:1+stringLength<itemsDataType,sizeDataType>(array+1);
}
//return the length of a numbered string checking if it ends with \0 character
template<typename itemsDataType,typename sizeDataType=unsigned long>
sizeDataType stringLength(itemsDataType*array,sizeDataType number){
  return*array==0||number==1?0:1+stringNumberedLength<itemsDataType,sizeDataType>(array+1,number-1);
}
template<typename itemsDataType,typename sizeDataType=unsigned long>
void sort(itemsDataType*array,sizeDataType left,sizeDataType right,int(*comparisonFunction)(itemsDataType,itemsDataType)){
  if(left<right){
    sizeDataType i=left-1,j=i+1,pivot=right-1;
    for(;j<right;j++){
      if(comparisonFunction(array[j],array[pivot])<0){
        i+=1;
        arrayValueDataType temporaryVariable=array[i];
        array[i]=array[j];
        array[j]=temporaryVariable;
      }
    }
    i+=1;
    arrayValueDataType temporaryVariable=array[i];
    array[i]=array[pivot];
    array[pivot]=temporaryVariable;
    sort<arrayValueDataType>(array,0,pivot-1,comparisonFunction);
    sort<arrayValueDataType>(array,pivot+1,right,comparisonFunction);
  }
}
template<typename itemsDataType,typename sizeDataType=unsigned long>
sizeDataType search(itemsDataType array,sizeDataType left,sizeDataType right,sizeDataType(*predicate)(itemsDataType,itemsDataType)){
  sort<itemsDataType,sizeDataType>(array,left,right,predicate);
  const sizeDataType middle=(right-left)/2;
  if(predicate(array[middle])<0)
}

//execute an action for each element in the array
template<typename itemsDataType,typename sizeDataType=unsigned long>
void forEach(itemsDataType array[],sizeDataType size,void(*callback)(itemsDataType)){
  for(sizeDataType index=0;index<size;index++)
    callback(array[index]);
}
//second overload of forEach
template<typename itemsDataType,typename sizeDataType=unsigned long>
void forEach(itemsDataType array[],sizeDataType size,void(*callback)(itemsDataType,sizeDataType)){
  for(sizeDataType index=0;index<size;index++)
    callback(array[index],index);
}
//third overload of forEach
template<typename itemsDataType,typename sizeDataType=unsigned long>
void forEach(itemsDataType array[],sizeDataType size,void(*callback)(itemsDataType,sizeDataType,itemsDataType*)){
  for(sizeDataType index=0;index<size;index++)
    callback(array[index],index,array);
}