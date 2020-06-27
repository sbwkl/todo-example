#include "csapp.h"
#include <netinet/in.h>
#include <arpa/inet.h>

void ddtohex(char **argv);
void hextodd(char **argv);

int main(int argc, char **argv) {
  char *usaga = "usage: pp-11.1 [dtoh/htod] <ip>\n";
  if (argc != 3) {
    printf(usaga);
    exit(0);
  }

  char *type = argv[1];
  if (strcmp(type, "dtoh") == 0) {
    ddtohex(argv);
  } else if (strcmp(type, "htod") == 0) {
    hextodd(argv);
  } else {
    printf(usaga);
    exit(0); 
  }
}

void ddtohex(char **argv) {
  uint32_t dst;
  char *src = argv[2];
  uint32_t hdst;
  int r;
  r = inet_pton(AF_INET, src, &dst);
  if (r == 1) {
    hdst = ntohl(dst);
    printf("%x\n", hdst);
  } else if (r == 0) {
    printf("dotted decimal address invalid.\n");
  } else {
    printf("error\n");
  }
}

void hextodd(char **argv) {
  char *p = argv[2];
  uint32_t hsrc = (int) strtol(p, NULL, 16);
  uint32_t src = htonl(hsrc);
  char *dst = (char *) Malloc(32);
  if (inet_ntop(AF_INET, &src, dst, 32) == NULL) {
    printf("error [%d, %s]\n", errno, strerror(errno));
  } else {
    printf("%s\n", dst);
  }
  free(dst);
}
