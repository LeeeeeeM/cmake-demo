
#include "includes/type.h"
#include "includes/utils.h"
#include <stdio.h>

int main() {
  Node *head = NULL;
  Node** headPtr = &head;
  insertHead(headPtr, 12);
  insertHead(headPtr, 11);
  insertHead(headPtr, 8);
  insertHead(headPtr, 9);
  traverseList(head);
  deleteNode(headPtr, 8);
  traverseList(head);
  searchNode(head, 13);
  searchNode(head, 9);
  return 0;
}