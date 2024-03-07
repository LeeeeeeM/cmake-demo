#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  printf("%s\n", "start");

  // 指向常量的指针可以修改

  const int *a;

  const int a1 = 12;

  a = &a1;

  printf("%d\n", *a);

  int a2 = 13;

  int a3 = 14;

  swap(&a2, &a3);

  a = &a2;

  printf("%d\n", *a);

  a2 = 15;

  printf("%d\n", *a);

  // 指向整数的指针常量，即指针不能修改

  int b = 22;

  int* const b1 = &b;

  *b1 = 23;

  printf("%d\n", *b1);

  printf("%s\n", "end");
  return 0;
}