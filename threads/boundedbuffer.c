#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>
#include <semaphore.h>

#define MAX 10

int buffer[MAX];
int fill = 0;
int use  = 0;

/* Semaphore declaration */

sem_t full;
sem_t empty;
sem_t lock;

void put( int it)
{
  buffer[fill] = it; 
  fill = ( fill +1 ) % MAX;
}
int get()
{
  int temp = buffer[use];
  use = (use+1) % MAX;
  return temp;
}
void* producer(void* arg)
{
  int i; 
  int *threadNum = (int*) (arg);
  printf("PROD:Thread %d created\n",*threadNum);
  for ( i = 0; i < 5; i++ )
    {
      sem_wait(&empty);
      sem_wait(&lock);
      put(i);
      sem_post(&lock);
      sem_post(&full);
    }
		      
}
void* consumer(void* arg)
{
  int i; 
  int *threadNum = (int*) (arg);
  printf("CONS:Thread %d created\n",*threadNum);
  for ( i = 0; i < 5; i++ )
    {
      sem_wait(&full);
      sem_wait(&lock);
      int item = get(i);
      sem_post(&lock);
      sem_post(&empty);
      printf(" Item is %d \n ", item);	     
    }
		      
}
int main(int argc, char** argv) 
{
  int i =0,j=0, loop =2;
  int rc = 0;
  pthread_t t[20];
  sem_init(&empty, 0, MAX);
  sem_init(&full, 0, 0);
  sem_init(&lock, 0, 1);
  for ( i = 0; i < loop ; i++ )
    {
      if ( i % 2)
	{
	  rc = pthread_create(&t[i], NULL, producer, &i); assert( rc == 0 );
	}
      else
	{
	  rc = pthread_create(&t[i], NULL, consumer, &i); assert( rc == 0 );
	}
    }
  for ( j = 0; i < loop ; j++ )
    {
      rc = pthread_join(t[j], NULL); assert( rc == 0 );
    }
}
