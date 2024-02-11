#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;


void Inorder_trav(node * root)
{
    if(root==NULL)
    {
        return;
    }
    Inorder_trav(root->left);
    printf("%d ",root->data);
    Inorder_trav(root->right);
}

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
    Inorder_trav(root);

    return 0;
}