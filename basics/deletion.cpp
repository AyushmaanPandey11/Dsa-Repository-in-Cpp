#include<iostream>
using namespace std;

void display(int arr[],int size)
{   
    for(int idx=0;idx<size;idx++)
    {
        cout<<arr[idx]<<" ";
    }
   cout<<endl;
}
void deletion(int arr[],int size,int idx)
{   
    if(idx>size)
    {
        cout<<"index does exits in the array";
    }
    //deletion starts from the index position till its size
    cout<<"the updated array is ";
    for ( int del = idx; del < size-1 ; del++)
    {
        arr[del]=arr[del+1];
    }
    cout<<endl;
}
int main()
{
    int arr[5]={54 , 32 ,21 ,76 ,87};
    int idx=2;
    int size=5;
    cout<<"the given array is "<<endl;
    display(arr,size);
    cout<<"the position to be deleted is "<<idx+1<<endl;
    deletion(arr,size,idx);
    size--;
    display(arr,size);

    return 0;
}