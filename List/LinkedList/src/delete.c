#include "../includes/macro.h"
#include "../includes/type.h"
#include <stdio.h>
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
  printf("can't delete: %d\n", key);
  return 0;
}

int deleteNodeWithHead(LinkedList *head, int key) {
  Node *pre = *head;
  while (!IS_NULL(pre->next)) {
    if (IS_EQUAL(pre->next->data, key)) {
      Node *temp = pre->next;
      pre->next = pre->next->next;
      free(temp);
      (*head)->data -= 1;
      printf("--- has deleted: %d ---\n", key);
      return 1;
    } else {
      pre = pre->next;
    }
  }
  printf("--- can't delete: %d ---\n", key);
  return 0;
}
