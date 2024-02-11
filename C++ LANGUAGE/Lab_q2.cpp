#include<iostream>
using namespace std;

class pk
{
    int data1;
    int data2;
    pk(int a,int b)
    {
        this->data1=a;
        this->data2=b;
    }
    public:
    pk(int a)
    {
        this->data1=a;
    }
};

int main()
{
    pk obj(3);
}
