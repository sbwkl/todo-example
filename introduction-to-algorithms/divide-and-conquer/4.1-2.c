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
  int i, j;
  int sum = subarray_sum(a, 0, n - 1);
  ret_t ret;
  ret.i = 0;
  ret.j = n - 1;
  ret.sum = subarray_sum(a, 0, n - 1);
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (ret.sum < subarray_sum(a, i, j)) {
        ret.sum = subarray_sum(a, i, j);
        ret.i = i;
        ret.j = j;
      }
    }
  }
  printf("max-subarray [%d, %d] sum = %d\n", ret.i, ret.j, ret.sum);
}

int subarray_sum(int a[], int left, int right) {
  int i, sum = 0;
  for (i = left; i <= right; i++) {
    sum += a[i];
  }
  return sum;
}
