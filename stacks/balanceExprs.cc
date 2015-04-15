#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
// #include <stdbool>
void usage( char** argv )
{
  std::cout<<argv[0]<<" <Expression> "<<std::endl;
}
bool isMatchingExpr(char a, char b)
{
  if ( a == '(' && b == ')' ) return true;
  else if ( a == '{' && b == '}' ) return true;
  else if ( a == '[' && b == ']' ) return true;
  else
    return false;
}
int main(int argc, char** argv)
{
  if ( argc < 2 )
    {
      usage(argv);
      exit(1);
    }
  std::stack<char>* myStack = new std::stack<char>();
  char* expr = argv[1];
  std::cout<<"Expression is "<<expr<<std::endl;
  int i = 0;
  while ( expr[i] )
    {
      if ( expr[i] == '(' || expr[i] == '[' || expr[i] == '{' )
	myStack->push(expr[i]);
      else if ( expr[i] == ')' || expr[i] == ']' || expr[i] == '}' )
	{
	  if ( myStack->empty() )
	    {
	      std::cout<<"Error: Not a balanced expression"<<std::endl;
	      delete myStack;
	      return 0;
	    }
	  else if ( !isMatchingExpr(myStack->top(), expr[i] ) )
	    {
	      std::cout<<"Error: Not a balanced expression"<<std::endl;
	      delete myStack;
	      return 0;
	    }
	    myStack->pop();
	}
	  i++;
    }
  if ( myStack->empty() )
    std::cout<<"Balanced Expression"<<std::endl;
  else 
    std::cout<<"Not Balanced Expression"<<std::endl;
  delete myStack;
  return 1;
}
