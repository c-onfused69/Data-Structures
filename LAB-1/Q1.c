#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, *p, i, j;
  printf("Input size of array: ");
  scanf("%d", &n);

  p = malloc(sizeof(int *) * n);

  printf("Array element: ");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &p[i]);
  }

  //Checking the values in pointer p
  /*printf("\nElements of pointer type array 1: ");
  for (i = 0; i < n; i++)
  {
    printf("%d ", p[i]);
  }*/

  //int *large = malloc(sizeof(p));
  int *large, *q;
  large = p;
  //int *q = malloc(sizeof(p));
  q = p;

  /*printf("\nElements of pointer type array 2: ");
  for (i = 0; i < n; i++)
  {
    printf("%d ", *q);
    q++;
  }*/

  for (i = 0; i < n; i++)
  {
    if (*large < *q)

      large = q;
    q++;
  }

  printf("\n\nExpected Output: %d\n\n", *large);

  // Rechecking p
  /*printf("\nRe checking elements of pointer type array 1: ");
  for (i = 0; i < n; i++)
  {
    printf("%d ", p[i]);
  }*/

  return 0;
}