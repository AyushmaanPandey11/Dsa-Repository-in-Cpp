#include<iostream>
using namespace std;

int partition( int *arr, int start , int end )
{
    int pivot = arr[start];
    // taking count of element smaller than pivot
    int count = 0;
    for( int idx =start+1; idx <=end ; idx++ )
    {
        if( arr[idx] < pivot )
        {
            count++;
        }
    }
    // placing pivot element in the right place 
    int pivotidx = start + count;
    swap( arr[start] , arr[pivotidx] );

    // sorting the left and right place of the array 
    int startidx = start;
    int endidx = end;
    while( startidx < pivotidx && endidx > pivotidx )
    {
        while( arr[startidx] < arr[pivotidx] )
        {
            startidx++;
        }
        while ( arr[endidx] > arr[pivotidx])
        {
            endidx--;
        }
        // else condition where arr[startidx] > pivotidx || arr[endidx] < arr[pivotidx]
        if(startidx < pivotidx && endidx > pivotidx)
        {
            swap( arr[startidx++], arr[endidx--] );
        }   
    }
    return pivotidx;
}
void QuickSort ( int *arr, int start , int end)
{
    // base case
    if( start >=end )
        return ;
    // partition, get pivot index
    int pivotindex = partition( arr, start, end);

    // recursive calling 
    // left side 
    QuickSort( arr, start , pivotindex-1 );
    // right side 
    QuickSort( arr, pivotindex+1 , end );
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
    int arr[8] = {-9,-8,-89,9,-99,9,9 };
    int size = 8;
    cout<<"Given array is : "<<endl;
    display(arr,size);
    QuickSort( arr, 0 , size-1 );
    cout<<"Sorted array is : "<<endl;
    for( int idx = 0; idx < size ; idx++ )
    {
        cout<<arr[idx]<<" ";
    }

    return 0;
}