#include<iostream>
#include<math.h>
using namespace std;

void printArray(int arr[],int n)
{
    cout<<"the given array is"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int uniqueinarray(int arr[],int n)
{   
    int ans=0;
    for(int i=0;i<n;i++)
    {
       ans=ans^arr[i];
    }
   return ans;
}

int main()
{
    int arr[5]={1,3,1,1,1};
    printArray(arr,5);
    int b=uniqueinarray(arr,5);
    cout<<"unique element in the array is "<<b<<endl;

    return 0;
}