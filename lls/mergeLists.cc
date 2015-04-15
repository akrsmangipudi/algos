#include <iostream>
#include <stdlib.h>
#include "singlell.h"

void usage(char** argv)
{
  std::cout<<argv[0]<<" <List size> "<<std::endl;
  return;
}

void moveNode(sLL** dest, sLL** source)
{
  sLL* temp    = (*source);
  (*source)    =  temp->next;
  // temp->next   = *dest;
  temp->next   = NULL;
  *dest        = temp;
}
void mergeLists(sLL* list1, sLL* list2)
{
  if ( !list1 && !list2 )
    return;
  sLL* root = NULL;
  sLL** lastRef = &root;
  while (1)
    {
      if ( list1 == NULL )
	{
	  *lastRef = list2;
	  break;
	}
      else if ( list2 == NULL )
	{
	  *lastRef = list1;
	  break;
	}
      else if ( list1->data <= list2->data )
	{
	  moveNode(lastRef, &list1);
	}
      else
	{
	  moveNode(lastRef, &list2);
	}
      lastRef = &((*lastRef)->next);
    }
  printLinkedList(&root);
  deletesll(&root);
  return;
}
int main( int argc, char** argv )
{
  if ( argc < 2 )
    {
      usage(argv);
      exit(1);
    }
  sLL* list1 = NULL, *list2 = NULL;
  for ( int i = atoi(argv[1]) ; i >= 0  ; i-- )
    {
      if ( i % 2 != 0 )
	push(&list1, i);
      else
	push(&list2, i);
    }

  std::cout<<"First List"<<std::endl;
  printLinkedList(&list1);
  std::cout<<"Second List"<<std::endl;
  printLinkedList(&list2);

  mergeLists(list1, list2);

  // deletesll(&list1);
  // deletesll(&list2);
}
