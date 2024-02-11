#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max(a,b) (a>b?a:b)

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

//HERE WE ONLY WRITE THE FUNCTION INVOLVED FOR FINDING THE DIAMETER OF ANY BINARY TREE...

//CREATES A STRUCTURE FOR STORING HEIGHT AND DIAMETER FOR ANY PARTICULAR NODE...
typedef struct arr
{
    int dia;
    int height;
}arr;

arr Diameter_BinTree(struct node * root)
{
    if(root==NULL)
    {
        arr p;
        p.dia=0;
        p.height=0;
    }
    arr p1=Diameter_BinTree(root->left);
    arr p2=Diameter_BinTree(root->left);
    int hei=max(p1.height,p2.height)+1;
    int diameter=max(p1.dia,max(p2.dia,p1.height+p2.height+1));
    arr result;
    result.dia=diameter;
    result.height=hei;
    return result;
}
