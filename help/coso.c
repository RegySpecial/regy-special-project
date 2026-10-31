#include <stdio.h>

void noRepeat(int array[], unsigned long *size)
{
  for (unsigned long i = 0; i < *size - 1; i++)
    for (unsigned long j = i + 1; j < *size;)
      if (array[i] == array[j])
      {
        (*size)--;
        for (unsigned long k = j; k < *size; k++)
          array[k] = array[k + 1];
      }
      else
        j++;
}

int main()
{
  int array[] = {5, 5, 5, 3, 5, 3, 3, 6, 4, 6, 4};

  unsigned long size = sizeof array / sizeof *array;
  noRepeat(array, &size);
  
  for (unsigned long long b = 0; b < size; b++)
    printf("%u%c", array[b], b < size - 1 ? ' ' : '\n');

  return 0;
}
