#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int solveMem( vector<int> &nums, int n, vector<int> &dp )
{
    // step 1 is to make dp array in the main function and call it in the function as parameter
    // base case
    if( n < 0 )
    {
        return 0;
    }
    if( n == 0 )
        return nums[0];
    //step 3 
    if( dp[n] != -1 )
        return dp[n];
    // step2 
    int inclusive = solveMem(nums,n-2,dp) + nums[n];
    int exclusive = solveMem(nums,n-1,dp) + 0;
    dp[n] = max( inclusive,exclusive );

    return dp[n];
}
int solveTabulation( vector<int> &nums )
{
    int n = nums.size();
    if( n <= 0 )
        return 0;   
    // step 1 is to make dp array 
    vector<int> dp(n,0);
    //step 2 
    dp[0] = nums[0];
    //step 3 
    for( int idx = 1; idx<n;idx++ )
    {
        int inclusive = (idx - 2 >= 0 ? dp[idx - 2] : 0) + nums[idx];
        int exclusive = dp[idx-1] + 0;
        dp[idx]= max(inclusive,exclusive); 
    }

    return dp[n-1];
}
int solveSpaceOpt( vector<int> &nums, int n )
{
    int prev2 = 0; // less than 0
    int prev1 = nums[0]; 
    for( int idx=1; idx<n; idx++ )
    {
        int inclusive = prev2 + nums[idx];
        int exclusive = prev1 + 0;
        int ans = max(inclusive,exclusive);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int main()
{
    vector<int> nums{9,9,8,2};
    int n = nums.size();
    vector<int> dp(n,-1);
    cout<< "Answer Using Recursion and Memoization: " << solveMem(nums,n-1,dp)<<endl;
    cout<< "Answer Using Recursion and Tabulation: " << solveTabulation(nums)<<endl;
    cout<< "Answer Using Space Optimisation: " << solveSpaceOpt(nums,n)<<endl;
    return 0;
}