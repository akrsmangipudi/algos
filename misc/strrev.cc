#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
void reverse(char* str, char* end)
{
  // int len = strlen(str);
  char* start = str;
  // char* end   = str+len-1;
  while ( start < end )
    {
      // printf("loop %p \n",start);
      // printf("loop %p \n",end);
      char temp = *start;
      *start++  = *end;
      *end--    = temp;
    }
  // printf("string is %s\n",str);
  return;
}
void reverseWords(char* str)
{
  char* word_begin = NULL;
  char* temp       = str;
  while ( *temp )
    {
      if ( ( word_begin == NULL ) && ( *temp != ' ' ) )
	{
	  word_begin = temp;
	}
      if ( word_begin && ((*(temp+1) == ' ') || ( *(temp+1) == '\0' )))
	{
	  reverse(word_begin,temp);
	  word_begin = NULL;
	}
      temp++;
    }
  reverse(str, temp-1);
}
int main(int argc, char** argv)
{
  char* string = (char*) argv[1];
  // char s[] = "Sandeep Ummadi";
  reverseWords(string);
  printf(" %s \n", string);
  return 0;
}
