OA
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <assert.h>
typedef struct __counter_t {
  int value;
  pthread_mutex_t lock;
} counter_t;
void init(counter_t *c) {
  c->value = 0;
  pthread_mutex_init(&c->lock, NULL);
}
void increment(counter_t *c) {
  pthread_mutex_lock(&c->lock);
  c->value++;
  pthread_mutex_unlock(&c->lock);
}

void decrement(counter_t *c) {
  pthread_mutex_lock(&c->lock);
  c->value--;
  pthread_mutex_unlock(&c->lock);
}
int get(counter_t *c) {
  pthread_mutex_lock(&c->lock);
  int rc = c->value;
  pthread_mutex_unlock(&c->lock);
  return rc;
}

void* foo(void* arg)
{
counter_t* c1 = (counter_t*)(arg);
int i=0;
for ( i =0; i<1e7; i++ )
  increment(c1);
printf("Get C1 value %d \n", get(c1));
}

int main(int argc, char* argv[])
{
pthread_t thr1, thr2;
counter_t c1;
int rc;
init(&c1);
rc = pthread_create(&thr1, NULL, foo, &c1); assert( rc == 0 );
rc = pthread_create(&thr2, NULL, foo, &c1); assert( rc == 0 );
pthread_join(thr1, NULL);
pthread_join(thr2, NULL);
printf("Get final C1 value %d \n", get(&c1));
return 0;
}
