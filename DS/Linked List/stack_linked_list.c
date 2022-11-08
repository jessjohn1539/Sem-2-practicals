/*
Since, stack is a LIFO structure
insertion and deletion in  linked list is possible in two ways
1. at the end of list
2. at beginning of list
since, the time complexity to insert and delete at
at the end of list is O(n);
we opt to insert/delete at begnning of list having
time complexity O(1);
*/
// stack using linked list
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} node;
struct node *top = NULL;
void push(int x);
void print();
void pop();

void push(int x)
{
    // there won't be overflow since it's linked list
    struct node *p;
    p = (node *)malloc(sizeof(struct node));
    p->data = x;
    p->link = top;
    top = p;
}
void pop()
{
    node *p;
    if (top == NULL)
    {
        printf("Error: stack is empty\n");
        return;
    }
    p = top;
    top = top->link;
    free(p);
}
void print()
{
    struct node *p = top;
    printf("The stack is: \n");
    while (p != NULL)
    {
        printf(" %d ", p->data);
        p = p->link;
    }
    printf("\n");
}
void main()
{
    top = NULL;
    push(2);
    print();
    push(4);
    print();
    push(6);
    print();
    pop();
    print();
    push(8);
    print();
}