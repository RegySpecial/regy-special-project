/*
*@description Header file where is defined the dynamic array data structure class of the dynamic array data structure library
*@author Regy Special
*@date (First version [Linux/Parrot OS]) sab 7 mar 2026, 16:12:08 | 2026 March 7th Saturday, 16:12:08
*@license GNU General Public License to stop private corporation to not share source code
*/
template<typename dataType>
class linkedList{
public:
  dataType value;
  linkedList*next;
  linkedList(dataType value);
  void forEach(void(*callbackFunction)(dataType,unsigned int));
  linkedList<dataType>filter(unsigned char(*filterFunction)(dataType,unsigned int));
  linkedList<dataType>push(dataType value);
  linkedList<dataType>pop();
  linkedList<dataType>add(dataType value,unsigned long long position);
  char remove(dataType value);
  void traverse();
  ~linkedList();
};