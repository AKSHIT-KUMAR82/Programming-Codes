/* IN THIS PROGRAM WE WILL SEE HOW CAN WE USE EXTERNAL FUNCTION DEFINITIONS TO DETECT 
THE EXCEPTION AND THROWS IT TO THE HANDLER WHICH IS INVOKED IN THE TRY BLOCK ONLY...
THIS IS DONE TO SIMPLIFY THE PROGRAM...*/

#include<iostream>
using namespace std;

void divide(int x,int y,int z)
{
    cout<<"INSIDE THE FUNCTION....\n";
    if((y-z)==0)
    {
        throw (y-z);
    }
    else{
        cout<<"RESULT x/(y-z) : "<<(float)x/(y-z)<<endl;
    }
    cout<<"END OF FUNCTION....\n";
}

int main()
{
    int x,y,z;
    cout<<"ENTER 3 VALUES FOR FURTHER OPERATION : ";
    cin>>x>>y>>z;
    try
    {
        divide(x,y,z);
    }
    catch(float m)
    {
        cout<<"DIVISION BY 0 EXCEPTION IS CAUGHT AND HANDLED..."<<endl;
    }
    cout<<"END OF MAIN..."<<endl;
    return 0;   
}

