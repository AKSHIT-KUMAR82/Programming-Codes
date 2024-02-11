#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insert(int *top, int val, int st[])
{
    st[++(*top)] = val;
}

int delete(int *top, int st[])
{
    int val;
    if (*top == -1)
    {
        printf("UNDERFLOW CONDITION...\n");
        return -1;
    }
    else
    {
        val = st[(*top)--];
    }
    return val;
}

void display(int top,int st[])
{
    if (top == -1)
    {
        printf("NOTHING TO DISPLAY...\n");
    }
    else
    {
        while (top != -1)
        {
            printf("%d ",st[top]);
            top--;
        }
    }

}

int main()
{
    char str[100];
    printf("ENTER THE STRING : ");
    gets(str);
    int top=-1;
    char ch;
    int val=strlen(str);
    for (int i = 0; i < val; i++) {
    for (int j = 0; j < val - i - 1; j++) {
        if (str[j] > str[j + 1]) {
            ch = str[j];
            str[j] = str[j + 1];
            str[j + 1] = ch;
        }
    }
    }
    char stack[val];
    for(int i=0;i<val;i++)
    {
        if(str[i]=='a'||str[i]=='A'||str[i]=='b'||str[i]=='B')
        {
            insert(&top,0,stack);
        }
        else{
            delete(&top,stack);
        }
    }
    if(top==-1)
    {
        printf("VALID STRING...\n");
    }
    else{
        printf("NOT VALID STRING...\n");
    }
    return 0;
}