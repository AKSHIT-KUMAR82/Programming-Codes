#include<iostream>
using namespace std;

class ak
{
    int val; //THIS IS BY DEFAULT PRIVATE BECAUSE WE HAVE NOT PUT IT UNDER ANY VISIBILITY TAG....
    public:
    ak(int a)
    {
        this->val=a;
    }
    int sum(int val)
    {
        this->val=this->val+val;
        return this->val;
    }
};
/* this-> pointer is created at the instance of any object , it's important to use when we have same name of
data members and paramaters of any member function in order to remove ambiguity....*/
int main()
{
    ak obj1(40);
    cout<<"SUM OF 30 AND OBJ1 : "<<obj1.sum(30)<<endl;
    return 0;
}