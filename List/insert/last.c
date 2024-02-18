
#include <stdio.h>
#include <stdlib.h>
#include "includes/type.h"

Node *head;

void insertLast(int e) {
  Node *newNode = malloc(sizeof(Node));
  newNode->data = e;
  newNode->next = NULL;
  if (IS_NULL(head)) {
    head = newNode;
  } else {
    Node *lastNode = head;
    while (!IS_NULL(lastNode->next)) {
      lastNode = lastNode->next;
    }
    lastNode->next = newNode;
  }
}

int main() {
  insertLast(10);
  insertLast(12);
  insertLast(17);
  insertLast(88);
  traverseList(head);
  return 0;
}