#include <stdio.h>

void main()
{
    int n, i, j, min, temp, a[100];

    printf("Enter no of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Selection sort
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }

    printf("Sorted array is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}
