#include "csapp.h"

unsigned int snooze(unsigned int secs) {
  unsigned int i;
  i = sleep(secs);
  printf("Woke up at %d secs", secs - i + 1);
  return i;
}
