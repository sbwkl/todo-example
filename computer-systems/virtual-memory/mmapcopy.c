#include "csapp.h"

int main (int argc, char **argv) {
  if (argc < 2) {
    printf("usage: mmapcopy <file>\n");
    return -1;
  }
  char *inputfile = argv[1];
  int fd;
  fd = Open(inputfile, O_APPEND, O_RDONLY);
  struct stat stat;
  fstat(fd, &stat);
  void *bufp;
  bufp = Mmap(NULL, 2, PROT_READ, MAP_PRIVATE, fd, 0);

  Write(1, bufp, stat.st_size);
  return 0;
}
