//fully menu driven program of a linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
void insert_b(node *head, int x);
node *insert_e(node *head, int x);
node *delete (node *head, int x);
void print(node *head);
void main()
{
    int op, x;
    node *head = NULL;
    do
    {
        printf("\n 1-insert in beginning \n 2-Insert at end\n 3-delete a specific\n 4-display\n 5-quit\n");
        printf("enter your choice\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter data to be inserted: ");
            scanf("%d", &x);
            insert_b(head, x);
            break;

        case 2:
            printf("Enter data to be inserted: ");
            scanf("%d", &x);
            insert_e(head, x);
            break;
        case 3:
            printf("enter the data to be deleted\n");
            scanf("%d", &x);
            head = delete (head, x);
            break;
        case 4:
            print(head);
            break;
        }
    } while (op != 5);
}
void insert_b(node *head, int x)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    p->data = x;
    p->next = head;
    head = p;
}
node *insert_e(node *head, int x)
{
    node *p, *q;
    p = (node *)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    if (head == NULL)
    {
        return p;
    }
    else
    {
        q = head;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
        return head;
    }
}
node *delete (node *head, int x)
{
    node *p, *q;
    if (x == head->data)
    {
        p = head;
        head = head->next;
        free(p);
    }
    else
    {
        while (x != (p->next)->data && p->next != NULL)
        {
            p = p->next;
        }
        if (p->next != NULL)
        {
            q = p->next;
            p->next = (p->next)->next;
            free(p);
        }
    }
    return head;
}
void print(node *head)
{
    node *p;
    p = head;
    while (p != NULL)
    {
        printf("%d", p->data);
        p = p->next;
    }
}