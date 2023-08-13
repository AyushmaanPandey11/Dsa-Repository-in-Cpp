#include<iostream>
using namespace std;
bool isPossible( int arr[], int nbook, int nstud, int mid)
{
    int pagesum = 0;
    int studcount = 1;
    for( int idx = 0; idx < nbook; idx++ )
    {   
        // stores values of pagesum of each student
        if( (pagesum += arr[idx]) <= mid )
        {
            pagesum += arr[idx];
        }
        else 
        {
            studcount++;
            // condition for returning false to the function
            if( (studcount > nstud) || (arr[idx] > mid) )
            {
                return 0;
            }
            // stores pagenum to next student, pagesum > mid
            pagesum = arr[idx];
        }
    }
    return 1;
}
int Sum( int arr[] , int size )
{   
    // base 
    if( size <= 0 ) 
        return 0;
    // addion of {arr[n-1] + arr[n-1]}
    return ( Sum(arr, size - 1) + arr[ size -1 ] );
}
int BookAllocation( int arr[] , int nbook , int nstud, int start , int end, int *answer )
{
    // base case
    if( start > end)
        return *answer;
    else if ( nstud > nbook)
        return -1;
    int mid = start + (end -start)/2;
    // element found 
    if( isPossible(arr, nbook , nstud, mid) )
    {   
        *answer = mid;
        BookAllocation(arr, nbook, nstud, start, mid-1, answer);
    }
    else 
    {
        BookAllocation(arr, nbook, nstud, mid+1, end, answer);
    }
    return *answer;
}
int main()
{
    int arr[4] = {10,20,30,40};
    int ans = -1;
    cout << "Sum of the elements in the array is " <<Sum(arr, 4)<<endl;
    int sum = Sum(arr, 4);
    cout<< " minimum number of pages alloted to stud which is maximum between two :"<<BookAllocation(arr, 4 , 2 , 0, sum , &ans);
    return 0;
}