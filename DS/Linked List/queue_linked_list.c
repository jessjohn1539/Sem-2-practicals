//implementing queue using linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
void enqueue(int x);
void dequeue();

node *front = NULL;
node *rear = NULL;
void main()
{
    enqueue(5);
    enqueue(4);
    enqueue(3);
    enqueue(2);
    enqueue(1);
    dequeue();
    dequeue();
}
void enqueue(int x)
{
    node *temp = (node *)malloc(sizeof(node *));
    temp->data = x;
    temp->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
        printf("Enqueued element %d\n", x);
        return;
    }
    rear->next = temp;
    rear = temp;
    printf("Enqueued element %d\n", x);
}
void dequeue()
{
    node *temp = front;
    if (front == NULL)
        return;
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        printf("dequeued element %d\n", (*temp));
    }
    free(temp);
}
