/*
*@description Header file where is defined the dynamic array data structure class of the dynamic array data structure library
*@author Regy Special
*@date (First version [Linux/Parrot OS]) 2026 June 16th Tuesday, 19:11:26
*@license GNU General Public License to stop private corporation to not share source code
*/
#include "../../include/lib/c++/code.hpp"
template<typename returnDataType=unsigned long long>
returnDataType stringToNumber(const char*string){
  returnDataType number=0;
  for(unsigned long i=*string=='+'||*string=='-'?1:0;string[i];i++)
    if('0'<=string[i]&&string[i]<='9')
      number=(number*10)+(string[i]-'0');
    else if(string[i]=='.')
      return number+=stringToNumber(string+i+1);
  return number;
}
template<typename numberDataType=unsigned long long>
void numberToBase(char*outputBuffer,numberDataType number,unsigned char base){
  for(unsigned long long c=0;outputBuffer[c];outputBuffer[c++]=0);
  if(2<=base&&base<=36)
    for(unsigned char bit=0;bit<sizeof number*8;bit++){
      outputBuffer[sizeof number*8-bit-1]="0123456789abcdefghijklmnopqrstuvwxyz"[number%base];
      number/=base;
    }
}
/*1st overload of numberToBase*/
template<typename numberDataType=unsigned long long,typename sizeDataType=unsigned long>
void numberToBase(char*outputBuffer,sizeDataType size,numberDataType number,unsigned char base){
  for(unsigned long long c=0;c<size;outputBuffer[c++]=0);
  if(2<=base&&base<=36)
    for(unsigned char bit=0;bit<sizeof number*8;bit++){
      outputBuffer[sizeof number*8-bit-1]="0123456789abcdefghijklmnopqrstuvwxyz"[number%base];
      number/=base;
    }
}

template<typename numberDataType=unsigned long long>
numberDataType grayCode(numberDataType number){
  numberDataType resultingCode=0,
                 Gn=number>>(sizeof number*8)&1,
                 Gn1=0;
  for (unsigned long bit=sizeof number*8;--bit;){
    Gn1^=(number>>bit&1);
    resultingCode|=Gn1<<bit;
  }
  Gn1^=number&1;
  return (resultingCode|=Gn1);
}