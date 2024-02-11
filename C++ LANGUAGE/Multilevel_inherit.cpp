/*SO,HERE WE ARE GOING TO DISCUSS MULTILEVEL INHERITANCE
WHERE WE INHERITS A CLASS FROM ANY OTHER DERIVED CLASS...
BASE CLASS--->INTERMEDIATE BASE CLASS--->DERIVED CLASS 
(AKSHIT)--->(NISCHAY)-->(SWAPNIL)*/

/*HERE AN EXAMPLE OF MULTILEVEL INHERITANCE ARE AS FOLLOWS : */

#include<iostream>
using namespace std;
class ak //BASE/PARENT CLASS...
{
    protected:
    int rno;
    public:
    void getid(int a)
    {
        this->rno=a;
    }
    void putid()
    {
        cout<<"RNO : "<<this->rno<<endl;
    }  
};

class pk:public ak{ //INTERMEDIATE BASE CLASS
    protected:
    float sub1;
    float sub2;
    public:
    void getmarks(int a,int b)
    {
        this->sub1=a;
        this->sub2=b;
    }
    void getmarks()
    {
        cout<<"SUB1 MARKS : "<<this->sub1<<endl;
        cout<<"SUB2 MARKS : "<<this->sub2<<endl;
    }
};

class stu:public pk{
    protected :
    float result;
    public:
    void getresult()
    {
        this->result=sub1+sub2;
    }
    void display()
    {
        putid();
        getmarks();
        cout<<"RESULT : "<<this->result<<endl;
    }
};

//HERE ABOVE WE HAVE DID MULTILEVEL INHERITANCE/DERIVATION...
int main()
{
    stu obj1;
    obj1.getid(101);
    obj1.getmarks(20,40);
    obj1.getresult();
    obj1.display();
    return 0;
}

