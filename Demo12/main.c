#include <stdio.h>
#include "include/head.h"
#define NUMBER 10

int main() {
#ifdef DEBUG
  printf("This is degbugger\n");
#endif
  for (int i=0; i < NUMBER; ++i) {
    printf("this %d, ", i);
    printf("add %d ", add(i, i));
    printf("sub %d ", subtract(i, i));
    printf("mult %d \n", multiply(i, i));
    
  }
  return 1;
}