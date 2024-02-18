#ifndef TYPES_H
#define TYPES_H

#include <stdio.h>
#define IS_NULL(ptr) ((ptr) == NULL)

typedef struct LNode {
  int data;
  struct LNode *next;
} Node;

void traverseList(Node *head);

#endif