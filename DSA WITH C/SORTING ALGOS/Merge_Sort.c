/* HERE WE ARE GOING TO STUDY AN ALGORITHM OF TWO WAY MERGE SORT , IN WHICH WE FIRST BREAK AN ARRAY INTO TWO PARTS 
RECURRSIVELY AND AT LAST WHEN THESE TWO ARRAYS BECOME SORTED THEN MERGE THEM INTO ORIGINAL*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


void Sort(int *arr,int s,int e)
{
    int mid=(s+e)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    int *arr1=(int *)malloc(sizeof(int)*len1);
    int *arr2=(int *)malloc(sizeof(int)*len2);

    //Now, Copy Values into 2 arrays...
    int index=s,i,j;
    for(i=0;i<len1;i++)
    {
        arr1[i]=arr[index++];
    }
    for(j=0;j<len2;j++)
    {
        arr2[j]=arr[index++];
    }
    i=0,j=0;
    index=s;
    while(i<len1&&j<len2)
    {
        if(arr1[i]>arr2[j])
        {
            arr[index++]=arr2[j++];
        }
        else{
            arr[index++]=arr1[i++];
        }
    }
    while(i<len1)
    {
        arr[index++]=arr1[i++];
    }
    while(j<len2)
    {
        arr[index++]=arr2[j++];
    }
    free(arr1);
    free(arr2);
}

void MergeSort(int *arr,int s,int e)
{
    //Base case...
    if(s>=e)
    {
        return ;
    }
    int mid=(s+e)/2;
    MergeSort(arr,s,mid);
    MergeSort(arr,mid+1,e);
    Sort(arr,s,e);
}
int main()
{
    int n;
    printf("ENTER THE SIZE OF THE ARRAY : ");
    scanf("%d",&n);
    int arr[n];
    printf("ENTER ELEMENTS TO BE INSERTED : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    MergeSort(arr,0,n-1); //Calling merge sort function which breaks an array into two sorted array and therefore combined them into a fully sorted array...
    printf("SORTED ARRAY : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
