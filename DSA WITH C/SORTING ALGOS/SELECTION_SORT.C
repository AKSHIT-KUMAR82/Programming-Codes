#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main()
{
    int n;
    printf("ENTER THE NO. OF ELEMENTS , YOU WANT TO INSERT : ");
    scanf("%d",&n);
    int arr[n];
    printf("ENTER DATA VALUES : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int temp=0,min_index=0;
    for(int i=0;i<n-1;i++)
    {
        min_index=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_index])
            {
                min_index=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min_index];
        arr[min_index]=temp;
    }
    printf("ELEMENTS IN SORTED ORDER : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}