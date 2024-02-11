#include<iostream>
using namespace std;

class Gk;
class Ak
{
    private:
    int data;
    public:
    void getdata(int val)
    {
        int *ptr=&data;
        *ptr=val;
    }
    int putdata()
    {
        return this->data;
    }
    friend void swap(Ak &obj1,Gk &Obj2);
};

class Gk
{
    private:
    int data;
    public:
    void getdata(int val)
    {
        int *ptr=&data;
        *ptr=val;
    }
    int putdata()
    {
        return this->data;
    }
    friend void swap(Ak &obj1,Gk &Obj2);
};

void swap(Ak &obj1,Gk &obj2)
{
    int Ak::*ptr1=&Ak::data;
    int Gk::*ptr2=&Gk::data;
    int temp=obj1.*ptr1;
    obj1.*ptr1=obj2.*ptr2;
    obj2.*ptr2=temp;
}

int main()
{
    Ak obj1;
    Gk obj2;
    obj1.getdata(20);
    obj2.getdata(40);
    cout<<"PREVIOUS VALUES : \n";
    cout<<"OBJ1 : "<<obj1.putdata()<<endl;
    cout<<"OBJ2 : "<<obj2.putdata()<<endl;
    swap(obj1,obj2);
    Ak *ptr1=&obj1;
    Gk *ptr2=&obj2;
    int (Ak::*pt1)()=& Ak::putdata;
    int (Gk::*pt2)()=& Gk::putdata;
    cout<<"SWAPPED VALUES : \n";
    cout<<"OBJ1 : "<<(ptr1->*pt1)()<<endl;
    cout<<"OBJ2 : "<<(ptr2->*pt2)()<<endl;
    return 0;
}