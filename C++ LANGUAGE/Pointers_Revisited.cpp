#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

int main()
{
    /*BASIC INTRODUCTION TO POINTERS OR SOME RUDIMENTS OF POINTERS....*/

    /*
    int *ptr1,*ptr2,a,b;
    a=4;
    b=9;
    ptr1=&a; //POINTER PTR1 POINTS TO THE PHYSICAL ADDRESS OF VARIABLE a.....
    ptr2=&b; //POINTER PTR2 POINTS TO THE PHYSICAL ADDRESS OF VARIABLE b.....

    // HERE WE USED DYNAMIC POINTERS , IT MEANS THAT THESE POINTERS CAN REFER TO ANY MEMORY ADDRESS AT A TIME...
    int **ptr=&ptr1; //POINTER TO POINTER...(DOUBLE POINTER...)
    printf("VALUE OF VARIABLE a : %d,%d,%d\n",a,*ptr1,**ptr);

    ptr=&ptr2;
    printf("VALUE OF VARIABLE b : %d,%d,%d",b,*ptr2,**ptr);
    */

   /* HERE WE GO WITH SOME POINTERS AIRTHMETIC CONCEPTS IN THE ARRAYS...*/
   /*int n;
   cout<<"ENTER THE NUMBER OF ELEMENTS TO BE INSERTED : ";
   cin>>n;
   int arr[n];
   int *ptr=arr;
   for(int i=0;i<n;i++)
   {
    cin>>*(ptr+i);
   }
   cout<<"ELEMENTS OF THE ARRAY ARE AS FOLLOWS : ";
   for(int i=0;i<n;i++)
   {
    cout<<*ptr;
    ptr++;
   }*/

   //HERE , I AM GOING TO SEARCH AN ELEMENT FROM THE ARRAY USING POINTERS

   /*
   int n,key,flag=0;
   cout<<"ENTER THE NUMBER OF ELEMENTS TO BE INSERTED : ";
   cin>>n;
   cout<<"ENTER THE KEY : ";
   cin>>key;
   int arr[n],*ptr=arr;
   for(int i=0;i<n;i++)
   {
    cin>>*(ptr+i);
   }
    for(int i=0;i<n;i++)
   {
    if(key==*(ptr+i))
    {
        flag=1;
    }
   }
   if(flag!=0)
   {
    cout<<"KEY IS PRESENT...\n";
   }
   else{
    cout<<"KEY IS NOT PRESENT...\n";
   }
   */


  //HERE WE WILL DISCUSS ABOUT ARRAY OF POINTERS TO STRINGS IN A GREAT DETAIL...
  /* I WILL CREATE A COLLECTION OF MOVIES...AND ACCONDING TO USER PREFERNCE WE SHOW RESULTS
  WHETHER WE HAVE THAT MOVIE OR NOT...*/

  char *movies[5], str[20];
    cout << "ENTER MOVIES IN THE DATABASE : ";
    for (int i = 0; i < 5; i++)
    {
        movies[i] = (char *)malloc(30);
        cin >> movies[i];
    }
    cout << "ENTER THE MOVIE TO BE SEARCHED : ";
    cin >> str;
    for (int i = 0; i < 5; i++)
    {
        if ((strcmp(str, movies[i])) == 0)
        {
            cout << "MOVIE FOUND...\n";
            break;
        }
        else if (i == 4)
        {
            cout << "MOVIE NOT FOUND...\n";
        }
    }

    /* LEARNINGS IN THIS PARTICULAR PEACE OF CODE : 
    1) STRING LITERAL/CONSTANT WILL ALWAYS STORED IN READ ONLY MEMORY AND CAN'T BE MODIFIED...
    2) YES YOU CAN ACCESS/ASSIGN A STRING LITERAL TO A CHARACTER POINTER BUT CAN'T DO IT FOR
    VARIABLE LENGTH/RUNTIME STRING INPUT....FOR THAT YOU MUST NEED TO ALLOCATE MEMORY FOR IT
    DYNAMICALLY OR ASSIGN IT A ARRAY OF CHARACTER FOR OCCUPYING THAT CONTIGOUS CHUNK OF MEMORY
    BLOCKS
    3) IN C++ YOU CAN'T SPECIFY A RUNTIME LENTH ARRAY , YOU MUST NEED TO SPECIFY A CONSTANT COMPILE
    TIME SIZE ARRAY.....*/

  
  return 0;
}