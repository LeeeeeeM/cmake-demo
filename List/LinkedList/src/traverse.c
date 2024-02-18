#include <stdio.h>
#include "../includes/type.h"
#include "../includes/macro.h"

void traverseList(Node *head) {
  Node *current = head;
  printf("%s\n", "Traversing...");
  while (!IS_NULL(current)) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("%s\n", "NULL");
}

void traverseListWithHead(LinkedList head) {
  Node *current = head->next;
  printf("%s\n", "Traversing...");
  printf("( LIST_LENGTH : %d ) -> ", head->data);
  while (!IS_NULL(current)) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("%s\n", "NULL");
}