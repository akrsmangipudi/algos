#ifndef __POINTS_H_
#define __POINTS_H_

#include <stdlib.h>
typedef struct fooStruct{
  int a;
  int b;
  int c;
}foostr;

int main(int argc, char **argv)
{
  int** iArray;
  foostr** fooArray;
  iArray = (int**)malloc(sizeof(int**) * 100);
  fooArray = (foostr**)malloc(sizeof(foostr**)*100);
  /* for ( int i=0;i < 100; i++ ) */
  /*   { */
      
  /*   } */
  int k = 10;
  //int* l = &k;
  iArray[0] = &k;
  /* foostr foo1; */
  /* foo1.a = 0; */
  /* foo1.b = 0; */
  /* foo1.c = 0; */
  /* fooArray[0] = &foo1; */
  /* printf("Address of foo1 is 0x%x and foo.a is 0x%x\n",&foo1,&foo1.a); */
  return 0;
}

#endif
