// HERE IN THIS QUETION WE WILL MAKE A LINKED LIST AND A KEY WILL BE GIVEN TO US AND WE HAVE TO FIND IT'S OCCURENCES..

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include<math.h>

typedef struct node
{
    int data;
    struct node *nxt;
} node;

void insert(node **head, int val)
{
    node *temp = (node *)malloc(sizeof(node *));
    temp->data = val;
    if (*head == NULL)
    {
        *head = temp;
        (*head)->nxt = NULL;
    }
    else
    {
        temp->nxt = *head;
        (*head) = temp;
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
        while (head != NULL)
        {
            printf("%d ", head->data);
            head = head->nxt;
        }
        printf("\n");
    }
}

int delete1(node **head)
{
    int val;
    if (*head == NULL)
    {
        printf("UNDERFLOW CONDITION...\n");
        return -1;
    }
    else
    {
        node *temp = *head;
        *head = (*head)->nxt;
        val = temp->data;
        temp->nxt = NULL;
        free(temp);
    }
    return val;
}

int key_occur(node *head, int key)
{
    int count = 0;
    while (head != NULL)
    {
        if (key == head->data)
            count++;
        head = head->nxt;
    }
    return count;
}

int Palindrome_lkd_lst(node *head)
{
    int flag=1;
    node *temp=head,*track=head;
    if((head!=NULL))
    {
        while(temp->nxt!=NULL)
        {
            temp=temp->nxt;
        }
        track=temp;
        while(track->nxt!=head&&track!=head)
        {
            if(head->data!=track->data)
            {
                flag=0;
                break;
            }
            track=head;
            while(track->nxt!=temp&&track->nxt!=NULL)
            {
                track=track->nxt;
            }
            head=head->nxt;
            temp=track;
        }
    }
    return flag;
}

int bin_decimal_lnk_lst(node *head)
{
    int count=0,decimal=0;
    node *temp=head;
    while(temp->nxt!=NULL)
    {
        count++;
        temp=temp->nxt;
    }
    while(head!=NULL)
    {
       decimal+=(head->data)*pow(2,count);
       count--;
       head=head->nxt;
    }
    return decimal;
}

node * delete_n_end(node *head)
{
    node *track=head,*temp;
    int count=0;
    while(track->nxt!=NULL)
    {
        count++;
        track=track->nxt;
    }
    track=head;
    int n;
    printf("ENTER THE NODE FROM LAST THAT YOU WANT DELETED : ");
    scanf("%d",&n);
    n=count-n;
    while(n>0)
    {
        track=track->nxt;
        n--;
    }
    if(track->nxt==NULL)
    {
        head=NULL;
    }
    else if(n==-1)
    {
        temp=head;
        head=head->nxt;
        temp->nxt=NULL;
    }
    else{
        temp=track->nxt;
        track->nxt=temp->nxt;
        temp->nxt=NULL;
    }
    free(temp);
    return head;
}

void sum_2_lnk_lst(node *head1,node *head2)
{
    int no1=0,no2=0;
    while(head1!=NULL)
    {
        no1=no1*10+(head1->data);
        head1=head1->nxt;
    }
    while(head2!=NULL)
    {
        no2=no2*10+(head2->data);
        head2=head2->nxt;
    }
    int no3=no1+no2,no4=0;
    node *head3=NULL;
    while(no3!=0)
    {
        insert(&head3,no3%10);
        no3/=10;
    }
    Display(head3);
}
int main()
{
    node *head = NULL;
    int choice = 1, key = 0;
    while (choice != 0)
    {
        printf("ENTER 1 FOR INSERTION, 2 FOR DELETION, 3 FOR DISPLAY & 4 FOR SEARCHING OCCUR FUNCTION : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("ENTER KEY TO BE INSERTED : ");
            scanf("%d", &key);
            insert(&head, key);
        }
        else if (choice == 2)
        {
            if ((key = delete1(&head)) != -1)
            {
                printf("DELTEDE ELEMENT : %d\n", key);
            }
        }
        else if (choice == 3)
        {
            Display(head);
        }
        else if (choice == 4)
        {
            printf("ENTER THE KEY FOR FINDING IT'S OCCURENCE : ");
            scanf("%d", &key);
            printf("ITS OCCURENCE IS %d TIMES IN THE LINKED LIST.....\n", key_occur(head, key));
        }
        else
        {
            choice = 0;
        }
    }
    if(Palindrome_lkd_lst(head))
    {
        printf("PALINDROME...\n");
    }
    else{
        printf("NOT PALINDROME...\n");
    }
    printf("IT'S DECIMAL EQUIVALENT NUMBER : %d\n",bin_decimal_lnk_lst(head));
    head=delete_n_end(head);
    Display(head);
    return 0;
}