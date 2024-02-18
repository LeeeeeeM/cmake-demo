#ifndef UTILS_H
#define UTILS_H
#include "type.h"
#define IS_NULL(ptr) ((ptr) == NULL)
void traverseList(Node *head);
void insertHead(Node **head, int key);
void deleteNode(Node **head, int key);
Node *searchNode(Node *head, int key);
#endif