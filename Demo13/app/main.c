#include <stdio.h>
#include <dlfcn.h>

int main() {
    // 打开动态链接库
    void* handle = dlopen("libadd.dylib", RTLD_LAZY);
    if (handle == NULL) {
        fprintf(stderr, "无法打开动态链接库: %s\n", dlerror());
        return 1;
    }

    // 获取函数指针
    int (*add)(int a, int b, int c) = dlsym(handle, "add");
    if (add == NULL) {
        fprintf(stderr, "无法获取函数指针: %s\n", dlerror());
        dlclose(handle);
        return 1;
    }

    // 调用函数
    add(1, 2, 3);

    // 关闭动态链接库
    dlclose(handle);

    return 0;
}