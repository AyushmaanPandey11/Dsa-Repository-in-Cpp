#include<iostream>
using namespace std;
void display(int arr[],int size)
{
    cout<<"the give unsorted array is ";
    for(int idx=0;idx<=size;idx++)
    {
        cout<<arr[idx]<<" ";
    }
    cout<<endl;
}
void insertionsort(int arr[],int size)
{   //loop for round &the sorted part of array,idx 0 element is considered sorted

    // rnd = 1 because 0 idxelement is already sorted so we have to start with the second(idx=1)
    for(int rnd=1;rnd<size;rnd++)
    {   //stores the value to check and put in right place in sorted array
        int temp=arr[rnd];
        //this loop is used to check in the sorted part on the left for the temp values location.
        int shift=rnd-1;
        for(;shift>=0;shift--)
        {
            if(arr[shift]>temp)
            {
                arr[shift+1]=arr[shift];
            }
            else 
            {
                break;
            }
        }
        //shift+1 because after coming out of loop shift the number to be placed after the element where condition is false(arr[shift]<temp)
        arr[shift+1]=temp;
    }
    cout<<"the sorted array is ";
    for(int idx=0;idx<=size;idx++)
    {
        cout<<arr[idx]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[5]={6,2,8,4,10};
    int size=sizeof(arr)/5;
    display(arr,size);
    insertionsort(arr,size);
    return 0;
}