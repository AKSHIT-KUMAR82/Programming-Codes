/* PROBLEM STATEMENT : IN THIS PROBLEM WE WILL HAVE TO BUILD A BALANCED BST FROM A NORMAL 
BST....*/

/*APPROACH : IT IS A SIMPLE APPROACH...WE FIRST NEED TO STORE THE INORDER TRAVERSAL OF THAT BST 
IN AN ARRAY IN FORM OF INTEGER ELEMENTS AND THEN WE WILL APPLY A SIMPLE ALGO...THAT IS 
WE WILL MAKE A FUNCTION IN WHICH WE WILL PASS THREE ARGUMENTS 1) ARRAY 2) STARTING VAL
3) END VALUE/INDEX THEN ACCONDING FIND THE MID AND ALLOCATE MEMORY AND INITIALISE IT WITH 
ARRAY MID INDEX VALUE THEN RECURRSIVELY CALLS IT LEFT POINTER AND RIGHT POINTER HAVING 
VALUES WHOSE ABS DIFF ALWAYS EQUATES TO <=1 AND BASE CASE WILL BE WHEN S>E AND RETURN NULL
FOR THAT...IN THIS MANNER WE WILL MAKE A BALANCED BST FROM A NORMAL BST... */

#include<stdio.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* HERE , I AM ONLY WRITING THE INTENDED FUNCTION FOR THE TASKS TO ACHIEVE THAT....*/
void InorderTrav(struct TreeNode *root,int *arr,int *n)
{
    if(root==NULL)
    {
        return;
    }
    InorderTrav(root->left,arr,n);
    arr[++(*n)]=root->val;
    InorderTrav(root->right,arr,n);
}

struct TreeNode * Balanced(int s,int e,int *arr)
{
    if(s>e)
    {
        return NULL;
    }
    int mid=(s+e)/2;
    struct TreeNode *node=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val=arr[mid];
    node->left=Balanced(s,mid-1,arr);
    node->right=Balanced(mid+1,e,arr);
    return node;
}
struct TreeNode* balanceBST(struct TreeNode* root) {
    if(root==NULL)
    {
        return NULL;
    }
    int arr[10000]={0};
    int n=-1;
    InorderTrav(root,arr,&n);
    return Balanced(0,n,arr);
}