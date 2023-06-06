#include <stdio.h>
#include <stdlib.h>

struct studentinfo
{
    char name[30];
    int roll;
    float cgpa;
};

int main()
{
    struct studentinfo *p;
    int n;
    float high;

    printf("\nEnter the number of students: ");
    scanf("%d ", &n);
    p = (struct studentinfo *)malloc(n * sizeof(struct studentinfo));

    for (int i = 0; i < n; i++) //Scanning students info
    {
        printf("\nEnter informations of student %d : \n", (i + 1));

        printf("\nEnter students name: ");
        scanf("%s", &p[i].name);
        printf("\nEnter students roll: ");
        scanf("%d", &p[i].roll);
        printf("\nEnter students cgpa: ");
        scanf("%f", &p[i].cgpa);
    }

    printf("\n\nDisplaying Information:\n"); //dis[laying students info
    for (int i = 0; i < n; ++i)
    {
        printf("\nName: %s\tRoll: %d\tCGPA: %.2f", p[i].name, p[i].roll, p[i].cgpa);
    }

    high = p[0].cgpa;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i].cgpa > high)
        {
            high = p[i].cgpa;
            count++;
        }
    }
    printf("\n\nHighest cgpa is: %.2f", high);
    printf("\nName of student with the highest CGPA is: %s\n", p[count].name);

    //return 0;
}
