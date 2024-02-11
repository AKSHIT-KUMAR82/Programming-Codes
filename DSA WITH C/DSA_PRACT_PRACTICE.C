#include<stdio.h>
#include<stdlib.h>


void Heapify(int *arr,int index,int size)
{
    int Pindex=index;
    int LeftIndex=Pindex*2;
    int RightIndex=LeftIndex+1;
    while(LeftIndex<=size&&RightIndex<=size)
    {
        int min=Pindex;
        if(arr[min]>=arr[LeftIndex])
        {
            min=LeftIndex;
        }
        if(arr[min]>=arr[RightIndex])
        {
            min=RightIndex;
        }
        if(min!=Pindex)
        {
            int temp=arr[Pindex];
            arr[Pindex]=arr[min];
            arr[min]=temp;
            Pindex=min;
            LeftIndex=Pindex*2;
            RightIndex=LeftIndex+1;
        }
        else{
            return;
        }
    }
}

void BuildToHeap(int *arr,int size)
{
    for(int i=size/2;i>=1;i--)
    {
        Heapify(arr,i,size);
    };
}


void InsertIntoHeap(int *arr,int *n,int data) //HERE WE ARE IMPLEMENTING MAX HEAP...
{
    if(n==0)//EMPTY HEAP...
    {
        arr[++(*n)]=data;
        return;
    }
    arr[++(*n)]=data;
    int pindex=*n/2;
    int cindex=*n;
    int temp;
    while(pindex>=1)
    {
        if(arr[pindex]<=arr[cindex])
        {
            temp=arr[pindex];
            arr[pindex]=arr[cindex];
            arr[cindex]=temp;
            cindex=pindex;
            pindex=cindex/2;
        }
        else{
            break;
        }
    }

}

void Delete(int *arr,int *n)
{
    //WHENEVER WE'LL TALK ABOUT DELETING ELEMENTS IN A HEAP...IT WILL BE DELETED FROM THE ROOT ELEMENT ONLY....
    if(*n==0)
    {
        printf("NOTHING TO DELETE....\n");
        return;
    }
    arr[1]=arr[*n];
    (*n)--;
    //NOW WE'LL TAKE THE ROOT ELEMENT TO IT'S RIGHT POSITION IN THE MAX HEAP...
    int MaxIndex=1;
    int Pindex=1;
    int leftIndex=Pindex*2;
    int rightIndex=leftIndex+1;
    while(leftIndex<=*n&&rightIndex<=*n)
    {
        if(arr[Pindex]<=arr[leftIndex])
        {
            MaxIndex=leftIndex;
        }
        if(arr[MaxIndex]<=arr[rightIndex])
        {
            MaxIndex=rightIndex;
        }
        if(MaxIndex!=Pindex)
        {
            int temp=arr[Pindex];
            arr[Pindex]=arr[MaxIndex];
            arr[MaxIndex]=temp;
            Pindex=MaxIndex;
            leftIndex=Pindex*2;
            rightIndex=leftIndex+1;
        }
        else{
            break;
        }
    }
}

void Display(int *arr,int size)
{
    if(size==0)
    {
        printf("NOTHING TO DISPLAY....\n");
        return;
    }
    for(int i=1;i<=size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void HeapSort(int *arr,int size)
{
    if(size<=1)
    {
        return;
    }
    int temp=arr[size];
    arr[size]=arr[1];
    arr[1]=temp;
    size--;
    Heapify(arr,1,size);
    HeapSort(arr,size);
}


int main()
{
    int arr[100];
    int data;
    // printf("ENTER THE VALUES TO BE INSERTED : ");
    // scanf("%d",&data);
    int size=0;
    // while(data!=-1)
    // {
    //     InsertIntoHeap(arr,&size,data);
    //     scanf("%d",&data);
    // }
    // Display(arr,size);
    // Delete(arr,&size);
    // Display(arr,size);
    // Delete(arr,&size);
    // Display(arr,size);
    int f;
    printf("ENTER THE SIZE OF THE ARRAY TO BE CONVERTED TO HEAP : ");
    scanf("%d",&f);
    size=f+1;
    int Arr[size];
    printf("ENTER ELEMENTS TO BE INSERTED : ");
    for(int i=1;i<=f;i++)
    {
        scanf("%d",&Arr[i]);
    }
    BuildToHeap(Arr,f);
    Display(Arr,f);
    HeapSort(Arr,f);
    Display(Arr,f);
    return 0;
}