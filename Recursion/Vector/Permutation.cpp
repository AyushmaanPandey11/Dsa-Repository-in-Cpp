#include<vector>
#include<iostream>
using namespace std;

void Solve( vector<int> nums, vector<vector<int>> &ans , int index , int &count )
{
    // base case 
    if( index >= nums.size() )
    {
        ans.push_back(nums);
        count++;
        return;
    }
    // loop for permutaion 
    for( int idx= index ; idx < nums.size() ; idx++ )
    {
        swap( nums[index] , nums[idx] );
        //recursive calling
        Solve( nums, ans, index+1,count );
        // backtracking to the original string to swap the element with next char ie thru idx
        swap( nums[index], nums[idx]);
    }
}
void Permutaion( vector<int> nums , vector<vector<int>> & ans, int &count)
{
    int index =0; 
    Solve( nums , ans , index, count);
}
void display( vector<int> nums )
{
    cout<<"The given string is :";
    cout<<"{";
    for( int idx=0; idx< nums.size(); idx++)
    {
        cout<<" "<<nums[idx]<<" ";
    }
    cout<<"}"<<endl;
    cout<<endl;
}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    display(nums);
    vector<vector<int>> ans;
    int count=0;
    Permutaion(nums,ans,count);
    cout<<"Total number of permuation is: "<<count<<endl;
    cout<<"All the Permutaions of the string is :";
    for( int idx=0; idx< ans.size() ; idx++)
    {
        cout<<"{";
        for( int idy=0; idy < ans[idx].size(); idy++ )
        {
            cout<<ans[idx][idy];
        }
        cout<<"}"<<" ";
    }
    return 0;
}