#include<iostream>
using namespace std;
/* 
THE MAIN DIFF BETWEEN REFERENCES AND POINTERS ARE AS FOLLOWS : 
POINTERS CAN BE NULL BUT REFERENCES CANNOT BE...
POINTERS ARE REPRESENTED BY * WHILE REFERENCES BY &...
POINTERS CAN HAVE DIFF ADDRESSES BUT REFERENCES ONCE INTIALIZED WITH ANY OBJ 
THEN CANNOT BE CHANGED...
POINTERS MAY OR MAY NOT BE INTIALIZED BUT REFERNCES MUST BE INTIALIZED BY ANY 
REFERENCE...
IN REFERENCES THEIR IS NO NEED OF DEFRENCING YOU JUST ACCESS MEMBERS BY . OPERATOR WHILE
IN POINTERS WE NEED *(DEFRENCING OPERATOR) TO ACCESS OR MANIPULATE THE VALUES... 
*/
class hello1
{
    int val;
    public:
    hello1(int a)
    {
        this->val=a;
    }
    void change1(hello1 &obj1)
    {
        obj1.val=val;
    }

    void change2(hello1 *obj1){
        obj1->val=val;
    }

    void display()
    {
        cout<<this->val;

    }
};

int main()
{
    hello1 obj1(10),obj2(20),obj3(100);
    cout<<"ORIGINAL VALUES :"<<endl<<"OBJ1 : ";
    obj1.display();
    cout<<endl<<"OBJ2 : ";
    obj2.display();
    obj1.change1(obj2);
    obj3.change2(&obj1);
    cout<<"\nCHANGED VALUES :"<<endl<<"OBJ1 : ";
    obj1.display();
    cout<<endl<<"OBJ2 : ";
    obj2.display();

}