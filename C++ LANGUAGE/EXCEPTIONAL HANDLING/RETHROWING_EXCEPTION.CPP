/* HERE WE WILL SEE THE CODE FOR RETHROWING AN EXCEPTION CAUGHT BY A HANDLER */
#include<iostream>
using namespace std;

void re_throw(int val)
{
    try
    {
        if(val==0)
        {
            throw val;
        }
        else
        {
            cout<<"NO EXCEPTION IS CAUGHT...\n";
        }
    }
    catch(int val)
    {
        cout<<"NOW RETHROW IT.."<<endl;
        throw; //THIS SYNTAX FOR THROWING IS USED FOR RETHROW ONLY..
    }
    cout<<"END OF FUNCTION....\n";
}

int main()
{
    int val;
    cout<<"ENTER THE VALUE : "<<endl;
    cin>>val;
    try
    {
        re_throw(val);
    }
    catch(int val)
    {
        cout<<"EXCEPTION IS CAUGHT IN NEXT HANDLER...\n";
    }
    cout<<"END................\n";
    return 0;
}