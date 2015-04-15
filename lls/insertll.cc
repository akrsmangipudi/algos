#include <iostream>
#include <stdlib.h>
#include "singlell.h"

void usage(char** argv)
{
  std::cout<<argv[0]<<" "<<"<Size> <Position> <Data>"<<std::endl;
  return;
}
void insertat( sLL** head, int data, int pos)
{
  int k=1;
  sLL* p,*q;
  sLL* newNode = (sLL*)malloc(sizeof(sLL));
  if ( !newNode )
    {
      std::cout<<"ERROR: Memory allocation failed"<<std::endl;
      return;
    }
  newNode->data = data;
  newNode->next = NULL;
  p = *head;
  if ( pos == 1 )
    {
      newNode->next = p;
      *head = newNode;
      return;
    }
  else 
    {
      while ( p != NULL && k < pos )
	{
	  q = p;
	  p = p->next;
	  k++;
	}
      newNode->next = p;
      q->next = newNode;
      return;
    }
}

void deleteNode( sLL** head, int pos )
{
 
  if ( !*head )
    {
      std::cout<<"Empty list, nothing to delete"<<std::endl;
      return;
    }
  sLL* p, *q; 
  int k = 1;
  p = *head;
  /* Special case deleting head */
  if ( pos == 1 )
    {
      *head = (*head)->next;
      free(p);
      return;
    }
  else
    {
      while ( p != NULL && k < pos )
	{
	  q = p;
	  p = p->next;
	  k++;
	}
      if ( p == NULL )
	{
	  std::cout<<"Error Position doesn't exist"<<std::endl;
	  return;
	}
      else
	{
	  q->next = p->next;
	  free(p);
	  return;
	}
    }
}
int main(int argc, char** argv)
{
  if ( argc < 4 )
    {
      usage(argv);
      exit(1);
    }
  int size = atoi(argv[1]);
  int pos = atoi(argv[2]);
  int data = atoi(argv[3]);

  sLL* head = NULL;
  for ( int i = 0; i < size; i++ )
    {
      push(&head,i);
    }
  insertat(&head, data, pos);
  printLinkedList(&head);
  std::cout<<"Delete node at a position"<<std::endl;
  std::cin>>pos;
  deleteNode(&head, pos);
  printLinkedList(&head);
  deletesll(&head);
}
