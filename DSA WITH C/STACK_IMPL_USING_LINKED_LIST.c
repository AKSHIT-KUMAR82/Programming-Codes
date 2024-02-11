#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *nxt;
} node;


//INSERTION (STACK IMPLEMENTATION PUSH OPERATION)......
node * insert(node *head,int val)
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->info=val;
    if(head==NULL)
    {
        temp->nxt=NULL;
        head=temp;
    }
    else
    {
        temp->nxt=head;
        head=temp;
    }
    return head;
}

//DELETION (STACK IMPLEMENTATION POP OPERATION)......
node * delete1(node *head)
{
    int val;
    node *temp;
    temp=head;
    head=head->nxt;
    val=temp->info;
    temp->nxt=NULL;
    free(temp);
    printf("DELETED ELEMENT IS : %d\n",val);
    return head;
}

//DISPLAY OPERATION USING STACK....
void display(node *head)
{
    node *temp;
    temp=head;
    if(temp==NULL)
    {
        printf("NOTHING TO DISPLAY....\n\n");
    }
    while(temp)
    {
        printf("%d ",temp->info);
        temp=temp->nxt;
    }
    printf("\n");
}

int main()
{
    node *head=NULL;
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
            head=insert(head,no);
            break;
        case 2:
            head=delete1(head);
            break;
        case 3:
            display(head);
            break;
        default:
            choice=0;
        }
    }
    return 0;
}
