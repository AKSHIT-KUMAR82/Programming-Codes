/* ASSIGNMENT 2 GIVEN BY ASHISH SIR...
PROBLEM STATEMENT : YOU HAVE TO MAKE ALL FOUR LINKED LIST AND INSERT ELEMENTS IN SORTED ORDER
AND FOR DELETEION YOU HAVE TO DO IT ACCORDING TO THE KEY PROVIDED BY THE USER
FOUR LINKED LIST :
1) SINGLY LINKED LIST..
2) DOUBLY LINKED LIST..
3) CIRCULAR LINKED LIST..
4) DOUBLY CIRCULAR LINKED LIST...*/

// SINGLY LINKED LIST...

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *nxt;
} node;

void insert(node **head, int key)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->info = key;
    if (*head == NULL)
    {
        *head = temp;
        temp->nxt = NULL;
    }
    else
    {
        if (((*head)->info) >= key)
        {
            temp->nxt = *head;
            (*head) = temp;
        }
        else
        {
            node *track = *head;
            while (track->nxt != NULL)
            {
                if (((track->nxt)->info) >= key)
                {
                    break;
                }
                track = track->nxt;
            }
            temp->nxt = track->nxt;
            track->nxt = temp;
        }
    }
}

void delete1(node **head, int key)
{
    node *temp = *head, *track;
    int flag = 0;
    if (*head == NULL)
    {
        printf("UNDERFLOW CONDITION...\n");
    }
    else
    {
        if(((*head)->info == key)&&((*head)->nxt==NULL))
        {
            flag = 1;
            *head = NULL;
            free(temp);
        }
        else if((*head)->info == key)
        {
            flag=1;
            (*head)=(*head)->nxt;
            temp->nxt=NULL;
            free(temp);
        }
        else
        {
            while (temp->nxt != NULL)
            {
                if (((temp->nxt)->info) == key)
                {
                    flag = 1;
                    break;
                }
                temp = temp->nxt;
            }
            if (flag == 1)
            {
                track = temp->nxt;
                temp->nxt = track->nxt;
                track->nxt = NULL;
                free(track);
            }
        }
    }
    if(flag==1)
    {
        printf("KEY IS FOUND AND HAS BEEN DELETED...\n");
    }
    else{
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
            delete1(&head,key);
        }
        else if (choice == 3)
        {
            Display(head);
        }
    }
    return 0;
}
