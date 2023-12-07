#include<bits/stdc++.h>
using namespace std;

bool solveMem( int N , vector<int> &nums, int index, int target, vector<vector<int>> &dp )
{
    // base case 
    if( target < 0 || index >= N )
        return 0;
    if( target == 0 )
        return 1;
    if( dp[index][target] != -1 )
        return dp[index][target];
    bool inc = solveMem(N,nums,index+1, target-nums[index],dp);
    bool exc = solveMem(N,nums,index+1,target,dp);
    return dp[index][target]= inc || exc;
}
bool solveTab(  int N , vector<int> &nums,int t )
{
    vector<vector<int>> dp( N+1, vector<int> (t+1,0) );
    for( int idx=0; idx<=N;idx++ )
    {
        dp[idx][0]=1;
    }
    for( int index= N-1; index>=0;index-- )
    {
        for( int target=1; target <= t; target++ )
        {
            bool inc=0; 
            if( target-nums[index] >= 0)
                inc = dp[index+1][target-nums[index]];
            bool exc = dp[index+1][target];
            dp[index][target] = inc || exc;
        }
    }
    return dp[0][t];
}
bool solveSpaceOpt(  int N , vector<int> &nums,int t )
{
    vector<int> curr(t+1,0), next(t+1,0);
    curr[0]=next[0]=1;
    for( int index= N-1; index>=0;index-- )
    {
        for( int target=1; target <= t; target++ )
        {
            bool inc=0; 
            if( target-nums[index] >= 0)
                inc = next[target-nums[index]];
            bool exc = next[target];
            curr[target] = inc || exc;
        }
        next=curr;
    }
    return next[t];
}
int main() {
    vector<int> nums{1,5,11,5};
    int n = nums.size();
    int sum = 0;
    for( int idx=0; idx<nums.size(); idx++ )
    {
        sum += nums[idx];
    }
    if( sum%2 != 0 )
        return 0;
    int target = sum/2;
    vector<vector<int>> dp( n+1, vector<int> (target+1,-1) );
    cout<<"The given array can be partition into two equal subset using recursion and memoization is: "<<solveMem(n,nums,0,target,dp)<<endl;
    cout<<"The given array can be partition into two equal subset using Tabulation is: "<<solveTab(n,nums,target)<<endl;
    cout<<"The given array can be partition into two equal subset using SpaceOptimisation is: "<<solveSpaceOpt(n,nums,target)<<endl;
    return 0;
}