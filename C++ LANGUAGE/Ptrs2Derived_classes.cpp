#include<iostream>
using namespace std;

class base
{
    public:
    int b;
    void getb(int val)
    {
        this->b=val;
    }
    void display()
    {
        cout<<"THIS IS BASE CLASS..."<<endl;
        cout<<"VALUE B : "<<b<<endl;
    }
};

class derived:public base
{
    public:
    int d;
    void getd(int val)
    {
        this->b=val;
    }
    void display()
    {
        cout<<"THIS IS DERIVED CLASS..."<<endl;
        cout<<"VALUE D : "<<d<<endl;
    }
};

int main()
{
    base *bptr;
    base bp;
    bptr=&bp;

    bptr->b=20;
    bptr->display();

    derived dp;
    bptr=&dp;
    bptr->b=100;
    bptr->display();

   /*
    bptr->d=100;
    bptr->display();

    IT WON'T WORKS AS WE CANNOT DIRECTLY ACCESS DERIVED CLASS OWN CLASS MEMBERS WITH THE HELP OF 
    BASE CLASS POINTER ... YES , WE CAN ACCESS ONLY INHERITED MEMEBERS OF DERIVED CLASS
*/
    derived *dptr=&dp;
    dptr->d=200;
    dptr->display();
    ((derived *)bptr)->d=201;
    ((derived *)bptr)->display();
}

