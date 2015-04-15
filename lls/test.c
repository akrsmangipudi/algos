#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  unsigned int *a = (unsigned int*) malloc(sizeof(unsigned int));
  *a = 1;
  printf("Address of a is %p 0x%x and data is %d\n",a, (unsigned int) a , *a);
  free(a);
  printf("Address of a is %p 0x%x and data is %d\n",a, (unsigned int) a , *a);
  int b = 1; 
  if ( *((char*) (&b)) == 1 )
    printf("Little end");
  else
    printf("GO");
  printf("Address of code segment %p\n", (void*) main);
  printf("Address of heap  is %p\n", (void*) malloc(1));
  printf("Address of stack  is %p\n", (void*) &b);
  return 1;
}
