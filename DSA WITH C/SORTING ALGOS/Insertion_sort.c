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
        arr[j+1]=temp; //Placing element in it's right place in the sorted array...
    }
    printf("ELEMENTS IN SORTED ORDER : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}