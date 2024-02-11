#include<stdio.h>
#include<stdlib.h>
#define n 6
/*QUEUE PROGRAM 
1)LINEAR QUEUE
2)CIRCULAR QUEUE
*/

// LINEAR QUEUE PROGRAM....

void enqueue(int q[],int *f,int *r,int val)
{
    if(*r>=n-1)
    {
        printf("OVERFLOW CONDITION OCCURS....\n");
    }
    else
    {
        if(*f==-1)
        {
            *f=0;
        }
        q[++(*r)]=val;
    }
}

int dequeue(int q[],int *f,int *r)
{
    int val;
    if(*f>*r)
    {
        return -1;
    }
    else{
        val=q[(*f)++];
        return val;
    }
}

void display(int q[],int *f,int *r)
{
    int a=*f;
    printf("ELEMENTS OF THE QUEUE : ");
    while(a<=*r)
    {
        printf("%d ",q[a]);
        a++;
    }
    printf("\n");
}

int  main()
{
    int queue[n],f=-1,r=-1;
    enqueue(queue,&f,&r,5);
    enqueue(queue,&f,&r,6);
    enqueue(queue,&f,&r,7);
    enqueue(queue,&f,&r,8);
    int a=dequeue(queue,&f,&r);
    if(a!=-1)
        printf("DELETED ELEMENT : %d\n",a);
    else
       printf("UNDERFLOW CONDITION OCCURS....\n");
    display(queue,&f,&r);
    a=dequeue(queue,&f,&r);
    if(a!=-1)
        printf("DELETED ELEMENT : %d\n",a);
    else
       printf("UNDERFLOW CONDITION OCCURS....\n");
    display(queue,&f,&r);
    a=dequeue(queue,&f,&r);
    if(a!=-1)
        printf("DELETED ELEMENT : %d\n",a);
    else
       printf("UNDERFLOW CONDITION OCCURS....\n");
    a=dequeue(queue,&f,&r);
    if(a!=-1)
        printf("DELETED ELEMENT : %d\n",a);
    else
       printf("UNDERFLOW CONDITION OCCURS....\n");
    a=dequeue(queue,&f,&r);
    if(a!=-1)
        printf("DELETED ELEMENT : %d\n",a);
    else
       printf("UNDERFLOW CONDITION OCCURS....\n");
    return 0;
}