#include<iostream>
using namespace std;
       
        // 1. Get the pivot element from the array
        // 2. condition 1-  check If the element in the second line having the pivot and put BinarySearch
        //              2-  if not in first line key will be in first element , put binary search 

void display(int arr[],int size)
{   
    cout<<"the given array is ";
    for(int idx=0;idx <= size;idx++)
    {
        cout<<arr[idx]<<" ";
    }
    cout<<endl;
}
int getPivot( int arr[], int size )
{
    int start = 0;
    int end = size - 1;
    int mid = start + ( end - start )/2;

    while( start < end )
    {
        if( arr[mid] >= arr[0] )
        {
            start = mid + 1;
        }
        else 
        {
            end = mid; 
        }
        mid = start + (end - start)/2;
    }
    return arr[start];
}
int binarySearch(int arr[], int start, int end , int key)
{
    int mid=start+(end-start)/2;
    while(start<=end)
    {
        if(arr[mid]==key)
        {
            return 1;
        }
        if(key>=arr[mid])
        {
            start=mid+1;
        }
        else 
        {
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}
int SearchinSortedRotatedArray(int arr[], int size, int key)
{   
    int pivot = getPivot(arr,size);
    // condition for the second line having the pivot element
    if( key >= arr[pivot]  && key <= arr[size-1]  )
    {
        return binarySearch(arr,pivot,size-1,key);
    }
    // condition for the first line 
    else 
    {
        return binarySearch(arr,0,pivot-1,key);
    }
}
int main()
{
    int arr[5] = { 9, 7 , 1 , 2 ,3};
    int size = sizeof(arr)/5;
    display(arr,size);
    cout << " element is "<< SearchinSortedRotatedArray(arr,size,5);
    return 0;
}