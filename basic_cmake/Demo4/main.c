#include <stdio.h>
#include "func1/func1.h"
#include "func2/func2.h"

int main() {
    printf("hello world!\n");
    int result = fn2(fn1(2));
    printf("%d\n", result);
    printf("hello world, Bye!\n");
}