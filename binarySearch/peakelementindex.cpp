#include<iostream>
using namespace std;

void display(int arr[],int size)
{   
    cout<<"the given array is ";
    for(int idx=0;idx<=size;idx++)
    {
        cout<<arr[idx]<<" ";
    }
    cout<<endl;
}

int peakidx(int arr[],int size)
{
    int start=0;
    int end=size-1;
    int mid = start + (end -start)/2;
    while(start<end)
    {
        if(arr[mid+1]>arr[mid])
        {
            start=mid+1;
        }
        // else condition is : arr[mid]>arr[mid+1]
        else 
        {
            end = mid;
        }
        mid = start+ (end -start)/2;
    }
    return start;
}
int main()
{
    int arr[5]={1,2,6,5,3};
    int size= sizeof(arr)/5;
    display(arr,size);
    cout<<"the peak element index in the array is "<<peakidx(arr,size);
    return 0;
}