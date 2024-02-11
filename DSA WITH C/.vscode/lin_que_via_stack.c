#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_size 100

void push(int *top, int stack[], int val)
{
    stack[++(*top)] = val;
}

int pop(int *top, int stack[])
{
    int val;
    if (*top == -1)
    {
        return -1;
    }
    val = stack[0];
    for (int i = 1; i <= *top; i++)
    {
        stack[i - 1] = stack[i];
    }
    --(*top);
    return val;
}

void Display(int top, int stack[])
{
    if (top == -1)
    {
        printf("NOTHING TO DISPLAY...\n");
    }
    else
    {
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int top = -1;
    int stack[max_size];
    int choice = 1;
    while (choice != -1)
    {
        int val;
        printf("ENTER 1 FOR PUSH , 2 FOR POP AND 3 FOR DISPLAY : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("ENTER THE ELEMENT TO BE INSERTED : ");
            scanf("%d", &val);
            push(&top, stack, val);
            break;
        case 2:
            val = pop(&top, stack);
            if (val != -1)
                printf("POPPED ELEMENT IS : %d\n", val);
            break;
        case 3:
            Display(top, stack);
            break;
        default:
            choice = -1;
            printf("WRONG CHOICE ENTERED...EXIT.....\n");
        }
    }
    return 0;
}
