#include<iostream>
using namespace std;

int firstocc( int arr[], int first, int last, int key)
{   
    // Base Class 
    if( first > last)
        return -1;
    int mid = first + (last-first)/2;
    // Element found
    if( arr[mid] == key)
    {
        return mid+1;
    }
    // if not found 
    else if ( arr[mid] > key)
    {
        return firstocc( arr, first, mid-1, key );
    }
    else
    {
       return firstocc(arr, mid+1, last,key );
    }
}
int lastocc(int arr[], int first, int last ,int key )
{
    // base class
    if( first > last )
    {
        return -1;
    }   
    int ans = -1;
    int mid = first + ( last - first )/2;
    // if element is found
    if( arr[mid] == key )
    {   /* We have to create on more variable to take the position of the lastocc as if we don't, then
           recursion will continue until the base class is satisfied
        */
        int firstans = mid+1;
        ans = lastocc( arr, mid+1 , last , key);
        if( ans >= firstans)
        {
            return ans;
        }
        else 
            return firstans;
    }
    else if( arr[mid] > key)
    {
        return lastocc( arr,first, mid-1, key );
    }
    else 
    {
        return lastocc( arr, mid+1, last , key);  
    }
}
int main()
{
    int arr[5] = { 1, 2, 3 , 3 , 4 };
    cout<<" first occ is at " << firstocc(arr, 0 , 5 , 3)<<endl;
    cout<<" last occ is at "<< lastocc(arr, 0 , 5, 3);
    return 0;
}