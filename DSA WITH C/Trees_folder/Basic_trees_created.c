#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;

node * TreeConstruct(node *root)
{
    root=(node *)malloc(sizeof(node *));
    int data;
    printf("ENTER THE DATA : ");
    scanf("%d",&data);
    if(data==-1)
    {
        return NULL; //FOR AN EMPTY TREE...
    }
    root->data=data;
    printf("ENTER DATA TO THE LEFT OF %d  \n",data);
    root->left=TreeConstruct(root->left);
    printf("ENTER DATA TO THE RIGHT OF %d \n",data);
    root->right=TreeConstruct(root->right);
    return root;
}
int main()
{
    node *root=NULL;
    root=TreeConstruct(root);
    if(root==NULL)
    {
        printf("AN EMPTY TREE IS FORMED...\n");
    }
    else{
        printf("A BINARY TREE HAS BEEN CREATED...\n");
    }
    return 0;
}

