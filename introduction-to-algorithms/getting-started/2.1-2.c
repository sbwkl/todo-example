#include <stdio.h>
#define N 6

void insertion_sort(int *a);
void printarray(int *array);

int main () {
  int a[N] = {31, 41, 59, 26, 41, 58};
  insertion_sort(a);
  printarray(a);
}

void insertion_sort(int *a) {
  int i, j, key;

  for (j = 1; j < N; j++) {
    key = a[j];
    i = j - 1;
    while (i >= 0 && a[i] < key) {
      a[i + 1] = a[i];
      i--;
    }
    a[i + 1] = key;
  }
}

void printarray(int *array) {
  int i;
  for (i = 0; i < N; i++) {
      printf("%d ", *array);
      array++;
  }
  printf("\n");
}
