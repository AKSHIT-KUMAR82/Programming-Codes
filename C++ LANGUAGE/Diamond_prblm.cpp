#include<iostream>
using namespace std;
/*.....DIAMOND PROBLEM IS SOMETHING WHICH RELATES TO INHERITANCE 
WHEN MANY DIFFERENT INHERITANCE TYPES IS INVOLVED IN INHERITANCE
FOR A DERIVED CLASS WHICH CREATES AMBIGUITY IN THE DERIVED CLASS
HENCE, LEADS TO DIAMOND PROBLM , GENERALLY IT'S ARRISES WHEN
MULTIPLE HIRERARICAL CLASSES COMBINES IN SINGLE DERIVED CLASS
SO IN THIS CASE THAT ANCESTOR BASE CLASS MEMBERS FUNCTIONS 
COMES AS PER NUMBER OF INHERITANCE PATHS WHICH CREATES AMBIGUITY 
HERE VIRTUAL BASE CLASSES CONCEPT ARRISES : .....*/

/*HERE , IN VIRTUAL BASE CLASSES WE MAKE ANCESTOR BASE CLASS AS VIRTUAL BASE CLASS
WHICH ENSURES THAT ONLY ONE INSTANCE OF THAT CLASS WILL BE INHERITED TO DERIVED CLASS
IRRESPECTIVE OF THE HIRERERICAL PATHS....*/

class stu //ANCESTOR BASE CLASS...(VIRTUAL BASE CLASS...)
{
    //GRANDFATHER...
    protected:
    int rno;
    public:
    void setrno(int a)
    {
        this->rno=a;
    }
    void getrno()
    {
        cout<<"RNO : "<<rno<<endl;
    }
};

class marks:public virtual stu
{
    protected:
    int sub1;
    int sub2;
    public:
    void setmarks(int a,int b)
    {
        sub1=a;
        sub2=b;
    }
    void getmarks()
    {
        cout<<"SUB1 AND SUB2 MARKS : "<<sub1<<","<<sub2<<endl;
    }
};

class sports:public virtual stu{
    protected:
    int sports_w;
    public:
    void setsports(int a)
    {
        sports_w=a;
    }
    void getsports()
    {
        cout<<"SPORTS WEIGHTAGE : "<<sports_w;
    }
};

class result:public sports,public marks{
    protected:
    int result;
    public:
    void display()
    {
        result=sub1+sub2+sports_w;
        getrno();
        getmarks();
        getsports();
        cout<<"RESULT : "<<result<<endl;
    }
};

int main()
{
    result obj;
    obj.setrno(12);
    obj.setsports(60);
    obj.setmarks(80,90);
    obj.display();
}
