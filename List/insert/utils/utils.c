#include <stdio.h>
#include "../includes/type.h"

void traverseList(Node *head) {
  Node *current = head;
  while (!IS_NULL(current)) {
    printf("%d\n", current->data);
    current = current->next;
  }
}