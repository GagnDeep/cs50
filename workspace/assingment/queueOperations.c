#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
  int item[SIZE];
  int rear, front;
}Queue;

// function prototypes
void insertion(Queue *, int );
int deletion(Queue *);

int main() {
  Queue q;
  q.front = 0;
  q.rear = 0;

  insertion(&q, 5);
  printf("inserted 5\n");
  insertion(&q, 10);
  printf("inserted 10\n");
  insertion(&q, 15);
  printf("inserted 15\n");
  insertion(&q, 20);
  printf("inserted 20\n");

  printf("%d\n", deletion(&q));
  printf("%d\n", deletion(&q));
  printf("%d\n", deletion(&q));
  printf("%d\n", deletion(&q));

  if(deletion(&q) == -9999)
  printf("queue underflow");

  return 0;
}

void insertion(Queue *qp, int v){
  if (qp->rear == SIZE){
    printf("Queue Overflow\n");
    return;
  }
  qp->item[qp->rear] = v;
  qp->rear = qp->rear + 1;
}

int deletion(Queue *qp){
  if (qp->rear == qp->front){
    return -9999;
  }
  int v = qp->item[qp->front];
  qp->front = qp->front + 1;
  return v;
}