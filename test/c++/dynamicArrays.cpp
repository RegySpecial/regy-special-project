#include "../../src/include/lib/c++/DSA/dataStructures/dynamicArrays.hpp"
#include <string.h>

int main()
{

  dynamicArray<int> dynamic_array(40);

  int scanfExit,
      pushScanExit,
      popScanExit;

  char commandInput[10];
	unsigned char mask = 0;

  do
  {
		const char *commandList[] = {"push", "pop", "insert", "at", "remove", "exit"};
		printf("Print the operation to execute with the dynamic array:");
		scanfExit = scanf("%s", commandInput);

		for (unsigned char commandIndex = 0; commandIndex < sizeof commandList / sizeof *commandList; commandIndex++)
		  mask |= !strcasecmp(commandInput, commandList[commandIndex]);
    
		if (!mask)
		  failureMessage("INVALID COMMAND!");
    else if (!strcasecmp(commandInput, "push"))
      do
      {
        int numberToPush;
        printf("Print a number to push into the dynamic array:");
	      pushScanExit = scanf("%d", &numberToPush);
        if(!pushScanExit)
          failureMessage("INVALID NUMBER TO PUSH!");
        else
          dynamic_array.push(numberToPush);
        while(getchar() != '\n');
      }
      while(!pushScanExit);
    else if (!strcasecmp(commandInput, "pop"))
      dynamic_array.pop();

    dynamic_array.forEach([](int element)
    {
      printf("element %i of dynamic_array\n", element);
    });
  }
  while (strncasecmp(commandInput, "exit", 4));

  OKMessage("Main process exited with status 0!");

  return 0;
}