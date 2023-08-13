#include<iostream>
#include<math.h>
using namespace std;

void swapalternate(int arr[],int n)
{   
    cout<<"the alternate array is"<<endl;
    for(int i=0;i<n;i+=2)
    {
        swap(arr[i],arr[i+1]);
    }
}
    /* int first=0;
    int second=1;
    while(second<n)
    {
        swap(arr[first],arr[second]);
        first+=2;
        second+=2;
    }
} */
void printArray(int a[], int x)
{   
    for(int i=0;i<x;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[6]={1,2,3,4,5,6};
    cout<<"the given array is"<<endl;
    printArray(arr,6);
    swapalternate(arr,6);
    printArray(arr,6);
    return 0;
}