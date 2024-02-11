#include<iostream>
#include<cstring>
using namespace std;

/* IF THERE IS NO DEFAULT CONSTRUCTOR IN THE CLASS BUT HAS PARAMETRISED CONSTRUCTOR 
THEN IT'S MADATORY TO PASS VALUES TO THE OBJECT DURING IT'S DECLARATION ELSE COMPILER WILL NOT
CREATE THE OBJECT SO TO AVOID THIS WE CAN DEFINE A DO-NOTHING CONSTRUCOR ONLY TO SATISFY
COMPILER */


class ak{
    private :
    int data;
    public:
    ak()
    {
      //DO NOTHING CONSTRUCTOR
      ;
    }
    ak(int a){ //PARAMETERISED CONSTRUCTOR...
        this->data=a;
    }
    void display()
    {
        cout<<"DATA VALUE : "<<this->data<<endl;
    }
};

int main()
{ 
    ak obj;
    ak *ptr=&obj;
    ptr->display();
    return 0;
}