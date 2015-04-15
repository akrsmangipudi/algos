#ifndef __SINGLELL_H_
#define __SINGLELL_H_

#include <iostream>
#include <stdlib.h>

typedef struct sLinkedList {
  int data;
  struct sLinkedList* next;
}sLL;

/* Functions to support SLL operations */
void printLinkedList(sLL **head);
void push(sLL **head,int data);
void deletesll(sLL **head);
int count(sLL *head);

void push(sLL **head,int data)
{
  sLL *newNode = (sLL*)malloc(sizeof(sLL));
  if ( !newNode ){
    std::cout<<"Error! Failed to create new node"<<std::endl;
    return;
  }
  
  newNode->data = data;
  newNode->next = *head;
  *head = newNode;  
}

void printLinkedList(sLL** head)
{
  sLL* current = *head;
  if ( !current )
    std::cout<<"Empty List"<<std::endl;
  while(current!=NULL)
    {
      std::cout<<current->data<<"->";
      current = current->next;
    }
  std::cout<<"NULL"<<std::endl;  
}

void deletesll(sLL **head)
{
  sLL *current = *head,*temp = NULL;
  
  if( !current ) return; // Nothing to do
  
  while ( current != NULL )
    {
      temp = current;
      current = current->next;
      std::cout<<"Deleting "<<temp->data<<std::endl;
      free(temp);
    }
  *head = NULL;
}


int count(sLL *head)
{
  int count = 0;
  sLL* current = head;
  while ( current != NULL )
    {
      count++;
      current = current->next;
    }
  return count;
}
#endif
