/*NOW, HERE IN THIS PROGRAM WE WILL SEE THE MAXIMUM AND MINIMUM NODE
IN A PARTICULAR BINARY SERACH TREE....*/

#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

void LevelOrderTraversal(Node * root)
{
    Node **ptr=(Node **)malloc(sizeof(Node)*100);
    int front=-1,rear=-1;
    if(root!=NULL)
    {
        ptr[++rear]=root;
        ptr[++rear]=NULL;
        Node *temp;
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


Node *InsertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = (Node *)malloc(sizeof(Node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        if (data < root->data)
        {
            root->left = InsertIntoBST(root->left, data);
        }

        if (data > root->data)
        {
            root->right = InsertIntoBST(root->right, data);
        }
    }
    return root;
}

int max_BST(Node *root)
{
    /* NOW, AS WE KNOW THAT WE WILL GET THE MAXIMUM VALUE AT THE RIGHTMOST NODE OF THE RIGHT SUBTREE OF ROOT NODE */
    if(root==NULL)
    {
        return 0;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

int min_BST(Node *root)
{
    /* NOW, AS WE KNOW THAT WE WILL GET THE MINIMUM VALUE AT THE LEFTMOST NODE OF THE LEFT SUBTREE OF ROOT NODE */
    if(root==NULL)
    {
        return 0;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

//FUNCTION TO DELETE A PARTICULAR NODE FROM A BST....
Node * Delete_BST(Node *root,int val)
{
    if(root==NULL)
    {
        return root; //Nothing to delete so as it is...
    }
    if(root->data==val)
    {
        //There are three cases in it as we also need to maintain the structure of bst..

        //Leaf nodes....(i.e 0 Child)
        if(root->left==NULL&&root->right==NULL)
        {
            free(root);
            return NULL;
        }
        //1 Child Node either at the left subtree or right subtree.

        //There are further two cases for one child,may be at left or right...
        else if(root->left==NULL&&root->right!=NULL)
        {
            Node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->left!=NULL&&root->right==NULL)
        {
            Node *temp=root->left;
            free(root);
            return temp;
        }
        //2 Child Nodes...
        else
        {
            /* NOW FOR THIS PARTICULAR CASE WE HAVE TWO WAYS : 
            1) BY REPLACING THE CURRENT NODE WITH THE MAXIMUM VALUE IN THE LEFT SUBTREE AND HENCE AGAIN CALL DELETE FUNCTION FOR THE REPLACED VALUE IN THE LEFT SUBTREE
            2) 1) BY REPLACING THE CURRENT NODE WITH THE MINIMUM VALUE IN THE RIGHT SUBTREE AND HENCE AGAIN CALL DELETE FUNCTION FOR THE REPLACED VALUE IN THE RIGHT SUBTREE
            */
           root->data=max_BST(root->left);
           root->left=Delete_BST(root->left,root->data);
        }
    }
    else if(root->data<val)
    {
        root->right=Delete_BST(root->right,val);
    }
    else{
        root->left=Delete_BST(root->left,val);
    }
    return root;
}


int main()
{
    Node *root = NULL;
    int data;
    printf("ENTER DATA VALUES : \n");
    scanf("%d", &data);
    while (data != -1)
    {
        // Assuming that -1 indicates invalid data...
        root = InsertIntoBST(root, data);
        scanf("%d", &data);
    }
    LevelOrderTraversal(root);
    printf("MIMIMUM VALUE : %d\nMAXIMUM VALUE : %d\n", min_BST(root), max_BST(root));
    int X;
    printf("ENTER THE VALUE TO BE DELETED : ");
    scanf("%d",&X);
    root=Delete_BST(root,X);
    LevelOrderTraversal(root);
    return 0;
}