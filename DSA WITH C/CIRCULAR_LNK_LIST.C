/* HERE , WE ARE DISCUSSING CIRCULAR LINKED LIST */

/*
INSERTION AT END AND BEGINING OF THE CIRCULAR LINKED LIST...
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *nxt;
} node;

// INSERTION AT THE END IN THE CIRCULAR LINKED LIST...
void insert_end(node **head, node **last, int val)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->info = val;
    if ((*head) == NULL)
    {
        *head = temp;
        *last = temp;
        (*last)->nxt = *head;
    }
    else
    {
        (*last)->nxt = temp;
        *last = temp;
        (*last)->nxt = *head;
    }
}

// INSERTION AT THE BEGINING IN THE CIRCULAR LINKED LIST...
void insert_begin(node **head, node **last, int val)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->info = val;
    if ((*head) == NULL)
    {
        *head = temp;
        *last = temp;
        (*last)->nxt = *head;
    }
    else
    {
        temp->nxt = *head;
        (*head) = temp;
        (*last)->nxt = (*head);
    }
}

// DELETION AT THE END IN THE CIRCULAR LINKED LIST...
int delete_end(node **head, node **last)
{
    int a;
    if (*head == NULL)
    {
        printf("UNDERFLOW CONDITION....\n");
        return -1; // ASSUMING THAT -1 IS AN INVALID VALUE...
    }
    else if (*head == *last)
    {
        *head = NULL;
        (*last)->nxt = NULL;
        a = (*last)->info;
        (*last) = NULL;
    }
    else
    {
        node *temp = *head;
        while (temp->nxt != (*last))
        {
            temp = temp->nxt;
        }
        (*last) = temp;
        temp = temp->nxt;
        temp->nxt = NULL;
        a = temp->info;
        (*last)->nxt = *head;
        free(temp);
    }
    return a;
}

// DELETION AT THE BEGINING IN THE CIRCULAR LINKED LIST...
int delete_begin(node **head, node **last)
{
    int a;
    if (*head == NULL)
    {
        printf("UNDERFLOW CONDITION....\n");
        return -1; // ASSUMING THAT -1 IS AN INVALID VALUE...
    }
    else if (*head == *last)
    {
        *head = NULL;
        (*last)->nxt = NULL;
        a = (*last)->info;
        (*last) = NULL;
    }
    else
    {
        node *temp;
        temp = *head;
        (*head) = (*head)->nxt;
        a = temp->info;
        temp->nxt = NULL;
        (*last)->nxt = *head;
        free(temp);
    }
    return a;
}

void display(node *head)
{
    if (head == NULL)
    {
        printf("NOTHING TO DISPLAY\n");
    }
    else
    {
        node *temp = head;
        while (temp->nxt != head)
        {
            printf("%d ", temp->info);
            temp = temp->nxt;
        }
        printf("%d\n", temp->info);
    }
}

int main()
{
    node *head = NULL, *last = NULL;
    int choice1, choice2;
    printf("ENTER 1 FOR INSERTION , 2 FOR DELETION & 3 FOR DISPLAY : ");
    scanf("%d", &choice1);
    while (choice1 == 1 || choice1 == 2 || choice1 == 3)
    {
        int val;
        switch (choice1)
        {
        case 1:
            printf("ENTER 1 FOR INSERTION AT END & 2 FOR INSERTION AT BEGINING : ");
            scanf("%d", &choice2);
            if (choice2 == 1)
            {
                printf("ENTER THE VALUE TO BE INSERTED : ");
                scanf("%d", &val);
                insert_end(&head, &last, val);
            }
            else
            {
                printf("ENTER THE VALUE TO BE INSERTED : ");
                scanf("%d", &val);
                insert_begin(&head, &last, val);
            }
            break;

        case 2:
            printf("ENTER 1 FOR DELETION AT END & 2 FOR DELETION AT BEGINING : ");
            scanf("%d", &choice2);
            if (choice2 == 1)
            {
                val = delete_end(&head, &last);
                if (val != -1)
                {
                    printf("DELETED VALUE : %d\n", val);
                }
            }
            else
            {
                val = delete_begin(&head, &last);
                if (val != -1)
                {
                    printf("DELETED VALUE : %d\n", val);
                }
            }
            break;

        case 3:
            display(head);
            break;
        }
        printf("ENTER 1 FOR INSERTION , 2 FOR DELETION & 3 FOR DISPLAY : ");
        scanf("%d", &choice1);
    }
}