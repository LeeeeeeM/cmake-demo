#include "../include/types.h"
#include <stdlib.h>

DNode* create(int key) {
    DNode* newNode = malloc(sizeof(DNode));
    newNode->data = key;
    newNode->pre = NULL;
    newNode->next = NULL;
    return newNode;
}

DoubleLinkedList initList() {
    DNode* head = create(0);
    head->pre = head;
    head->next = head;
    return head;
}

