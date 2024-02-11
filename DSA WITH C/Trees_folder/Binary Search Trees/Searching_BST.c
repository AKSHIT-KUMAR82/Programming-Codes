/* THERE ARE TWO WAYS FOR SEARCHING A KEY IN A BST :
1) USING RECURSION
2) ITERATIVE WAY...............*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

//USING RECURSION
int search(Node* root, int x) {
    if(root==NULL)
    {
        return 0;
    }
    else if(root->data==x)
    {
        return 1;
    }
    if(root->data>x)
    {
        return search(root->left,x);
    }
    return search(root->right,x);
}

//USING ITERATION
int search(Node* root, int x) {
    while(root)
    {
        if(root->data==x)
        {
            return 1;
        }
        else if(root->data>x)
        {
            root=root->left;
            continue;
        }
        root=root->right;
    }
    return 0;
}