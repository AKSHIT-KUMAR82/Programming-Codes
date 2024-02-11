/* TWO SUM IN A BST MEANS , THAT WE HAVE GIVEN A TARGET VALUE , WE HAVE TO CHECK WETHER THERE
EXISTS ANY TWO NODES WHOSE VALUES SUM EQUATES TO TARGET VALUE....

APPROACH 1 : HERE , WE CAN DO ONE THING IS THAT FIRST WE'LL TAKE ROOT NODE AND DEDUCTS IT'S VALUE
FROM THE TARGET VALUE AND THEN SEARCHES THAT REMAINING VALUE IN IT'S RIGHT AND LEFT SUBTREE RECURSSIVELY....

APPROACH 2 : AS, WE KNOW THAT INORDER TRAVERSAL OF A BST ALWAYS BE SORTED IN ASCENDING ORDER
SO, WHAT WE CAN DO IS WE WILL STORE INORDER TRAVERSAL VALUES OF A BST IN AN ARRAY AND THEN
USING TWO VARIABLES...ONE POINTING AT Oth INDEX AND ANOTHER AT (N-1)th Index APPROACHES EACH OTHER IN SUCH A WAY
IN A WHILE LOOP WHICH ENDS WHEN FIRST EXCEEDS OTHER...ALONG WITH EACH ITERATION WE'LL CHECK
SUM OF THOSE VALUES STORED IF IT'S EQUALS TO TARGET VALUE THEN RETURN TRUE ELSE CHECK WHETHER IT'S
GREATER OR SMALLER THEN ACCONDINGLY MOVE THE VARIABLES....AT END BEFORE COMLETETION OF THE FUNCTION
RETURN FALSE BECAUSE IF IT WILL NOT RETURN TRUE IN WHILE LOOP THEN IT'S OBVIOUS THAT , IT'S FALSE...
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
    int info;
    struct Node *left;
    struct Node *right;
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

void InorderTrav(Node *root, int *arr, int *i)
{
    // Base Case..
    if (root == NULL)
    {
        return;
    }
    InorderTrav(root->left, arr, i);
    arr[(*i)++] = root->info;
    InorderTrav(root->right, arr, i);
}

int TwoSumInBST(Node *root,int key)
{
    int arr[100] = {0};
    int i = 0;
    InorderTrav(root, arr, &i);
    int j = 0, k = i - 1;
    while (j < k)
    {
        int sum = arr[j] + arr[k];
        if (sum == key)
        {
            return 1;
        }
        else if (sum > key)
        {
            k--;
        }
        else
        {
            j++;
        }
    }
    return 0;
}

int main()
{
    Node *root = NULL;
    int data;
    printf("ENTER THE DATA : ");
    scanf("%d", &data);
    while (data != -1)
    {
        root = Insert_BST(root, data);
        scanf("%d", &data);
    }
    printf("ENTER THE KEY TO BE SEARCHED FOR TWO SUM IN BST : ");
    scanf("%d",&data);
    int check=TwoSumInBST(root,data);
    if(check==1)
    {
        printf("YES, IT'S A TWO SUM IN BST...\n");
    }
    else{
        printf("NO, IT'S NOT A TWO SUM IN BST...\n");
    }
    return 0;
}