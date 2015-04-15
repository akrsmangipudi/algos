//#include <stdlib.h>
#include <iostream>
#include "singlell.h"

int main(int argc, char** argv)
{
  sLL* head = NULL;
  for ( int i = 1; i <=5 ; i++ )
    {
      push(&head,i);
    }
  sLL* temp = head;
  sLL* prev = temp;
  while (temp->next)
    {
      prev = temp;
      temp = temp->next;
    }
  printLinkedList(&head);
  std::cout<<prev<<": prev data: "<<prev->data<<"  "<<temp<<": temp data is "<<temp->data<<std::endl;
  free(temp);
  // free(temp);
  //delete temp;
  // prev->next = temp + sizeof(sLL);
  std::cout<<prev->next<<" "<<prev->next->data<<std::endl;
  deletesll(&head);
  std::cout<<prev->next<<std::endl;
  return 1;
}
