

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_INIT_OBJECT_COUNT 8

typedef enum { INT, PAIR } DataType;

typedef struct sObject {
  DataType type;
  unsigned char marked;
  struct sObject *next;

  union {
    int value;
    struct {
      struct sObject *tail;
      struct sObject *head;
    };
  };
} Object;

typedef struct {
  Object *stack[MAX_STACK_SIZE];
  int stackSize;
  Object *firstObject;
  int numObjects;
  int maxObjects;
} VM;

void assert(int condition, const char *message) {
  if (!condition) {
    printf("%s\n", message);
    exit(1);
  }
}

VM *newVM() { 
  VM *vm = malloc(sizeof(VM));
  vm->stackSize = 0;
  vm->firstObject = NULL;
  vm->numObjects = 0;
  vm->maxObjects = MAX_INIT_OBJECT_COUNT;
  return vm;
}

void sweep(VM* vm) {
  Object **object = &vm->firstObject;
  while (*object) {
    if (!(*object)->marked) {
      /* This object wasn't reached, so remove it from the list and free it. */
      Object *unreached = *object;

      *object = unreached->next;
      free(unreached);

      vm->numObjects--;
    } else {
      /* This object was reached, so unmark it (for the next GC) and move on to
       the next. */
      (*object)->marked = 0;
      object = &(*object)->next;
    }
  }
}


// void sweep(VM* vm) {
//   Object *prev = NULL;
//   Object *current = vm->firstObject;

//   while (current) {
//     if (!current->marked) {
//       /* This object wasn't reached, so remove it from the list and free it. */
//       Object *unreached = current;

//       if (prev) {
//         prev->next = current->next;
//       } else {
//         vm->firstObject = current->next;
//       }

//       current = current->next;
//       free(unreached);
//       vm->numObjects--;
//     } else {
//       /* This object was reached, so unmark it (for the next GC) and move on to the next. */
//       current->marked = 0;
//       prev = current;
//       current = current->next;
//     }
//   }
// }

void mark(Object* object) {
  if (object->marked) return;
  object->marked = 1;
  if (object->type == PAIR) {
    mark(object->head);
    mark(object->tail);
  }
}

void markAll(VM* vm) {
  for (int i = 0; i < vm->stackSize; i++) {
    mark(vm->stack[i]);
  }
}

void gc(VM* vm) {
  int numObjects = vm->numObjects;
  markAll(vm);
  sweep(vm);
  vm->maxObjects = vm->numObjects == 0 ? MAX_INIT_OBJECT_COUNT : vm->numObjects * 2;

  printf("Collected %d objects, %d remaining.\n", numObjects - vm->numObjects,
         vm->numObjects);
}



void push(VM* vm, Object* value) {
  assert(vm->stackSize < MAX_STACK_SIZE, "StackOverflow!");
  vm->stack[vm->stackSize++] = value;
}

Object* pop(VM* vm) {
  assert(vm-> stackSize > 0, "StackUnderflow!");
  return vm->stack[--vm->stackSize];
}

Object* newObject(VM* vm, DataType type) {

  if (vm->numObjects == vm->maxObjects) {
    gc(vm);
  }

  Object* obj = malloc(sizeof(Object));
  obj->type = type;
  obj->marked = 0;

  obj->next = vm->firstObject;
  vm->firstObject = obj;

  vm->numObjects++;
  return obj;
}


void pushInt(VM* vm, int intValue) {
  Object* obj = newObject(vm, INT);
  obj->value = intValue;
  push(vm, obj);
}

Object* pushPair(VM* vm) {
  Object* obj = newObject(vm, PAIR);
  obj->tail = pop(vm);
  obj->head = pop(vm);
  push(vm, obj);
  return obj;
}

void freeVM(VM* vm) {
  vm->stackSize = 0;
  gc(vm);
  free(vm);
}

void objectPrint(Object *object) {
  switch (object->type) {
  case INT:
    printf("%d", object->value);
    break;

  case PAIR:
    printf("(");
    objectPrint(object->head);
    printf(", ");
    objectPrint(object->tail);
    printf(")");
    break;
  }
}

void test4() {
  printf("Test 4: Handle cycles.\n");
  VM *vm = newVM();
  pushInt(vm, 1);
  pushInt(vm, 2);
  Object *a = pushPair(vm);
  pushInt(vm, 3);
  pushInt(vm, 4);
  Object *b = pushPair(vm);

  /* Set up a cycle, and also make 2 and 4 unreachable and collectible. */
  a->tail = b;
  b->tail = a;

  gc(vm);
  assert(vm->numObjects == 4, "Should have collected objects.");
  freeVM(vm);
}

int main() {
  test4();
  return 0;
}