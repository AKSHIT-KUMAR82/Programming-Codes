#include<iostream>
using namespace std;

//CLASS DECLARATION...
class ak
{
    int val; // By default private data member..
    public : //visibility label or access specifiers..
    void getdata(int a);
    int putdata();
};

//FUNCTION DEFINITONS...
void ak::getdata(int a)
{
    this->val=a;
}

int ak::putdata()
{
    return (this->val);
}

int main()
{
    ak obj1,obj2;
    obj1.getdata(4);
    int a=obj1.putdata();
    obj2.getdata(5);
    int b=obj2.putdata();
    cout<<" VAL 1 : "<<a<<endl;
    cout<<" VAL 2 : "<<b;
    return 0;
}