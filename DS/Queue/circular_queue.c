/*
Drawbacks of linear queue:
    - space is not used efficiently
Increments:
i = i+1;          //linear increment
i = (i+1) % size; //circular increment
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct circular_queue
{
    int size;
    int front;
    int rear;
    int *arr;
} queue;

void enqueue(queue *q, int val);
int dequeue(queue *q);
int is_full(queue *q);
int is_empty(queue *q);
void main()
{
    queue q;
    q.size = 4;
    q.front = q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int)); // dynamic memory allocation
    // enqueue few elements
    enqueue(&q, 14);
    enqueue(&q, 15);
    enqueue(&q, 16);
    enqueue(&q, 17);
    printf("Dequeueing element %d\n", dequeue(&q));
    printf("Dequeueing element %d\n", dequeue(&q));
    printf("Dequeueing element %d\n", dequeue(&q));
    printf("Dequeueing element %d\n", dequeue(&q));
    if (is_empty(&q))
    {
        printf("Queue is empty\n");
    }
    if (is_full(&q))
    {
        printf("Queue is full\n");
    }
}
void enqueue(queue *q, int val)
{
    if (is_full(q))
    {
        printf("queue overflow");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = val;
    }
}
int dequeue(queue *q)
{
    int a = -1;
    if (is_empty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        a = q->arr[q->front];
    }
    return a;
}
int is_full(queue *q)
{
    if ((q->rear + 1) % q->size == q->front)
        return 1;
    else
        return 0;
}
int is_empty(queue *q)
{
    if (q->front == q->rear)
        return 1;
    else
        return 0;
}
