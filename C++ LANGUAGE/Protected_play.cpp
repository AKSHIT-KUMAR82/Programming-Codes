#include<iostream>
using namespace std;

/*IN ALL THE ABOVE DERIVATION WE HAD SEEN THAT PRIVATE MEMBERS
ARE NOT INHERITED IN THE CORRESPONDING SUBCLASS/DERIVED CLASS...
SO HERE IS AN WAY SO THAT PRIVATE MEMBERS BECOMES INHERITABLE 
IN THE SUBCLASS...BY USING PROTECTED VISIBILTY LABEL WHICH IS
MOST LIKELY PRIVATE BUT WE CAN INHERIT THESE MEMBERS..
LET'S SEE : */

class ak
{
    private :
    int data1;
    protected :
    int data2;
    public:
    void getdata1()
    {
        this->data1=12;
    }
    void putdata1()
    {
        cout<<"DATA1 : "<<data1<<endl;
    } 
    void getdata2()
    {
        this->data2=16;
    }
    void putdata2()
    {
        cout<<"DATA2 : "<<data1<<endl;
    } 
};

class pk:public ak{
    int cal1() //MEMBER FUNCTION OF THE SUBCLASS/DERIVED CLASS..
    {
        return (2*(this->data2));
        //HERE WE ARE ABLE TO ACCESS THE PROTECTED DATA MEMBERS OF THE BASE CLASS WITHIN THE MEMBER FUNCTION OF ITS DERIVED CLASS...
    }
    /*
    int cal2()
    {
        return (2*(this->data1));
        : HERE WE ARE UNABLE TO ACCESS THE PRIVATE MEMBERS OF THE BASE CLASS WITHIN THE DERIVED CLASS...
    }*/
};

int main()
{
    pk obj1;
    /*
    obj1.data1; //PRIVATE MEMBERS ARE NOT INHERITABLE...
    obj1.data2; //PROTECTED MEMBERS ARE INHERITABLE THAT'S THE ONLY DIFFERNEC...
    */
    return 0;
}