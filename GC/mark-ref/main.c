#include <stdio.h>
#include <stdlib.h>

#define BLACK 0
#define WHITE 1
#define GRAY 2
#define HATCH 3

typedef struct obj {
  int color;
  int ref_cnt;
  // other fields
  struct obj *next;  // 指向下一个兄弟节点的指针
  struct obj *child; // 指向第一个子节点的指针
} obj_t;

// Function prototypes
void dec_ref_cnt(obj_t *obj);
obj_t *new_obj(int size);
void scan_hatch_queue();
void paint_gray(obj_t *obj);
void scan_gray(obj_t *obj);
void paint_black(obj_t *obj);
void collect_white(obj_t *obj);
// void reclaim(obj_t *obj);

typedef struct queue_node {
  obj_t *data;
  struct queue_node *next;
} queue_node_t;

typedef struct {
  queue_node_t *front;
  queue_node_t *rear;
} queue_t;

int is_empty(queue_t *queue) { return queue->front == NULL; }

void enqueue(queue_t *queue, obj_t *obj) {
  queue_node_t *new_node = (queue_node_t *)malloc(sizeof(queue_node_t));
  new_node->data = obj;
  new_node->next = NULL;

  if (is_empty(queue)) {
    queue->front = new_node;
    queue->rear = new_node;
  } else {
    queue->rear->next = new_node;
    queue->rear = new_node;
  }
}

obj_t *dequeue(queue_t *queue) {
  if (is_empty(queue)) {
    return NULL;
  }

  queue_node_t *front_node = queue->front;
  obj_t *front_obj = front_node->data;

  queue->front = queue->front->next;
  if (queue->front == NULL) {
    queue->rear = NULL;
  }

  free(front_node);
  return front_obj;
}

void allocation_fail() { printf("allocation fail"); }

queue_t *hatch_queue = NULL;

void dec_ref_cnt(obj_t *obj) {
  obj->ref_cnt--;
  if (obj->ref_cnt == 0) {
    // delete(obj);
    free(obj);
  } else if (obj->color != HATCH) {
    obj->color = HATCH;
    enqueue(hatch_queue, obj);
    // Assuming enqueue() is a function to add obj to hatch_queue
  }
}

obj_t *new_obj(int size) {
  obj_t *obj = (obj_t *)malloc(sizeof(obj_t));
  if (obj != NULL) {
    obj->color = BLACK;
    obj->ref_cnt = 1;
    return obj;
  } else if (is_empty(hatch_queue) == 0) {
    scan_hatch_queue();
    return new_obj(size);
  } else {
    allocation_fail();
    return NULL;
  }
}

void scan_hatch_queue() {
  while (!is_empty(hatch_queue)) {
    obj_t *obj = dequeue(hatch_queue);
    if (obj->color == HATCH) {
      paint_gray(obj);
      scan_gray(obj);
      collect_white(obj);
    }
  }
}

void paint_gray(obj_t *obj) {
  if (obj->color == (BLACK | HATCH)) {
    obj->color = GRAY;
  }
  obj_t *child = obj->child;
  while (child != NULL) {
    child->ref_cnt--;
    paint_gray(child);
    child = child->next;
  }
}

void scan_gray(obj_t *obj) {
  if (obj->color == GRAY) {
    if (obj->ref_cnt > 0) {
      paint_black(obj);
    } else {
      obj->color = WHITE;
    }
    obj_t *child = obj->child;
    while (child != NULL) {
      scan_gray(child);
      child = child->next;
    }
  }
}

void paint_black(obj_t *obj) {
  obj->color = BLACK;
  obj_t *child = obj->child;
  while (child != NULL) {
    child->ref_cnt++;
    if (child->color != BLACK) {
      paint_black(child);
    }
    child = child->next;
  }
}

void collect_white(obj_t *obj) {
  if (obj->color == WHITE) {
    obj->color = BLACK;
  }
  obj_t *child = obj->child;
  while (child != NULL) {
    collect_white(child);
    child = child->next;
  }
  // reclaim(obj);
}

int main() {

  hatch_queue = (queue_t *)malloc(sizeof(queue_t));
  hatch_queue->front = NULL;
  hatch_queue->rear = NULL;
  // Test the algorithm
  // ...
  return 0;
}