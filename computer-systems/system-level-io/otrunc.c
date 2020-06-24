#include "csapp.h"

int main() {
  int fd;
  fd = Open("foo.txt", O_TRUNC, 0);
  printf("fd = %d\n", fd);
}
