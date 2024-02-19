#ifndef LIBS_H
#define LIBS_H

#include "types.h"

DNode *create(int key);
DoubleLinkedList initList();

void insertTail(DoubleLinkedList head, int key);
void insertTailBatch(DoubleLinkedList head, int *keys, int size);

void insertHead(DoubleLinkedList head, int key);
void insertHeadBatch(DoubleLinkedList head, int *keys, int size);

void traverse(DoubleLinkedList head);

int deleteTail(DoubleLinkedList head);

int deleteHead(DoubleLinkedList head);

#endif