#include<iostream>
using namespace std;

class rno
{
    protected:
    int rno;
    public:
    void getrno(int a)
    {
        this->rno=a;
    }
    void putrno(void)
    {
        cout<<"RNO : "<<this->rno;
    }

};

class marks:public rno //1st level of inheritance....
{
    protected:
    int m1;
    int m2;
    public:
    void getmarks(int a,int b)
    {
        this->m1=a;
        this->m2=b;
    }
    void putmarks(void)
    {
        cout<<"MARKS 1 : "<<m1<<endl;
        cout<<"MARKS 2 : "<<m2;
    }

};

class result:public marks{
     //2nd level of inheritance 
     protected:
     int result;
     public:
     void Display()
     {
        int total=m1+m2;
        putrno();
        putmarks();
        cout<<"TOTAL MARKS OBTAINED : "<<total<<endl;
     }
};

int main()
{
    result A;
    A.getrno(05);
    A.getmarks(90,100);
    A.Display();
    return 0;
}