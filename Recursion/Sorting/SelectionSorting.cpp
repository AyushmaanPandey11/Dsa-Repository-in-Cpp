#include<iostream>
using namespace std;
void display( int arr[], int size )
{
    for(int idx=0; idx<size; idx++)
    {
        cout<<arr[idx]<<" ";
    }
    cout<<endl;
}
void SelSorting( int *arr, int size, int idx )
{
    if( size == 0 || size == 1 || idx>=size )
        return ;
    // doing the first round of the sorting 
    int minelementidx = idx;
    for( int ch = idx+1; ch <= size -1 ; ch++ )
    {
        if( arr[ch] < arr[minelementidx] )
        {
            minelementidx = ch;
        }   
    }
    swap( arr[minelementidx], arr[idx] );
    // recursive calling
    SelSorting( arr, size , idx+1);
}
int main ()
{
    int arr[5]={6,2,8,4,10};
    int size=5;
    display(arr,size);
    cout<<endl;
    SelSorting(&arr[0],size,0);
    display(arr,size);
    return 0;
}