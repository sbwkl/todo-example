
#include <stdio.h>
#define N 6

void selection_sort(int *a);
void printarray(int *array);

int main () {
  int a[N] = {31, 41, 59, 26, 41, 58};
  selection_sort(a);
  printarray(a);
}

void selection_sort(int *a) {
  int i, j, min, temp;

  for (j = 0; j < N; j++) {
    min = j;
    for (i = j + 1; i < N; i++) {
      if (a[j] > a[i]) {
        min = i;
      }
    }
    // exchange j and min
    temp = a[j];
    a[j] = a[min];
    a[min] = temp;
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
