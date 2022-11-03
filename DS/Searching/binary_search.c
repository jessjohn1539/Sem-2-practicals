/*
step 1: input an array from user.
step 2: sort it in ascending order.
step 3: mark starting point and ending point as i and j.
step 4: find centre using c=(i+j)/2
        if(key==a[c]){
        printf("Value found");
        break;
        }
        if(key>a[c])
        {
        centre ke left mei search karna hai by
        changing the value of j to c-1.
        }
        if(key>a[c])
        {
         centre ke right mei search karna hai by
         changing the value of i to c-1.
        }
*/
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
    printf("Enter the value to search:\n");
    scanf("%d", &key);
    // sorting in ascending order:
    bubbleSort(a, n);
    // start of binary search:
    i = 0;
    j = n - 1;
    c = (i + j) / 2;

    while (key != a[c])
    {
        if (key > a[c])
        {
            i = c + 1;
        }
        else
        {
            j = c - 1;
        }
        c = (i + j) / 2;
    }
    if (key == a[c])
    {
        printf("Data found!\n");
    }
    else
    {
        printf("Data not found!\n");
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