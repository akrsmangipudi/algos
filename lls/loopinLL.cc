#include <stdbool.h>

#include "singlell.h"

void createLoop(sLL** head)
{
  sLL* temp = *head;
  sLL* last = *head;
  sLL* nextNode = *head;
  int size = count(temp);
  
  /* create loop at half of the list */
  for (int i = 0; i<size/3; i++)
    temp=temp->next;
  while(nextNode!=NULL)
    {
      /* save last node pointer */
      last = nextNode;
      nextNode = nextNode->next;
    }
  /* now create loop by pointing last to middle */
  last->next = temp;
}

bool findLoop(sLL* head)
{
  sLL* slow = head;
  sLL* fast = head;
  
  while( slow && fast )
    {
      fast = fast->next;
      if ( slow == fast )
	return true;
      if ( fast == NULL )
	return false;
      fast = fast->next;
      if ( slow == fast )
	return true;
      slow = slow->next;
    }
  return false;
}

sLL* startOfLoop(sLL* head)
{
  sLL* slow = head;
  sLL* fast = head;
  
  bool loop = false;
  while ( slow && fast && fast->next )
  {
    slow = slow->next;
    fast = fast->next->next;
    if ( slow == fast )
    {
      loop = true;
      break;
    }
  }
  
  if ( loop )
  {
    unsigned int count = 1;
    while(slow->next!=fast){
      count++;
      slow=slow->next;
    }
    std::cout<<"length of loop is "<<count<<std::endl;
    
    slow = head;

    fast = head;
    for (int i=0;i<count;i++)
      fast = fast->next;

    while(slow != fast )
    {
      fast=fast->next;
      slow=slow->next;
    }
    //    sLL* temp = slow;
    fast = fast->next;
    while(fast->next != slow )
      fast = fast->next;
    fast->next = NULL;
    return slow;
  }
  return NULL;
}

sLL* findMiddle(sLL* head)
{
  sLL* slow = head;
  sLL* fast = head;
  while ( fast && fast->next )
    {
      slow=slow->next;
      fast=fast->next->next;
    }
  return slow;
}
int main(int argc, char** argv)
{

  /*Linked check if loop exists */
  /* Create a linked list with loop */

  sLL* head = NULL;
  for (int i = 0; i < 18 ; i++ )
    push(&head,i);
  printLinkedList(&head);
  std::cout<<"Middle of linked list is "<<findMiddle(head)<<" data is "<<(findMiddle(head))->data<<std::endl;
  /* check the count here */
  std::cout<<"Size of linked list is "<<count(head)<<std::endl;
  
  std::cout<<"Linked List has loop ? "<<(findLoop(head)? "True":"False")<<std::endl;
  std::cout<<"Creating Loop"<<std::endl;
  createLoop(&head);
  std::cout<<"Linked List has loop ? "<<(findLoop(head)? "True":"False")<<std::endl;
  std::cout<<"Satrt of the Loop is "<<(startOfLoop(head))->data<<std::endl;
  deletesll(&head);
}
