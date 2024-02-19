#include "../include/types.h"
#include "../include/macro.h"
#include <stdio.h>

void traverse(DoubleLinkedList head) {
    printf("( HEAD )-> ");
    DNode *current = head->next;
    while (!IS_NULL(current, head)) {
        printf("<-%d-> ", current->data);
        current = current->next;
    }
    printf("<-( HEAD )\n");
}