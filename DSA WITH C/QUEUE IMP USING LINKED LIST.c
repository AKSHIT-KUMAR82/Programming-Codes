// Online C compiler to run C program online

#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *nxt;
} node;

//INSERTION OPERATION....
void insert(node **front,node **rear,int val)
{
    node *temp=NULL;
    temp=(node *)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("OVERFLOW CONDITION....\n");
    }
    else
    {
        temp->info=val;
        if((*front)==NULL)
        {
            (*front)=temp;
            (*rear)=temp;
            temp->nxt=NULL;
        }
        else
        {
            (*rear)->nxt=temp;
            (*rear)=temp;
           (*rear)->nxt=NULL;
        }
    }
}

//DELETION OPERATION USING LINKED LIST QUEUE IMPLEMENTATION...
int delete1(node **front,node **rear)
{
    node *temp;
    int x;
    if((*front)==NULL)
    {
        printf("NOTHING TO DISPLAY...\n");
    }
    else if((*front)==(*rear))
    {
        x=(*front)->info;
        (*front)=NULL;
    }
    else
    {
        temp=(*front);
        (*front)=(*front)->nxt;
        x=temp->info;
        temp->nxt=NULL;
        free(temp);
    }
    return x;

}

//DISPLAYING THE CONTENT IN THE LINKED LIST USING QUEUE IMPLEMENTATION....
void display(node **front,node **rear)
{
    node *temp=(*front);
    while(temp!=(*rear))
    {
        printf("%d ",temp->info);
        temp=temp->nxt;
    }
    printf("%d\n",temp->info);
}

int main()
{
    node *front=NULL,*rear=NULL;
    int choice=1,no,del;
    while(choice)
    {
        printf("ENTER 1,2,3,0 FOR INSERTION,DELETION,DISPLAY AND EXIT REPECTIVELY : \n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("ENTER NUMBER TO BE ENTERED : ");
            scanf("%d",&no);
            insert(&front,&rear,no);
            break;
        case 2:
            printf("DELETED ELEMENT : %d\n",delete1(&front,&rear));
            break;
        case 3:
            display(&front,&rear);
            break;
        default:
            choice=0;
        }
    }
    return 0;
}
