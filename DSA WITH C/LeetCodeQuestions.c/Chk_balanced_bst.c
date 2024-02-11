/* PROBLEM STATEMENT : WE HAVE TO CHECK WEATHER A BST IS BALANCED OR NOT....
A BALANCED BST IS ONE IN WHICH AT EACH NODE ABSOLUTE DIFF OF LEFT AND RIGHT SUB TREES
EQUATES TO LESS THAN EQUAL TO 1....*/

/*APPROACH : HERE MY APPROACH WILL BE THAT I'LL GET THE HEIGHT H1 OF LEFT SUB TREE AND SIMILIARLY
RIGHT SUB TREE THEN FIND THEIR DIFF IF IT'S LESS THAN EQUAL TO 1 THEN TRUE AND HEIGHT AS MAX OF LEFT AND RIGHT SUBTREE +1 ....*/

#include<stdio.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define max(a, b) (a > b ? a : b)
typedef struct check
{
    int h;
    int chk;
} check;

check CheckBalanced(struct TreeNode *root)
{
    if (root == NULL)
    {
        check ak;
        ak.h = 0;
        ak.chk = 1;
        return ak;
    }
    check left = CheckBalanced(root->left);
    check right = CheckBalanced(root->right);
    check final;
    final.h = max(left.h, right.h) + 1;
    final.chk = (abs(left.h - right.h) <= 1) && left.chk && right.chk;
    return final;
}

int isBalanced(struct TreeNode *root)
{
    return CheckBalanced(root).chk;
}