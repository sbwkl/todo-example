#include "csapp.h"

void sigint_handler(int sig) {
  sio_puts("Caught SIGINT!\n");
  _exit(0);
}

int main () {
  if (signal(SIGINT, sigint_handler) == SIG_ERR) {
    unix_error("signal error");
  }

  pause();

  return 0;
}
