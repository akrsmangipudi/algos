#include <iostream>
#include <stdlib.h>
#include "singlell.h"

void usage(char** argv)
{
  std::cout<<argv[0]<<" <size> "<<std::endl;
  return;
}

void alternateSplit(sLL* head, sLL** list1, sLL** list2)
{
  if ( !head || !head->next )
    {
      *list1 = head;
      return;
    }
  sLL* current = head, *tail1 = NULL, *tail2 = NULL;
  while ( current && current->next )
    {
      if ( !*list1 )
	{
	  *list1 = current;
	   tail1 = current;
	}
      else
	{
	  tail1->next = current; 
	  tail1       = current;
	}
      if ( !*list2 ) 
	{
	  *list2 = current->next;
	   tail2 = current->next;
	}
      else
	{
	  tail2->next = current->next; 
	  tail2       = current->next;
	}
      current = current->next->next;
    }
  if ( current ) { tail1->next = current; tail1 = current;}
  tail1->next = NULL;
  tail2->next = NULL;
  return;
}

int main( int argc, char** argv )
{
  if ( argc < 2 )
    {
      usage(argv);
      exit(1);
    }
  sLL* head = NULL;
  for ( int i = atoi(argv[1]); i >= 1 ; i-- )
    {
      push(&head, i);
    }
  sLL* list1 = NULL, *list2=NULL;
  std::cout<<"Original Linked List is"<<std::endl;
  printLinkedList(&head);
  alternateSplit(head, &list1, &list2);
  std::cout<<"First Linked List is"<<std::endl;
  printLinkedList(&list1);
  std::cout<<"Second Linked List is"<<std::endl;
  printLinkedList(&list2);
  deletesll(&list1);
  deletesll(&list2);
}
