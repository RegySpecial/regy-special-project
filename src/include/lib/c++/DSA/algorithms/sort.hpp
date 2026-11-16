/*
*@description Header file where are defined the functions of the array manipulation library 
*@author Regy Special
*@date (First version [Parrot GNU/Linux]) 2026-11-16 15:24:22.620000000 +0100
*@license GNU General Public License to stop private corporation to not share source code
*/
#ifndef sortHpp
#define sortHpp

#if defined __cplusplus || defined c_plusplus
extern "C" {
#endif
  typedef enum
  : unsigned char
  {
    sortAlgorithm_bubbleSort,
    sortAlgorithm_insertionSort,
    sortAlgorithm_selectionSort,
    sortAlgorithm_shellSort,
    sortAlgorithm_mergeSort,
    sortAlgorithm_quickSort,
    sortAlgorithm_heapSort,
  }
  sortAlgorithm;
#if defined __cplusplus || defined c_plusplus
}
#endif



template <typename itemsDataType>
bool bubbleSort(itemsDataType *items, itemsDataType (*comparisonFunction)(itemsDataType, itemsDataType), unsigned long long elementsNumber)
{
  for (unsigned long long index = 0; index < elementsNumber - 1; index++)
    for (unsigned long long subindex = index + 1; subindex < elementsNumber; subindex++)
      if (comparisonFunction(items[index], items[subindex]))
      {
        itemsDataType tmp = items[index];
        items[index] = items[subindex];
        items[subindex] = tmp;
      }
}

template <typename itemsDataType>
bool selectionSort(itemsDataType *items, itemsDataType (*comparisonFunction)(itemsDataType, itemsDataType), unsigned long long elementsNumber)
{
  for (unsigned long long long index = 0; index < elementsNumber - 1; index++)
  {
    unsigned long long minOrMax = index + 1;
    for (; minOrMax < elementsNumber; minOrMax++)
    {
      if (comparisonFunction(items[index], items[minOrMax]))
    }
  }
}

template <typename itemsDataType>
bool quickSort(itemsDataType *items, itemsDataType (*comparisonFunction)(itemsDataType, itemsDataType), unsigned long long startIndex, unsigned long long elementsNumber)
{
  unsigned long i = startIndex - 1;
  itemsDataType tmp;
  
  if (0 <= startIndex && startIndex < elementsNumber)
  {
    for (; startIndex < elementsNumber; startIndex++)
    {
      if (comparisonFunction(items[startIndex], items[elementsNumber - 1]))
      {
        i++
        tmp = items[i];
        items[i] = items[startIndex];
        items[startIndex] = tmp;
      }
    }
    i++;
    tmp = items[i];
    items[i] = items[elementsNumber - 1];
    items[elementsNumber - 1] = tmp;
    quickSort(items, 0, i - 1);
    quickSort(items, i, elementsNumber);
  }
}

#endif