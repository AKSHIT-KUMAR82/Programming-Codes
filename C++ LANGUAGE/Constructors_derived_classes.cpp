#include<iostream>
using namespace std;

class stu
{
    protected:
    int rno;
    public:
    stu(int a)
    {
        this->rno=a;
    }
    void showrno()
    {
        cout<<"RNO : "<<this->rno<<endl;
    }
};

class marks
{
    protected:
    int sub1;
    int sub2;
    public:
    marks(int a,int b)
    {
        this->sub1=a;
        this->sub2=b;
    }
    void showmarks()
    {
        cout<<"SUB1 MARKS : "<<sub1<<endl;
        cout<<"SUB2 MARKS : "<<sub2<<endl;
    }
};

class result:public stu,public marks{ 
    protected:
    int res;
    public:
    void display()
    {
        res=sub1+sub2;
        showrno();
        showmarks();
        cout<<"RESULT : "<<res<<endl;
    }
    result(int a,int b,int c):
    stu(a),
    marks(b,c)
    {
        ;
    }
};

/* HERE WE ARE DISCUSSING ABOUT CONSTRUCTORS IN DERIVED CLASSES FROM THEIR BASE CLASSES
SO, ITS NOT MANDATORY FOR US TO DEFINE ANY CONSTRUCTOR IN DERVIED CLASSES AS LONG AS THERE IS 
NOT ANY PARAMETERISED CONSTRUCTOR IN THE BASE <<CLASS... */

/* HERE NO MATTER IN WHICH ORDER YOU ARE CALLING CONSTRUCTOR OF BASE CLASSES , IT WILL BE 
CONSTRUCTED IN THE SAME ORDER AS IN THE DERIVED CLASS DECALARATION THEN DERIVED CLASS CONSTRUCTOR
WILL BE CALLED ACCONDINGLY...
IN CASE OF VIRTUAL BASE CLASSES THEIR CONSTRUCTOR WILL BE CALLED BEFORE ANY NON-VIRTUAL CONSTRUCTOR
*/

/* NOW, IN C++ INITILISATION OF BASE CLASSES ARE AS FOLLOWS IN DERIVED CLASS CONSTRUCTOR :
>>>> BY PROVIDING AN ARGUMENT LIST FOR INTIALISING BASE CLASSES FOLLOWED BY RESPECTIVE BASE
CLASSES CONSTRUCTOR CALLS OR IT'S RESPECTIVE DATA MEMBER INITIALISATION......

FORMAT :
DERIVED_CONSTRUCTOR(argument list): BASE CONSTRUCTOR CALLS,DATA_MEMBER(ARGUMENT LIST VALUE)
{
    //INITIALISATION OF IT'S OWN DATA MEMBERS OR LEAVE AS IT IS.....
}
*/


int main()
{
    int i,j,k;
    cout<<"ENTER RNO : ";
    cin>>i;
    cout<<"ENTER SUB1 AND SUB2 MARKS : "<<endl;
    cin>>j>>k;
    result obj(i,j,k);
    obj.display();
    return 0;
}