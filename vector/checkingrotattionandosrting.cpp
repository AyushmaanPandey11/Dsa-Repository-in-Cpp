#include<iostream>
#include<vector>
using namespace std;
// only for non decreasing sorted and rotated array
bool check(vector<int> arr)
{
    int count=0;
    int size=arr.size();
    // gives true only if count is 0 or 1. for decreasing order, 
    // loop gives count>1 which is false. And for unsorted it can give count>2 
    for(int idx=1; idx<size; idx++)
    {
        if(arr[idx-1] > arr[idx])
        {
            count++;
        }
    }
    // to check for that last element and the first element
    if(arr[size-1]>arr[0])
    {
        count++;
    }
    return count<=1;
}
int main()
{
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(2);
    int bol= check(arr);
    if(bol==1)
    {
        cout<<"array is sorted and rotated ";
    }
    else 
    {
        cout<<"array is not sorted and rotated";
    }
    return 0;
}