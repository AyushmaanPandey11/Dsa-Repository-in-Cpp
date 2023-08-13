#include<iostream>
using namespace std;
void display(int arr[],int size)
{   cout<<"the array is ";
    for(int idx=0;idx<size;idx++)
    {
        cout<<arr[idx]<<" ";
    }
    cout<<endl;
}
// returns the frst index of the key
int firstocc(int arr[],int n, int key)
{
    int start=0;
    int end=n-1;
    int mid=start+(end-start)/2;
    while(start<=end)
    {
        if(arr[mid]==key)
        {
           return mid;
        }
        else if(key>=arr[mid])
        {
            start=mid+1;
        }
        else 
        {
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}
// for the last occurence, we go to right side
int lastocc(int arr[],int size,int key)
{
     int start=0;
    int end=size-1;
    int mid=(start +(end-start)/2);
    int ans=-1;
    while(start<=end)
    {
        if(arr[mid]==key)
        {
            ans=mid;
            start=mid+1;
        }
        else if(key>arr[mid])
        {
            start=mid+1;
        }
        else if(key<arr[mid])
        {
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return ans;
    
}
int main()
{
    int arr[5]={1,2,3,3,5};
    int size=5;
    int key=3;
    display(arr,size);
    cout<<"the first occurence of the key element is "<<firstocc(arr,size,key)<<endl;
    cout<<"the last occurence of the key element is "<<lastocc(arr,size,key)<<endl;
    return 0;
}

