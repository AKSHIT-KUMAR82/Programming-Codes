#include<iostream>

using namespace std;

class nischay
{
    int val;
    public:
    int operator <(nischay obj2)
    {
        return (val<obj2.val);
    }
    nischay(int a)
    {
        this->val=a;
    }
};

int main()
{
    nischay obj1(20),obj2(30);
    if(obj1<obj2)
    {
        printf("VAL OF OBJ2 IS GREATER THAN OBJ1..\n");
    }
    else{
        printf("VAL OF OBJ2 IS SMALLER THAN OBJ1...\n");
    }
    return 0;
}