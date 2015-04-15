#include <iostream>
#include <stdlib.h>

class stack
{
  typedef struct singlell{
    int data;
    struct singlell* next;
  }sll;
  sll* head;
public:
  stack() { head = NULL; }
  void push(int);
  int pop();
};

void
stack::push(int data)
{
  sll* node = (sll*) malloc (sizeof(sll));
  if ( !node )
    {
      std::cout<<"Memory failure"<<std::endl;
      abort();
    }
  node->data = data;
  node->next = head;
  head       = node;
}
int
stack::pop()
{
  if ( !head )
    {
      std::cout<<"Stack Underflow"<<std::endl;
      abort();
    }
  int k = head->data;
  sll* temp = head;
  head = head->next;
  free(temp);
  return k;
}

int main(int argc, char** argv)
{
  stack* mystack = new stack();
  for ( int i=0 ; i<10 ; i++ )
    mystack->push(i);
  for ( int i=0 ; i<10 ; i++ )
    std::cout<<"Deleting " << mystack->pop() << " from stack"<<std::endl;

}
