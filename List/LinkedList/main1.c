
#include "includes/type.h"
#include "includes/utils.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("New head ---- \n");

  LinkedList head1 = malloc(sizeof(LinkedList));
  LinkedList *headPtr1 = &head1;

  insertHeadWithHead(headPtr1, 2);
  insertHeadWithHead(headPtr1, 3);
  insertHeadWithHead(headPtr1, 5);
  insertHeadWithHead(headPtr1, 7);
  insertHeadWithHead(headPtr1, 11);
  traverseListWithHead(head1);
  printf("data length: %d\n", head1->data);
  deleteNodeWithHead(headPtr1, 9);
  printf("data length: %d\n", head1->data);
  deleteNodeWithHead(headPtr1, 5);
  printf("data length: %d\n", head1->data);
  traverseListWithHead(head1);
  searchNode(head1, 13);
  searchNode(head1, 11);

  return 0;
}