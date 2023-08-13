#include<iostream>
using namespace std;

void Merge( int *arr, int start , int end )
{
    int mid = start + ( end - start )/2;
    int len1 = mid - start +1 ;
    int len2 = end - mid ;
    int mainarridx;
    // creation of 2 arrays using heap
    int *firstarr = new int[len1];
    int *secondarr = new int[len2];

    // copy values to the new arrays
    // FIRST ARRAY 
    mainarridx = start;
    for( int idx = 0 ; idx < len1 ; idx++ )
    {
        firstarr[idx] = arr[mainarridx++];
    }
    // SECOND ARRAY
    mainarridx = mid+1;
    for( int idx = 0 ; idx < len2 ; idx++ )
    {
        secondarr[idx] = arr[mainarridx++];
    }
    // array created and values are copied 
    // merging 2 sorted arrays
    int idx1 = 0; 
    int idx2 = 0;
    mainarridx = start;
    while( idx1 < len1 && idx2 < len2 )
    {
        if( firstarr[idx1] < secondarr[idx2] )
        {
            arr[mainarridx++] = firstarr[idx1++];
        }
        else
        {
            arr[mainarridx++] = secondarr[idx2++];
        }
    }
    // remaining element in the first array
    while( idx1 < len1 )
    {
        arr[mainarridx++] = firstarr[idx1++];
    }
    // remaining element in the second array
    while ( idx2 < len2)
    {
        arr[mainarridx++] = secondarr[idx2++];
    }
    // releasing memory of heap 
    delete []firstarr;
    delete []secondarr;
}
void MergeSort( int *arr, int start, int end)
{
    // base case
    if( start >= end)
    {
        return ;
    }
    int mid = start + ( end - start )/2;
    // recursive calling
    // MergeSort of the left part of array
    MergeSort( arr, start , mid ); 
    // mergesort of the right part of array
    MergeSort( arr, mid+1 , end );

    // merge of 2 sorted array 
    Merge( arr, start , end );
}
void display(int arr[], int size)
{
    for( int idx = 0; idx < size ; idx++ )
    {
        cout<<arr[idx]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[5] = { 2,5,1,6,9 };
    int size = 5;
    cout<<"Given array is : "<<endl;
    display(arr,size);
    MergeSort(arr, 0 , size-1);
    cout<<"sorted array is : "<<endl;
    for( int idx = 0; idx < size ; idx++ )
    {
        cout<<arr[idx]<<" ";
    }
    cout<<endl;
    return 0;
}