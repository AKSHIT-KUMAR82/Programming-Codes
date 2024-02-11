#include<iostream>
using namespace std;
#define size 50
class bin
{
    char str[size];
    public:
    void input() //Inline Function..
    {
        cout<<"ENTER THE BINARY NUMBER : ";
        cin>>str;
    }  
    void display();
    void bin_ck();
    void comp();
}; 

void bin::comp()
{
    for(int i=0;str[i];i++)
    {
        if(str[i]==48)
        {
            str[i]=49;
        }
        else{
            str[i]=48;
        }
    }
}
void bin::bin_ck()
{
    for(int i=0;str[i];i++)
    {
        if(str[i]!=48&&str[i]!=49)
        {
            cout<<"NOT A VALID BINARY NUMBER..."<<endl;
            exit(1);
        }

    }
    comp();
}
void bin::display()
{
    bin_ck(); //NESTING OF MEMBER FUNCTION AND CALLING WITHOUT ANY . OPERATOR UNLIKE OBJECT...
    cout<<"COMPLIMENTED BINARY NUMBER : "<<str<<endl;
}

int main()
{
    bin obj;
    obj.input();
    obj.display();
    return 0;
}