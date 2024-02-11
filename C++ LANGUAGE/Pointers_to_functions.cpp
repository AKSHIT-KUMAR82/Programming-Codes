#include <iostream>
using namespace std;

/* POINTERS TO FUNCTIONS...*/
/* YOU CAN'T DEFINE A FUNCTION IN THE MAIN FUNCTION...*/

/* MAIN USES OF THIS CONCEPT : 
1) IT IS USED FOR PASSING A FUNCTION AS AN ARGUMENT TO OTHER FUNCTIONS...
2) TO CALL FUNCTION DYNAMICALLY OR AT RUN TIME....
*/

//HERE THERE IS NO NEED TO USE & OPERATOR FOR PASSING ADDRESS TO FUNCTION POINTERS....

int sum(int a, int b)
{
    return (a + b);
}

int subtract(int a, int b)
{
    return (a-b);
}

int main()
{
    int (*funptr)(int ,int);
    funptr=sum;
    cout<<"SUM : "<<funptr(4,7)<<endl;
    funptr=subtract;
    cout<<"SUBTRACT : "<<funptr(10,7);
    return 0;
}