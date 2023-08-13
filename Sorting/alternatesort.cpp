#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> arr1, vector<int> arr2, vector<int> arr3)
{  
    int idx1=0, idx2=0,idx3=0;
    // loop is for comparing between two arrays 
    while(idx1<arr1.size() || idx2<arr2.size())
    {
        
        if(arr1[idx1]<arr2[idx2])
        {
            arr1[idx3++]=arr1[idx1++];
        }
        else if(arr1[idx1]==arr2[idx2]) 
        {
            arr1[idx3++]=arr1[idx1++];
        }
        else if(arr1[idx1]==0)
        {
            arr1.pop_back();
            idx1++;
        }
        else
        {
            arr1[idx3++]=arr2[idx2++];
        }
    }
    cout<<"the merged and sorted array of the two arrays is ";
    for(int idx3=0; idx3<arr3.size();idx3++)
    {
       cout<<arr3[idx3]<<" "; 
    }
}

void display(vector<int> arr)
{   cout<<"the given array is ";
    for(int idx=0; idx<arr.size();idx++)
    {
       cout<<arr[idx]<<" "; 
    }
    cout<<endl;
}
int main()
{
    vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(3);
    arr1.push_back(0);
    arr1.push_back(0);
    arr1.push_back(0);
    vector<int> arr2;
    arr2.push_back(2);
    arr2.push_back(5);
    arr2.push_back(6);
    vector<int> arr3;
    display(arr1);
    display(arr2);
   merge(arr1,arr2,arr3);
    return 0;
}