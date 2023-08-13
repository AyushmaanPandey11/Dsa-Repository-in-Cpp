#include<iostream>
using namespace std;
void Sort( int arr[], int size )
{
    for( int idx =0; idx < size-1 ; idx++ )
    {
        int minelementidx = idx;
        for( int ch = idx ; ch <= size-1; ch++ )
        {
            if(arr[ch] < arr[minelementidx])
            {
                minelementidx = ch;
            }
        }
        swap(arr[minelementidx], arr[idx]);
    }
}
int isPossilble ( int arr[], int nCow , int mid , int size )
{
    int CowCount = 1;
    int lastposition = arr[0];
    for( int idx = 0 ; idx < size ; idx++ )
    {
        if( (arr[idx] - lastposition) >= mid ) 
        {
            CowCount++;
            if(CowCount == nCow)
            {
                return true ;
            }
            lastposition = arr[idx];
        } 
    }
    return false;
}
// we are using pointers to store the answer because after recursive of function address will have the changed value
// not the case same with the pass by value where out of recusive function value doesnot change 
int CowAggressive( int arr[], int size, int start , int end , int nCow, int *ans )
{
    // base case
    if( start > end || nCow > size)
    {
        return -1;
    }
   
    int mid = start + ( end -start )/2;
    // element  found 
    if( isPossilble(arr, nCow, mid, size) )
    {
        *ans = mid;
        CowAggressive(arr,size,mid+1,end, nCow,ans);
    }
    // element not found 
    else 
    {
        CowAggressive(arr,size,start,mid-1,nCow,ans);
    }
    return *ans;
}
int maxi( int arr[], int size )
{
    int maxi= -1;
    for( int idx =0 ; idx < size; idx++ )
    {
        maxi = max( maxi , arr[idx]);
    }
    return maxi;
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
    for( int idx = 0; idx < 5; idx++ )      
    {
        cout<<arr[idx]<<" ";
    }
    cout<<endl;
    int ans = -1;
    int max = maxi(arr,5);
    cout<<"the largest minimum distance between 2 aggressive cows is "<<CowAggressive(arr, 5,0, max,2,&ans);

    return 0;
}