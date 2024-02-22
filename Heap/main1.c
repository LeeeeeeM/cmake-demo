#include "src/sort.c"
#include <stdio.h>

int main () {
    int a[] = {4, 2, 3, 7, 9, 6, 5, 1};
    int size = sizeof(a) / sizeof(a[0]);
    printf("Origin Array: \n");
    printArray(a, size);
    minHeapSort(a, size);
    printf("Sorted Array: \n");
    printArray(a, size);


    int a1[] = {4, 2, 3, 7, 9, 6, 5, 1};
    int size1 = sizeof(a1) / sizeof(a1[0]);
    printf("Origin Array: \n");
    printArray(a1, size1);
    maxHeapSort(a1, size1);
    printf("Sorted Array: \n");
    printArray(a1, size1);
}