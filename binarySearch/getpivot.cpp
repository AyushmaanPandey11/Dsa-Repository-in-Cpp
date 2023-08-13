#include<iostream>
using namespace std;
void display(int arr[],int size) 
{   
    cout<<"the given array is ";
    for(int idx=0; idx <= size ; idx++ )
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
int main()
{
    int arr[5] = {7,9,1,2,3};
    int size = sizeof(arr)/5;
    display(arr,size);
    cout << "The pivot element in the array is "<<getPivot(arr,size);
    return 0;
    
}