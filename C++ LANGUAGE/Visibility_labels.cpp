#include<iostream>
using namespace std;

/*HERE WE ARE GOING TO DISCUSS ABOUT ALL THREE VISIBILITY LABELS
AND THEIR TRANSFORMATION DURING DERIVATION/INHERITANCE
VISIBILITY LABELS :
1) PUBLIC :
2) PROTECTED :
3) PRIVATE :*/

class ak
{
    //BY DEFAULT PRIVATE...
    int data;
    public:
    void getdata()
    {
        cout<<"ENTER THE DATA FOR THE CURRENT INHERITANCE : ";
        cin>>this->data;
    }
    void putdata()
    {
        cout<<"DATA : ";
        cout<<this->data<<endl;
    }
};

class gk:ak{
    //HERE DURING INHERITANCE VISIBILITY LABEL IS OPTIONAL
    //BY DEFAULT IT'S PRIVATE...
    //gk class is inherited class from ak privately..
    /* WE CANNOT ACCESS MEMBER FUNCTIONS OF THE BASE CLASS THAT
    PRIVATELY INHERITED IN MY PROGRAM...HENCE SUCH SUBCLASS IS
    USELESS..BUT YEAH WITH THE HELP OF EXTENDED MEMBER FUNCTIONS 
    OF THE SUBCLASS WE CAN ACCESS THE PRIVATE MEMBER FUNCTIONS OF
    THE DERIVED CLASS , NOW LET'S SEE.....*/
    public:
    void getd()
    {
        getdata(); //IT ALSO INDIRECTLY ABLE TO ACCESS PRIVATE MEMBERS OF THE BASE CLASS...WHICH ARE NOT INHERITED IN MY SUBCLASS..
    }
    void putd()
    {
        putdata();
    }
};

class mk:public ak{
    //PUBLICALLY INHERITED CLASS FROM BASE CLASS "ak"
    /*HERE WE CAN DIRECTLY ACCESS PUBLIC MEMBER FUNCTIONS
    OF BASE CLASS AS THAT WERE INHERITED PUBLICALLY... */
};

int main(){
    ak obj1;
    gk obj2;
    mk obj3;
    cout<<"BASE CLASS MEMBER FUNCTIONS : "<<endl;
    obj1.getdata();
    obj1.putdata();
    cout<<"DERIVED CLASS MEMBER FUNCTIONS : "<<endl;
    obj2.getd();
    obj2.putd();
    cout<<"DERIVED CLASS MEMBER FUNCTIONS : "<<endl;
    obj3.getdata();
    obj3.putdata();
    return 0;
}