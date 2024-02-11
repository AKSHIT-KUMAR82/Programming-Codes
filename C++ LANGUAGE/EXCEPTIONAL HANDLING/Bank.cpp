#include<iostream>
using namespace std;

class excep
{
    public:
    void exception_gen(float val)
    {
        float amount;
        cout<<"ENTER AMOUNT TO BE WITHDRAWN : ";
        cin>>amount;
        try
        {
            if(amount>val)
            {
                throw val;
            }
            cout<<"WITHDRAWN SUCCESSFULLY...\n";
        }
        catch(float val)
        {
            cout<<"LOW BALANCE...."<<endl;
        }
    }
};

class bank:public excep
{
    string name;
    int acc_no;
    float balance;
    public:
    bank(string name,int acc_no,float balance)
    {
        this->name=name;
        this->acc_no=acc_no;
        this->balance=balance;
    }
    void withdraw()
    {
        exception_gen(balance);
    }
};

int main()
{
    bank obj1("AKSHIT KUMAR",2218294,10000.09);
    obj1.withdraw();
    return 0;
}