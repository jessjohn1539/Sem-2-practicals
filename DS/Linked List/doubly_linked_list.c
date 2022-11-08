//freecodecamp.org
/*
-advantage is that at the time of deletion we only need address of the node which is
to be deleted where in singly we must have the node and the side nodes too.
-disadvantge is extra memory is allocated for pointers to previous node.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;
struct node *head; // global variable- pointer to head node
node *GetNewNode(int x);
void InsertAtHead(int x);
void print();
void ReversePrint();

void InsertAtHead(int x)
{
    node *newNode = GetNewNode(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
node *GetNewNode(int x)
{
    // local variable
    //  will be cleared from memory when function call will finish
    //  node myNode;
    node *newNode = (node *)malloc(sizeof(node)); // creating a memory in heap or dynamic memory
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void print()
{
    node *temp = head;
    printf("forward print:\n");
    while (temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void ReversePrint()
{
    node *temp = head;
    if (temp == NULL)
        return; // empty list-> exit
    // Going to last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // Traversing backward dir using prev pointer
    printf("Reverse print: \n");
    while (temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void main()
{
    head = NULL; // empty list
    InsertAtHead(2);
    print();
    ReversePrint();
    InsertAtHead(4);
    print();
    ReversePrint();
    InsertAtHead(6);
    print();
    ReversePrint();
    InsertAtHead(8);
    print();
    ReversePrint();
}