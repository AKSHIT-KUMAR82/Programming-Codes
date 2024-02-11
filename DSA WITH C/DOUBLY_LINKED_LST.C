#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *nxt;
    struct node *prev;
} node;

/*int delete_end(node **head, node **tail)
{
    int a;
    if (*head == NULL)
    {
        printf("UNDERFLOW CONDITION...\n");
        return -1;
    }
    else if (*head == *tail)
    {
        a = (*head)->info;
        (*head) = NULL;
        (*tail) = NULL;
    }
    else
    {
        node *temp = (*tail)->prev;
        temp->nxt = NULL;
        (*tail)->prev = NULL;
        a = (*tail)->info;
        (*tail) = temp;
        free(temp);
    }
    return a;
}
*/
/*
int delete_end(node **head)
{
    int a;
    if (*head == NULL)
    {
        printf("UNDERFLOW CONDITION...\n");
        return -1;
    }
    else if ((*head)->nxt==NULL)
    {
        a = (*head)->info;
        (*head) = NULL;
    }
    else
    {
        node *temp=*head;
        (*head)=(*head)->nxt;
        temp->nxt=NULL;
        a=temp->info;
        free(temp);
    }
    return a;
}*/

/*int delete_n(node **head,int n)
{
    int a;
    if (*head == NULL)
    {
        printf("UNDERFLOW CONDITION...\n");
        return -1;
    }
    else if ((*head)->nxt==NULL)
    {
        a = (*head)->info;
        (*head) = NULL;
    }
    else
    {
        node *temp=*head;
        while(n-1)
        {
            temp=temp->nxt;
            if((temp->nxt==NULL)&&(n>1))
            {
                printf("OUT OF BOUNDS...");
                return -1;
            }
            n--;
        }
        node *track=temp->nxt;
        temp->nxt=track->nxt;
        (track->nxt)->prev=temp;
        track->nxt=NULL;
        track->prev=NULL;
        a=track->info;
        free(track);
    }
    return a;
}
*/

void insert_end(node **head, node **tail, int val)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->info = val;
    temp->nxt = NULL;
    if (*head == NULL)
    {
        *head = temp;
        *tail = temp;
        temp->prev = NULL;
    }
    else
    {
        temp->prev = *tail;
        (*tail)->nxt = temp;
        (*tail) = temp;
    }
}

void insert_begin(node **head, int val)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->info = val;
    if (*head == NULL)
    {
        *head = temp;
        temp->nxt = NULL;
        temp->prev = NULL;
    }
    else
    {
        temp->nxt = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}



void insert_n(node **head, int val, int n)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->info = val;
    if (*head == NULL)
    {
        *head = temp;
        temp->nxt = NULL;
        temp->prev = NULL;
    }
    else if(((*head)->nxt==NULL)&&(n==1))
    {
        temp->nxt=NULL;
        temp->prev=(*head);
        (*head)->nxt=temp;
    }
    else
    {
        node *track = *head;
        while (n - 1)
        {
            track = track->nxt;
            if ((track->nxt == NULL) && (n>2))
            {
                printf("OUT OF BOUNDS...\n");
                exit(1);
            }
            n--; 
        }
        temp->nxt = track->nxt;
        temp->prev = track;
        track->nxt=temp;
    }
}


void display(node *head)
{

    node *temp = head;
    while (temp->nxt != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->nxt;
    }
    printf("%d\n", temp->info);
}


int main()
{
    node *head = NULL, *tail = NULL;
    insert_end(&head,&tail,1);
    insert_end(&head,&tail,2);
    insert_end(&head,&tail,3);
    insert_end(&head,&tail,4);
    insert_end(&head,&tail,5);
    insert_end(&head,&tail,6);
    insert_n(&head,7,7);

    display(head);
}