#include<iostream>
using namespace std;

int fib( int number )
{   
    // the base cases 
    if( number ==0 )
        return 0;
    if( number == 1 )
        return 1;

    // the recursive relation 
    int ans = fib( number -1 ) + fib( number -2 );
    return ans;
}

int main()
{
    int number;
    cout<<"Enter the nth fibonacci number to find "<<endl;
    cin>> number;
    cout<< "the nth fibonacci number is "<<fib(number);
    return 0;
}