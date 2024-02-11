/* SINCE , WE ALL KNOW THAT FOR ANY PARTICULAR CLASS MEMBER FUNCTIONS CAN ONLY ACCESS ITS
PRIVATE MEMBERS BUT WE HAVE A EXCEPTION TO THIS :
WE HAVE FRIEND FUNCTIONS THAT ARE NOT MEMBER FUNCTION BUT NORMAL C++ FUNCTION THAT
CAN ACCESS PRIVATE MEMBERS OF ANY NUMBER OF CLASSES WHERE THESE ARE DECLARED AS FRIEND
USING "FRIEND" KEYWORD.........IT DOESN'T LIE IN THE SCOPE OF ANY CLASS SO DOESN'T ACCESSED
BY USING OBJECTS...*/

#include<iostream>
using namespace std;

class B; //CLASS ""FORWARD DECLARTION""..
class A
{
    int data;
    friend int sum(A obj1,B obj2);
    public: // VISIBILITY LABEL 
    void getdata(int val);
    void putdata();
};

void A::getdata(int val)
{
    this->data=val;
}

void A::putdata()
{
    cout<<"VAL : "<<this->data<<endl;
}

class B
{
    int data;
    public:
    void getdata(int val);
    void putdata();
    friend int sum(A obj1,B obj2);
};

void B::getdata(int val)
{
    this->data=val;
}

void B::putdata()
{
    cout<<"VAL : "<<this->data<<endl;
}

int sum(A obj1,B obj2)
{
    return (obj1.data+obj2.data);
}

int main()
{
    A obj1;
    B obj2;
    obj1.getdata(4);
    obj1.putdata();
    obj2.getdata(10);
    obj2.putdata();
    cout<<"SUM OF THE DATA OF OBJ1 AND OBJ2 : "<<sum(obj1,obj2)<<endl;
    return 0;
}