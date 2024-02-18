#include <stdio.h>
#include <stdlib.h>
#include "includes/type.h"

Node *head = NULL;

void insertHead(int e) {
  Node *newNode = malloc(sizeof(Node));
  newNode->data = e;
  newNode->next = head;
  head = newNode;
}

int main() {
  insertHead(3);
  insertHead(18);
  insertHead(16);
  insertHead(13);
  traverseList(head);
  return 0;
}