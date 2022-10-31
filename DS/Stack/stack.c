#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct stack
{
    int data[MAX];
    int top;
} stack;

void init(stack *);
int is_full(stack *);
int is_empty(stack *);
void push(stack *, int x);
int pop(stack *);
void display(stack *);

void main()
{
    stack s;
    int choice, x;
    init(&s);
    do
    {
        printf("\n\n1.Push\n2.Pop\n3.Print\n4.Quit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (is_full(&s))
            {
                printf("stack overflow!");
            }
            else
            {
                printf("\nEnter number to be pushed:");
                scanf("%d", &x);
                push(&s, x);
            }
            break;
        case 2:
            if (is_empty(&s))
            {
                printf("stack under flow!");
            }
            else
            {
                x = pop(&s);
                printf("popped value is %d", x);
            }
            break;
        case 3:
            if (is_empty)
            {
                printf("stack is empty\n");
            }
            else
            {
                display(&s);
            }
            break;
        case 4:
            printf("exited!");
            break;
        }
    } while (choice != 4);
}

void init(stack *s)
{
    s->top = -1;
}

int is_full(stack *s)
{
    if (s->top == MAX - 1)
        return 1;
    else
        return 0;
}

int is_empty(stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

void push(stack *s, int x)
{
    s->top = s->top + 1;
    s->data[s->top] = x;
}

int pop(stack *s)
{
    int x;
    x = s->data[s->top];
    s->top = s->top - 1;
    return x;
}

void display(stack *s)
{
    int i;
    for (i = s->top; i >= 0; i--)
    {
        printf("\n| %d |\n", s->data[i]);
    }
}