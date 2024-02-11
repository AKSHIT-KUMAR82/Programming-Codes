#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define max_size 100

int precendence(char token)
{
    if(token=='*'||token=='/')
    {
        return 2;
    }
    else if (token=='+'||token=='-')
    {
        return 1;
    }
    else{
        return 0;
    }
}

void infix_to_postfix(char *infix)
{
    char postfix[max_size];
    char stack[max_size];
    int top=-1;
    int index=0;
    char token;
    for(int i=0;infix[i];i++)
    {
        token=infix[i];
        if(isdigit(token))
        {
            postfix[index++]=token;
        }
        else if(token=='(')
        {
            stack[++top]=token;
        }
        else if(token==')')
        {
            while(top>=0&&stack[top]!='(')
            {
                postfix[index++]=stack[top--];
            }
            if(stack[top]=='(')
            {
                top--;
            }
            else{
                printf("INVALID EXPRESSION...\n");
            }
        }
        else{
            while((top>=0)&&(precendence(token)<=precendence(stack[top])))
            {
                postfix[index++]=stack[top--];
            }
            stack[top++]=token;
        }

    }
    while(top>=0)
    {
        if(stack[top]==')')
        {
            printf("INVALID EXPRESSION...\n");
            return ;
        }
        postfix[index++]=stack[top--];
    }
    postfix[index]='\0';
    printf("EVALUATED POSTFIX EXPRESSION : %s",postfix);
}
int main()
{
    char infix[max_size];
    printf("ENTER INFIX EXPRESSION : ");
    scanf("%s",infix);
    infix_to_postfix(infix);
    return 0;
}