/* CONSTRUCTORS ARE SPECIAL MEMBER FUNCTIONS THAT ARE USED TO 
INITIATE THE OBJECTS WITH SOME INITIAL VALUES TO THEIR MEMBER 
VARIABLES...THEY DON'T HAVE ANY RETURN TYPE NOT EVEN VOID...
THERE ARE GENERALLY TWO TYPES OF CONSTRUCTORS :
DEFAULT CONSTRUCTORS(NON-PARAMETERISED)
PARAMETERISED CONSTRUCTORS */

#include<iostream>
using namespace std;
//WHEN WE USE MORE THAN ONE CONSTRUCTOR IN THE SAME CLASS THEN IT IS CALLED AS CONSTRUCTOR OVERLOADING...
/*COPY CONSTUCTOR : WHEN WE INITALIZE THE OBJECT DATA MEMBERS
 WITH THE VALUES OF DATA-MEMBERS  OF THE OBJECT PASSED BY REFERENCE 
 TO THE CONSTRUCTOR IS KNOWN AS COPY CONSTRUCTOR....*/
class ak
{
    int a,b;
    public :
    ak() // Inline default constructor....
    {
        this->a=0;
        this->b=0;
    }
    ak(int a,int b)
    {
        this->a=a;
        this->b=b;

    }
    void display()
    {
        cout<<"POINT : "<<"("<<a<<","<<b<<")"<<endl;
    }
};
/* GENERALLY , IT IS NOT PREFFERED TO USE DEFAULT AND DEFAULT 
ARGUMENT CONSTRUCTORS IN THE SAME CLASS AS IT WILL PRODUCES
AMBIGUITY IN THE PROGRAM */
int main()
{
    ak obj1; //AUTOMATICALLY INVOKES DEFAULT CONSTRUCTOR TO INITIALIZE ITT...
    obj1.display();
    ak obj2(4,7);
    
    obj2.display(); //IT CALLS THE PARAMETERISED CONSTRUCTOR...
    return 0;
}