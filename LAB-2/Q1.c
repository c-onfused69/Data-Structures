#include <stdlib.h>
#include <stdio.h>

void create();
void display();
void insert_beginning();
void insert_end();
void insert_any_pos();
void delete_beginning();
void delete_end();
void delete_any_pos();
void reverse();
void remove_duplicate();
struct node
{
    int info;
    struct node *next;
};
struct node *start = NULL;
int main()
{
    int choice;
    while (1)
    {
        printf("\n 1.Create");
        printf("\n 2.Display");
        printf("\n 3.Insert at the beginning");
        printf("\n 4.Insert at specified position");
        printf("\n 5.Delete from beginning");
        printf("\n 6.Delete from the end");
        printf("\n 7.Delete from specified position");
        printf("\n 8.Reverse linked list");
        printf("\n 9.Remove Duplicate linked list");
        printf("\n 10.Exit \n");
        printf("\nEnter your choice:\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_beginning();
            break;

        case 4:
            insert_any_pos();
            break;
        case 5:
            delete_beginning();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            delete_any_pos();
            break;

        case 8:
            reverse();
            break;

        case 9:
            remove_duplicate();
            break;

        case 10:
            exit(0);
            break;

        default:
            printf("\n Wrong Choice:\n");
            break;
        }
    }
    return 0;
}
void create()
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\nOut of Space:\n");
        exit(0);
    }
    printf("\nEnter the data value for the node:\t");
    scanf("%d", &temp->info);
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
void display()
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("\nThere is nothing:\n");
        return;
    }
    else
    {
        ptr = start;
        printf("\nThe List elements are:\n");
        while (ptr != NULL)
        {
            printf("%d\t", ptr->info);
            ptr = ptr->next;
        }
    }
}
void insert_beginning()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\nOut of Space:\n");
        return;
    }
    printf("\nEnter the data value for the node:\t");
    scanf("%d", &temp->info);
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        temp->next = start;
        start = temp;
    }
}

void insert_any_pos()
{
    struct node *ptr, *temp;
    int i, pos;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\nOut of Space:n");
        return;
    }
    printf("\nEnter the position for the new node to be inserted:\t");
    scanf("%d", &pos);
    printf("\nEnter the data value of the node:\t");
    scanf("%d", &temp->info);

    temp->next = NULL;
    if (pos == 0)
    {
        temp->next = start;
        start = temp;
    }
    else
    {
        for (i = 0, ptr = start; i < pos - 1; i++)
        {
            ptr = ptr->next;
            if (ptr == NULL)
            {
                printf("\nPosition not found:[Handle with care]\n");
                return;
            }
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
}
void delete_beginning()
{
    struct node *ptr;
    if (ptr == NULL)
    {
        printf("\nThere is nothing:\n");
        return;
    }
    else
    {
        ptr = start;
        start = start->next;
        printf("\nThe deleted element is :%d\t", ptr->info);
        free(ptr);
    }
}
void delete_end()
{
    struct node *temp, *ptr;
    if (start == NULL)
    {
        printf("\nThere is nothing:");
        exit(0);
    }
    else if (start->next == NULL)
    {
        ptr = start;
        start = NULL;
        printf("\nThe deleted element is:%d\t", ptr->info);
        free(ptr);
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        printf("\nThe deleted element is:%d\t", ptr->info);
        free(ptr);
    }
}
void delete_any_pos()
{
    int i, pos;
    struct node *temp, *ptr;
    if (start == NULL)
    {
        printf("\nThe There is nothing:\n");
        exit(0);
    }
    else
    {
        printf("\nEnter the position of the node to be deleted:\t");
        scanf("%d", &pos);
        if (pos == 0)
        {
            ptr = start;
            start = start->next;
            printf("\nThe deleted element is:%d\t", ptr->info);
            free(ptr);
        }
        else
        {
            ptr = start;
            for (i = 0; i < pos; i++)
            {
                temp = ptr;
                ptr = ptr->next;
                if (ptr == NULL)
                {
                    printf("\nPosition not Found:\n");
                    return;
                }
            }
            temp->next = ptr->next;
            printf("\nThe deleted element is:%d\t", ptr->info);
            free(ptr);
        }
    }
}
void reverse()
{
    struct node *prevNode, *curNode, *temp;
    if (start != NULL)
    {
        prevNode = start;
        curNode = start->next;
        start = start->next;
        prevNode->next = NULL;
        while (start != NULL)
        {
            start = start->next;
            curNode->next = prevNode;
            prevNode = curNode;
            curNode = start;
        }
        start = prevNode;
        printf("Reveresed list is :\n");
    }
    if (start == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = start;
        while (temp != NULL)
        {
            printf(" %d ", temp->info);
            temp = temp->next;
        }
    }
}
void remove_duplicate()
{
    struct node *current = start;

    struct node *next_next, *temp;

    if (current == NULL)
        return;

    while (current->next != NULL)
    {
        if (current->info == current->next->info)
        {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else
        {
            current = current->next;
        }
    }
    temp = start;
    while (temp != NULL)
    {
        temp = temp->next;
    }
}
