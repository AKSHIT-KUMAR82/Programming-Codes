#include<iostream>
using namespace std;

class count
{
    static int val;
    public:
    count()
    {
        val++;
    }
    int getcount()
    {
        return (this->val); 
    }
};
int count::val; /*THIS WILL PROVIDE A SEPERATE MEMORY ASSOCIATED WITH CLASS RATHER
THAN FOR EACH OBJECT */

int main()
{
    count obj1,obj2,obj3,obj4;
    cout<<"NUMBER OF OBJECTS CREATED : "<<obj1.getcount();
    return 0;
}