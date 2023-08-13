#include<iostream>
using namespace std;
int sqrt(  int number , int start, int end )
{
    long long int ans = -1;
    // base case
    if( start > end )
        return -1;
    if( number < 0 )
        return -1;
    int mid = start + ( end - start )/2;
    long long int square = mid*mid;
    // element found 
    if( square == number )
    {
        return ans = mid;
    }
    // element not found
    else if( square < number )
    {
        ans = mid;
        return sqrt(number, mid+1, end);
    }
    else // square > number ie mid*mid > number 
    {
        return sqrt(number, start, mid -1);
    }
    return ans;
}

int main()
{
    int number = 36;
    cout<<"the sqrt of the number is "<<sqrt(number,0, number - 1 );
    return 0;
}