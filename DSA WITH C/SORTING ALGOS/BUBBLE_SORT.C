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
    int temp=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("ELEMENTS IN SORTED ORDER : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}