#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
}node;

void ConstructTree(node **root)
{
    int val;
    printf("ENTER THE DATA : ");
    scanf("%d",&val);
    if(val==-1) //BASE CONDITION VERY IMPORTANT FOR RECURSION TO STOP...
    {
        *root=NULL;
        return;
    }
    *root=(node *)malloc(sizeof(node));
    (*root)->data=val;
    printf("ENTER DATA TO THE LEFT OF %d >>>\n",val);
    ConstructTree(&((*root)->left));
    printf("ENTER DATA TO THE RIGHT OF %d >>>\n",val);
    ConstructTree(&((*root)->right));
}

void LevelOrderTraversal(node * root)
{
    node **ptr=(node **)malloc(sizeof(node)*100);
    int front=-1,rear=-1;
    if(root!=NULL)
    {
        ptr[++rear]=root;
        ptr[++rear]=NULL;
        node *temp;
        while(front<=rear)
        {
            temp=ptr[++front];
            if(temp==NULL)
            {
                printf("\n");
                if(front<rear)
                {
                    ptr[++rear]=NULL;
                }
                else
                {
                    break;
                }
            }
            else
            {
                printf("%d ",temp->data);
                if(temp->left)
                   ptr[++rear]=temp->left;
                if(temp->right)
                   ptr[++rear]=temp->right;
            }

        }
    }

}

void PreOrder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ",root->data);
}

void InOrder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    InOrder(root->left);
    printf("%d ",root->data);
    InOrder(root->right);
}

int NoLeafNode(node *root)
{
    static int count=0;
    if(root==NULL)
    {
        return -1;
    }
    if((root->left==NULL)&&(root->right==NULL))
      count++;
    NoLeafNode(root->left);
    NoLeafNode(root->right);
    return count;
}

int main()
{
    node * root=NULL;
    ConstructTree(&root);
    printf("LEVEL ORDER TRAVERSAL : \n");
    LevelOrderTraversal(root);
    printf("PREORDER TRAVERSAL : \n");
    PreOrder(root);
    printf("\nPOST ORDER TRAVERSAL : \n");
    PostOrder(root);
    printf("\nIN ORDER TRAVERSAL : \n");
    InOrder(root);
    printf("\nNUMBER OF LEAF NODES IN THE GIVEN BINARY TREE : %d",NoLeafNode(root));
    return 0;
}

