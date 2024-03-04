#include <stdio.h>
void insertSort(int *arr, int size) {
  int pos;
  int cur;
  for (int i = 1; i < size; i++) {
    pos = i - 1;
    cur = *(arr + i);
    while (pos >= 0 && *(arr + pos) > cur) {
      *(arr + pos + 1) = *(arr + pos);
      pos--;
    }
    *(arr + pos + 1) = cur;
  }
}

void printfArray(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d, ", *(arr + i));
  }
  printf("\n");
}

int main() {
  int array[] = {3, 1, 4, 6, 8, 5, 2, 7};
  int size = sizeof(array) / sizeof(array[0]);

  printf("%s: \n", "before sort");

  printfArray(array, size);

  insertSort(array, size);

  printf("%s: \n", "after sort");

  printfArray(array, size);

  return 0;
}