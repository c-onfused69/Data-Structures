#include <stdio.h>
#include <stdlib.h>

void sortarray(int n, int *p);

int main()
{
    int n, i, arr[100];

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    //p = (int *)malloc(n * sizeof(int));

    printf("Input %d number of elements in the array: ", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sortarray(n, arr);

    return 0;
}

void sortarray(int n, int *p)
{
    int i, j, temp;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (*(p + j) < *(p + i))
            {
                temp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
            }
        }
    }

    printf("\nExpected Output: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));
    }
}