#include<iostream>
using namespace std;
int sqrt(int number)
{
    int start = 0; 
    int end = number - 1;
    int mid = start + (end - start)/2;
    long long int answer = -1;
    while (start <= end)
    {   
        long long int square = mid*mid;
        // checks if mid square is equal to the number
        if( square == number)
        {
            return mid;
        }
        // mid square is less than number , start is mid+1
        if( square < number)
        {
            answer = mid;
            start = mid +1;

        }
        // mid square is more than number , end is mid -1  
        else
        {
            end = mid -1;
        }
        mid = start + (end - start)/2;
    }
    return answer;
}
double moreprecision( int number, int tempsolution, int precision )
{
    double answer = tempsolution;
    double factor = 1;
    for( int digit = 0 ; digit < precision ; digit++)
    {
        factor = factor/10;
        for( double idx = answer; idx*idx < number ; idx = idx + factor)
        {
            answer = idx;
        }
    }
    return answer;
}
int main()
{
    int number ;
    cout<<"enter a number"<<endl;
    cin >> number;
    cout << " the squareroot is "<<sqrt(number)<<endl;
    cout << " More precise number is "<<moreprecision(number, sqrt(number), 3);
    return 0;
}