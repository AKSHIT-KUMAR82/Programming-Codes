#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int info;
    struct Node *left;
    struct Node *right;
} Node;

Node *Construct_BST(Node *root, int data)
{
    if (root == NULL)
    {
        root = (Node *)malloc(sizeof(Node));
        root->info = data;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        if (root->info < data)
        {
            root->right = Construct_BST(root->right, data);
        }
        if (root->info > data)
        {
            root->left = Construct_BST(root->left, data);
        }
    }
    return root;
}

void Level_odr_traversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Node **queue = (Node **)(malloc(sizeof(Node *) * 100));
    int front = -1, rear = -1;
    queue[++rear] = root;
    queue[++rear] = NULL;
    Node *temp = NULL;
    while (front <= rear)
    {
        temp = queue[++front];
        if (temp == NULL)
        {
            printf("\n");
            if (front < rear)
            {
                queue[++rear] = NULL;
            }
            else
            {
                break;
            }
        }
        else
        {
            printf("%d ", temp->info);
            if (temp->left)
            {
                queue[++rear] = temp->left;
            }
            if (temp->right)
            {
                queue[++rear] = temp->right;
            }
        }
    }
}

int No_leafNodes(Node *root,int *ptr)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=No_leafNodes(root->left,ptr);
    int right=No_leafNodes(root->right,ptr);
    if(left==0&&right==0)
    {
        (*ptr)++;
    }
    return *ptr;
}

int main()
{
    Node *root = NULL;
    int data;
    printf("ENTER THE DATA : ");
    scanf("%d", &data);
    while (data != -1)
    {
        root = Construct_BST(root, data);
        scanf("%d", &data);
    }
    Level_odr_traversal(root);
    int count=0;
    printf("NUMBER OF LEAF NODES : %d\n",No_leafNodes(root,&count));
}