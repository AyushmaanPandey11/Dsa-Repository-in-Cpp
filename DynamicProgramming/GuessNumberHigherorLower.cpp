#include<bits/stdc++.h>
using namespace std;

int solveMem( int start, int end, vector<vector<int>> &dp )
{
    // base case
    if( start >= end )
        return 0;
    if( dp[start][end] != -1 )
        return dp[start][end];
    int ans = INT_MAX;
    for( int idx=start; idx<=end;idx++ )
    {
        ans = min( ans, idx + max( solveMem(start,idx-1,dp),solveMem(idx+1,end,dp)) );
    }
    return dp[start][end]=ans;
}
int solveTab( int n )
{
    vector<vector<int>> dp(n+2, vector<int> (n+2,0));
    for( int start = n ; start >= 1; start-- )
    {
        for( int end= start ; end <= n; end++ )
        {
            if( start == end )
                continue;
            else
            {
                int ans=INT_MAX;
                for( int idx=start; idx <=end; idx++ )
                {
                    ans = min(ans,idx + max( dp[start][idx-1],dp[idx+1][end] ));
                }
                dp[start][end]=ans;
            }
        }
    }
    return dp[1][n];
}
int main() 
{
    int n=5;
    vector<vector<int>> dp(n+2,vector<int> (n+2,-1));
    cout<<" the minimum amount of money you need to guarantee a win regardless of what number I pick(Recursion&Memoization): "<<solveMem(1,n,dp)<<endl;   
    cout<<" the minimum amount of money you need to guarantee a win regardless of what number I pick(Tabulation): "<<solveTab(n); 
}