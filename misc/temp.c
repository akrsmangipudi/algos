#ifndef __POINTS_H_
#define __POINTS_H_

#include <stdlib.h>
#include <stdio.h>
#define  FOO_ARRAY_SIZE 100
typedef struct fooStruct{
  int a;
  int b;
  int c;
}foostr;
void bar(foostr* fooArray);
foostr* findElement(foostr* fooArray,int idx);
foostr* findElement(foostr* fooArray,int idx)
{
  return &fooArray[idx];
}
void bar(foostr* fooArray)
{
  foostr* elm = findElement(fooArray,0);
  printf("Elements are %d,%d and %d\n",elm->a,elm->b,elm->c);
}
int main(int argc, char **argv)
{
  foostr* fooArray;
  fooArray = (foostr*) malloc (sizeof(FOO_ARRAY_SIZE * sizeof(foostr)));
  foostr foo;
  foo.a=foo.b=foo.c=10;
  fooArray[0] = foo;
  printf("size of struct is %lu and size of a is %lu\n",sizeof(foostr),sizeof(foo.a));
  printf("size of struct is %lu and elements are %d,%d and %d\n",sizeof(fooArray),fooArray[0].a,fooArray[0].b,fooArray[0].c);
  bar(fooArray);
  return 0;
}

#endif
