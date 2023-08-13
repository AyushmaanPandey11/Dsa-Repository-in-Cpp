#include<iostream>
#include<vector>
using namespace std;

void  reverse(vector<int> arr, int place )
{
    int start = place+1;
    int end= arr.size()-1;
    while(start<=end)
    {
      swap(arr[start],arr[end]);
      start++;
      end--;  
    }

    cout<<"the reverse of the array after the place is "<<endl;
    for(int idx=0; idx<arr.size();idx++)
    {
        cout<<arr[idx]<<" ";
    }
    cout<<endl;
}
void print(vector<int> arr)
{
    for(int idx=0; idx<arr.size();idx++)
    {
        cout<<arr[idx]<<" ";
    }
    cout<<endl;
}

int main ()
{
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(7);
    arr.push_back(23);
    arr.push_back(45);
    arr.push_back(60);
    print(arr);
    reverse(arr,1);
    return 0;
}