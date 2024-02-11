#include<iostream>
#include<string.h>

using namespace std;

class ak{
    private:
    char *ptr;
    public:
    void set(char str[])
    {
        ptr=new char[strlen(str)+1];
        strcpy(ptr,str);
    }
    void display()
    {
        cout<<"CITY NAME : "<<ptr<<endl;
    }
};

/*..............HERE WE HAVE DISCUSSED ABOUT THE ARRAY OF POINTERS TO OBJECTS AND WHY IT IS NEEDED..
SO ACTUALLY WHEN A CLASS IS CONSTANT MEANS ALL THE OBJECTS OF THAT CLASS TYPE WILL
BE OF THE SAME SIZE BUT IF THERE IS ANY CLASS EXISTS IN WHICH WE HAVE SOME CHARACTER 
STRINGS AND BASED ON IT'S SIZE OF SOMETHING , IT'S DATA MEMBER SIZE WILL BE DECIDED 
AT THE RUN TIME SO THERE WE NEED THE CONCEPT OF ARRAY OF POINTERS TO OBJECTS FOR 
POINTING INDIVISUAL OBJECTS OF DIFFERENT SIZES..............*/


int main()
{
    ak *ptr_arr[5];
    char city[100];
    for(int i=0;i<5;i++)
    {
        cout<<"ENTER CITY : ";
        cin>>city;
        ptr_arr[i]=new ak;
        ptr_arr[i]->set(city);
    }
    cout<<"CITIES LIST : "<<endl;
    for(int i=0;i<5;i++)
    {
        ptr_arr[i]->display();
    }
    return 0;
}