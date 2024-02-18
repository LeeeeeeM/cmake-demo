#ifndef UTILS_H
#define UTILS_H
#include "type.h"

void traverseList(Node *head);
void traverseListWithHead(Node *head);

void insertHead(Node **head, int key);
void insertHeadWithHead(LinkedList *head, int key);
void insertLastWithHead(Node** head, int key);

void deleteNode(Node **head, int key);
int deleteNodeWithHead(LinkedList *head, int key);

Node *searchNode(Node *head, int key);

#endif