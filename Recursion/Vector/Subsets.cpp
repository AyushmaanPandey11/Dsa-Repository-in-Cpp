#include<iostream>
#include<vector>
using namespace std;

void solve( vector<int> nums, vector<int> output , int idx , vector<vector<int>> &ans) // call by reference
{
    // base case
    if( idx == nums.size() )
    {
        ans.push_back(output);
        return;
    }
    // recursion
    // exclude
    solve( nums , output, idx+1 , ans );
    //include
    int element = nums[idx];
    output.push_back(element);
    solve( nums,output,idx+1,ans );
}
void subsets( vector<int>&nums,vector<vector<int>> &ans )
{
    vector<int> output;
    int idx =0;
    solve( nums,output,idx,ans);
}
void display(  vector<int> nums )
{
    cout<<"The array is: ";
    cout<<"{ ";
    for( int idx =0; idx<nums.size(); idx++ )
    {
        cout<<nums[idx]<<" ";
    }
    cout<<"}"<<endl;
}
int main()
{
    vector<vector<int>> ans;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    display(nums);
    subsets(nums,ans);
    cout<<"The subsets of the array are : "<<endl;
    cout<<"{}";
    for( int idx =0; idx<ans.size(); idx++ )
    {
        for( int yidx=0; yidx < ans[idx].size(); yidx++ )
        {
            cout<<"{"<<"{"<<ans[idx][yidx]<<"}"<<"}"<<" ";
        }
        cout<<endl;
    }
    return 0;
}