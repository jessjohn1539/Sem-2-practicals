// freecodecamp.org
/*
Definition: A list with the restriction that insertion and deletion
can be performed only from one end, called top.

stack as an ADT meaning;
we only talk about the logical features/operations.
and not onto actual implementations.
LIFO(last in first out) - only top element accessible.

both push and pop operations are O(1) or constant time.

Applications:
    -function calls/recursion
    -undo in an editor
    -Balanced parenthesis in compiler
*/
// stack array based implementations
#include <stdio.h>
#include <stdlib.h>
#define MAX 101

void push(int x);
void pop();
int Top();

int a[MAX];
int top = -1;
void push(int x)
{
    if (top == MAX - 1)
    {
        printf("Error: stack overflow\n");
        return;
    }
    a[++top] = x;
}
void pop()
{
    if (top == -1)
    {
        printf("Error: No element to pop\n");
        return;
    }
    top--;
}
int Top()
{
    return a[top];
}
void print(){
    int i;
    for(i=0;i<=top;i++){
        printf(" %d ",a[i]);
    }
    printf("\n");
}
void main()
{
    push(2);
    print();
    push(5);
    print();
    push(10);
    print();
    pop();
    print();
    push(12);
    print();
}