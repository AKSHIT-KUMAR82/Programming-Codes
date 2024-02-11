#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/* IN THIS PROGRAM WE HAVE TO VALIDATE WHETHER A PARTICULAR BST IS VALID OR NOT...
SO WE HAVE TO LOOK UPON IT'S PROPERTIES FOR THIS VALIDATION...
1) INORDER TRAVERSAL OF A BST IS ALWAYS IN SORTED ORDER....
2) AT EACH NODE THE VALUES AT IT'S LEFT SUBTREE IS ALWAYS LESS THAN IT'S OWN VALUE SIMILARILY VICE-VERSA FOR RIGHT SUBTREE...
*/

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

// 1st Way...
int Inorder_Valid(Node *root)
{
    static int key=-1;
    if(root==NULL)
    {
        return 1;
    }
    int left=Inorder_Valid(root->left);
    int right=Inorder_Valid(root->right);
    int check=key<=root->data;
    key=root->data;
    return left&&right&&check;   
}