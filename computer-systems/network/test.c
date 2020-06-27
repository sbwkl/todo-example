#include "csapp.h"
#include <netinet/in.h>

int main() {
  printf("sockaddr_in size = %d\n", sizeof(struct sockaddr_in));
  printf("uint16_t size = %d\n", sizeof(uint16_t));
  printf("sockaddr size = %d\n", sizeof(struct sockaddr));
}
