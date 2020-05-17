#include <stdio.h>
void f(void);

int y = 15212;
int x = 15213;
double z;

int main() {
  printf("int size = %d \n", sizeof(x));
  printf("double size = %d \n", sizeof(z));
  printf("x address is %p, y address is %p \n", (void*) &x, (void*) &y);
  f();
  printf("x = 0x%x y = ox%x \n", x, y);
  return 0;
}
