#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 100

typedef struct Object {
  struct Object *next;
  int marked;
  int value; // 添加一个额外的字段用于示例
} Object;

typedef struct VM {
  Object *stack[HEAP_SIZE];
  int stackSize;
  Object *heap[HEAP_SIZE];
  int heapSize;
} VM;

void mark(Object *object) {
  if (object->marked) {
    return;
  }

  object->marked = 1;

  if (object->next != NULL) {
    mark(object->next);
  }
}

void startMark(Object *object) {
  if (object->next != NULL) {
    mark(object->next);
  }
}

void markAll(VM *vm) {
  for (int i = 0; i < vm->stackSize; i++) {
    startMark(vm->stack[i]);
  }
}

void sweep(VM *vm) {
  for (int i = 0; i < vm->heapSize; i++) {
    Object *object = vm->heap[i];
    if (!object->marked) {
      printf("unreachable object { address: %p, value: %d, marked: %d }\n", object, object->value, object->marked);
      free(object);
      vm->heap[i] = NULL;
    } else {
      object->marked = 0;
    }
  }
}

void push(VM *vm, Object *object) {
  if (vm->stackSize >= HEAP_SIZE) {
    printf("Stack overflow\n");
    return;
  }

  vm->stack[vm->stackSize++] = object;
}

Object *pop(VM *vm) {
  if (vm->stackSize <= 0) {
    printf("Stack underflow\n");
    return NULL;
  }

  return vm->stack[--vm->stackSize];
}

void printRootObjects(VM *vm) {
  printf("Root objects:\n");
  for (int i = 0; i < vm->stackSize; i++) {
    Object *obj = vm->stack[i];
    printf("Object value: %d\n", obj->value);
    if (obj->next != NULL) {
      printf("Next object value: %d\n", obj->next->value);
    } else {
      printf("Next object: NULL\n");
    }
  }
}

VM *newVM() {
  VM *vm = (VM *)malloc(sizeof(VM));
  vm->stackSize = 0;
  vm->heapSize = 0;
  return vm;
}

void freeVM(VM *vm) {
  free(vm);
}

int main() {
  VM *vm = newVM();

  // 创建对象
  Object *obj1 = (Object *)malloc(sizeof(Object));
  Object *obj2 = (Object *)malloc(sizeof(Object));
  Object *obj3 = (Object *)malloc(sizeof(Object));

  // 对象之间建立引用关系
  obj1->next = obj2;
  obj2->next = obj3;
  obj3->next = NULL;

  // 设置对象的值
  obj1->value = 1;
  obj2->value = 2;
  obj3->value = 3;

  // 将对象放入堆栈和堆中
  push(vm, obj1);
  push(vm, obj2);
  push(vm, obj3);

  vm->heap[vm->heapSize++] = obj1;
  vm->heap[vm->heapSize++] = obj2;
  vm->heap[vm->heapSize++] = obj3;

  // 打印垃圾回收前的对象引用状态
  printf("Objects before garbage collection:\n");
  printRootObjects(vm);

  // 标记和清除
  markAll(vm);
  sweep(vm);

  freeVM(vm);

  return 0;
}