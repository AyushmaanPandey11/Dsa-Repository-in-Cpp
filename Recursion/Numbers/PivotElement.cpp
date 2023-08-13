#include<iostream>
using namespace std;
int getpivot( int arr[], int start, int end)
{   
    // base case
    if ( start > end)
        return -1;
    // element found
    int mid = start + ( end - start)/2; 
    if(start == end)
    {
        return arr[end];
    }
    // element not found
    if( arr[mid] >= arr[0])
    {
        return getpivot( arr, mid+1 , end);
    }
    else        // arr[mid] <= arr[0]
    {
        return getpivot( arr, start, mid);
    }
}
int main()
{
    int arr[5] = {7,9,1,2,3};
    cout << "The pivot element in the array is "<<getpivot( arr , 0 , 4 );
    return 0;
}