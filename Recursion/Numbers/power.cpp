#include<iostream>
using namespace std;
int power ( int base, int pow)
{
    // base case
    if( pow == 0)
        return 1;
    if( pow ==1 )
        return base;
    // recursive call 
    int ans = power( base, pow/2);
    // after the recursion
    // if the pow is odd
    if ( pow&1 )
    {
        return ans*ans;
    }
    // if power is even
    else
    {
        return base*ans*ans;
    }
    return ans;
}
int main()
{
    cout<< "power of 2 power 10 is "<<power(2,5);
    return 0;
}