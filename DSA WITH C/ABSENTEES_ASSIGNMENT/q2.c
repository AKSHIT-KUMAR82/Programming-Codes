#include<stdio.h>
#include<stdlib.h>

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
    printf("ADDITION RESULT IN THE THIRD LINKED LIST : ");
    Display(head3);
}

int main()
{
    /*THIS QUESTION PARTICULARLY FOR ADDING TWO NUMBERS IN THE FORM OF TWO SINGLY LINKED LISTS , WHOSE ADDITION WILL BE REPRESENTED IN THE FORM OF OTHER LINKED LIST...*/
    node *head1=NULL,*head2=NULL;
    int val;
    insert(&head1,4);
    insert(&head1,5);
    insert(&head1,6);
    printf("ELEMENTS IN 1st LINKED LIST : ");
    Display(head1);
    insert(&head2,7);
    insert(&head2,8);
    insert(&head2,9);
    printf("ELEMENTS IN 1st LINKED LIST : ");
    Display(head2);
    sum_2_lnk_lst(head1,head2);
    return 0;
}