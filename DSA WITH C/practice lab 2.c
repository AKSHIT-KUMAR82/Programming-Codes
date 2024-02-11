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
}node;

int delete2(node *ptr)
{
    node *temp,*temp2;
    temp=ptr->nxt;
    temp2=temp->nxt;
    temp->nxt=NULL;


}
node * insert(node *head,int val)
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->info=val;
    if(head==NULL)
    {
        head=temp;
        temp->nxt=NULL;
    }
    else
    {
        temp->nxt=head;
        head=temp;
    }
    return head;
}

int delete1(node **head)
{
    node *temp;
    int val;
    if((*head)==NULL)
    {
        return -1;
    }
    temp=(*head);
    (*head)=(*head)->nxt;
    temp->nxt=NULL;
    val=temp->info;
    free(temp);
    return val;
}

void display(node * head)
{
    node *temp=NULL;
    temp=head;
    if(temp==NULL)
    {
        printf("NOTHING TO DISPLAY....\n");
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
    int ch=1;
    while(ch)
    {
        printf("ENTER 1 FOR INSERTION....\nENTER 2 FOR DELETION....\nENTER 3 FOR DISPLAY....\nENTER 0 TO EXIT...\n");
        scanf("%d",&ch);
        int val;
        switch(ch)
        {
            case 1:
                printf("\nENTER THE VALUE TO BE INSERTED : ");
                scanf("%d",&val);
                head=insert(head,val);
                break;
            case 2:
                val=delete1(&head);
                if(val!=-1)
                {
                    printf("DELETED ELEMENT : %d\n",val);
                }
                else
                {
                    printf("UNDER FLOW CONDITION OCCURS...\n");
                }
                break;
            case 3:display(head);
                   break;
            default : ch=0;
        }
    }
    printf("ENTER WHICH NODE TO BE DELETED : ");
    scanf("%d",&ch);
    node *ptr=head;
    while(ch-2)
    {
        ptr=ptr->nxt;
        ch--;
    }
    delete2(ptr);
    display(head);

    return 0;
}
