#include "../include/libs.h"
#include "../include/types.h"

void insertTail(DoubleLinkedList head, int key) {
  DNode *newNode = create(key);
  DNode *tail = head->pre;
  tail->next = newNode;
  newNode->pre = tail;
  newNode->next = head;
  head->pre = newNode;
}

void insertTailBatch(DoubleLinkedList head, int *keys, int size) {
  for (int i = 0; i < size; i++) {
    insertTail(head, keys[i]);
  }
}

void insertHead(DoubleLinkedList head, int key) {
  DNode *newNode = create(key);
  DNode *next = head->next;
  head->next = newNode;
  newNode->pre = head;
  next->pre = newNode;
  newNode->next = next;
}

void insertHeadBatch(DoubleLinkedList head, int *keys, int size) {
  for (int i = 0; i < size; i++) {
    insertHead(head, keys[i]);
  }
}