#include <stdio.h>

void main()
{
    int n, a[20], i, key;
    printf("Enter no.of elements:\n");
    scanf("%d", &n);
    printf("Enter the values:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the value to search:\n");
    scanf("%d", &key);

    for (i = 0; i < n; i++)
    {
        if (key == a[i])
        {
            printf("Value found at %d.", i + 1);
            break;
        }
    }
    if (i == n)
    {
        printf("Data not found.\n");
    }
}