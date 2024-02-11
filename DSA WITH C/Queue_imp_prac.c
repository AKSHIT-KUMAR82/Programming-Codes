#include<stdio.h>
#include<stdlib.h>

void insert(int *f,int *r,int val,int queue[],int n)
{
    if((*r+1)%n==(*f))
    {
        printf("QUEUE IS FULL...\n");
    }
    else if(*f==-1)
    {
        *f=0;
        queue[++(*r)]=val;
    }
    else{
        *r=(*r+1)%n;
        queue[*r]=val;
    }
}

int delete(int *f,int *r,int queue[],int n)
{
    int a;
    if(*f==-1)
    {
        printf("UNDERFLOW CONDITION...\n");
        return -1;
    }
    else if(*f==*r)
    {
        a=queue[*f];
        *f=-1;
        *r=-1;
    }
    else{
        a=queue[*f];
        *f=(*f+1)%n;
    }
    return a;
}

void display(int queue[],int f,int r,int n)
{
    int temp=f;
    if(f==-1)
    {
        printf("NOTHING TO DISPLAY...\n");
    }
    else{
        while(temp!=r)
        {
            printf("%d ",queue[temp]);
            temp=(temp+1)%n;
        }
        printf("%d\n",queue[temp]);
    }
}


int main()
{
    int front=-1,rear=-1,n;
    printf("ENTER THE SIZE OF THE QUEUE : ");
    scanf("%d",&n);
    int queue[n],a;
    insert(&front,&rear,1,queue,n);
    insert(&front,&rear,2,queue,n);
    insert(&front,&rear,3,queue,n);
    insert(&front,&rear,4,queue,n);
    insert(&front,&rear,5,queue,n);
    insert(&front,&rear,7,queue,n);
    a=delete(&front,&rear,queue,n);
    if(a!=-1)
       printf("DELETED VALUE : %d\n",a);
    a=delete(&front,&rear,queue,n);
    if(a!=-1)
       printf("DELETED VALUE : %d\n",a);
    a=delete(&front,&rear,queue,n);
    if(a!=-1)
       printf("DELETED VALUE : %d\n",a);
    a=delete(&front,&rear,queue,n);
    if(a!=-1)
       printf("DELETED VALUE : %d\n",a);
    a=delete(&front,&rear,queue,n);
    if(a!=-1)
       printf("DELETED VALUE : %d\n",a);
    a=delete(&front,&rear,queue,n);
    if(a!=-1)
       printf("DELETED VALUE : %d\n",a);
    a=delete(&front,&rear,queue,n);
    if(a!=-1)
       printf("DELETED VALUE : %d\n",a);
    display(queue,front,rear,n);
    return 0;
}