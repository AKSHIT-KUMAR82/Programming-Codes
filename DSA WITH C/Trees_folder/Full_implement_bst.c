#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

typedef struct Node
{
    int info;
    struct Node *left, *right;
} Node;

Node *Insert_BST(Node *root, int data) // Insertion in BST....
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
        if (root->info > data)
        {
            root->left = Insert_BST(root->left, data);
        }
        if (root->info < data)
        {
            root->right = Insert_BST(root->right, data);
        }
    }
    return root;
}

int MinVal_BST(Node *root) // Minimum value in BST...
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        while (root->left != NULL)
        {
            root = root->left;
        }
        return (root->info);
    }
}

int MaxVal_BST(Node *root) // Maximum value in BST...
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        while (root->right != NULL)
        {
            root = root->right;
        }
        return (root->info);
    }
}

Node *Delete_BST(Node *root, int val) // Deletion in BST...
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->info == val)
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else
        {
            int Min = MinVal_BST(root->right);
            root->info = Min;
            root->right = Delete_BST(root->right, Min);
        }
    }
    else if (val < root->info)
    {
        root->left = Delete_BST(root->left, val);
    }
    else
    {
        root->right = Delete_BST(root->right, val);
    }
    return root;
}

void PreOrderTrav(Node *root) // Preorder Traversal in BST..
{
    if (root == NULL)
    {
        return;
    } 
    printf("%d ", root->info);
    PreOrderTrav(root->left);
    PreOrderTrav(root->right);
}

void PostOrderTrav(Node *root) // Postorder Traversal in BST..
{
    if (root == NULL)
    {
        return;
    }
    PostOrderTrav(root->left);
    PostOrderTrav(root->right);
    printf("%d ", root->info);
}

void InOrderTrav(Node *root) // Inorder Traversal in BST..
{
    if (root == NULL)
    {
        return;
    }
    InOrderTrav(root->left);
    printf("%d ", root->info);
    InOrderTrav(root->right);
}

int main()
{
    printf("NAME : AKSHIT KUMAR\nSECTION : A1\nRNO : 05\n");
    Node *root = NULL;
    int choice = 1, data = -1;
    while (choice != -1) //Menu driven...
    {
        printf("HEY, USER ENTER YOUR CHOICE FOR OPERATIONS IN BST.....\nENTER :\n0 FOR INSERTION\n");
        printf("1 FOR DELETION\n2 FOR PREORDER TRAVERSAL\n3 FOR POSTORDER\n4 FOR INORDER\n");
        printf("5 FOR MAXIMUM VALUE\n6 FOR MINIMUM VAL\n...........\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("ENTER THE DATA : ");
            scanf("%d", &data);
            while (data != -1)
            {
                root = Insert_BST(root, data);
                scanf("%d", &data);
            }
            break;
        case 1:
            printf("ENTER VALUE TO BE DELETED : ");
            scanf("%d", &data);
            root=Delete_BST(root, data);
            break;
        case 2:
            printf("PREORDER TRAVERSAL : ");
            PreOrderTrav(root);
            break;
        case 3:
            printf("POSTORDER TRAVERSAL : ");
            PostOrderTrav(root);
            break;
        case 4:
            printf("INORDER TRAVERSAL : ");
            InOrderTrav(root);
            break;
        case 5:
            printf("MAXIMUM VALUE IN BST : %d\n",MaxVal_BST(root));
            break;
        case 6:
            printf("MINIMUM VALUE IN BST : %d\n",MinVal_BST(root));
            break;
        default:
            choice = -1;
        }
    }
    return 0;
}