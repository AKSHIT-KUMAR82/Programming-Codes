#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max(a,b) (a>b?a:b)

typedef struct node
{
    struct node *left;
    int info;
    struct node *right;
}node;

node * ConstructTree(node *root)
{
    int data;
    printf("ENTER THE DATA : ");
    scanf("%d",&data);
    if(data==-1)
    {
        //SIGNIFYING INVALID VALUE...
        return NULL;
    }
    root=(node *)malloc(sizeof(node));
    root->info=data;
    printf("ENTER THE DATA TO THE LEFT OF %d >>>\n",data);
    root->left=ConstructTree(root->left);
    printf("ENTER THE DATA TO THE RIGHT OF %d >>>\n",data);
    root->right=ConstructTree(root->right);
    return root;
}

int HeightBinaryTree(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=HeightBinaryTree(root->left);
    int right=HeightBinaryTree(root->right);
    int height=max(left,right)+1;
    return height;
}

int Diameter_BinTree(node *root)
{
    if(root==NULL)
    {
        return 0;
    }

    int h1=HeightBinaryTree(root->left);
    int h2=HeightBinaryTree(root->right);
    int dia=h1+h2+1;
    return dia;
}

int main()
{
    node *root=NULL;
    root=ConstructTree(root);
    int height=HeightBinaryTree(root);
    printf("HEIGHT OF THE ENTERED BINARY TREE : %d\n",height);
    int dia=Diameter_BinTree(root);
    printf("DIAMETER OF THE ENTERED BINARY TREE : %d\n",dia);
    return 0;
}