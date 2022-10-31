#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
} queue;
void enqueue(queue *q, int val);
int dequeue(queue*q);
int is_full(queue *q);
int is_empty(queue *q);
void main()
{
    queue q;
    q.size = 50;
    q.front = q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int)); // dynamic memory allocation
}
void enqueue(queue *q, int val)
{
    if (is_full(q))
    {
        printf("queue overflow");
    }
    else
    {
        q->rear = q->rear + 1;
        q->arr[q->rear] = val;
    }
}
int dequeue(queue*q){

}
int is_full(queue *q)
{
    if (q->rear == q->size - 1)
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