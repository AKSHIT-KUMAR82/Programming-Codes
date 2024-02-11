#include<iostream>
using namespace std;

class ak
{
    private:
    int rno;
    float marks;
    public:
    void getdata(int a,float b)
    {
        this->rno=a;
        this->marks=b;
    }
    void display()
    {
        cout<<"RNO : "<<this->rno<<endl;
        cout<<"MARKS : "<<this->marks<<endl;
    }
};

/* . OPERATOR HAS MORE PRECENDANCE THAN ( *,-> ) OPERATOR.... */

int main()
{
    ak obj;
    ak *ptr=&obj; //POINTER TO OBJECT...
    ptr->getdata(5,100);
    ptr->display();

    ak *ptr1=new ak; //DYNAMIC MEMORY ALLOCATION FOR POINTERS TO OBJECTS USING "NEW" KEYWORD...
    ptr1->getdata(7,80.0);
    ptr1->display();
    return 0;
}