#include <stdio.h>

int main()
{
  unsigned int array[] = {0,12,3,213,3,32,213,324,12,4,32};

  unsigned long size = sizeof array / sizeof *array;
  for (unsigned long i = 0; i < size - 1; i++)
    for (unsigned long j = i + 1; j < size; j++)
      if (array[i] == array[j])
      {
        for (unsigned long k = j; k < size - 1; k++)
          array[k] = array[k + 1];
        --size;
      }
  
  for (unsigned long long b = 0; b < size; b++)
    printf("%u%c", array[b], b < size - 1 ? ' ' : '\n');

  return 0;
}
