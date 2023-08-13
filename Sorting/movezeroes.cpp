#include<iostream>
#include<vector>
using namespace std;

void movezeros(vector<int> arr)
{
    int nonzero=0;
    //loop checks the whole array from start to find the first non zero element and put it in 0 idx
    for(int idx=0;idx<arr.size();idx++)
    {   
        if(arr[idx]!=0)
        {
            swap(arr[idx],arr[nonzero]);
            nonzero++;
        }
        // else condition will ignore the swapping and go to next element
    }
    cout<<"the output of the inserted array is ";
    for(int idx=0;idx<arr.size();idx++)
    {
        cout<<arr[idx]<<" ";
    }
    cout<<endl;
}


void display(vector<int> arr)
{
    for(int idx=0;idx<arr.size();idx++)
    {
        cout<<arr[idx]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(4);
    arr.push_back(12);
    display(arr);
    movezeros(arr);
    return 0;
}