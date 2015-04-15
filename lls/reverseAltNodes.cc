#include <iostream>
#include <stdlib.h>
#include "singlell.h"

void usage(char** argv)
{
  std::cout<<argv[0]<<" <size> "<<std::endl;
  return;
}

void reverse(sLL** head)
{
  if ( !*head ) return;
  sLL* next, *current=NULL;
  while (*head)
    {
      next = (*head)->next;
      (*head)->next = current;
      current = *head;
      *head = next;
    }
  *head = current;
  return;
}
void splitAlt(sLL* head, sLL** list1, sLL** list2)
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

void altSplitReverse(sLL* head)
{
  if ( !head || !head->next ) return; 
  sLL* current = head;
  sLL* list1 = NULL, *list2 = NULL;
  splitAlt(head, &list1, &list2);
  sLL* temp = list1;

  while ( temp->next)
    temp = temp->next;

  reverse(&list2);
  temp->next = list2;
  std::cout<<"Alternate Split list is "<<std::endl;
  printLinkedList(&list1);
  
}
int main(int argc, char** argv)
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
  std::cout<<"Original Linked List is"<<std::endl;
  printLinkedList(&head);
  altSplitReverse(head);
}
