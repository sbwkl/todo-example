#include <stdio.h>
#include <unistd.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {

  char msg[1024];
  int n;
  while((n = read(STDIN_FILENO, msg, sizeof(msg))) > 0) {
    printf("%s", msg);
    fflush(stdout);
  }
}
