#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Node
{
    int info;
    struct Node *left;
    struct Node *right;
}Node;

//HERE , IN THIS PROGRAM WE WILL CHECK WETHER A TREE IS BST OR NOT...
//HERE , I AM ONLY WRITING THE INTENDED FUNCTION TO EVALUATE....
int ValidBST(Node *root,int min,int max)
{
    if(root==NULL)
    {
        return 1; //ASSUMING AN EMPTY TREE IS A BST...
    }
    if(root->info>=min&&root->info<=max)
    {
        int left=ValidBST(root->left,min,root->info);
        int right=ValidBST(root->right,root->info,max);
        return left&&right;
    }
    else{
        return 0;
    }

}

int KthLargest(Node *root,int *count,int K)
{
    if(root==NULL)
    {
        return -1; //HERE, WE ARE ASSUMING THAT NO KTH VALUE IS PRESENT OR AN EMPTY TREE...
    }
    KthLargest(root->left,count,K);
    (*count)++;
    if(*count==K)
    {
        return root->info;
    }
    KthLargest(root->right,count,K);
}

int main()
{
    Node *root=NULL;
    int val=ValidBST(root,INT_MIN,INT_MAX);
    if(val!=0)
    {
        printf("IT'S A VALID BST....\n");
    }
    else{
        printf("IT'S NOT A VALID BST...\n");
    }
    return 0;

}