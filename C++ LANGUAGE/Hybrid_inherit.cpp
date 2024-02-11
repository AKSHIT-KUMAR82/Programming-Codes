#include<iostream>
using namespace std;
/*NOW WHEN WE COMBINE TWO OR MORE TYPE OF INHERITANCE IN THE 
DESIGN OF ANY PROGRAM THEN THAT INHERITANCE IS CALLED HYBRID 
INHERITANCE...*/

/* THIS CAN BE ILLUSTRATED BY A SIMPLE EXAMPLE AS FOLLOWS : */
class stu
{
    protected :
    int rno;
    public:
    void getrno(int a)
    {
        rno=a;
    }
    void putrno()
    {
        cout<<"RNO : "<<rno<<endl;
    }
};

class marks:public stu
{
    protected:
    int sub1,sub2;
    public:
    void getmarks(int a,int b)
    {
        sub1=a;
        sub2=b;
    }
    void putmarks()
    {
        cout<<"SUB1 MARKS : "<<sub1<<endl;
        cout<<"SUB2 MARKS : "<<sub2<<endl;
    }

};

class sports
{
    protected:
    int sports;
    public:
    void getsports(int a)
    {
        sports=a;
    }
    void putsports()
    {
        cout<<"SPORTS WEIGHTAGE : "<<sports<<endl;
    }

};

class result:public marks,public sports
{
    private:
    int result;
    public:
    void display()
    {
        putrno();
        putmarks();
        putsports();
        result=sub1+sub2+sports;
        cout<<"RESULT SCORE OUT OF 300 : "<<result;
    }
};

int main()
{
    result obj;
    obj.getrno(05);
    obj.getmarks(80,90);
    obj.getsports(50);
    obj.display();
    return 0;
}