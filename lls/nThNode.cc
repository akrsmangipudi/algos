#include <iostream>
#include <stdlib.h>
#include "singlell.h"
void usage(char **argv)
{
  std::cout<<argv[0]<<" <Size> <NthNode> "<<std::endl;  
}
void printNthNodeFromLast( sLL* head, int pos )
{
  if ( !head ) return;
  sLL* temp = head;
  sLL* nodeN = head;
  int count = 1; 
  while ( temp != NULL && count < pos )
    {
      temp = temp->next;
      count++;
    }
  if ( temp == NULL && count <= pos )
    {
      std::cout<<"Error: Position doesn't exist"<<std::endl;
      return;
    }
  while ( temp->next != NULL )
    {
      nodeN = nodeN->next;
      temp  = temp->next;
    }
  std::cout<<pos<<"th Node from last is : "<<nodeN->data<<std::endl;
}
int main(int argc, char** argv)
{
  if ( argc < 3 )
    {
      usage(argv);
      exit(1);
    }
  int size = atoi(argv[1]);
  int pos  = atoi(argv[2]);
  sLL* head = NULL;
  for ( int i = 0 ; i < size ; i++ )
    {
      push(&head, i);
    }
  printLinkedList(&head);
  printNthNodeFromLast(head, pos);
  deletesll(&head);
}
