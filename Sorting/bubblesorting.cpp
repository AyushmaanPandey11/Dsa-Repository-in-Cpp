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
void bubblesort(int arr[],int size )
{
    /*first loop is for counting the number of rounds for sorting
      the rounds will go from 0 to size-1 as the last element will already
       be sorted*/
    for(int rnd=0; rnd<size-1;rnd++)
    {
        /*the second round is for sorting the elements, elements in pair 
            will be sorted by swapping...this sorts the array from maximum element
            i.e from the rear end till the first element(smalleste element)*/
        for(int idx=0;idx<size-rnd;idx++)
        {
            if(arr[idx]>arr[idx+1])
            {
                swap(arr[idx],arr[idx+1]);
            }
        }  
    }
    cout<<"the sorted array is ";
    for(int idx=0;idx<=size;idx++)
    {
        cout<<arr[idx]<<" ";
    }
    cout<<endl;
}
int  main()
{
    int arr[6]={14,7,6,1,4,5};
    int size= sizeof(arr)/6;
    display(arr,size);
    bubblesort(arr,size);
    return 0;
}