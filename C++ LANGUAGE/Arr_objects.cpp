#include<iostream>
using namespace std;

class employee
{
    private :
    char name[20];
    int age;
    public:
    void getdata();
    void putdata();
};

void employee::getdata()
{
    cout<<"ENTER NAME OF THE EMPLOYEE : "<<endl;
    cin>>this->name;
    cout<<"ENTER AGE : ";
    cin>>this->age;
}

void employee::putdata()
{
    cout<<"NAME : "<<this->name<<endl<<"AGE : "<<this->age<<endl;
}

int main()
{
    int n;
    cout<<"ENTER THE NUMBER OF EMPLOYEES : ";
    cin>>n;
    employee employee[n];
    for(int i=0;i<n;i++)
    {
        cout<<"ENTER INFO FOR "<<i+1<<" EMPLOYEE : "<<endl ;
        employee[i].getdata();
    }
    cout<<"INFORMATION OF EMPLOYEES ARE AS FOLLOWS : \n";
    for(int i=0;i<n;i++)
    {
        employee[i].putdata();
    }
    return 0;
}