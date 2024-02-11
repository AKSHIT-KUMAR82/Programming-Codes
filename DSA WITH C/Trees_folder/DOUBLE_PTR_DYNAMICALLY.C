#include <stdio.h>
#include <stdlib.h>

// typedef struct node
// {
//     struct node * left;
//     int data;
//     struct node * right;
// }node;

typedef struct node
{
    int info;
    struct node *nxt;
}node;

void Display(node *head)
{
    if (head == NULL)
    {
        printf("NOTHING TO DISPLAY...\n");
    }
    else
    {
        node *temp = head;
        while (temp->nxt!=NULL)
        {
            printf("%d ", temp->info);
            temp = temp->nxt;
        }
        printf("%d\n", temp->info);
    }
}

void insert(node **head, int key)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->info = key;
    if (*head == NULL)
    {
        *head = temp;
        temp->nxt = NULL;
    }
    else
    {
        if (((*head)->info) >= key)
        {
            temp->nxt = *head;
            (*head) = temp;
        }
        else
        {
            node *track = *head;
            while (track->nxt != NULL)
            {
                if (((track->nxt)->info) >= key)
                {
                    break;
                }
                track = track->nxt;
            }
            temp->nxt = track->nxt;
            track->nxt = temp;
        }
    }
}

class book
{
    private:
    int book_id;
    float price;
    char title[100];
    
};

int count_lkd_lst(node *head)
{
    int count=0;
    if(head!=NULL){
        while(head!=NULL)
        {
            count++;
            head=head->nxt;
        }
    }
    return count;
}

int main() {
    node *head = NULL;
    int choice = 1, key = 0;
    while (choice != 0)
    {
        printf("ENTER 1 FOR INSERTION, 2 FOR DISPLAY & 0 TO EXIT : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("ENTER KEY TO BE INSERTED : ");
            scanf("%d", &key);
            insert(&head, key);
        }
        else if (choice == 3)
        {
            Display(head);
        }
    }
    int count=count_lkd_lst(head);
    node **ptr=(node **)malloc(sizeof(node)*count);
    while((count--)&&(head!=NULL))
    {
        ptr[5-count]=head;
        printf("%d ",(ptr[5-count])->info);     
        head=head->nxt;   
    }
    return 0;
}