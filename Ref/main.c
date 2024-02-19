#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void func1(int tmp){
    ++tmp;
}
void func2(int* tmp){
    printf("%p, %d", tmp, *tmp);
    *tmp = 12;
}
void func3(int* tmp) {
    ++tmp;
}

void init_memory(char **s) {
    *s = malloc(128);
}

int main(int agrc, char** agrv) {
    int v = 42;

    func1(v);
    printf("%d\n", v);
    func2(&v);
    printf("%d\n", v);
    func3(&v);
    printf("%d\n", v);

    char *str = NULL;

    init_memory(&str);
    strcpy(str, "hello world");
    printf("%s\n", str);

    return 0;
}