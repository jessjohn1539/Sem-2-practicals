#include <stdio.h>
#include <malloc.h>

struct node
{
    float coef;
    int expo;
    struct node *link;
};

typedef struct node *NODE;

NODE insert(NODE start, float co, int ex)
{

    NODE p, q;
    q = (NODE)malloc(sizeof(struct node));
    q->coef = co;
    q->expo = ex;

    if (start == NULL || ex > start->expo)
    {
        q->link = start; // setting the start
        start = q;
    }

    else
    {
        p = start;

        while (p->link != NULL && p->link->expo > ex)
            p = p->link;
        q->link = p->link;
        p->link = q;

        if (p->link == NULL)
            q->link = NULL;
    }
    return start;
}

NODE poly_add(NODE p1, NODE p2)
{

    NODE p3_start, p3, tmp;
    p3_start = NULL;

    if (p1 == NULL && p2 == NULL)
        return p3_start;

    while (p1 != NULL && p2 != NULL)
    {
        tmp = (NODE)malloc(sizeof(struct node));

        if (p3_start == NULL)
        {
            p3_start = tmp;
            p3 = p3_start;
        }

        else
        {
            p3->link = tmp;
            p3 = p3->link;
        }

        if (p1->expo > p2->expo)
        {
            tmp->coef = p1->coef;
            tmp->expo = p1->expo;
            p1 = p1->link;
        }
        else if (p2->expo > p1->expo)
        {
            tmp->coef = p2->coef;
            tmp->expo = p2->expo;
            p2 = p2->link;
        }
        else if (p1->expo == p2->expo)
        {
            tmp->coef = p1->coef + p2->coef;
            tmp->expo = p1->expo;
            p1 = p1->link;
            p2 = p2->link;
        }
    }

    while (p1 != NULL)
    {
        tmp = (NODE)malloc(sizeof(struct node));
        tmp->coef = p1->coef;
        tmp->expo = p1->expo;

        if (p3_start == NULL)
        {
            p3_start = tmp;
            p3 = p3_start;
        }
        else
        {
            p3->link = tmp;
            p3 = p3->link;
        }

        p1 = p1->link;
    }

    while (p2 != NULL)
    {
        tmp = (NODE)malloc(sizeof(struct node));
        tmp->coef = p2->coef;
        tmp->expo = p2->expo;

        if (p3_start == NULL)
        {
            p3_start = tmp;
            p3 = p3_start;
        }
        else
        {
            p3->link = tmp;
            p3 = p3->link;
        }
        p2 = p2->link;

    } /*End of while*/

    p3->link = NULL;
    return p3_start;
}

NODE enter(NODE start)
{
    int i, n, ex;
    float co;
    printf("\nHow many terms u want to enter:");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("\nEnter coeficient for term %d:", i);
        scanf("%f", &co);
        printf("Enter exponent for term %d:", i);
        scanf("%d", &ex);
        start = insert(start, co, ex);
    }
    return start;
} /*End of enter()*/

void display(NODE ptr)
{

    if (ptr == NULL)
    {
        printf("\nEmpty\n");
        return;
    }

    while (ptr != NULL)
    {
        printf("(%.1fx^%d) + ", ptr->coef, ptr->expo);
        ptr = ptr->link;
    }

    printf("\b\b \n"); /* \b\b to erase the last + sign*/
} /*End of display()*/

int main()
{
    NODE p1_start, p2_start, p3_start;
    p1_start = NULL;
    p2_start = NULL;
    p3_start = NULL;
    printf("\nPolynomial 1 :\n");
    p1_start = enter(p1_start);
    printf("\nPolynomial 2 :\n");
    p2_start = enter(p2_start);
    p3_start = poly_add(p1_start, p2_start);
    system("cls"); // clrscr();
    printf("\nPolynomial 1 is: ");
    display(p1_start);
    printf("\nPolynomial 2 is: ");
    display(p2_start);
    printf("\nAdded polynomial is: ");
    display(p3_start);

    getch();
    return (0);
}
