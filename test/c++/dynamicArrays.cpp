#include "../../src/include/lib/c++/DSA/dataStructures/dynamicArrays.hpp"
#include <string.h>

int main()
{

  dynamicArray<int> dynamic_array(40);

  int scanfExit;

  char commandInput[10];
	unsigned char mask = 0;

  do
  {
		const char *commandList[] = {"push", "pop", "insert", "at", "remove", "exit"};
		printf("Print the operation to execute with the dynamic array:");
		scanfExit = scanf("%s", commandInput);
		for (unsigned char commandIndex = 0; commandIndex < sizeof commandList / sizeof * commandList; commandIndex++)
		  mask |= !!strcasecmp(commandInput, commandList[commandIndex]);
		if (!mask)
		  failureMessage("INVALID COMMAND!");
    else if (!strcasecmp(commandInput, "push"))
      dynamic_array.push(0);
		
    printf("%s %i\n", commandInput, scanfExit);
  }
  while (strncasecmp(commandInput, "exit", 4));

  printf("%s %i\n", commandInput, scanfExit);

  return 0;
}