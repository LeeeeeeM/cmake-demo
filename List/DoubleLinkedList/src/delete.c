#include "../include/macro.h"
#include "../include/types.h"
#include <stdio.h>
#include <stdlib.h>

int deleteHead(DoubleLinkedList head) {
  if (IS_LIST_EMPTY(head)) {
    printf("LIST IS EMPTY ...\n");
    return 0;
  }

  DNode *next = head->next;
  DNode *nextNext = next->next;
  free(next);
  nextNext->pre = head;
  head->next = nextNext;
  return 1;

  return 0;
}

int deleteTail(DoubleLinkedList head) {
  if (IS_LIST_EMPTY(head)) {
    printf("LIST IS EMPTY ...\n");
    return 0;
  }
  DNode *tail = head->pre;
  DNode *tailPre = tail->pre;
  free(tail);
  tailPre->next = head;
  head->pre = tailPre;
  return 1;
}