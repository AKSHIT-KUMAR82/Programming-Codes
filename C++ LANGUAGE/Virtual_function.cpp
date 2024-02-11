#include <iostream>
using namespace std;

/* HERE , WE ARE GOING TO DISCUSS ABOUT THE VIRTUAL FUNCTION ??
 SO, WHAT IS VIRTUAL FUNCTION IN C++ :

 VIRTUAL FUNCTION ARE USED TO ACHIEVE RUNTIME POLYMORPHISM / LATE BINDING...
 WITH THE HELP OF VIRTUAL FUNCTION , A BASE CLASS POINTER CAN CALLS OF VIRTUAL FUNCTION
 OVERRIDEN FUNCTION IN A DERIVED CLASS....

 BY USING VIRTUAL FUNCTION , COMPILER CALLS THE MEMBER FUNCTION OF THAT CLASS WHICH THE POINTERS
 POINTING RATHER THAN THE FUNCTION OF BASE CLASS WHICH IS THE TYPE OF THE POINTERS
 OPENS A GATEWAY FOR EARLY BINDING...*/

 class shape
 {
    public:
    virtual void display()
    {
        cout<<"THIS IS BASE CLASS..."<<endl;
    }

 };

 class circle : public shape{
    public:
    void display()
    {
        cout<<"THIS IS CIRCLE SHAPE..."<<endl;
    }
 };

 class square : public shape{
    public:
    void display()
    {
        cout<<"THIS IS SQAURE SHAPE..."<<endl;
    }
 };

 int main()
 {
    shape *ptr,b;
    ptr=&b;
    ptr->display();
    circle c;
    square s;
    ptr=&c;
    ptr->display();
    ptr=&s;
    ptr->display();
 }

 