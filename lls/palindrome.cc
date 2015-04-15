#include <stdbool.h>
#include <iostream>
#include <stack>
#include "singlell.h"

bool isPalindrome(sLL* head)
{
  bool isPalindrome = false;
  sLL* temp = head,*slow = head, *fast = temp;
  std::stack<sLL*> myStack;
  while ( fast && fast->next )
    {
      fast = fast->next->next;
      myStack.push(slow);
      slow = slow->next;
    }
  if(fast) // odd length
    slow = slow->next; //forward slow one more
  while ( slow && !myStack.empty() )
    {
      if ( slow->data != myStack.top()->data)
        return false;
      else
	{
	  slow = slow->next;
	  myStack.pop();
	}
    }
  return true;
}
int main(int argc, char** argv)
{

  /*Linked check if loop exists */
  /* Create a linked list with loop */

  sLL* head = NULL;
  for (int i = 1; i < 6 ; i++ )
    push(&head,i);
  for (int i =4; i>0 ; i--)
    push(&head,i);
  printLinkedList(&head);
  std::cout<<"Is the list palindrome?"<<(isPalindrome(head)?"True":"False")<<std::endl;
  deletesll(&head);
}
