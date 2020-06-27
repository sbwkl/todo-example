#include "csapp.h"
#include <netinet/in.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len);

int main() {
  uint32_t hostlong = 1809087181;
  uint32_t x;
  x = htonl(hostlong);
  printf("x = %x\n", x);

  printf("host order: ");
  show_bytes((byte_pointer) &hostlong, sizeof(uint32_t));
  printf("network order: ");
  show_bytes((byte_pointer) &x, sizeof(uint32_t));
}

void show_bytes(byte_pointer start, size_t len) {
  int i;
  for (i = 0; i < len; i++) {
    printf(" %.2x", start[i]);
  }
  printf("\n");
}
