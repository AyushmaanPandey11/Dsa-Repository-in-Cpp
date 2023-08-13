#include<iostream>
using namespace std;
int PeakElement( int arr[], int start , int end)
{
    // base case 
    if( start > end )
        return -1;
    int mid = start + ( end -start )/2;
    int ans = -1;
    // gives the answer, when the start and end will be same 
    if ( start == end )
        return arr[start];
    // left side of the peak element will satisfy this condition
    else if( arr[mid+1] > arr[mid])
    {   
        return PeakElement(arr, mid+1, end);
    }
    // right side of the peak element. arr[mid]> arr[mid+1]
    else
    {   
        return PeakElement(arr, start, mid);   
    }
}
int main()
{
    int arr[8] = { 3,4,5,9,8,6,2,1 };
    cout<<"Peak element the array is "<<PeakElement(arr,0,8);
    return 0;
}