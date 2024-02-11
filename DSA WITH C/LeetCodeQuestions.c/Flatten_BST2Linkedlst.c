/* PROBLEM STATEMENT : WE HAVE GIVEN A BST AND WE NEED TO CONVERT IT INTO SORTED LINKED LIST....*/

/*APPROACH : AS, WE KNOW THAT INORDER TRAVERSAL OF A BST IS SORTED SO WHAT WE CAN DO IS...
WE WILL STORE NODES OF A BST THROUGH INORDER TRAVERSAL AND STORES IT IN AN ARRAY OF POINTERS 
TO THAT TREE STUCTURE TYPE....AND THEN WITH THE HELP OF A LOOP WE WILL CONNECT THOSE NODES
LIKE A LINKED LIST...*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*HERE, IN THIS PROGRAM I AM JUSTING WRITING THE INTENDED FUNCTION DEFINITION ONLY...*/

typedef struct Node{
    int data;
    struct Node *left,*right;
}Node;

void InorderTrav(Node *root,Node **arr,int *n)
{
    if(root==NULL)
    {
        return;
    }
    InorderTrav(root->left,arr,n);
    arr[++(*n)]=root;
    InorderTrav(root->right,arr,n);
}
Node * ConvertSortList(Node *root) //I am assuming that my bst contains nodes only btw 0 to 1000....
{
    Node *arr[1000]={NULL}; //Array of pointers to Node data elements...
    int n=-1;
    InorderTrav(root,arr,&n);
    if(n==-1)
    {
        printf("IT'S AN EMPTY BST...");
    }
    else{
        root=arr[0];
        root->left=NULL;
        Node *curr=root;
        for(int i=1;i<=n;i++)
        {
            curr->right=arr[i];
            arr[i]->left=NULL;
            curr=arr[i];
        }
        curr->left=NULL;
        curr->right=NULL;
    }
}

