#include<iostream>
using namespace std;

class B; //FORWARD DECLARATION...
class A
{
    int data; //Private...
    public:
    void getdata(int val)
    {
        this->data=val;
    }
    friend void swap(A &obj1,B &obj2);
};

class B
{
    int data;
    public:
    void getdata(int val)
    {
        this->data=val;
    }
    friend void swap(A &obj1,B &obj2);
};

void swap(A & obj1,B & obj2) //FRIEND FUNCTION SWAPPING PRIVATE DATA MEMBERS VALUES OF 2 DIFFERENT CLASSES..
{
    cout<<"PREVIOUS VALUES : "<<endl;
    cout<<"OBJ1 l : "<<obj1.data<<endl<<"OBJ2 : "<<obj2.data<<endl;
    int temp=obj1.data;
    obj1.data=obj2.data;
    obj2.data=temp;
    cout<<"SWAPPED VALUES : "<<endl;
    cout<<"OBJ1 l : "<<obj1.data<<endl<<"OBJ2 : "<<obj2.data;
}

int main()
{
    A obj1;
    B obj2;
    obj1.getdata(10);
    obj2.getdata(20);
    swap(obj1,obj2);
    return 0;
}