#include <stdio.h>
#include <stdlib.h>
#include "myfork.h"

int main() {
  pid_t pid;
  int x = 1;
  pid = Fork();
  if (pid == 0) {
    printf("clild : x=%d\n", ++x);
    exit(0);
  }

  printf("pid = %d\n", pid);
  printf("parent: x = %d\n", --x);
  exit(0);
}
