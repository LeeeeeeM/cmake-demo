#ifndef TYPES_H
#define TYPES_H

typedef struct DLNode {
  int data;
  struct DLNode *next;
  struct DLNode *pre;
} DNode, *DoubleLinkedList;

#endif