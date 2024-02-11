/* IN THIS PROGRAM WE WILL SEE HOW TO ENFORCE A FUNCTION INVOKED BY TRY BLOCK TO THROW ONLY
SPECIFIC TYPE OF EXCEPTIONS ONLY AND IF PROGRAM THROW SOME OTHER TYPE OF EXCEPTION THEN
PROGRAM WILL BE TERMINATED ABNORMALLY */
#include <iostream>
using namespace std;

void spec_func(int x) throw(int,float)
//                      THROW LIST CLAUSE TO SPECIFY TYPE....
{
    if (x == 0)
        throw x;
    else if (x == 1)
        throw 'x'; //WHEN THIS EXCEPTION WILL BE THROWN THEN PROGRAM WILL BE TERMINATED ABNORMALLY (CORE DUMPED...)
    else if (x == 2)
        throw (float)x;
    else
        cout<<"NO EXCEPTION IS CAUGHT...\n";
    return;
}

/* IF WE DON'T WANT THAT ANY FUNCTION WILL THROW ANY TYPE OF EXCEPTION THEN WE CAN THE THROW 
CLAUSE LIST EMPTY....*/


int main()
{
    int val;
    cout<<"ENTER VALUE : ";
    cin>>val;
    try
    {
        spec_func(val);
    }
    catch(int val)
    {
        cout<<"INTEGER VALUE CAUGHT...\n";
    }
    catch(float val)
    {
        cout<<"FLOATING VALUE CAUGHT...\n";
    }
    catch(...)
    {
        cout<<"EXCEPTION CAUGHT...GENERIC...\n";
    }
    cout<<"END OF MAIN...\n";
    return 0;
}