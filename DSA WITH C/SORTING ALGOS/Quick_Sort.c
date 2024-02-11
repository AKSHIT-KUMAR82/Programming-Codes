/* HERE WE ARE DOING AN ANOTHER SORTING ALGORITHM KNOWN AS QUICK SORT...IN THIS ALGO WHAT WE DO IS FIRST 
WE SET A RANDOM ELEMENT IN AN ARRAY (I.E PIVOT ) AT IT'S CORRECT POSITION IN AN ARRAY IN SUCH A WAY THAT ALL
ELEMENTS SMALLER THAN IT COMES TO IT RIGHT SIDE AND ALL GREATER ELEMENTS COMES TO IT'S LEFT SIDE AND HENCE THEREFORE
WE WILL RECURRSIVELY SORT IT'S LEFT SUBARRAY AND IT'S RIGHT SUBARRAY...WHICH FINALLY RESULTS INTO A SORTED ARRAY...*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


int PartitionIndex(int *arr,int s,int e)
{
    int pivot=arr[s];
    int count=0;
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<=pivot)
        {
            count++;
        }
    }
    //Now, We will swap the pivot elements with it's right positioned element...
    int PivotIndex=s+count;
    int temp=arr[PivotIndex];
    arr[PivotIndex]=pivot;
    arr[s]=temp;
    //Now, Positioned smaller elements to it's right and greater elements to it's left respectively..
    int i=s,j=e;
    while(i<PivotIndex&&j>PivotIndex)
    {
        while(arr[i]<pivot)
        {
            i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }
        if(i<PivotIndex&&j>PivotIndex) //This will be only true when in both side we have inappropriate element...
        {
            //Both above while loops exit only when both side limit exceeds or when both side inappropriate elements found...
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
    //Base Case...
    if(s>=e)
    {
        return ;
    }
    int P = PartitionIndex(arr,s,e);
    QuickSort(arr,s,P-1);
    QuickSort(arr,P+1,e);
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
    QuickSort(arr,0,n-1); //Calling Quick sort function...
    printf("SORTED ARRAY : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}