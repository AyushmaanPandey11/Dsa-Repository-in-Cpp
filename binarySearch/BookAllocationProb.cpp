#include<iostream>
using namespace std;
/*
                                    CONDITIONS
                                    1.  each book to be allocated to students.
                                    2.  each student should get atleast one book.
                                    ALGORITHM
                                    we have to find the maximum number of pages allocated to one out of  combination , it should be minimum  
                                    two functions are created and defined , 1 - isPossible 2 - BookAllocProb 
                                    1 - isPossible : give bool value that the mid value gives solution or not
                                    2 - use binary search method to find the mid value which gives the answer.
                                            2.1 - If solution exist - end = mid -1 ; (Left Part)
                                            2.2 - IF doesnt exist - start = mid +1;  (Right part)
*/

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
int BookAllocProb( int arr[], int nbook , int nstud)    
{
    int sum = 0 ;
    // taking the total number of pages
    for( int idx =0; idx < nbook ; idx++ )
    {
        sum += arr[idx];
    }
    int start = 0;
    int end = sum ;
    int mid = start + (end - start)/2;
    int ans = -1;
    // binary search
    while( start <= end )
    {   
        // students are more than the books. Invalid case
        if(nstud > nbook)
        {
            return -1;
        }
        // solution exists
        if( isPossible(arr,nbook,nstud,mid) )
        {
            ans = mid;
            end = mid-1 ;
        }
        // solution doesnt exists in the limit
        else 
        {
            start = mid+1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}
int main()
{
    int arr[4] = { 10,20,30,40 };
    int nstud = 2;
    cout << "The Smallest maximum number of books assigned to nstud is "<<BookAllocProb( arr,4,nstud )<<endl;
    return 0;
}
