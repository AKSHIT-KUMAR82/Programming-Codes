#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

class SumCal
{
    public: //Visibility label...
    //Multiple Member Functions....
    int sum(int a,int b)
    {
        return (a+b);
    }
    double sum(double a,double b)
    {
        return (a+b);
    }

    template <typename T>
    void show(T result)
    {
        cout<<"SUM : "<<result;
    }

};

int main()
{
    SumCal obj1;
    SumCal obj2;
    int a=obj1.sum(10,15);
    float b=obj2.sum(10.0,15.0);
    obj1.show(a);
    obj2.show(b);

}

