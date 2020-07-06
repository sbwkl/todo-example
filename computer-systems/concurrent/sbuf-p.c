#include "csapp.h"
#include "sbuf.h"

void *producer(void *vargp);
void *consumer(void *vargp);

sbuf_t sp;

int main(int argc, char **argv) {

  if (argc != 2) {
    fprintf(stderr, "usage: %s <n>\n", argv[0]);
    exit(0);
  }

  int n;
  n = atoi(argv[1]);
  sbuf_init(&sp, n);
  srand(time(NULL));
  pthread_t p, c;
  Pthread_create(&p, NULL, producer, NULL);
  Pthread_create(&c, NULL, consumer, NULL);
  Pthread_join(p, NULL);
  Pthread_join(c, NULL);
}

void *producer(void *vargp) {
  int n = 0;
  while ((n++) < 5) {
    int r = rand();
    sbuf_insert(&sp, r);
    printf("producer item = %d\n", r);
    Sleep(1);
  }
}

void *consumer(void *vargp) {
  int n = 0;  
  while ((n++) < 5) {
    int r = sbuf_remove(&sp);
    printf("consumer item = %d\n", r);
    Sleep(2);
  }
}
