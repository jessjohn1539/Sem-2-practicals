#include <stdio.h>
void SelectionSort(int a[], int n);
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
    SelectionSort(a, n);
    printf("sorted data is\n");
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
}
void SelectionSort(int a[], int n)
{
    int i, j, temp, k;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[k])
            {
                k = j;
            }
        }
        if (i != k)
        {
            temp = a[i];
            a[i] = a[k];
            a[k] = temp;
        }
    }
}