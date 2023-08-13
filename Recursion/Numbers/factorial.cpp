#include<iostream>
using namespace std;

int factorial(int n)
{   
    // base case
    if( n == 0 )
        return 1;
    // recursive function
    int ans = n * factorial( n -1 );
    return ans;
}

int main()
{
    int number ;
    cin>>number;
    cout<<"the factorial of the number is "<<factorial(number);
    return 0;
}