/*
*@description Header file where are defined the functions of the array manipulation library 
*@author Regy Special
*@date (First version [Windows]) 2024 October 17th Thursday, 01:20:17
*@license GNU General Public License to stop private corporation to not share source code
*/
#ifndef arraysHpp
#define arraysHpp
//verifies if all the elements in the array sastify the condition defined by the predicate function
template<typename itemsDataType>
bool every(itemsDataType array[],unsigned int size,bool(*predicate)(itemsDataType)){
  bool everyValue=1;
  for(size_t i=0;i<size;i++)everyValue&=predicate(array[i])==1;
  return everyValue;
}
//overloading of 'every' function
template<typename itemsDataType>
bool every(itemsDataType array[],unsigned int start,unsigned int end,bool(*predicate)(itemsDataType)){
  bool everyValue=1;
  for(;start<end;start++)everyValue&=predicate(array[start])==1;
  return everyValue;
}
//verifies if at least one element in the array sastify the condition defined by the predicate function
template<typename itemsDataType>
bool some(itemsDataType array[],unsigned int size,bool(*predicate)(itemsDataType)){
  bool someValue=0;
  for(unsigned int i=0;i<size;i++)someValue|=predicate(array[i])==1;
  return someValue;
}
//overloading of 'some' function
template<typename itemsDataType>
bool some(itemsDataType array[],unsigned int start,unsigned int end,bool(*predicate)(itemsDataType)){
  bool someValue=0;
  for(;start<end;start++)someValue|=predicate(array[start])==1;
  return someValue;
}
//verifies if only even elements in the array sastify the condition defined by the predicate function
template<typename itemsDataType>
bool xsome(itemsDataType array[],unsigned int size,bool(*predicate)(itemsDataType)){
  bool xsomeValue=0;
  for(unsigned int i=0;i<size;i++)xsomeValue^=predicate(array[i])==1;
  return xsomeValue;
}
//overloading of 'xsome' function
template<typename itemsDataType>
bool xsome(itemsDataType array[],unsigned int start,unsigned int end,bool(*predicate)(itemsDataType)){
  bool xsomeValue=0;
  for(;start<end;start++)xsomeValue^=predicate(array[start])==1;
  return xsomeValue;
}
//compare to arrays
template<typename arrayValueDataType>
long long compare(arrayValueDataType*array1,arrayValueDataType*array2){
  for(;*array1==*array2;array1++,array2++)if(*array1!=*array2)return*array1-*array2;
  return *array1-*array2;
}
//compare n elements of 2 arrays
template<typename arrayValueDataType>
long long numberedCompare(arrayValueDataType*array1,arrayValueDataType*array2,unsigned int n){
  for(unsigned int i=0;*array1==*array2&&i<n;array1++,array2++)if(*array1!=*array2)return*array1-*array2;
  return *array1-*array2;
}
#endif