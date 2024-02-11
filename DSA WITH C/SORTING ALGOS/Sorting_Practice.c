/* 
HEY , HERE WE ARE GOING TO PRACTICE ALL 5 SORTING ALGOS LEARNED SO FAR....
1) BUBBLE SORTING 
2) SELECTION SORTING 
3) INSERTION SORTING
4) TWO WAY MERGE SORTING
5) QUICK SORTING
*/

#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int *arr,int n) //Ascending order sorting...
{
    int temp;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(arr[j]>=arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }

    }
}

void SelectionSort(int *arr,int n)
{
    int temp,MaxIndex;
    for(int i=0;i<n-1;i++)
    {
        MaxIndex=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>=arr[MaxIndex])
            {
                MaxIndex=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[MaxIndex];
        arr[MaxIndex]=temp;
    }

}

void InsertionSort(int *arr,int n)
{
    int temp,j;
    for(int i=1;i<n;i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>=temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

void Merge(int *arr,int s,int e)
{
    int mid=(s+e)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    int *arr1=(int *)malloc(sizeof(int)*len1);
    int *arr2=(int *)malloc(sizeof(int)*len2);

    //Copies Value from main array to it's left and right subarray...
    int MainIndex=s;
    for(int i=0;i<len1;i++)
    {
        arr1[i]=arr[MainIndex++];
    }
    for(int i=0;i<len2;i++)
    {
        arr2[i]=arr[MainIndex++];
    }
    int i=0,j=0;
    MainIndex=s;
    while(i<len1&&j<len2)
    {
        if(arr1[i]<arr2[j])
        {
            arr[MainIndex++]=arr2[j++];
        }
        else{
            arr[MainIndex++]=arr1[i++];
        }
    }
    while(i<len1)
    {
        arr[MainIndex++]=arr1[i++];
    }
    while(j<len2)
    {
        arr[MainIndex++]=arr2[j++];
    }
}

void MergeSort(int *arr,int s,int e)
{
    //Base Case..
    if(s>=e)
    {
        return;
    }
    int mid=(s+e)/2;
    MergeSort(arr,s,mid);
    MergeSort(arr,mid+1,e);
    Merge(arr,s,e);
}

int PartitionIndex(int *arr,int s,int e)
{
    int pivot=arr[s];
    int count=0;
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<=arr[s])
        {
            count++;
        }
    }
    int PivotIndex=s+count;
    int temp=arr[PivotIndex];
    arr[PivotIndex]=arr[s];
    arr[s]=temp;
    int i=s,j=e;
    while(i<PivotIndex&&j>PivotIndex)
    {
        while(arr[i]<arr[PivotIndex])
        {
            i++;
        }
        while(arr[j]>arr[PivotIndex])
        {
            j--;
        }
        if(i<PivotIndex&&j>PivotIndex)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
    return PivotIndex;
}
void QuickSort(int *arr,int s,int e)
{
    //Base case..
    if(s>=e)
    {
        return ;
    }
    int P=PartitionIndex(arr,s,e);
    QuickSort(arr,s,P-1);
    QuickSort(arr,P+1,e);
}
int main()
{
    int n;
    printf("ENTER NO. OF ELEMENTS TO BE INSERTED : ");
    scanf("%d",&n);
    int arr[n];
    printf("ENTER ELEMENTS TO BE INSERTED :  ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    BubbleSort(arr,n);    //Ascending
    SelectionSort(arr,n); //Decending
    InsertionSort(arr,n); //Ascending
    MergeSort(arr,0,n-1); //Decending
    QuickSort(arr,0,n-1); //Ascending
    printf("SORTED ARRAY LOOK LIKE : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}