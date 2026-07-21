#ifndef codeHpp
#define codeHpp
/*
*@description Header file where is defined the dynamic array data structure class of the dynamic array data structure library
*@author Regy Special
*@date (First version [Linux/Parrot OS]) 2026 July 16th Thursday, 13:16:02
*@license GNU General Public License to stop private corporation to not share source code
*/
template<typename returnDataType>
returnDataType stringToNumber(const char*string);

template<typename numberDataType=unsigned long long>
void numberToBase(char*outputBuffer,numberDataType number,unsigned char base);
/*1st overload of numberToBase*/
template<typename numberDataType=unsigned long long,typename sizeDataType=unsigned long>
void numberToBase(char*outputBuffer,sizeDataType size,numberDataType number,unsigned char base);

template<typename numberDataType=unsigned long long>
numberDataType grayCode(numberDataType number);
#endif