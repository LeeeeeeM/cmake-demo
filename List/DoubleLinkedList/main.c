#include "include/libs.h"

int main() {
  DoubleLinkedList head = initList();

  int keys[] = {2, 3, 5, 7, 4, 6, 8, 9};
  // int keys[] = {2};
  int size = sizeof(keys) / sizeof(keys[0]);

  insertTailBatch(head, keys, size);

  traverse(head);

  deleteTail(head);

  traverse(head);

  deleteHead(head);

  traverse(head);

  return 0;
}