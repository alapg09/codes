#include<iostream>
using namespace std;


//using loops for first n terms
int main()
{
    int first=0,second=1,next, number;

    cout<<"How many terms of Fibonacci Sequence do you want to print? "<<endl;
    cin>>number;
    cout<<"The Fibonacci Sequence till "<<number<<" terms is: "<<endl;
    for(int i = 0; i<number; i++)
    {
        cout<<first<<", ";
        next = first + second;
        first = second;
        second = next;

    } 
 return 0 ;
 }



//using recursive function for nth term


// int fib(int n){
//     if(n<3){
//         return 1;
//     }
//     return fib(n-2) + fib(n-1);
// }

// int main()
// {
//     int a;
//     cout<<"Enter a number"<<endl;
//     cin>>a;
//     cout<<"The term in fibonacci sequence at position "<<a<< " is "<<fib(a)<<endl;
//     return 0;
  
// }

















