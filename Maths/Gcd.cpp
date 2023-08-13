#include<iostream>
using namespace std;
int GreatestCommonDivisor( int num1 , int num2)
{
    if( num1 == 0 )
    {
        return num2;
    }
    if( num2 == 0)
    {
        return num1;
    }
    while ( num1 != num2)
    {
        if( num1 > num2)
        {
            num1 = num1 - num2;
        }
        else 
        {
            num2 = num2 - num1;
        }
    }
    return num1;
}
int main()
{
    int num1 , num2 = 0;
    cin>> num1 >> num2;
    cout<< "the gcd of the two numbers is " << GreatestCommonDivisor(num1, num2);
    return 0;
}