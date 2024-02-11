#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *nxt;
} node;

// INSERTING NODES IN A SINGLY LINKED LIST....
void insert(node **head, node **last, int val)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->info = val;
    if (*head == NULL)
    {
        (*head) = temp;
        (*last) = temp;
        temp->nxt = NULL;
    }
    else
    {
        (*last)->nxt = temp;
        temp->nxt = NULL;
        (*last) = temp;
    }
}

void display(node *head)
{
    if (head == NULL)
    {
        printf("NOTHING TO DISPLAY\n");
    }
    else
    {
        node *temp = head;
        while (temp->nxt != NULL)
        {
            printf("%d ", temp->info);
            temp = temp->nxt;
        }
        printf("%d\n", temp->info);
    }
}

void reverse(node **head, int size, int k, int a)
{
    node *rev_start = NULL, *rev_end = NULL;
    int b = k;
    while (a)
    {
        if (rev_start == NULL)
        {
            rev_start = *head;
        }
        rev_end=rev_start;
        while (b - 1)
        {
            rev_end=rev_end->nxt;
            b--;
        }
        node *track1=rev_end->nxt;
        node *track2;
        int val1,val2;
        while(rev_start<rev_end)
        {
            val1=rev_start->info;
            rev_start->info=rev_end->info;
            rev_end->info=val1;
            track2=rev_start;
            while(track2->nxt!=rev_end)
            {
                track2=track2->nxt;
            }
            rev_end=track2;
            rev_start=rev_start->nxt;
        }
        rev_start=track1;
        b=k; 
        a--;
    }
}

int main()
{
    int size, k;
    printf("HOW MANY NODES WOULD YOU WANT IN A LINKED LIST : ");
    scanf("%d", &size);
    printf("ENTER THE VALUE TO WHICH NODES SHOULD BE REVERSED : ");
    scanf("%d", &k);
    int a = size / k;
    int b = size, val;
    node *head = NULL, *last = NULL;
    while (b)
    {
        printf("ENTER %d TO BE INSERTED : ", size + 1 - b);
        scanf("%d", &val);
        insert(&head, &last, val);
        b--;
    }
    reverse(&head,size,k,a);
    display(head);
}