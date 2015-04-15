#include "stack.h"

int main(int argc, char** argv)
{
  std::cout<<"Simple test of stack with integer data type"<<std::endl;
  size_t size = 10;
  Stack<int>* myStack = new Stack<int>(size);
  myStack->push(1);
  myStack->push(2);
  for ( int i = 0; i < 3 ; i++ )
    std::cout<<"Pop from stack  "<<myStack->pop()<<std::endl;
  delete myStack;
  Stack<float>* floatStack = new Stack<float>();
  floatStack->push(1.123232);
  for ( int k = 0 ; k < 6; k++)
    floatStack->push(2.234334);
  for ( int i = 0; i < 6 ; i++ )
    std::cout<<"Pop from stack  "<<floatStack->pop()<<std::endl;
  delete floatStack;
  return 1;
}
