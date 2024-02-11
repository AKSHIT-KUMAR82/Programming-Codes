#include<stdio.h>
#include<stdlib.h>

/* WRITE A C PROGRAM USING SINGLY LINKED LIST FOR THE FOLLOWING OPERATIONS :
INSERTION
DELETION
UPDATION
*/

typedef struct node
{
    int info;
    struct node *nxt;
} node;

void insert(node **f,node **r,int val)
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->info=val;
    temp->nxt=NULL;
    if((*f)==NULL)
    {
        (*f)=temp;
        (*r)=temp;
    }
    else
    {
        (*r)->nxt=temp;
        (*r)=temp;
    }
}

int delete1(node **f,node **r)
{
    node *temp;
    int val;
    if((*f)==(*r))
    {
        val=(*f)->info;
        (*f)=NULL;
    }
    else if((*f)==NULL)
    {
        return -1;
    }
    else
    {
        temp=(*f);
        (*f)=(*f)->nxt;
        temp->nxt=NULL;
        val=temp->info;
        free(temp);
    }
    return val;
}

void display(node **f,node **r)
{
    node *temp;
    if((*f)==NULL)
    {
        printf("NOTHING TO DISPLAY....\n");
    }
    else
    {
        temp=(*f);
        while(temp!=(*r))
        {
            printf("%d ",temp->info);
            temp=temp->nxt;
        }
        printf("%d \n",temp->info);
    }
}

int main()
{
    node *front=NULL,*rear=NULL;
    int ch;
    printf("\nENTER 1 FOR INSERTION....\nENTER 2 FOR DELETION....\nENTER 3 FOR DISPLAY....\nENTER ANY CHARACTER TO EXIT...\n");
    scanf("%d",&ch);
    while(ch)
    {
        int val;
        switch(ch)
        {
        case 1:
            printf("\nENTER THE VALUE TO BE INSERTED : ");
            scanf("%d",&val);
            insert(&front,&rear,val);
            break;
        case 2:
            val=delete1(&front,&rear);
            if(val!=-1)
            {
                printf("DELETED ELEMENT : %d\n",val);
            }
            else
            {
                printf("UNDER FLOW CONDITION OCCURS...\n");
            }
            break;
        case 3:
            display(&front,&rear);
            break;
        default :
            break;
        }
    }
    printf("\nENTER 1 FOR INSERTION....\nENTER 2 FOR DELETION....\nENTER 3 FOR DISPLAY....\nENTER ANY CHARACTER TO EXIT...\n");
    scanf("%d",&ch);
    return 0;
}

