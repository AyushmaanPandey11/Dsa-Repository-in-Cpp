#include<iostream>
using namespace std;
void Sort( int arr[], int size )
{
    for( int idx = 0; idx < size-1; idx++ )
    {
        int minelementidx = idx;
        for( int ch = idx ; ch <= size -1 ; ch++ )
        {
            if( arr[ch] < arr[minelementidx] )
            {
                minelementidx = ch;
            }
        }
        swap( arr[minelementidx] , arr[idx] );
    }   
}
bool isPossible( int arr[], int nCow , int mid , int size )
{
    int Cowcount = 1;
    int lastPos = arr[0];
    for( int idx = 0 ; idx < size ; idx++ )
    {
        if( (arr[idx] - lastPos) >= mid )
        {
            Cowcount++;
            if( Cowcount == nCow )
            {
                return true;
            }
            lastPos = arr[idx];
        }
    }
    return false;
}
int AggresCowProb( int arr[], int size, int nCow)
{   
    Sort(arr,size);
    int start = 0;
    int end ;
    int maxi = -1;
    for( int idx = 0 ; idx < size ; idx++ )
    {
        maxi = max( maxi, arr[idx]);
    }
    end = maxi;
    int ans = -1;
    int mid = start + (end - start)/2;
    while( start <= end )
    {   
        if( nCow > size )
        {
            return -1;
        }
        if( isPossible(arr,nCow,mid,size ) )
        {
            ans = mid;
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }
        mid = start + ( end - start )/2;
    }
    return ans;
}
int main()
{
    int arr[5] = { 4,1,2,3,6 };
    cout<< "The stalls are at "<<endl;
    for( int idx = 0; idx < 5; idx++ )
    {
        cout<<arr[idx]<<" ";
    }
    cout<<endl;   
    Sort( arr,5 );
    cout<< "The stalls are sorted : "<<endl;
    for( int idx = 0; idx < 5; idx++)      
    {
        cout<<arr[idx]<<" ";
    }
    cout<<endl;
    cout<<"the largest minimum distance between 2 aggressive cows is "<<AggresCowProb(arr, 5,2);

    return 0;
}