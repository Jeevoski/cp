#include <stdio.h>

int main()
{
    int n, i, j, temp, a[100];

    printf("Enter no of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Insertion Sort
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }

        a[j + 1] = temp;
    }

    printf("Sorted array is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
