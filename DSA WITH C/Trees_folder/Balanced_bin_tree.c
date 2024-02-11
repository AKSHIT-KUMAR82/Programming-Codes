/* A BALANCED BINARY TREE IS A TREE WHERE AT EACH NODE THE ABSOLUTE
DIFFERENCE OF IT'S LEFT AND RIGHT SUBTREE IS LESS THAN EQUAL TO 1 */
#include <stdio.h>
#include <stdlib.h>

/* HERE I AM ONLY WRITING THE FUNCTION DEFINITION FOR THE INTENTED TASK APPOINTED...*/
typedef struct node
{
   int data;
   struct node *left;
   struct node *right;
} Node;

typedef struct bal
{
    int b;
    int h;
} bal;

// Function to check whether a binary tree is balanced or not.
bal isfastBalanced(Node *root)
{
    if (root == NULL)
    {
        bal obj;
        obj.b = 1; //It means that a null node is considered as balanced..
        obj.h = 0; //Similarily it also means that height of null node is 0...
        return obj;
    }
    bal obj1, obj2, obj3;
    obj1 = isfastBalanced(root->left);
    obj2 = isfastBalanced(root->right);
    int balance = abs(obj1.h - obj2.h) <= 1;
    int height = max(obj1.h, obj2.h) + 1;
    obj3.h = height;
    obj3.b = obj1.b && obj2.b && balance;
    return obj3;
}
int isBalanced(Node *root)
{
    int final = isfastBalanced(root).b;
    return final;
}
