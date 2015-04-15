#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <assert.h>

#define SIZE  2
#define COUNT 2

typedef struct _buffer_t {
  int*  buffer; // buffer array
  int   n; //size of bounded buffer 
  int   head; // front
  int   tail; // back
  sem_t mutex; // locking mutex;
  sem_t slots; // for producer
  sem_t items; // for consumer
}buf_t;

void* producer(void* args);
void* consumer(void* args);

buf_t* bufInit(void);
void addItem(buf_t* b, int item);
void removeItem(buf_t* b, int *item);
void deleteBuf(buf_t* b);

  
int main(int argc, char** argv)
{
  buf_t* queue;
  pthread_t prod, cons;
  pthread_t prod2, cons2;
  queue = bufInit();
  
  if ( queue == NULL ) {
    printf(" Error! No memory available\n");
    exit(1);
  }
  int rc = pthread_create( &prod, NULL, producer, (void*) queue);
  assert ( rc == 0 );
  rc = pthread_create( &cons, NULL, consumer, (void*) queue);
  assert ( rc == 0 );
  rc = pthread_create( &prod2, NULL, producer, (void*) queue);
  assert ( rc == 0 );
  rc = pthread_create( &cons2, NULL, consumer, (void*) queue);
  assert( rc == 0 );
  pthread_join(prod, NULL);
  pthread_join(cons, NULL);
  pthread_join(prod2, NULL);
  pthread_join(cons2, NULL);
  printf( " Cleaning memory \n "); 
  deleteBuf(queue);

  return 0;
}

buf_t* bufInit(void)
{
  buf_t* b = (buf_t*) malloc (sizeof(buf_t));
  if ( !b ) return NULL;

  b->buffer = (int*) malloc( SIZE * sizeof(int) );
  if ( !b->buffer ) return NULL;
  b->n = SIZE;
  b->head = b->tail = 0;
  sem_init(&b->mutex, 0, 1);
  sem_init(&b->slots, 0, b->n);
  sem_init(&b->items, 0, 0);
  return b;
}

void* producer(void* q)
{
   buf_t* queue = (buf_t*)q;
   int i = 0;
   for ( i = 0; i < COUNT; i++ ) {
     printf("Producer: %p,   Adding item: %4d\n", (void*) pthread_self(), i); 
     addItem(queue, i);
   }
   usleep(10000);
   for ( i = 0; i < COUNT; i++ ) {     
     printf("Producer: %p,   Adding item: %4d\n",(void*) pthread_self(), i); 
     addItem(queue, i);
   }
   usleep(10000);
   return NULL;
}

void* consumer(void* q)
{
  buf_t* queue = (buf_t*) q;
  int i = 0, d;
  for ( i = 0; i < COUNT; i++ ){
    removeItem(queue, &d);
    printf("Consumer: %p,   Received item: %4d\n", (void*) pthread_self(), d);
  }
  usleep(10000);
  for ( i = 0; i < COUNT; i++ ){
    removeItem(queue, &d);
    printf("Consumer: %p,   Received item: %4d\n",(void*) pthread_self(), d);
  }
  usleep(10000);
}

void addItem(buf_t* b, int item)
{
  sem_wait(&b->slots);
  sem_wait(&b->mutex);
  printf("Placing at position %d and %d \n", (b->tail % b->n), b->n);
  b->buffer[(b->tail++) % (b->n) ] = item;
  sem_post(&b->mutex);
  sem_post(&b->items);
}

void removeItem(buf_t* b, int* item)
{
  sem_wait(&b->items);
  sem_wait(&b->mutex);
  *item = b->buffer[(b->head++) % (b->n) ]; 
  sem_post(&b->mutex);
  sem_post(&b->slots);
}

void deleteBuf(buf_t* b)
{
  if ( b->buffer) free(b->buffer);
  free(b);
}
