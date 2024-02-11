#include<iostream>
using namespace std;

class ak
{
    private:
    int rno;
    float marks;
    public:
    void getdata(int a,float b)
    {
        this->rno=a;
        this->marks=b;
    }
    void display()
    {
        cout<<"RNO : "<<this->rno<<endl;
        cout<<"MARKS : "<<this->marks<<endl;
    }
};

int main()
{
    ak *ptr=new ak; //WE HAVE CREATED AN OBJECT AT RUNTIME USING NEW KEYWORD...
    ptr->getdata(10,90.2);
    ptr->display();

    /* HERE WE HAVE CREATED AN ARRAY OF OBJECTS USING POINTERS....*/
    ak *arr_ptr=new ak[5];
    int a;
    float b;
    cout<<"ENTER DETAILS FOR 5 STUDENTS : \n\n";
    for(int i=0;i<5;i++)
    {
        cout<<"ENTER DETAILS FOR "<<i+1<<" STUDENT :"<<endl;
        cout<<"ENTER RNO AND MARKS : ";
        cin>>a>>b;
        (arr_ptr[i]).getdata(a,b);
    }
    for(int i=0;i<5;i++)
    {
        cout<<"DETAILS FOR "<<i+1<<" STUDENT :"<<endl;
        arr_ptr[i].display();
    }
    return 0;
}