#include "../includes/macro.h"
#include "../includes/type.h"
#include <stdlib.h>

void insertHead(Node **head, int key) {
  Node *newNode = malloc(sizeof(Node));
  newNode->data = key;
  newNode->next = *head;
  *head = newNode;
}

void insertHeadWithHead(LinkedList *head, int key) {
  Node *newNode = malloc(sizeof(Node));
  newNode->data = key;
  newNode->next = NULL;

  newNode->next = (*head)->next;
  (*head)->next = newNode;
  (*head)->data += 1;
}

void insertLastWithHead(LinkedList *head, int key) {
  Node *newNode = malloc(sizeof(Node));
  newNode->data = key;
  newNode->next = NULL;

  Node *lastNode = *head;
  while (!IS_NULL(lastNode->next)) {
    lastNode = lastNode->next;
  }
  lastNode->next = newNode;
  (*head)->data += 1;
}