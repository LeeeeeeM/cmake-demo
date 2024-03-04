#include <stdio.h>
void selectionSort(int *arr, int size) {
  int minIndex;
  for (int i = 0; i < size - 1; i++) {
    minIndex = i;
    for (int j = i + 1; j < size; j++) {
      if (*(arr + j) < *(arr + minIndex)) {
        minIndex = j;
      }
    }
    int temp = *(arr + i);
    *(arr + i) = *(arr + minIndex);
    *(arr + minIndex) = temp;
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

  selectionSort(array, size);

  printf("%s: \n", "after sort");

  printfArray(array, size);

  return 0;
}