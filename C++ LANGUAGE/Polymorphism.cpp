#include<iostream>
using namespace std;

class base
{
    int data;
    public:
    void getdata(int val)
    {
        data=val;
    }
    void show()
    {
        cout<<"DATA : "<<data<<endl;
    }
};

class subclass:public base{
    int val;
    public :
    void getdata(int val) //FUNCTION OVERRIDING...
    {
        this->val=val;
    }
    void show() //FUNCTION OVERRIDING...
    {
        cout<<"VALUE : "<<val<<endl;
    }
};

/* FUNCTION OVERRIDING : IT'S A PROCESS WHEN WE REDEFINE A BASE CLASS FUNCTION IN IT'S CORRESPONDING
SUBCLASSES/INHERITED CLASSES....*/

int main()
{
    subclass obj;
    obj.getdata(20);
    obj.show();

    /* HERE WE DID COMPILE TIME POLYMORPHISM WHICH IS ACHIEVED BY FUNCTION OVERLOADING AND OPERATOR OVERLOADING
    IN THIS POLYMORPHISM , WE HAVE SEEN THAT NO AMBIGUITY ARRISES WHILE CALLING A PARTICULAR FUNCTION 
    AT COMPILE TIME .... A PARTICULAR FUNCTION CALL LINKED TO A SPECIFIC FUNCTION WITHOUT ANY
    AMBIGUITY....*/

    obj.base::getdata(20);
    obj.base::show();
    return 0;
}
/* RUNTIME POLYMORPHISM IS ACHIEVED USING VIRTUAL FUNCTIONS FOR THAT WE SHOULD NEED TO LEARN POINTERS TO DERIVED CLASSES...*/