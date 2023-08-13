#include<iostream>
#include<vector>
using namespace std;
vector<int> reverse(vector<int> arr)
{
    int start=0;
    int end= arr.size()-1;
    while(start<end)
    {
        swap(arr[start++],arr[end--]);
    }
    return arr;
}
vector<int> sum(vector<int> arr, vector<int> arr2)
{
    int firstarr = arr.size()-1;
    int secondarr = arr2.size()-1;
    int carry= 0;
    int sum = 0;
    vector<int> rsult;
    // till when both arrays have common number of elements
    while(firstarr>=0 && secondarr>=0)
    {
        int value = arr[firstarr] + arr2[secondarr] + carry;
        int sum = value % 10;
        carry = value / 10;
        firstarr--;
        secondarr--;
        rsult.push_back(sum);
        
    }
    // if the first array have more elements than the second one 
    while( firstarr>=0 )
    {
        int value = arr[firstarr] + carry;
        sum = value % 10;
        carry = value / 10;
        firstarr--;
        rsult.push_back(sum);
    }
    // if the second array have more elements than the first one 
    while( secondarr>=0 )
    {
        int value = arr2[secondarr] + carry ;
        sum = value % 10;
        carry = value / 10;
        secondarr--;
        rsult.push_back(sum);
    }
    return reverse(rsult);
}

void display(vector<int> arr)
{
    cout<<"the answer is ";
    for(int idx=0;idx<arr.size();idx++)
    {
        cout<<arr[idx]<<" ";
    }
    cout<<endl;
}
int main ()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    vector<int> arr2;
    arr2.push_back(2); 
    arr2.push_back(2);
    arr2.push_back(2);
    display(sum(arr,arr2));
    return 0;
}