#include<stdio.h>
#include<stdlib.h>

#define size 100

int main()
{
    int n;
    printf("ENTER THE NUMBER OF ELEMENTS : ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int count1=0,count2=0,count3=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]-'1'==0)
        {
            count1++;
        }
        else if(arr[i]-'2'==1)
        {
            count2++;
        }
        else if(arr[i]-'3'==2)
        {
            count3++;
        }
        else{
            count1=-1;
            break;
        }
    }
    if(count1==count2&&count2==count3)
    {
        printf("VALID STRING...\n");
    }
    else{
        printf("NOT VALID STRING...\n");
    }
}