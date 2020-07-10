
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 6

void merge_sort(int *a, int p, int r);
void merge(int *a, int p, int q, int r);

int main (int argc, char **argv) {
  if (argc != 2) {
    printf("usage: %s <v>\n", argv[0]);
    exit(0);
  }
  int v = atoi(argv[1]);
  int a[N] = {31, 41, 59, 26, 41, 58};
  int r[2] = {-1, -1};
  merge_sort(a, 0, N - 1);
  int i = 0; 
  int j = N;
  while (i < j) {
    if (a[i] + a[j] == v) {
      r[0] = a[i];
      r[1] = a[j];
      break;
    } else if (a[i] + a[j] < v) {
      i++;
    } else if (a[i] + a[j] > v) {
      j--;
    }
  }
  if (r[0] == -1 || r[1] == -1) {
    printf("%s\n", "NIL");
  } else {
    printf("[%d, %d]\n", r[0], r[1]);
  }

}

void merge_sort(int *a, int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;
    merge_sort(a, p, q);
    merge_sort(a, q + 1, r);
    merge(a, p, q, r);
  }  
}

void merge(int *a, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  int left[n1], right[n2];
  int i, j, k;
  for (i = 0; i < n1; i++) {
    left[i] = a[p + i];
  }
  for (i = 0; i < n2; i++) {
    right[i] = a[q + i + 1];
  }
  left[n1] = INT_MAX;
  right[n2] = INT_MAX;
  i = 0, j = 0;
  for (k = p; k <= r; k++) {
    if (left[i] < right[j]) {
      a[k] = left[i];
      i++;
    } else {
      a[k] = right[j];
      j++;
    }
  }
}
