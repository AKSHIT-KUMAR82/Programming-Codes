#include<stdio.h>
#include<stdlib.h>

void swap(int *val1,int *val2)
{
    *val1+=*val2;
    *val2=*val1-*val2;
    *val1=*val1-*val2;
}

void InsertHeap(int val,int *arr,int *n)
{
    int index=*n+1;
    *n+=1;
    arr[index]=val; //Putting val at last in the array...

    //Now, Placing it in it's right position...
    int pindex;
    while(index>1)
    {
        pindex=index/2;
        if(pindex>=1&&arr[pindex]<=arr[index]) //We are taking max heap into consideration...
        {
            swap(&arr[pindex],&arr[index]);
            index=pindex;
        }
        else{
            return;
        }
    }
}

/*Delete function for heaps-data structure...Whenever we'll talk about deletion in heaps..
we are talking about deleting elements from the root node*/

void Delete1(int *arr,int *n) //Considering max heap...
{
    if(*n==0)
    {
        printf("NOTHING TO DELETE IN THE HEAP....\n");
        return ;
    }
    arr[1]=arr[*n];
    (*n)--;
    int max=1;
    while(max<*n)
    {
        int i=max;
        int lefti=max*2; //Left child index....
        int righti=lefti+1; //Right child index....
        if(lefti<=*n&&arr[lefti]>=arr[max])
        {
            max=lefti;
        }
        if(righti<=*n&&arr[righti]>=arr[max])
        {
            max=righti;
        }
        if(i!=max) //That index elements must be placed at it's right position...
        {
            swap(&arr[max],&arr[i]);
        }
        else{
            return;
        }
    }
}

int main()
{
    int arr[100];
    int n=0; //Array size...
    int val;
    printf("ENTER THE VALUEs TO BE INSERTED IN THE HEAP : ");
    scanf("%d",&val);
    while(val!=-1)
    {
        InsertHeap(val,arr,&n);
        scanf("%d",&val);
    }
    printf("DATA IN HEAP : ");
    for(int i=1;i<=n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    Delete1(arr,&n);
    printf("DATA IN HEAP AFTER DELETION : ");
    for(int i=1;i<=n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}