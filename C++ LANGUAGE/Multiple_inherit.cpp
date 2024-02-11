#include<iostream>
using namespace std;

/* HERE WE WILL DISCUSS MULTIPLE INHERITANCE WHERE A CLASS INHERITS 
TRAITS FROM MULTIPLE CLASSES */

class A
{
    protected :
    int a;
    public:
    void geta(int b)
    {
        this->a=b;
    }
    void puta()
    {
        cout<<"DATA : "<<this->a<<endl;
    }
    void display()
    {
        cout<<"***THIS IS BASE CLASS A***"<<endl;
    }

};

class B
{
    protected :
    int b;
    public:
    void getb(int a)
    {
        this->b=a;
    }
    void putb()
    {
        cout<<"DATA : "<<b<<endl;
    }
    void display()
    {
        cout<<"***THIS IS BASE CLASS B***"<<endl;
    }

};

class C:public A,public B //MULTIPLE INHERITANCE...
{
    protected :
    int data;
    public:
    void cal()
    {
        data=a*b;
    }
    void display()
    {
        puta();
        putb();
        cout<<"PRODUCT OF A AND B CLASSES DATA : "<<data<<endl;
    }
};

int main()
{
    C obj1;
    obj1.geta(12);
    obj1.getb(8);
    obj1.cal();
    obj1.display();
    /*HERE IN MULTIPLE INHERITANCE , WE SEEN SOME AMBIGUITY ISSUES
    ARRISES WHEN SAME MEMBER FUNCTION NAME COMES IN MULTIPLE BASE CLASS
    AS WELL AS IN DERIVED CLASS...
    FOR RESOLVING IT , SOLUTION ARE AS FOLLOWS : */
    obj1.A::display();
    obj1.B::display();
    /*HERE ONE MORE THING WE CAN DO IS : WHEN WE INHERIT A CLASS FROM MULTIPLE BASE
    CLASSES THEN MAY BE THERE CAN BE MULTIPLE BASE CLASSES HAVING SAME MEMBER 
    FUNCTION NAME SO , IN THIS CASE YOU CAN CHOOSE TO WHICH MEMBER FUNCTION 
    YOU WOULD LIKELY TO INHERIT BY DEFINING A SAME MEMBER FUNCTION NAME CONTAINING
    BODY WHICH CALLS MEMBER FUNCTION FROM ANY BASE CLASS USING SCOPE RESOLUTION
    OPERATOR....*/
    return 0;
}