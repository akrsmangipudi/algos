#include "minElem.h"

int auxStack::pop()
{
  if ( !minStack.empty() )
    minStack.pop();
  if ( !myStack.empty() )
    {
     int element = myStack.top();
     myStack.pop();
     return element;
    }
  else 
    {
      std::cout<<"Error - Stack is empty"<<std::endl;
    }
}

int auxStack::getMinimum()
{
  
  if ( !minStack.empty() )
    {
     int element = minStack.top();
     // minStack.pop();
     return element;
    }
  else 
    {
      std::cout<<"Error - Stack is empty"<<std::endl;
    }
}

void auxStack::push(int element)
{

  myStack.push(element);
  !minStack.empty()?( element < minStack.top() ? minStack.push(element) : minStack.push(minStack.top())):minStack.push(element); 
}
