#include "csapp.h"

unsigned int wakeup(unsigned int secs) {
  unsigned int x = sleep(secs);
  printf("Woke up at %d secs", secs - x + 1);
  return x;
}
