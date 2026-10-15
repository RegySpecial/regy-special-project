#include <iostream>
#include <stdlib.h>

template<typename T>
class alloc
{
public:
  T *pointer;
  size_t size;
  alloc(T *pointer, size_t size)
  {
    this->size = size;
    this->pointer = (T *) malloc(this->size * sizeof (T));
    for (size_t i = 0; i < this->size; i++)
      this->pointer[i] = pointer[i];
  }
  ~alloc()
  {
    this->size = 0;
    free(this->pointer);
    this->pointer = NULL;
  }
};

template<typename T>
class alloc1
: public alloc<T>
{
public:
  alloc1(T *pointer, size_t size) : alloc<T>::alloc(pointer, size)
  {
    coso:
    for (size_t i = 0; i < this->size - 1; i++)
      for (size_t j = i + 1; j < this->size; j++)
        if (this->pointer[i] == this->pointer[j])
        {
          for (size_t k = j; k < this->size - 1; k++)
            this->pointer[k] = this->pointer[k + 1];
          --this->size;
          goto coso;
        }
  }
};

int main() {
  int array[] = {5, 5, 5, 3, 21, 2, 213, 23, 21, 4, 6, 6};
  size_t size = sizeof array / sizeof *array;
  alloc1<int> a(array, size);
  for (size_t i = 0; i < a.size; i++)
    std::cout << a.pointer[i] << '\n';
  return 0;
}