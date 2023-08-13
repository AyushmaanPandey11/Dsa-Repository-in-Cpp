#include<iostream>
using namespace std;
void InsertionSort( int *arr , int size , int rnd)
{
    // base case 
    if( size == 0 || size == 1 || rnd > size)
        return ;
    // algo for the first rnd of sorting
    int temp = arr[rnd];
    int shift = rnd - 1;
    for( ; shift>= 0 ; shift-- )
    {
        if( arr[shift] > temp)
        {   
            // no need to worry about the shift+1(= rnd) value which is temp 
            arr[shift+1] = arr[shift];
        }
        else
        {
            break;
        }
    } 
    // shift+1 because in the loop "shift>=0" can satisfy so 'shift--' will be done so we have to do arr[shift +1]
    arr[shift+1] = temp;
    // recursive calling
    InsertionSort( arr, size , rnd+1 );
}
void display(int arr[],int size)
{
    cout<<"the give unsorted array is ";
    for(int idx=0;idx<size;idx++)
    {
        cout<<arr[idx]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[5]={6,2,8,4,10};
    int size = 5 ;
    display(arr,size);
    InsertionSort(arr,size,1);
    cout<<"Sorted array is "<<endl;
    display(arr,size);
    return 0;
}