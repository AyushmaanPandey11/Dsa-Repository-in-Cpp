#include<iostream>
using namespace std;
bool binarySearch( int *arr, int start, int end , int key)
{
    // base class
    if( start > end)
    {
        return 0;
    }
    int mid = start + ( end - start)/2;
    // elemment found 
    if( arr[mid] == key)
    {
        return 1;
    }
    // element is not found

    // key < arr[mid], will move to left part ie end = mid -1
    if( arr[mid] > key)
    {
        return binarySearch(arr, start, mid -1, key );
    }
    // key > arr[mid], will move to the right part ie start = mid +1
    else
    {
        binarySearch(arr, mid+1, end, key);
    }
    return 1;
}
int main()
{
    int arr[6] = { 4 , 6 ,12, 25 ,50, 70 };
    cout<<" Element is present(1) or absent(0) : "<< binarySearch(arr,0, 5, 50);
    return 0;
}