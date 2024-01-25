#include <stdio.h>
#include "../include/func1.h"
#include "../include/func2.h"

int main() {
    printf("Hello World!\n");
    int result = fn2(fn1(18));
    printf("The Result is %d\n", result);
    
    return 0;
}