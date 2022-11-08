//freecodecamp.org
// Insert a node at the beginning of a linked list
/*
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
struct node *head;
void insert(int x);
void print();
void insert(int x)
{

    struct node *p;
    p = (node *)malloc(sizeof(struct node));
    p->data = x;
    p->next = head;
    head = p;
}
void print(){
    struct node *p = head;
    printf("The list is: \n");
    while (p!=NULL)
    {
        printf("| %d |->", p->data);
        p  = p->next;
    }

}
void main()
{
    head = NULL;
    printf("How many numbers?\n");
    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the number\n");
        scanf("%d", &x);
        insert(x);
        print();
    }
}*/

// Insert at n th node of a linked list
/*
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
struct node *head;
void insert(int data, int n);
void print();
void insert(int data, int n)
{
    node *p = (node *)malloc(sizeof(node));
    p->data = data;
    p->next = NULL;
    if (n == 1)
    {
        p->next = head;
        head = p;
        return;
    }
    node *p2 = head;
    for (int i = 0; i < n - 2; i++)
    {
        p2 = p2->next;
    }
    p->next = p2->next;
    p2->next = p;
}
void print()
{
    node *p = head;
    while (p != NULL)
    {
        printf("| %d |->", p->data);
        p = p->next;
    }
    printf("\n");
}
void main()
{
    head = NULL;
    insert(2, 1);
    insert(3, 2);
    insert(4, 1);
    insert(5, 2);
    print();
}*/

// Delete a node at n th position
/*
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
struct node *head;
void insert(int x);  // insert an integer at the end of the list
void print();        // print all elements
void delete (int n); // delete node at position
void insert(int x)
{
    node *p, *q;
    p = (node *)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    if (head == NULL)
    {
        p->data = x;
        p->next = head;
        head = p;
    }
    else
    {
        q = head;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
        p->data = x;
        p->next = NULL;
    }
}
void print()
{
    node *temp = head;
    while (temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void delete (int n)
{
    node *temp1 = head;
    if (n == 1)
    {
        head = temp1->next; // head now points to the second node
        free(temp1);
        return;
    }
    for (int i = 0; i < n - 2; i++)
    {
        temp1 = temp1->next;
        // temp1 points to (n-1)th node
    }
    node *temp2 = temp1->next; // nth node
    temp1->next = temp2->next; //(n+1)th node
    free(temp2);
}
void main()
{
    head = NULL;
    insert(2);
    insert(4);
    insert(6);
    insert(5);
    print();
    int n;
    printf("Enter a position to be deleted: \n");
    scanf("%d", &n);
    delete (n);
    print();
}*/
