#include<iostream>
using namespace std;
int binarySearch(int arr[],int n, int key)
{
    int start=0;
    int end=n-1;
    int mid=start+(end-start)/2;
    while(start<=end)
    {
        if(arr[mid]==key)
        {
            return mid+1;
        }
        if(key>=arr[mid])
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
int main ()
{
    int a[5]={5,7,8,10,15};
    int index= binarySearch(a,5,15);
    if(index>=1)
    {
        cout<<"the number is at "<<index;
    }
    else
    {
        cout<<"the number is not in the array";
    }
}