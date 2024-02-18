#include "../includes/macro.h"
#include "../includes/type.h"
#include <stdio.h>
#include <stdlib.h>

Node *searchNode(Node *head, int key) {
  Node *current = head;
  while (!IS_NULL(current)) {
    if (IS_EQUAL(current->data, key)) {
      printf("%s: %d\n", "--- found node ---", current->data);
      return current;
    } else {
      current = current->next;
    }
  }
  printf("%s: %d\n", "--- can't find node ---", key);
  return NULL;
}