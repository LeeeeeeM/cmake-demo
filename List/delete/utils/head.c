#include <stdlib.h>
#include "../includes/type.h"

void insertHead(Node** head, int e) {
  Node *newNode = malloc(sizeof(Node));
  newNode->data = e;
  newNode->next = *head;
  *head = newNode;
}