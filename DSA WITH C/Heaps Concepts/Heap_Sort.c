/*

WHAT IS HEAP SORTING ALGORITHM ????

BASICALLY, HEAP SORT IS A SORTING IN WHICH WE SORT ELEMENTS USING HEAP DATA STRUCTURE,
STORED IN FORM AN ARRAY.....
IT'S TIME COMPLEXITY IS O(NlogN)

WORKING ALGORITHM ???

:- CONSIDERING WE HAVE TO SORT IN ASCENDING ORDER SO WE ARE TAKING MAX HEAP...NOW, AS WE KNOW
THAT ROOT NODE VALUE IS GREATER THAN ALL NODES VALUE SO WHAT WE DO :

1) FIRSTLY , WE WILL SWAP THE 1ST INDEX VALUE WITH THE VALUE STORED AT LAST INDEX...
2) SECONDLY , WE WILL HEAPIFY THAT INDEX VALUE AND THEN AGAIN REPEAT THE PROCESS FROM FIRST...


*/

#include<stdio.h>
#include<stdlib.h>

void swap(int *val1, int *val2)
{
    *val1 += *val2;
    *val2 = *val1 - *val2;
    *val1 = *val1 - *val2;
}

void Heapify(int *arr, int index, int n) // We are considering max heap...
{
    int max = index;
    int lefti = max * 2;    // Left child index...
    int righti = lefti + 1; // Right child index...
    if (lefti <= n && arr[lefti] >= arr[max])
    {
        max = lefti;
    }
    if (righti <= n && arr[righti] >= arr[max])
    {
        max = righti;
    }
    if (max != index) // Changes occurs...means that index value must we placed at it's right position in the array...
    {
        swap(&arr[max], &arr[index]);
        Heapify(arr, max, n);
    }
}

void HeapSort(int *arr, int *n)
{
    while (*n > 1)
    {
        swap(&arr[1], &arr[*n]);
        (*n)--;
        Heapify(arr, 1, *n);
    }
    return;
}

int main()
{
    int arr[7]={-1,140,120,70,100,60,50};
    int n=6;
    int copy=n;
    HeapSort(arr,&n);
    printf("ELEMENTS AFTER HEAP SORT : ");
    for(int i=1;i<=copy;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}