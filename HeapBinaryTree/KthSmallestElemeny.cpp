#include<bits/stdc++.h>
using namespace std;
void display( int *arr, int size  )
{
    cout<<"Elements in the array are : "<<endl;
    for( int idx =0; idx<size; idx++ )
    {
        cout<<arr[idx]<<" ";
    }
    cout<<endl;
}
int KthSmallestElement( int *arr, int size, int k )
{
    priority_queue<int> pq;
    for( int idx =0; idx<k ; idx++ )
    {
        pq.push(arr[idx]);
    }
    for(int idx = k; idx<size;idx++)
    {
        if( arr[idx] < pq.top() )
        {
            pq.pop();
            pq.push(arr[idx]);
        }
    }
    int ans =pq.top();
    return ans;
}
int main()
{
    int arr[5] = {4, 3, 10, 8,15};
    display(arr,5);
    int k;
    cout<<"Enter the Kth smallest element to find: ";
    cin>>k;
    cout<<"The "<<k<<"th Smallest element is: "<<KthSmallestElement(arr,5,k);
    return 0;
}