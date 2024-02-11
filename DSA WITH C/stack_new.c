#include<stdio.h>
#include<stdlib.h>

void push(int stack[],int val,int *top)
{
  stack[++(*top)]=val;
}

int pop(int stack[],int *top)
{
  if(*top==-1)
  {
    printf("UNDERFLOW CONDITION..\n");
    return -1;
  }
  return (stack[(*top)--]);
}

void Display(int stack[],int top)
{
  if(top==-1)
  {
    printf("NOTHING TO DISPLAY...\n");
  }
  else
  {
    while(top>=0)
    {
      printf("%d ",stack[top--]);
    }
  }
}
int main()
{
  int n;
  printf("ENTER THE MAX SIZE OF THE STACK : ");
  scanf("%d",&n);
  int stack[n],top=-1; //HERE -1 IS SOME INVALID VALUE IN TERMS OF INDEXING...
  int choice=1;
  while(choice!=-1)
  {
    int val;
    printf("ENTER 1 FOR PUSH,2 FOR POP & 3 FOR DISPLAY : ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:printf("ENTER THE ELEMENT TO BE INSERTED : ");
             scanf("%d",&val);
             push(stack,val,&top);
             break;
      case 2:val=pop(stack,&top);
             if(val!=-1)
                printf("POPPED ELEMENT IS : %d\n",val);
              break;
      case 3:Display(stack,top);
             break;
      default :choice=-1;
               printf("WRONG CHOICE ENTERED...EXIT.....\n");
    }
  }
  return 0;
}