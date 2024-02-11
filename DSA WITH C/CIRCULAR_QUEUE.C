#include<stdio.h>
#include<stdlib.h>
#define n 6

/*QUEUE PROGRAM 
1)LINEAR QUEUE
2)CIRCULAR QUEUE
*/

// CIRCULAR QUEUE PROGRAM....

void enqueue(int q[],int *f,int *r,int val)
{
    if((*r+1)%n==*f)
    {
        printf("OVERFLOW CONDITION OCCURS....\n");
    }
    else
    {
        if(*f==-1)
        {
            *f=0;
        }
        *r=(*r+1)%n;
        q[*r]=val;
    }
}

int dequeue(int q[],int *f,int *r)
{
    int val;
    if(*f<0)
    {
        return -1;
    }
    else{
        if(*r==*f)
        {
            val=q[*f];
            *f=-1;
            *r=-1;
        }
        else{
            val=q[*f];
            *f=(*f+1)%n;
        }
    }
    return val;
}

void display(int queue[],int *f,int *r)
{
    int a=*f;
    if(*f==-1)
    {
        printf("NOTHING TO DISPLAY....\n");
    }
    else{
        while(a!=*r)
    {
        printf("%d ",queue[a]);
        a=(a+1)%n;
    }
    printf("%d\n",queue[a]);
    }
}
int  main()
{
    int queue[n],f=-1,r=-1;
    enqueue(queue,&f,&r,5);
    enqueue(queue,&f,&r,6);
    enqueue(queue,&f,&r,7);
    enqueue(queue,&f,&r,8);
    enqueue(queue,&f,&r,9);
    enqueue(queue,&f,&r,10);
    display(queue,&f,&r);
    int a=dequeue(queue,&f,&r);

    if(a!=-1)
        printf("DELETED ELEMENT : %d\n",a);
    else
       printf("UNDERFLOW CONDITION OCCURS....\n");
    enqueue(queue,&f,&r,11);
    enqueue(queue,&f,&r,12);

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

    display(queue,&f,&r);
    return 0;
}