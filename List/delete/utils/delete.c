#include "../includes/macro.h"
#include "../includes/type.h"
#include <stdlib.h>

int deleteNode(Node **head, int key) {
  Node *temp;

  if (IS_EQUAL((*head)->data, key)) {
    temp = *head;
    *head = (*head)->next;
    free(temp);
    return 1;
  } else {
    Node *pre = *head;
    while (!IS_NULL(pre->next)) {
      if (IS_EQUAL(pre->next->data, key)) {
        temp = pre->next;
        pre->next = temp->next;
        free(temp);
        return 1;
      } else {
        pre = pre->next;
      }
    }
  }

  return 0;
}