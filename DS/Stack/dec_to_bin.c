#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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

void main()
{
    stack s;
    int x;
    init(&s);
    printf("Enter a decimal number:");
    scanf("%d", &x);
    while (x != 0)
    {
        if (!is_full(&s))
        {
            push(&s, x % 2);
            x = x / 2;
        }
        else
        {
            printf("Stack overflow");
        }
    }
    while (!is_empty(&s))
    {
        x = pop(&s);
        printf("%d", x);
    }
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