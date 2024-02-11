/*BINARY SEARCH TREE IS A TREE IN WHICH ALL THE VALUES SMALLER THAN THE VALUE OF ROOT
COMES TO THE LEFT SIDE AND GREATER AT THE RIGHT SIDE OF THE TREE...*/
#include<stdio.h>
#include<stdlib.h>

//Structure of each node of a BST....
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node * InsertIntoBST(Node *root,int data)
{
    if(root==NULL)
    {
        root=(Node *)malloc(sizeof(Node));
        root->data=data;
        return root;
    }
    else if(data<root->data)
    {
        root->left=InsertIntoBST(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=InsertIntoBST(root->right,data);
    }
    return root;
}
int main()
{
    Node *root=NULL;
    int data;
    printf("ENTER DATA VALUES : \n");
    scanf("%d",&data);
    while(data!=-1)
    {
        //Assuming that -1 indicates invalid data...
        root=InsertIntoBST(root,data);
        scanf("%d",&data);
    }
}

