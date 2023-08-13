#include<iostream>
using namespace std;

int merge( int *arr , int start , int end )
{
    int mid = start + ( end - start )/2;
    int invcnt = 0;

    // copying values to new arrays
    int len1 =  mid - start +1 ;
    int len2 = end - mid;
    int mainarridx = 0;

    int *first = new int[len1];
    int *second = new int[len2];
    // copying values to the array
    mainarridx = start;
    for( int idx = 0 ; idx < len1 ; idx++)
    {
        first[idx] = arr[mainarridx++];
    }
    mainarridx = mid+1;
    for( int idx = 0 ; idx < len2 ; idx++)
    {
        second[idx] = arr[mainarridx++];
    }

    // merging the 2 sorted arrays
    int idx1, idx2 = 0; 
    mainarridx = start;
    while( idx1 < len1 && idx2 < len2 )
    {
        if( first[idx1] < second[idx2] )
        {
            arr[mainarridx++] = first[idx1++];
        }
        else // first[idx1++] > second[idx2++] 
        {
            arr[mainarridx++] = second[idx2++];
            // increment of inversion from the left part of array
            invcnt += len1 - idx1 ;
        }
    }
    while( idx1 < len1 )
    {
        arr[mainarridx++] = first[idx1++];
    }
    while( idx2 < len2 )
    {
        arr[mainarridx++] = second[idx2++];
    }
    delete []first;
    delete []second;
    return invcnt;
}
int CountInversion( int *arr, int start , int  end )
{   
    int inv = 0;
    if( start < end )
    {
        int mid = start + ( end - start )/2;
        inv += CountInversion( arr, start, mid );
        inv += CountInversion( arr, mid+1, end );
        inv += merge( arr, start, end ); 
    }
    return inv;
}
int main ()
{
    int arr[3] = {  3,2,1 };
    int size = 3;
    cout<< " total inversion count of the array is "<<CountInversion( arr, 0 , size -1 );
    return 0;
}