

#include "csapp.h"
#define MAXTHREADS 32

void *sum_local(void *vargp);

long gsum[MAXTHREADS];
long nelems_per_thread;

int main(int argc, char **argv) {
  long i, nelems, log_nelems, nthreads, myid[MAXTHREADS];
  pthread_t tid[MAXTHREADS];
  struct timeval stop, start;

  if (argc != 3) {
    printf("Usage: %s <nthreads> <log_nelems>\n", argv[0]);
    exit(0);
  }
  nthreads = atoi(argv[1]);
  log_nelems = atoi(argv[2]);
  nelems = (1L << log_nelems);
  nelems_per_thread = nelems / nthreads;

  gettimeofday(&start, NULL);
  for (i = 0; i < nthreads; i++) {
    myid[i] = i;
    Pthread_create(&tid[i], NULL, sum_local, &myid[i]);
  }
  for (i = 0; i < nthreads; i++) {
    Pthread_join(tid[i], NULL);
  }

  long tsum = 0;
  for (i = 0; i < nthreads; i++) {
    tsum += gsum[i];
  }
  if (tsum != (nelems * (nelems - 1)) / 2) {
    printf("Error: result = %ld\n", tsum);
  }
  gettimeofday(&stop, NULL);
  long overhead = (stop.tv_sec - start.tv_sec) * 1000 + (stop.tv_usec - start.tv_usec) / 1000;
  printf("%dms\n", overhead);
  exit(0);
}

void *sum_local(void *vargp) {
  long myid = *((long *) vargp);
  long start = myid * nelems_per_thread;
  long end = start + nelems_per_thread;
  long i, sum = 0;

  for (i = start; i < end; i++) {
    sum += i;
  }
  gsum[myid] = sum;
  return NULL;
}
