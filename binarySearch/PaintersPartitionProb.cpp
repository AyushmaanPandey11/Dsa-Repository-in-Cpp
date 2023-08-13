#include<iostream> 
using namespace std;
        /*          PAINTERS PARTITION PROBLEM
            1. There are nPainters
            2. Painters can paint only in continuos manner
            3. area alloted to each painter should be minimum 
            SAME ALGORITHM AS THE BOOK ALLOCATION PROBLEM 
        */

bool isPossible( int slot[], int mid, int nPainters , int size )
{
    int Paintercount = 1;
    int area = 0;
    for( int idx = 0; idx < size; idx++ )
    {
        if( (area + slot[idx]) <= mid )
        {
            area += slot[idx];
        }
        else
        {
            Paintercount++;
            if( Paintercount>nPainters || slot[idx] > mid )
            {
                return 0;
            }
            area = slot[idx];
        }
    }
    return 1;
}
int PainterPartitionProb( int slot[], int nPainters, int size )
{   
    int totalarea=0;
    // to get maximum value for the answer sample space 
    for(int idx=0; idx<size; idx++)
    {
        totalarea += slot[idx];
    }
    int ans = -1;
    int start = 0;
    int end = totalarea;
    int mid = start + (end - start)/2;
    // ANSWER SAMPLE SPACE IS BETWEEN 0 AND SUM OF THE UNIT OF WALL TO PAINT
    while(start <= end)
    {   // if the number of painters is more than the given number of slots, not possible case
        if(nPainters > size)
        {
            return -1;
        }
        // its true then the mid is stored in the answer and to find the minimum value, will go to the left part of the answer space 
        if( isPossible(slot,  mid, nPainters, size) )
        {
            ans = mid;
            end = mid -1 ;
        }
        // not true . goes to the right part of sample space 
        else 
        {
            start = mid+1 ;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}
int main()
{
    int slot[4] = { 5,5,5,5 };
    int nPainters = 2;
    cout << " the minimum area to be assigned to a painter is "<<PainterPartitionProb( slot, nPainters, 4);
    return 0;
}