#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<int> arr,int k)
{   // temp vector is created to store all the rotated elements, prevent overwriting
    // of element if we use loop on the same arr vector.
    vector<int> temp(arr.size());
    for(int idx=0; idx<arr.size();idx++)
    {
        temp[(idx+k)%arr.size()]= arr[idx];
    }
    // stores all rotated values of temp vector to arr.
    arr = temp;
    cout<<"The rotated array is ";
    for(int idx=0; idx<arr.size();idx++)
    {
        cout<<arr[idx]<<" ";
    }
    cout<<endl;
}
void display(vector<int> arr)
{
    cout<<"The given array is ";
    for(int idx=0; idx<arr.size();idx++)
    {
        cout<<arr[idx]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr;
    arr.push_back(11);
    arr.push_back(12);
    arr.push_back(13);
    arr.push_back(14);
    display(arr);
    rotate(arr, 3);
    return 0;

}