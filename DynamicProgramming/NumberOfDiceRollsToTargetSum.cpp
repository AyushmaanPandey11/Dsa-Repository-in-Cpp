#include<bits/stdc++.h>
using namespace std;

int solveMem( int dice, int faces, int target, vector<vector<long long>> &dp )
{
    // base case 
    if (target == 0 && dice == 0)
        return 1;
    if (target < 0 || (dice == 0 && target != 0))
        return 0;
    // memoize
    if( dp[dice][target] != -1 )
        return dp[dice][target];
    // traversing through the faces of each dice and then going to next dice
    long long  ans=0;
    for( int idx=1 ; idx <= faces; idx++ )
    {
        ans = (ans + solveMem( dice-1,faces,target-idx,dp ))%1000000007;
    }
    return dp[dice][target]=ans;
}
int solveTab(int ndice, int nface, int t)
{
    vector<vector<long long>> dp(ndice+1, vector<long long> (t+1,0));
    dp[0][0]=1;
    
    for( int dice = 1; dice <= ndice; dice++ )
    {
        for( int target =1; target <= t; target++ )
        {
            long long ans = 0;
            for( int idx = 1; idx<= nface; idx++ )
            {
                if( target - idx >= 0)
                    ans = (ans + dp[dice-1][target-idx])%1000000007;
            }
            dp[dice][target]=ans;
        }
    }
    return dp[ndice][t];
}
int solveSpaceOpt(int ndice, int nface, int t)
{
    vector<int> prev(t+1,0);
    vector<int> curr(t+1,0);
    prev[0]=1;
    
    for( int dice = 1; dice <= ndice; dice++ )
    {
        for( int target =1; target <= t; target++ )
        {
            long long ans = 0;
            for( int idx = 1; idx<= nface; idx++ )
            {
                if( target - idx >= 0)
                    ans = (ans + prev[target-idx])%1000000007;
            }
            curr[target]=ans;
        }
        prev=curr;
    }
    return prev[t];
}
int main() {
    int n=2; 
    int k=6;
    int target=7;
    vector<vector<long long>> dp(n+1, vector<long long> (target+1,-1));
    cout<<" Total number of ways to reach the target using recursion and memoization is: "<<solveMem(n,k,target,dp)<<endl;
    cout<<" Total number of ways to reach the target using tabulation is: "<< solveTab( n , k , target)<<endl;
    cout<<" Total number of ways to reach the target using space Optimisation is: "<<solveSpaceOpt(n,k,target)<<endl;
    return 0;
}
