#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct term
{
    int coeff;
    int power;
} term;

typedef struct node
{
    int coeff;
    int power;
    struct node *nxt;

}node;

node * insert(node *head,int val1,int val2)
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->coeff=val1;
    temp->power=val2;
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
        printf("%d %d\n",temp->coeff,temp->power);
        temp=temp->nxt;
    }
}

//FUNCTION TO SEPERATE COEFF AND POWERS OF ANY POLYNOMIAL...

term * func(char poly[],int *a)
{
    term *terms=(term *)malloc(sizeof(term)*50);
    int no_terms = 0;
    char *str = strtok(poly, "+-");
    while (str != NULL)
    {
        if (strstr(str, "x") != NULL)
        {
            if (sscanf(str, "%dx%d", &terms[no_terms].coeff, &terms[no_terms].power) == 2)
            {
                // Term with both coefficient and power
            }
            else if (sscanf(str, "%dx", &terms[no_terms].coeff) == 1)
            {
                terms[no_terms].power = 1;
            }
            else if (sscanf(str, "x%d", &terms[no_terms].power) == 1)
            {
                terms[no_terms].coeff = 1;
            }
            else{
                terms[no_terms].coeff = 1;
                terms[no_terms].power = 1;
            }
        }
        else
        {
            sscanf(str, "%d", &terms[no_terms].coeff);
            terms[no_terms].power = 0;
        }
        no_terms++;
        str = strtok(NULL, "+-");
    }
    *a=no_terms-1;
    return terms;
}

//FUNCTION TO CREATE A LINKED LIST FOR ANY POLYNOMIAL...
node * lnk_list(term terms[],int a,node *head)
{
    int val1,val2;
    for (int i = 0; i <=a; i++)
    {
        val1=terms[i].coeff;
        val2=terms[i].power;
        head=insert(head,val1,val2);
    }
    return head;
}

int main()
{
    char poly1[100],poly2[100];
    printf("ENTER I POLYNOMIAL : ");
    fgets(poly1, sizeof(poly1), stdin);
    printf("ENTER II POLYNOMIAL : ");
    fgets(poly2, sizeof(poly2), stdin);

    //LINKED LIST FOR 1ST POLYNOMIAL....
    node *head1=NULL,*head2=NULL;
    int a,b;
    term *terms1=func(poly1,&a);
    term *terms2=func(poly2,&b);
    head1=lnk_list(terms1,a,head1);
    head2=lnk_list(terms2,b,head2);
    display(head1);
    display(head2);


    return 0;
}

