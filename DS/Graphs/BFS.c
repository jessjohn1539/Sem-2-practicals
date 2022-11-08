#include <stdio.h>
#include <conio.h>
#define MAX 10

int R, F;      // FRont and Rear of the Queue
int data[MAX]; // The Queue of the size MAX

int isempty();       // to check whether the Queue is empty
int isfull();        // to check whether the Queue is Full
void enqueue(int x); // to insert a element in a  Queue
int dequeue();       // to delete a element from the Queue
void BFS(int);
int G[MAX][MAX]; // to store the adjacency matrix
int n;

int main()
{
    int i, j, v;

    printf("Enter the number of vertices\n");
    scanf("%d", &n);

    printf("\n Enter the Adjacency Matrix of the graph\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    printf("Enter the starting vertex for BFS\n");
    scanf("%d", &v);
    BFS(v);

    getch();
    return 0;
} // end of the function main

void BFS(int v)
{
    int visited[MAX], i;

    R = -1;
    F = -1; // initializing the queue

    // initializing the nodes as unvisited
    for (i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(v); // inserting the element in the queue
    printf("\n visit \t%d", v);

    visited[v] = 1;

    while (!isempty())
    {
        v = dequeue(); // dequeue the element
        // visit and add adjacent vertices

        for (i = 0; i < n; i++)

            if (visited[i] == 0 && G[v][i] != 0)
            {
                enqueue(i);
                visited[i] = 1;
                printf("\n visit \t %d", i);
            } // end for

    } // end while
}

int isempty()
{
    if (R == -1)
        return (1);

    return (0);
}

int isfull()
{
    if (R == MAX - 1)
        return (1);

    return (0);
}

void enqueue(int x)
{
    if (R == -1)
    {
        R = 0;
        F = 0;
        data[R] = x;
    }
    else
    {
        R = R + 1;
        data[R] = x;
    }
}

int dequeue()
{
    int x;
    x = data[F];

    if (R == F)
    {
        R = -1;
        F = -1;
    }

    else
        F = F + 1;
    return (x);
}
