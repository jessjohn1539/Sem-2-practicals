#include <stdio.h>
void insertionSort(int a[], int n);
void main()
{
    // input number of elements and values from user:
    int n, a[20], i;
    printf("Enter no.of elements:\n");
    scanf("%d", &n);
    printf("Enter the values:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    // sorting:
    insertionSort(a, n);
    printf("sorted list is\n");
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
}
void insertionSort(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0 && a[j] > temp; j--)
        {
            a[j + 1] = a[j];
        }
        if (a[i] = temp)
        {
            a[j + 1] = temp;
        }
    }
}