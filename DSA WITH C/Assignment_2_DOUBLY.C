// DOUBLY LINKED LIST..

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *nxt;
    struct node *prev;
} node;

void insert(node **head, int key)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->info = key;
    if (*head == NULL)
    {
        *head = temp;
        temp->nxt = NULL;
        temp->prev = NULL;
    }
    else
    {
        node *track = *head;
        while (track->nxt != NULL)
        {
            if ((track->info) >= key)
            {
                break;
            }
            track = track->nxt;
        }
        if ((track->info) >= key)
        {
            if (track->prev == NULL)
            {
                temp->prev = NULL;
                temp->nxt = track;
                track->prev = temp;
                (*head) = temp;
            }
            else
            {
                temp->nxt = track;
                temp->prev = track->prev;
                ((track->prev)->nxt) = temp;
                track->prev = temp;
            }
        }
        else
        {
            temp->nxt = NULL;
            temp->prev = track;
            track->nxt = temp;
        }
    }
}

void delete1(node **head, int key)
{
    int flag = 0;
    if (*head == NULL)
    {
        printf("UNDERFLOW CONDITION...\n");
    }
    else
    {
        node *track = *head, *temp;
        while (track->nxt != NULL)
        {
            if (track->info == key)
                break;
            track = track->nxt;
        }
        if (track->info == key)
        {
            flag = 1;
            if((track->nxt==NULL)&&(track->prev==NULL))
            {
                *head=NULL;
            }
            else if(track->nxt == NULL)
            {
                (track->prev)->nxt = NULL;
            }
            else if(track->prev==NULL)
            {
                *head=track->nxt;
                (*head)->prev=NULL;
            }
            else
            {
                ((track->prev)->nxt) = track->nxt;
                ((track->nxt)->prev) = track->prev;
            }
            track->nxt = NULL;
            track->prev = NULL;
            free(track);
        }
    }
    if (flag == 1)
    {
        printf("KEY IS FOUND AND HAS BEEN DELETED...\n");
    }
    else
    {
        printf("KEY IS NOT FOUND...\n");
    }
}

void Display(node *head)
{
    if (head == NULL)
    {
        printf("NOTHING TO DISPLAY...\n");
    }
    else
    {
        node *temp = head;
        while (temp->nxt!=NULL)
        {
            printf("%d ", temp->info);
            temp = temp->nxt;
        }
        printf("%d\n", temp->info);
    }
}

int main()
{
    node *head = NULL;
    int choice = 1, key = 0;
    while (choice != 0)
    {
        printf("ENTER 1 FOR INSERTION, 2 FOR DELETION, 3 FOR DISPLAY & 0 TO EXIT : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("ENTER KEY TO BE INSERTED : ");
            scanf("%d", &key);
            insert(&head, key);
        }
        else if (choice == 2)
        {
            printf("ENTER KEY TO BE DELETED : ");
            scanf("%d", &key);
            delete1(&head, key);
        }
        else if (choice == 3)
        {
            Display(head);
        }
    }
    return 0;
}
