#include<iostream>
using namespace std;

void merge(int arr1[], int size1, int arr2[], int size2, int arr3[],int size3)
{
    int idx1=0, idx2=0, idx3=0;
    // loop is for comparing between two arrays 
    while(idx1<size1 && idx2<size2)
    {
        if(arr1[idx1]<arr2[idx2])
        {
            arr3[idx3++]=arr1[idx1++];
        }
        else
        {
            arr3[idx3++]=arr2[idx2++];
        }
    }
    // loop for storing extraa elements of first array into the merged one
    while(idx1<size1)
    {
        arr3[idx3++]=arr1[idx1++];
    }
    // loop stores extraa elements of second array to the merged one;
    while(idx2<size2)
    {
        arr3[idx3++]=arr2[idx2++];
    }
    cout<<"the merged and sorted array of the two arrays is ";
    for(int idx3=0; idx3<size3;idx3++)
    {
       cout<<arr3[idx3]<<" "; 
    }
}




void display(int arr[],int size)
{   cout<<"the given array is ";
    for(int idx=0; idx<size;idx++)
    {
       cout<<arr[idx]<<" "; 
    }
    cout<<endl;
}
int main()
{
    int arr1[5]={1,3,5,7,9};
    int arr2[4]={2,4,6,8};
    int arr3[9];
    display(arr1, 5);
    display(arr2,4);
    merge(arr1,5,arr2,4,arr3,9);
    return 0;
}