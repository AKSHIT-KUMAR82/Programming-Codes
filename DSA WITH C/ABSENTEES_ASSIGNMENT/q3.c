#include <stdlib.h>
#include <stdio.h>

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

void lkd_lst_sort(node *head1, node **head)
{
    int val;
    node *temp;
    node *head2=*head;
   while(head1!=NULL)
   {
    temp=(node *)malloc(sizeof(node));
    val=head1->data;
    temp->data=val;
    if(val>(head2->data))
    {
        while((head2->nxt!=NULL)&&val>((head2->nxt)->data))
        {
            head2=head2->nxt;
        }
        temp->nxt=head2->nxt;
        head2->nxt=temp;
        head2=temp;
    }
    else{
        temp->nxt=head2;
        head2=temp;
        *head=head2;
    }
    head1=head1->nxt;
   }
   printf("SORTED COMBINATION OF TWO LINKED LIST : ");
}

int main()
{
    node *head1 = NULL, *head2 = NULL;
    insert(&head1,21);
    insert(&head1,11);
    insert(&head1,7);
    printf("ELEMENTS IN 1st LINKED LIST : ");
    Display(head1);
    insert(&head2,20);
    insert(&head2,10);
    insert(&head2,8);
    printf("ELEMENTS IN 1st LINKED LIST : ");
    Display(head2);
    lkd_lst_sort(head1,&head2);
    Display(head2);
    return 0;
}