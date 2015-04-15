#include "singlell.h"

sLL* findNthFromLast(sLL** headRef,int position)
{
  int curPos = 0;
  sLL* temp = *headRef;
  sLL* NthNode = *headRef;
  if ( !temp )
  {
    std::cout<<"Empty List"<<std::endl;
    return NULL;
  }
  while ( temp != NULL )
  {
      if ( curPos == position )
	break;
      curPos++;
      temp = temp->next;
  }
  if ( temp == NULL && curPos < position )
  {
    std::cout<<"Boundary condition"<<std::endl;
    return NULL;
  }
  else
  {
    while ( temp != NULL )
    {
      temp = temp->next;
      NthNode = NthNode->next;
    }
    return NthNode;
  }
}

int main(int argc,char **argv)
{

  /* kick start to demo sLL operations; */
  sLL *head = NULL;
  std::cout<<"Size of List " <<count(head)<<std::endl;
  push(&head,1);
  push(&head,2);
  push(&head,3);
  push(&head,4);
  
  printLinkedList(&head);
  std::cout<<"Size of List " <<count(head)<<std::endl;
  
  for( int i=0 ; i < count(head)+2;i++)
    {
      sLL* temp = findNthFromLast(&head,i);
      if ( temp )
	std::cout<<"Node "<<i<<" from Last is "<<temp->data<<std::endl;
    }
  deletesll(&head);
  std::cout<<"Size of List " <<count(head)<<std::endl;
  
}
