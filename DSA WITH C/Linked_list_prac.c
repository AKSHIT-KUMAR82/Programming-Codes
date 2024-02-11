#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *nxt;
}node;

void insert(node **head,node **tail,int val)
{
    node *temp=(node *)malloc(sizeof(node));
    temp->info=val;
    if(*head==NULL)
    {
        (*head)=temp;
        (*tail)=temp;
        (*head)->nxt=NULL;
    }
    else{
        (*tail)->nxt=temp;
        temp->nxt=NULL;
        (*tail)=temp;
    }
}

int delete(node **head,node **tail)
{
    int a;
    if(*head==NULL)
    {
        printf("UNDERFLOW CONDITION...\n");
        return -1;
    }
    else if(*head==*tail)
    {
        a=(*head)->info;
        (*head)=NULL;
        (*tail)=NULL;
    }
    else{
        node *track=*head;
        while(track->nxt!=*tail)
        {
            track=track->nxt;
        }
        a=(*tail)->info;
        track->nxt=NULL;
        (*tail)=track;
    }
    return a;
}

void display(node *head,node *tail)
{
    node *temp=head;
    while(temp!=tail)
    {
        printf("%d ",temp->info);
        temp=temp->nxt;
    }
    printf("%d\n",temp->info);
}

int main()
{
    node *head=NULL,*tail=NULL;
    insert(&head,&tail,1);
    insert(&head,&tail,2);
    insert(&head,&tail,3);
    insert(&head,&tail,4);
    insert(&head,&tail,5);
    insert(&head,&tail,6);
    int a=delete(&head,&tail);
    if(a!=-1)
       printf("DELETED VALUE : %d\n",a);
    a=delete(&head,&tail);
    if(a!=-1)
       printf("DELETED VALUE : %d\n",a);
    a=delete(&head,&tail);
    if(a!=-1)
       printf("DELETED VALUE : %d\n",a);
    display(head,tail);
    return 0;
}