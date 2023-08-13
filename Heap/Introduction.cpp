#include<iostream>
using namespace std;
 
int Sumof( int* arr, int size)
{
    int sum = 0 ;
    for( int idx=0 ; idx < size ; idx++)
    {
        sum += arr[idx];
    }
    return sum;
}

int main()
{      
    int size; 
    cin>> size;
    int* arr = new int[size];
    for( int idx = 0 ; idx < size ; idx++ )
    {
        cin>> arr[idx];
    }
    
    int answer = Sumof(arr, size);
    cout<< " the sum of the all values is " << answer;

    return 0;
}