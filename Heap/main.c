
#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void maxHeapify(int arr[], int *size, int rootIndex) {
  int largest = rootIndex;
  int leftChild = 2 * rootIndex + 1;
  int rightChild = 2 * rootIndex + 1;

  if (leftChild < *size && arr[leftChild] > arr[largest]) {
    largest = leftChild;
  }

  if (rightChild < *size && arr[rightChild] > arr[largest]) {
    largest = rightChild;
  }

  if (largest != rootIndex) {
    swap(&arr[largest], &arr[rootIndex]);
    maxHeapify(arr, size, largest);
  }
}

void minHeapify(int arr[], int *size, int rootIndex) {
  int smallest = rootIndex;
  int leftChild = 2 * rootIndex + 1;
  int rightChild = 2 * rootIndex + 1;

  if (leftChild < *size && arr[leftChild] < arr[smallest]) {
    smallest = leftChild;
  }

  if (rightChild < *size && arr[rightChild] < arr[smallest]) {
    smallest = rightChild;
  }

  if (smallest != rootIndex) {
    swap(&arr[smallest], &arr[rootIndex]);
    minHeapify(arr, size, smallest);
  }
}

void buildMaxHeap(int arr[], int *size) {
  for (int i = *size / 2 - 1; i >= 0; i--) {
    maxHeapify(arr, size, i);
  }
}

void buildMinHeap(int arr[], int *size) {
  for (int i = *size / 2 - 1; i >= 0; i--) {
    minHeapify(arr, size, i);
  }
}

void deleteMax(int arr[], int *n) {
  if (*n <= 0) {
    return;
  }
  swap(&arr[0], &arr[*n - 1]);
  (*n)--;
  buildMaxHeap(arr, n);
}

void insertMin(int arr[], int *n, int key) {
  int currentIndex = *n;
  arr[currentIndex] = key;
  (*n)++;
  int parentIndex = (currentIndex - 1) / 2;
  while (currentIndex > 0 && arr[currentIndex] < arr[parentIndex]) {
    swap(&arr[currentIndex], &arr[parentIndex]);
    currentIndex = parentIndex;
    parentIndex = (currentIndex - 1) / 2;
  }
//   minHeapify(arr, n, 0);
}

// 打印数组的元素
void printArray(int arr[], int *size) {
  for (int i = 0; i < *size; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {8, 5, 3, 9, 2};
  int size = sizeof(arr) / sizeof(arr[0]);
  printf("Original array: ");
  printArray(arr, &size);

  buildMaxHeap(arr, &size);

  printf("Max heap: ");
  printArray(arr, &size);

  deleteMax(arr, &size);

  printArray(arr, &size);

  buildMinHeap(arr, &size);

  printf("Min heap: ");
  printArray(arr, &size);

  insertMin(arr, &size, 6);
  printArray(arr, &size);

  return 0;
}