#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define MAX 50
typedef struct stack
{
    int data[MAX];
    int top;
} stack;
void init(stack *);
int is_empty(stack *);
int is_full(stack *);
int pop(stack *);
void push(stack *, int x);
int evaluate(int op1, int op2, char x);

void main()
{
    char x;
    stack s;
    init(&s);
    int op1,op2,val;
    printf("Enter a postfix expression:\n");
    while ((x = getchar()) != '\n')
    {
        if (isdigit(x))
        {
            push(&s, x - 48);
        }
        else
        {
            op1 = pop(&s);
            op2 = pop(&s);
            val = evaluate(op1, op2, x);
            push(&s, val);
        }
    }
    val = pop(&s);
    printf("After evaluation=%d", val);
}
int evaluate(int op1, int op2, char x)
{
    if (x == '+')
        return (op1 + op2);
    if (x == '-')
        return (op1 - op2);
    if (x = '*')
        return (op1 * op2);
    if (x == '/')
        return (op1 / op2);
    if (x == '%')
        return (op1 % op2);
}
void init(stack *s)
{
    s->top == -1;
}
int is_empty(stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}
int is_full(stack *s)
{
    if (s->top == MAX - 1)
        return 1;
    else
        return 0;
}
int pop(stack *s)
{
    int x;
    x = s->data[s->top];
    s->top = s->top - 1;
    return x;
}
void push(stack *s, int x)
{
    s->top = s->top + 1;
    s->data[s->top] = x;
}