#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cout<<"ENTER SIZE OF ARRAY : ";
    cin>>n;
    int arr[n];
    cout<<"ENTER THE ELEMENTS : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ClosestSum=INT_MAX;
    int CurrSum=0;
    int f,s;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            CurrSum=arr[i]+arr[j];
            if(abs(CurrSum)<abs(ClosestSum))
            {
                f=arr[i];
                s=arr[j];
                ClosestSum=CurrSum;
            }
        }
    }
    cout<<"THE ELEMENTS WHOSE SUM CLOSEST TO ZERO ARE "<<f<<" & "<<s<<endl;
    return 0;
}