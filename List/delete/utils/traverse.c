#include <stdio.h>
#include "../includes/type.h"
#include "../includes/utils.h"

void traverseList(Node *head) {
  Node *current = head;
  printf("%s\n", "Traversing...");
  while (!IS_NULL(current)) {
    printf("%d\n", current->data);
    current = current->next;
  }
}