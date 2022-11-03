#include <stdio.h>
void bubbleSort(int a[], int n);
void main()
{
    // input number of elements and values from user:
    int n, a[20], i, key, j, c;
    printf("Enter no.of elements:\n");
    scanf("%d", &n);
    printf("Enter the values:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    // sorting in ascending order:
    bubbleSort(a, n);
    printf("sorted data is\n");
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
}
void bubbleSort(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < 5 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}