/* NOW , WE ARE TALKING ABOUT THE SUM TREE >>>>>>>>
A SUM BINARY TREE IS A TREE IN WHICH AT EACH NODE THE SUM OF THE DATA
OF LEFT SUBTREE AND RIGHT SUBTREE IS EQUAL TO THE DATA OF THAT NODE ITSELF...*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int data;
    struct node *left,*right;
}node;

typedef struct sum
{
    int check;
    int sum;
}sum;

sum isfast_SumTree(node *root)
{
    if(root==NULL)//BASE CASE 1
    {
        sum obj;
        obj.check=1;
        obj.sum=0;
        return obj;
    }
    if(root->left==NULL&&root->right==NULL)//BASE CASE 2
    {
        sum obj;
        obj.check=1;
        obj.sum=root->data;
        return obj;
    }
    sum obj1,obj2,obj3;
    obj1=isfast_SumTree(root->left);
    obj2=isfast_SumTree(root->right);
    int equal=(obj1.sum+obj2.sum==root->data);
    obj3.sum=obj1.sum+obj2.sum+root->data;
    obj3.check=equal&&obj1.check&&obj2.check;
    return obj3;
}

