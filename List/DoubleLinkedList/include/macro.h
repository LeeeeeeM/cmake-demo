#ifndef MACRO_H
#define MACRO_H

#define IS_NULL(ptr, head) (ptr == head)
#define IS_EQUAL(a, b) ((a) == (b) ? 1 : 0)

#define ARRAY_LENGTH(arr) (sizeof(*arr) / sizeof(arr[0]))

#include "types.h"
static inline int IS_LIST_EMPTY(DNode *el) { return el->next == el; }

#endif