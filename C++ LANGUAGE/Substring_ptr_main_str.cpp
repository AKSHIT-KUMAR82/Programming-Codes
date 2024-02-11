#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
// STRING MANIPULTAION FUNCTIONS : <cstring>

int main()
{
    char *mnstr,*substr;
    mnstr=(char *)malloc(sizeof(char)*50);
    substr=(char *)malloc(sizeof(char)*50);
    cout<<"ENTER THE MAIN STRING : ";
    cin>>mnstr;
    cout<<"ENTER SUBSTRING TO BE SEARCHED : ";
    cin>>substr;
    int mn=strlen(mnstr);
    int sub=strlen(substr),k,flag=0;
    for(int i=0;i<mn;i++)
    {
        k=i;
        for(int j=0;j<sub;j++)
        {
            if(mnstr[k]==substr[j])
            {
                if(j==sub-1)
                {
                    flag=1;
                    break;
                }
                k++;
            }
            else{
                break;
            }
        }
        if(flag==1)
        {
            break;
        }
    }
    if(flag==1)
    {
        cout<<"SUBSTRING FOUND...\n";
    }
    else{
        cout<<"SUBSTRING NOT FOUND...\n";
    }
    return 0;
}