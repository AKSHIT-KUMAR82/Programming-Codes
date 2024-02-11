// DOUBLY CIRCULAR LINKED LIST...

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *nxt;
    struct node *prev;
} node;

void insert(node **head, node **tail, int key)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->info = key;
    if (*head == NULL)
    {
        *head = temp;
        *tail = temp;
        temp->nxt = *head;
        temp->prev = *head;
    }
    else
    {
        node *track = *head;
        if (((*head)->info) >= key)
        {
            temp->prev = *tail;
            temp->nxt = *head;
            (*tail)->nxt = temp;
            (*head)->prev = temp;
            (*head) = temp;
        }
        else
        {
            while (track != (*tail))
            {
                if (((track->nxt)->info) >= key)
                {
                    break;
                }
                track = track->nxt;
            }
            if (track == *tail)
            {
                temp->nxt = *head;
                (*head)->prev = temp;
                (*tail) = temp;
                track->nxt = temp;
            }
            else
            {
                temp->nxt = track->nxt;
                temp->prev = track;
                track->nxt = temp;
                ((temp->nxt)->prev) = temp;
            }
        }
    }
}

void delete1(node **head, node **tail, int key)
{
    int flag = 0;
    if (*head == NULL)
    {
        printf("UNDERFLOW CONDITION...\n");
    }
    else
    {
        node *track = *head;
        if ((*head == *tail) && (((*head)->info) == key))
        {
            flag = 1;
            *head = NULL;
            *tail = NULL;
            track->nxt = NULL;
            track->prev = NULL;
            free(track);
        }
        else if (((*head)->info) == key)
        {
            flag = 1;
            (*head) = (*head)->nxt;
            (*tail)->nxt = (*head);
            (*head)->prev = (*tail);
            track->nxt = NULL;
            track->prev = NULL;
        }
        else
        {
            while (track != *tail)
            {
                if (((track->nxt)->info) == key)
                {
                    flag = 1;
                    break;
                }
                track = track->nxt;
            }
            if (flag == 1)
            {
                if (track->nxt == *tail)
                {
                    (*tail) = track;
                    track = track->nxt;
                    (*tail)->nxt = *head;
                    track->nxt = NULL;
                    track->prev = NULL;
                    free(track);
                }
                else
                {
                    node *temp = track->nxt;
                    track->nxt = temp->nxt;
                    (temp->nxt)->prev = track;
                    temp->nxt = NULL;
                    temp->prev = NULL;
                    free(temp);
                }
            }
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

void Display(node *head, node *tail)
{
    if (head == NULL)
    {
        printf("NOTHING TO DISPLAY...\n");
    }
    else
    {
        node *temp = head;
        while (temp != tail)
        {
            printf("%d ", temp->info);
            temp = temp->nxt;
        }
        printf("%d\n", temp->info);
    }
}

int main()
{
    node *head = NULL, *tail = NULL;
    int choice = 1, key = 0;
    while (choice != 0)
    {
        printf("ENTER 1 FOR INSERTION, 2 FOR DELETION, 3 FOR DISPLAY & 0 TO EXIT : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("ENTER KEY TO BE INSERTED : ");
            scanf("%d", &key);
            insert(&head, &tail, key);
        }
        else if (choice == 2)
        {
            printf("ENTER KEY TO BE DELETED : ");
            scanf("%d", &key);
            delete1(&head, &tail, key);
        }
        else if (choice == 3)
        {
            Display(head, tail);
        }
    }
    return 0;
}
