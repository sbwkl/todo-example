#include "csapp.h"

void my_handler(int sig) {
  printf("Caught sig %d\n", sig);
  return;
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("must has one args");
    exit(0);
  }

  if (signal(SIGINT, my_handler) == SIG_ERR) {
    unix_error("signal error");
  }

  int secs = atoi(argv[1]);
  snooze((unsigned int) secs);
  return 0;
}  
