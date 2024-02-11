/* 
HEAPIFY ALGORITHM ??????

:- HEAPIFY ALGORITHM HELPS US IN BUILDING A HEAP FROM AN ARRAY , IN WHICH WE PLACE AN 
INDEX VALUE IN ARRAY TO IT'S RIGHT POSITION USING HEAPIFY ALGO...IT'S TIME COMPLEXITY IS O(LogN)...

:- HERE, WE'LL TALK ABOUT HOW TO BUILD A HEAP FROM AN ARRAY....SO LET'S SEE...

AS, WE KNOW THAT IN ANY ARRAY, VALUES STORED AT LEAF NODES ARE ALREADY AT THEIR RIGHT POSITIONS
IN THAT ARRAY...LEAF NODES INDEX STARTS FROM (N/2+1) TO N...(I.E 1 BASED INDEXING)
SO WHAT WE DO IS WE'LL RUN A REVERSE LOOP FROM N TO 1 AND HEAPIFY EACH INDEX VALUES 
CORRESPONDING TO THAT....TIME COMPLEXITY FOR BUILDING A HEAP IS O(N)....

*/
#include<stdio.h>
#include<stdlib.h>


void swap(int *val1,int *val2)
{
    *val1+=*val2;
    *val2=*val1-*val2;
    *val1=*val1-*val2;
}

void Heapify(int arr[],int index,int n) //We are considering max heap...
{
    int max=index;
    int lefti=max*2; //Left child index...
    int righti=lefti+1; //Right child index...
    if(lefti<=n&&arr[lefti]>=arr[max])
    {
        max=lefti;
    }
    if(righti<=n&&arr[righti]>=arr[max])
    {
        max=righti;
    }
    if(max!=index) //Changes occurs...means that index value must we placed at it's right position in the array...
    {
        swap(&arr[max],&arr[index]);
        Heapify(arr,max,n);
    }
}

void BuildHeap(int arr[],int n)
{
    // arr is an array to be heapified and n is the size considering 1 based indexing..where n represents size as well as last indexing...

    //Build a heap from a CBT...
    for(int i=n/2;i>0;i--) //Leaf nodes are already at their right positions...
    {
        Heapify(arr,i,n);
    }

    printf("ELEMENTS AFTER HEAPIFICATION : ");
    for(int i=1;i<=n;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    int arr[7]={-1,50,60,70,100,120,140};
    int n=6;
    BuildHeap(arr,n);
    return 0;
}