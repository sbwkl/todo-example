#include <stdlib.h>
#include <stdio.h>

int main() {
  void *p1;
  void *p2;
  void *p3;
  void *p4;
  printf("int size = %d\n", sizeof(int));
  p1 = malloc(7 * sizeof(int));
  printf("p1 = %p\n", p1);
  p2 = malloc(5 * sizeof(int));
  printf("p2 = %p\n", p2);
  p3 = malloc(6 * sizeof(int));
  printf("p3 = %p\n", p3);
  free(p2);
  printf("p2 = %d\n", *((int *)p2));
  p4 = malloc(2 * sizeof(int));
  printf("p4 = %p\n", p4);
  return 0;
}
