#include <stdio.h>
#include <stdlib.h>
#define n 100

void push(int val, int *top, int stack[])
{
    if ((*top) >= n - 1)
    {
        printf("****OVERFLOW CONDITION****\n");
    }
    else
    {
        stack[++(*top)] = val;
    }
}

int pop(int stack[], int *top)
{
    int val;
    if ((*top) < 0)
    {
        printf("****UNDERFLOW CONDITION OCCURS****\n");
        return -1;
    }
    else
    {
        val = stack[(*top)--];
        return val;
    }
}

void display(int stack[], int top)
{
    printf("ELEMENTS ARE : ");
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int IsEmpty(int top)
{
    return (top < 0 ? 1 : 0);
}
int main()
{
    int top=-1;
    int choice, choice1;
    int stack[n];
    printf("ENTER 1 FOR STACK MENU DRIVEN PROGRAM && ENTER 2 FOR QUEUE MENU DRIVEN PROGRAM : ");
    scanf("%d", &choice);
    while (choice)
    {
        switch (choice)
        {
        case 1:
            printf("*****WELCOME TO STACK MENU DRIVEN PROGRAM*****\n\n");
            printf("ENTER 1 FOR PUSH,ENTER 2 FOR POP,ENTER 3 FOR DISPLAY AND 4 FOR CHECKING STACK IS EMPTY OR NOT : ");
            scanf("%d", &choice1);
            int val;
            while (choice1)
            {
                switch (choice1)
                {
                case 1:
                    printf("ENTER ELEMENT TO BE INSERTED : ");
                    scanf("%d", &val);
                    push(val, &top, stack);
                    break;

                case 2:
                    val = pop(stack, &top);
                    if (val != -1)
                    {
                        printf("DELETED ELEMENT : %d\n", val);
                    }
                    break;

                case 3:
                    display(stack,top);
                    break;

                case 4:
                    val = IsEmpty(top);
                    if (val == 1)
                    {
                        printf("*****IT IS EMPTY*****\n");
                    }
                    else
                    {
                        printf("*****IT IS NOT EMPTY*****\n");
                    }
                    break;
                default:
                    exit(1);
                }
                printf("ENTER 1 FOR PUSH,ENTER 2 FOR POP,ENTER 3 FOR DISPLAY AND 4 FOR CHECKING STACK IS EMPTY OR NOT : ");
                scanf("%d", &choice1);
            }
        }
        break;
    }
    return 0;
}