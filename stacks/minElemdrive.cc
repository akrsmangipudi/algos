#include "minElem.h"
int main(int argc, char** argv)
{
  auxStack* a = new auxStack();
  for ( int i=5; i >= 1; i--)
    {
      a->push(i);
    }
  std::cout<<"Minimum element is "<<a->getMinimum()<<std::endl;//<<"Top of the stack is"<<a->pop()<<std::endl;
  std::cout<<a->pop()<<std::endl;
  std::cout<<"Minimum element is "<<a->getMinimum()<<std::endl;//<<"Top of the stack is"<<a->pop()<<std::endl;
  delete a;

}
