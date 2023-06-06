
//If we take arr[n]={-7 6 9 -5 2 -3};

#include <stdio.h>
#include <stdlib.h>

int count = 0, i;

void deletef(int *a, int *p, int *q);

int main()
{
    int *a, n, size;

    printf("enter the size of array: ");
    scanf("%d", &n);

    a = (int *)malloc(sizeof(int) * n);

    printf("enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int *p, *q;
    p = a;
    q = (a + n - 1);
    //int size = (sizeof(a)) / (sizeof(int));
    size = n;
    deletef(a, p, q);

    printf("\nThe Array without negative numbers : ");
    for (i = 0; i < size - count; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n\n");

    //return 0;
}
void deletef(int *a, int *p, int *q)
{
    int *del;
    del = &a[0];
    while (p <= q)
    {
        if (*p >= 0)
        {
            *del = *p;
            del++;
        }
        p++;
    }
    for (; del <= q; del++)
    {
        *del = 0;
        count++;
    }
}
