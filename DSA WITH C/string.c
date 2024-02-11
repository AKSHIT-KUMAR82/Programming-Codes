#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define max_size 100

void push(int *top,int val,int *stack)
{
    stack[++(*top)]=val;
}

int pop(int *top,int *stack)
{
    int a=stack[(*top)--];
    return a;
}

int main()
{
    int top=-1,flag=0;
    char str[max_size];
    int stack[max_size];
    printf("ENTER STRING : ");
    scanf("%s",str);
    for(int i=0;str[i];i++)
    {
        if(str[i]=='0'||str[i]=='1')
        {
            push(&top,str[i],stack);
        }
        else{
            if(top==-1)
            {
                flag=1;
                break;
            }
            pop(&top,stack);
        }
    }
    if(top==-1&&flag==0)
    {
        printf("BALANCED STRING...");
    }
    else{
        printf("NOT BALANCED STRING...");
    }
    return 0;
}