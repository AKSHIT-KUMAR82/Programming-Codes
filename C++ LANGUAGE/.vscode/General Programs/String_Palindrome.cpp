#include<iostream>
#include<string>
using namespace std;

int main()
{
    string name;
    cout<<"ENTER ANY STRING TO BE CHECKED FOR PALINDROME : ";
    cin>>name;
    int i=0,j=name.length()-1;
    int flag=0;
    while(i<=j)
    {
        if(name[i]!=name[j])
        {
            flag=1;
            break;
        }
        i++;
        j--;
    }
    if(flag==0){
        cout<<"STRING IS PALINDROME...";
    }
    else{
        cout<<"STRING IS NOT PALINDROME...";
    }
    return 0;
}