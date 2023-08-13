#include<iostream>
using namespace std;
void SortBubble( int arr[] , int size)
{
    // base case
    if( size == 0 || size == 1 )
        return ;
    // sorting the first round of the array
    for( int idx = 0 ; idx < size-1 ; idx++ )
    {
        if( arr[idx] > arr[idx+1] )
        {
            swap(arr[idx], arr[idx+1]);
        }
    }
    // recursive calling with size -1 than 1st round as the last element is already placed correctly
    SortBubble(arr, size-1); 
}
void display(int arr[], int size)
{
    for( int idx = 0; idx < size ; idx++ )
    {
        cout<<arr[idx]<<" ";
    }
    cout<<endl;
}
int main ()
{
    int arr[5] = { 4 , 1 , 3 , 7 , 5 };
    cout<<"the given array is : "<<endl;
    display(arr, 5);
    SortBubble(arr, 5);
    cout<<"Sorted array is :"<<endl;
    display(arr,5);
    return 0;
    
}