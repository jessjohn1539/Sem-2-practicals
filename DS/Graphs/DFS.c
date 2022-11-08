#include <stdio.h>
#include <conio.h>

void DFS(int);

int G[10][10], visited[10], n = 0;
// n = No of vertices
// graph stored in array G[10][10]

// function main()
int main()
{
    int i = 0, j = 0;
    // ask for the total number of Vertices
    printf("enter the Number of Vertices\n");
    scanf("%d", &n);
    // read the adjacency matrix
    printf("\n Enter the Adjacency matrix of the graph\n");
    // enter 1 or 0 based on adjacency
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);
    // printf("\nHello");
    // visited is initialized to 0
    for (i = 0; i < n; i++)
        visited[i] = 0;
    int start;
    printf("Enter the starting Vertex");
    scanf("%d", &start);
    DFS(start); // call to the DFS Function
    getch();
    return (0);
}
void DFS(int i)
{
    int j;
    printf("\n %d", i);
    visited[i] = 1;
    for (j = 0; j < n; j++)
    {
        if (!visited[j] && G[i][j] == 1)
            DFS(j); // recursive call to DFS Function
    }
}
