#include <iostream>
#include <stack>
#include <string.h>
#include <algorithm>
#include <ctype.h>

typedef struct _converstion_t
{
  char* source;
  char* result;
  std::stack<char> *opStack;
} conversion_t;

void usage(char** argv)
{
  std::cout<<argv[0]<<" <Expression> "<<std::endl;
}

char *strrev(char *str)
{
  char *p1, *p2;

  if (! str || ! *str)
    return str;
  for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
      *p1 ^= *p2;
      *p2 ^= *p1;
      *p1 ^= *p2;
    }
  return str;
}

int priority ( char op )
{
  switch ( op )
    {
    case '$': return 3;
    case '*':
    case '/': return 2;
    case '+':
    case '-': return 1;
    default : return 0;
    }
}
void prefixConversion( conversion_t* prefix )
{
  // Reverse the input infix string.
  strrev(prefix->source);
  std::cout<<"Reverse Expression "<<prefix->source<<std::endl;
  
  char op;
  
  while ( *(prefix->source) )
    {
      if ( *(prefix->source) == ' ' || *(prefix->source) == '\t' )
	{
	  prefix->source++;
	  continue;
	}
	if ( isdigit( *(prefix->source) ) || isalpha( *(prefix->source) ) )
	  {
	    while ( isdigit( *(prefix->source) ) || isalpha( *(prefix->source) ) )
	      {
		*(prefix->result) = *(prefix->source);
		prefix->source++;
		prefix->result--;
	      }
	  }
	if ( *(prefix->source) == ')' )
	  {
	    prefix->opStack->push( *(prefix->source) );
	    prefix->source++;
	  }
	if ( *(prefix->source) == '*' || *(prefix->source) == '/' ||
	     *(prefix->source) == '+' || *(prefix->source) == '-' ||
	     *(prefix->source) == '$' )
	  {
	    if ( !prefix->opStack->empty() )
	      {
		op = prefix->opStack->top();
		while ( !prefix->opStack->empty() && priority(op) > priority ( *(prefix->source) ) )
		  {
		    op = prefix->opStack->top();
 		    *(prefix->result) = op;
		    prefix->result--;
		    prefix->opStack->pop();		    
		  }
		  prefix->opStack->push(*(prefix->source));
	      }
	    else
	      prefix->opStack->push(*(prefix->source));
	    prefix->source++;
	  }
	if ( *(prefix->source) == '(' )
	  {
	    while ( !prefix->opStack->empty() && prefix->opStack->top() != ')' )
	      {
		op = prefix->opStack->top();
		*(prefix->result) = op;
		prefix->result--;
		prefix->opStack->pop();		    		
	      }
	    prefix->opStack->pop();
	    prefix->source++;
	  }
    }
  // std::cout<<"Size of stack is"<<prefix->opStack->empty()<<std::endl;
  while ( !prefix->opStack->empty() )
    {
      op = prefix->opStack->top();
      *(prefix->result) = op;
      prefix->result--;
      prefix->opStack->pop();		    		
    }
  prefix->result++;
  std::cout<<"Prefix Expresion is "<<prefix->result<<std::endl;
  return; 
  
}
void postfixConversiion(conversion_t* postfix)
{
  // Reverse the input infix string.
  
  // postfix->result = &postfix->result[0];// postfix->result - strlen(postfix->source);
  char op;
  // char temp[20];
  char* foo = &postfix->result[0];
  
  while ( *(postfix->source) )
    {
      if ( *(postfix->source) == ' ' || *(postfix->source) == '\t' )
	{
	  postfix->source++;
	  continue;
	}
	if ( isdigit( *(postfix->source) ) || isalpha( *(postfix->source) ) )
	  {
	    while ( isdigit( *(postfix->source) ) || isalpha( *(postfix->source) ) )
	      {
		*(postfix->result) = *(postfix->source);
		// std::cout<<postfix->result<<*(postfix->result)<<" "<<std::endl;
		postfix->source++;
		postfix->result++;
	      }
	  }
	if ( *(postfix->source) == '(' )
	  {
	    postfix->opStack->push( *(postfix->source) );
	    postfix->source++;
	  }
	if ( *(postfix->source) == '*' || *(postfix->source) == '/' ||
	     *(postfix->source) == '+' || *(postfix->source) == '-' ||
	     *(postfix->source) == '$' )
	  {
	    if ( !postfix->opStack->empty() )
	      {
		op = postfix->opStack->top();
		while ( !postfix->opStack->empty() && priority(op) >= priority ( *(postfix->source) ) )
		  {
		    op = postfix->opStack->top();
 		    *(postfix->result) = op;
		    // std::cout<<*(postfix->result)<<" "<<std::endl;
		    postfix->result++;
		    postfix->opStack->pop();		    
		  }
		  postfix->opStack->push(*(postfix->source));
	      }
	    else
	      postfix->opStack->push(*(postfix->source));
	    postfix->source++;
	  }
	if ( *(postfix->source) == ')' )
	  {
	    while ( !postfix->opStack->empty() && postfix->opStack->top() != '(' )
	      {
		op = postfix->opStack->top();
		*(postfix->result) = op;
		// std::cout<<*(postfix->result)<<" "<<std::endl;
		postfix->result++;
		postfix->opStack->pop();		    		
	      }
	    postfix->opStack->pop();
	    postfix->source++;
	  }
    }
  // std::cout<<"Size of stack is"<<postfix->opStack->empty()<<std::endl;
  while ( !postfix->opStack->empty() )
    {
      op = postfix->opStack->top();
      *(postfix->result) = op;
      // std::cout<<*(postfix->result)<<" "<<std::endl;
      postfix->result++;
      postfix->opStack->pop();		    		
    }
  *(postfix->result) = '\0';
  //postfix->result = &postfix->result[0];
  std::cout<<"Postfix Expresion is "<<foo<<std::endl;
  return;
}
conversion_t* initStruct(char* expr,bool flag)
{
// Convert here to Prefix from Infix
  conversion_t* prefix = (conversion_t*) malloc (sizeof(conversion_t));
  
  if ( !prefix ) { std::cout<<"Memory allocation error"<<std::endl; exit(1); } 
  // Copy input infix expression to source string
  prefix->source = (char*) malloc (sizeof(char) * (strlen(expr) + 1));
  prefix->result = (char*) malloc (sizeof(char) * (strlen(expr) + 1));
  if  ( flag ) {
  prefix->result[strlen(expr)] = '\0';
  prefix->result = prefix->result + (strlen(expr) - 1);
  }
  strcpy( prefix->source, expr );
  prefix->opStack = new std::stack<char>();
  return prefix;
}
int main(int argc, char* argv[])
{
  if ( argc < 2 )
    {
      usage(argv);
      exit(1);
    }
  char* expr = argv[1];
  std::cout<<" Infix Expression is "<<expr<<std::endl; 

  // Convert here to Prefix from Infix
  conversion_t* prefix = initStruct(expr,true);
  prefixConversion(prefix);
  conversion_t* postfix = initStruct(expr,false);
  postfixConversiion(postfix);

  if ( prefix ) { // free(prefix->source); free(prefix->result); 
    delete prefix->opStack; free(prefix); }
  if ( postfix )
   if ( prefix ) { // free(prefix->source); free(prefix->result); 
    delete postfix->opStack; free(postfix); }

}
