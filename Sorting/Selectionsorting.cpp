#include<iostream>
using namespace std;

void display(int arr[],int size)
{
    cout<<"the given unsorted array is ";
    for(int idx=0;idx<=size;idx++)
    {
        cout<<arr[idx]<<" ";
    }
    cout<<endl;
}
void Selsorting(int arr[],int size)
{
    for(int idx=0;idx<size;idx++)
    {   // we are considering the first element as the minimum and taking idx
        //  to swap with element which will be less than it 
        int minelementidx= idx;
        // this loop is to compare with remaining elements to check for smaller
        // value element and store it to minelementidx variable for swapping
        for(int ch=idx+1;ch<=size-1;ch++)
        {
            if(arr[ch]<arr[minelementidx])
            {   //ch idx is stored in minele for swapping it with the 
                //idx location value
                minelementidx=ch;
            }
            swap(arr[minelementidx],arr[idx]);
        }
    }
    cout<<"the sorted array is ";
    for(int idx=0;idx<=size;idx++)
    {
        cout<<arr[idx]<<" ";
    }
    cout<<endl;
}
int main ()
{
    int arr[5]={6,2,8,4,10};
    int size=sizeof(arr)/5;
    display(arr,size);
    Selsorting(arr,size);
    return 0;
}