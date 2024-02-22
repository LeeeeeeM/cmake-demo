#include <stdio.h>
void swap(int *a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapSortImpl(int arr[], int index) {
    int parent = (index - 1) / 2;
    if (parent >= 0 && arr[parent] > arr[index]) {
        swap(&arr[parent], &arr[index]);
        minHeapSortImpl(arr, parent);
    }
};

void minHeapSort(int arr[], int size) {
    for (int i = size - 1; i > 0; i--) {
        minHeapSortImpl(arr,i);
    }
}

void maxHeapSortImpl(int arr[], int index) {
    int parent = (index - 1) / 2;
    if (parent >= 0 && arr[parent] < arr[index]) {
        swap(&arr[parent], &arr[index]);
        maxHeapSortImpl(arr, parent);
    }
};

void maxHeapSort(int arr[], int size) {
    for (int i = size - 1; i > 0; i--) {
        maxHeapSortImpl(arr,i);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ->", arr[i]);
    }
    printf("\n");
}