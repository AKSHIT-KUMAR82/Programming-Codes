/*
//INSERT NODES IN A CIRCULAR LINKED LIST CONSIDERING ALL TEST CASES...

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int info;
    struct Node *nxt;
}Node;

void InsertCirLink(Node **head,Node **tail,int data)
{
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->info=data;
    if(*head==NULL)
    {
        *head=temp;
        *tail=temp;
        temp->nxt=*head;
    }
    temp->nxt=*head;
    *head=temp;
    (*tail)->nxt=*head;
}

void Display(Node *head,Node *tail)
{
    if(head==NULL)
    {
        printf("NOTHING TO DISPLAY...\n");
        return;
    }
    while(head!=tail)
    {
        printf("%d ",head->info);
        head=head->nxt;
    }
    printf("%d",head->info);
}

int main()
{
    Node * head=NULL,*tail=NULL;
    int data;
    printf("ENTER THE DATA TO BE INSERTED IN THE CIRCULAR LINKED LIST : ");
    scanf("%d",&data);
    //Here , We are assuming that -1 is an invalid value...
    while(data!=-1)
    {
        InsertCirLink(&head,&tail,data);
        scanf("%d",&data);
    }
    printf("THE DATA IN CIRCULAR LINKED LIST AS FOLLOWS : \n");
    Display(head,tail);
    return 0;
}
*/

/* WE HAVE GIVEN TWO LINKED LISTS IN SORTED ORDER FROM LOWEST TO HIGHEST AND WE HAVE TO MERGE THESE TWO LINKED LISTS 
TO GET THE RESULTANT LIST IN WHICH ELEMENTS MUST BE IN THE SAME ORDER FROM LOWEST TO HIGHEST */

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int info;
    struct Node *nxt;
}Node;

void insert(Node **head,Node **tail,int data)
{
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->info=data;
    if(*head==NULL)
    {
        //Empty linked list...
        temp->nxt=*head;
        *head=temp;
        *tail=temp;
        temp->nxt=*head;
    }
    (*tail)->nxt=temp;
    temp->nxt=*head;
    *tail=temp;
}

void MergeLnkLst(Node *head1,Node *head2,Node **tail1,Node **tail2,Node **head,Node **tail)
{
    Node *temphead=NULL,*temptail=NULL;
    (*tail1)->nxt=NULL;
    (*tail2)->nxt=NULL;
    while(head1!=NULL&&head2!=NULL)
    {
        if(head1->info>=head2->info){
            insert(&temphead,&temptail,head2->info);
            head2=head2->nxt;
        }
        else{
            insert(&temphead,&temptail,head1->info);
            head1=head1->nxt;
        }
    }
    while(head1!=NULL)
    {
        insert(&temphead,&temptail,head1->info);
        head1=head1->nxt;
    }
    while(head2!=NULL)
    {
        insert(&temphead,&temptail,head2->info);
        head2=head2->nxt;
    }
    *head=temphead;
    *tail=temptail;
}

void Display(Node *head,Node *tail)
{
    if(head==NULL)
    {
        printf("NOTHING TO DISPLAY...\n");
        return;
    }
    while(head!=tail)
    {
        printf("%d ",head->info);
        head=head->nxt;
    }
    printf("%d",head->info);
}

int main()
{
    Node *head1=NULL,*tail1=NULL,*tail2=NULL,*head2=NULL,*head=NULL,*tail=NULL;
    int data;
    printf("ENTER THE DATA ELEMENTS FOR 1st LINKED LIST : ");
    scanf("%d",&data);
    while(data!=-1)
    {
        insert(&head1,&tail1,data);
        scanf("%d",&data);
    }

    printf("ENTER THE DATA ELEMENTS FOR 2st LINKED LIST : ");
    scanf("%d",&data);
    while(data!=-1)
    {
        insert(&head2,&tail2,data);
        scanf("%d",&data);
    }
    MergeLnkLst(head1,head2,&tail1,&tail2,&head,&tail);
    printf("RESULTANT MERGED LINKED LIST : ");
    Display(head,tail);
    return 0;
}

