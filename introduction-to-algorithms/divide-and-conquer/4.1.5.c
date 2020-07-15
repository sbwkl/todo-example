
#include <stdio.h>

typedef struct {
  int i;
  int j;
  int sum;
} ret_t;

int main() {
  // solution (7, 10)
  int a[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
  int n = sizeof(a) / sizeof(int);
  int i;
  ret_t ret;
  int max_here = 0;
  ret.sum = 0;
  for (i = 0; i < n; i++) {
    if (a[i] > max_here + a[i]) {
      ret.i = i;
      max_here = a[i];
    } else {
      max_here = max_here + a[i];
    }
    if (ret.sum < max_here) {
      ret.j = i;
      ret.sum = max_here;
    }
  }
  printf("max-subarray [%d, %d] sum = %d\n", ret.i, ret.j, ret.sum);
}

