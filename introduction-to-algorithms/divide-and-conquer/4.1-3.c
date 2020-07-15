#include <stdio.h>
#include <limits.h>

typedef struct {
  int i;
  int j;
  int sum;
} ret_t;

ret_t find_maximum_subarray(int a[], int left, int right);
ret_t find_max_crossing_subarray(int a[], int left, int mid, int right);

int main() {
  // solution (7, 10)
  int a[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
  int n = sizeof(a) / sizeof(int);
  ret_t ret;
  ret = find_maximum_subarray(a, 0, n - 1);
  
  printf("max-subarray [%d, %d] sum = %d\n", ret.i, ret.j, ret.sum);
}

ret_t find_maximum_subarray(int a[], int left, int right) {
  ret_t ret;
  if (left == right) {
    ret.i = left;
    ret.j = right;
    ret.sum = a[left];
    return ret;
  }
  int mid = (left + right) / 2;
  ret_t ls, ms, rs;
  ls = find_maximum_subarray(a, left, mid);
  rs = find_maximum_subarray(a, mid + 1, right);
  ms = find_max_crossing_subarray(a, left, mid, right);
  
  if (ls.sum >= rs.sum && ls.sum >= ms.sum) {
    return ls;
  } else if (rs.sum >= ls.sum && rs.sum >= ms.sum) {
    return rs;
  } else {
    return ms;
  }
}

ret_t find_max_crossing_subarray(int a[], int left, int mid, int right) {
  ret_t ret;
  int left_sum = INT_MIN;
  int i, sum = 0;
  for (i = mid; i >= left; i--) {
    sum += a[i];
    if (sum > left_sum) {
      left_sum = sum;
      ret.i = i;
    }
  }
  
  int right_sum = INT_MIN;
  sum = 0;
  for (i = mid + 1; i <= right; i++) {
    sum += a[i];
    if (sum > right_sum) {
      right_sum = sum;
      ret.j = i;
    }
  }
  ret.sum = left_sum + right_sum;
  return ret;
}
