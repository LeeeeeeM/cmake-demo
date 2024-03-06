#include <stdio.h>
#define MAX 20
#define BASE 10

void printArray(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d, ", *(arr + i));
  }
  printf("\n");
}

int getDigit(int num, int digit) {
  int divisor = 1;
  for (int i = 0; i < digit - 1; i++) {
    divisor *= 10;
  }
  return (num / divisor) % 10;
}

void radixSort(int *arr, int size) {
  int maxNum = *arr;
  for (int i = 1; i < size; i++) {
    if (*(arr + i) > maxNum) {
      maxNum = *(arr + i);
    }
  }

  int numDigits = 0;
  while (maxNum > 0) {
    maxNum /= 10;
    numDigits++;
  }

  int bucket[10][size];
  int bucketCount[10];

  for (int digit = 1; digit <= numDigits; digit++) {
    // 初始化桶数组和桶计数数组
    for (int i = 0; i < 10; i++) {
      bucketCount[i] = 0;
    }
    // 将当前位上的元素放入对应的桶中
    for (int i = 0; i < size; i++) {
      int digitValue = getDigit(*(arr + i), digit);
      bucket[digitValue][bucketCount[digitValue]] = *(arr + i);
      bucketCount[digitValue]++;
    }

    // 从桶中按顺序取出元素，重新组成原始数组
    int index = 0;
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < bucketCount[i]; j++) {
        arr[index] = bucket[i][j];
        index++;
      }
    }
  }
}

int main() {
  int a[MAX] = {31, 17, 25, 89, 47, 33, 18, 8,  74, 36,
                29, 53, 91, 67, 3,  37, 78, 96, 62, 19};
  int size = sizeof(a) / sizeof(a[0]);
  printf("before sort: \n");
  printArray(a, size);
  printf("after sort: \n");
  radixSort(a,  size);
  printArray(a, size);
  return 0;
}