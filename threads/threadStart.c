#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>
static volatile int counter = 0;
void *foo(void* arg)
{
  printf("%s: Begin \n", (char*) arg);
  int i;
  for (i = 0; i < 1e7; i++)
    {
      counter += 1;
    }
  printf("%s: Done \n", (char*) arg);
  return NULL;
}

int main(int argc, char* argv[])
{
  pthread_t p1,p2;
  int rc;
  printf("Main: Start \n");
  rc = pthread_create(&p1, NULL, foo, "A"); assert( rc == 0 );
  rc = pthread_create(&p2, NULL, foo, "B"); assert( rc == 0 );
  rc = pthread_join(p1, NULL ); assert( rc == 0 );
  rc = pthread_join(p2, NULL ); assert( rc == 0 );
  printf("Final counter value is ( counter = %d ) \n", counter);
  printf("Main: End \n");
  return 0;
}
