#include <iostream>
#include <stdlib.h>

typedef struct linkedList {
  int data;
  struct linkedList* next;
  struct linkedList* arbitary;
}aDLL;

// Create a list with next and arbitary points
//       ^------------->| 
//  |<---|----|<--------|
//  2 -> 3 -> 4 -> 5 -> 6 
//  |         ^    |    ^
//  |_________|    |____| 
//   
void createList()
{
  aDLL* list = NULL, *tail = NULL;
  for ( int i=2 ; i <= 6 ; i++ )
    {
      aDLL* newNode = (aDLL*)malloc(sizeof(aDLL));
      if ( !newNode )
	{
	  std::cout<<"Error: Node creation Failed"<<std::endl;
	  exit(1);
	}
      newNode->data = i;
      newNode->next = NULL;
      // First Node
      if ( !list && !tail)
	{
	list = newNode;
	}
      else
	
    }
  aDLL* newNode
}
