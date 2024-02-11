// CIRCULAR LINKED LIST..

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *nxt;
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
    }
    else
    {
        if (((*head)->info) >= key)
        {
            temp->nxt = *head;
            (*head)=temp;
            (*tail)->nxt=*head;
        }
        else
        {
            node *track = *head;
            while (track != *tail)
            {
                if (((track->nxt)->info) >= key)
                {
                    break;
                }
                track = track->nxt;
            }
            if (track == *tail)
            {
                track->nxt = temp;
                temp->nxt = *head;
                *tail = temp;
            }
            else
            {
                temp->nxt = track->nxt;
                track->nxt = temp;
            }
        }
    }
}

void delete1(node **head,node **tail,int key)
{
    node *temp=*head;
    int flag=0;
    if(*head==NULL)
    {
        printf("UNDERFLOW CONDITION...\n");
    }
    else{
        if((*head==*tail)&&(((*head)->info)==key))
        {
            flag=1;
            (*head)=NULL;
            (*tail)=NULL;
            temp->nxt=NULL;
            free(temp);
        }
        else if((*head)->info==key)
        {
            flag=1;
            (*head)=(*head)->nxt;
            (*tail)->nxt=*head;
            temp->nxt=NULL;
            free(temp);
        }
        else{
            while(temp!=(*tail))
            {
                if(((temp->nxt)->info)==key)
                {
                    flag=1;
                    break;
                }
                temp=temp->nxt;
            }
            if(flag==1)
            {
                if(temp->nxt==(*tail))
                {
                    (*tail)=temp;
                    temp=temp->nxt;
                    (*tail)->nxt=*head;
                    temp->nxt=NULL;
                    free(temp);
                }
                else{
                    node *track=temp->nxt;
                    temp->nxt=track->nxt;
                    track->nxt=NULL;
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

}

void Display(node *head, node *tail)
{
    if (head == NULL)
    {
        printf("NOTHING TO DISPLAY..\n");
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
    node *head = NULL,*tail = NULL;
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
            delete1(&head,&tail,key);
        }
        else if (choice == 3)
        {
            Display(head,tail);
        }
    }
    return 0;
}