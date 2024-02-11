/* We are going to add objects of two different classes using friend functions concept....*/
#include<iostream>
using namespace std;

class Ak2;
class Ak1
{
    int data;
    public:
    void getdata(int val) //Inline function....
    {
        this->data=val;
    }
    void putdata()
    {
        cout<<"Value1 : "<<data<<" ";
    }
    friend void Swap(Ak1 &,Ak2 &);
};

class Ak2
{
    int data;
    public:
    void getdata(int val) //Inline function....
    {
        this->data=val;
    }
    void putdata()
    {
        cout<<"Value2 : "<<data<<" ";
    }
    friend void Swap(Ak1 &,Ak2 &);
};

void Swap(Ak1 &obj1,Ak2 &obj2)
{
    int temp=obj1.data;
    obj1.data=obj2.data;
    obj2.data=temp;
}

int main()
{
    Ak1 obj1;
    Ak2 obj2;
    void (Ak1::*ptr1)(int)=&Ak1::getdata;
    (obj1.*ptr1)(20); 
    obj2.getdata(80);
    cout<<"VALUES BEFORE SWAPPING : "<<endl;
    obj1.putdata();
    obj2.putdata();
    Swap(obj1,obj2);
    cout<<"\nVALUES AFTER SWAPPING : "<<endl;
    obj1.putdata();
    obj2.putdata();
    return 0;
}

