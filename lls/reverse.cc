#include <iostream>
#include <stdlib.h>
#include "singlell.h"

void usage(char** argv)
{
  std::cout<<argv[0]<<" <size> "<<std::endl;
  return;
}

sLL* reserseList(sLL* head)
{
  if ( !head ) return NULL;
  sLL* current = NULL, *next = NULL;
  while(head)
    {
      next       = head->next;
      head->next = current;
      current    = head;
      head       = next;
    }
  // std::cout<<"After Reverse"<<head->data<<std::endl;
  return current;
}
int main( int argc, char** argv )
{
  if ( argc < 2 )
    {
      usage(argv);
      exit(1);
    }
  sLL* head = NULL;
  for ( int i = 0; i <= atoi(argv[1]); i++ )
    {
      push(&head, i);
    }
  printLinkedList(&head);
  head = reserseList(head);
  std::cout<<"After Reverse"<<std::endl;
  printLinkedList(&head);
  deletesll(&head);
}
