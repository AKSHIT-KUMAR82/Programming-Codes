/* THE TWO BINARY TREES ARE CALLED IDENTICAL IF , EACH CORRESPONDING NODES OF 
THE RESPECTIVE TREES HAVE SAME DATA , THIS PROCESS WILL RECURRSILY PROPAGATES TO THE ROOT NODE...*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left,*right;
}node;

/*HERE WE ARE ONLY WRITING THE MAIN FUNCTION FOR THE PURPOSE OF FINDING TWO TREES AS IDENTICAL OR NOT...*/
int IsIdentical(node *r1,node *r2)
{
    if(r1==NULL&&r2==NULL)
    {
        return 1;
    }
    else if(r1==NULL&&r2!=NULL)
    {
        return 0;
    }
    else if(r1!=NULL&&r2==NULL)
    {
        return 0;
    }
    int left=IsIdentical(r1->left,r2->left);
    int right=IsIdentical(r1->right,r2->right);
    int check=r1->data==r2->data;
    return left&&right&&check;
}