#include<bits/stdc++.h>
using namespace std;
/*
        Same as Algorithm of House Robber robbing in houses in circular shape where there will
        2 cases:
        1. first house is chosen and last one is removed
        1. last house is chosen and first one is removed 
*/
int solve( vector<int>& slices, int startidx, int endidx, vector<vector<int>> &dp, int n )
{
    // base case
    if( startidx > endidx || n == 0 )
        return 0;
    // using remnant space 
    if( dp[startidx][n] != -1 )
        return dp[startidx][n];
    // included
    int inc = slices[startidx] + solve(slices,startidx+2,endidx,dp,n-1);
    // excluded
    int exc = 0 + solve(slices,startidx+1,endidx,dp,n);

    return dp[startidx][n] = max(inc,exc);
    
}
int solveTab( vector<int>& slices )
{
    int k = slices.size();
    vector<vector<int>> dp( k+2, vector<int> (k+2,0) );
    // taken
    for( int startidx=k-2; startidx>=0; startidx--  )
    {
        for( int n=1; n <= k/3; n++)
        {
            //included
            int inc = slices[startidx] + dp[startidx+2][n-1];
            // excluded
            int exc = 0 + dp[startidx+1][n];

            dp[startidx][n] = max(inc,exc);    
        }
    }
    int case1 = dp[0][k/3];
    // not taken
    vector<vector<int>> dp1( k+2, vector<int> (k+2,0) );
    for( int startidx=k-1; startidx>=1; startidx--  )
    {
        for( int n=1; n <=k/3; n++ )
        {
            //included
            int inc = slices[startidx] + dp1[startidx+2][n-1];
            // excluded
            int exc = 0 + dp1[startidx+1][n];

            dp1[startidx][n] = max(inc,exc);    
        }
    }
    int case2 = dp1[1][k/3];
    return max(case1,case2);
}
int solveOpt( vector<int> & slices )
{
    int k = slices.size();
    vector<int> prev1(k+2,0);
    vector<int> curr1(k+2,0);
    vector<int> next1(k+2,0);
    // taken
    for( int startidx=k-2; startidx>=0; startidx--  )
    {
        for( int n=1; n <= k/3; n++)
        {
            //included
            int inc = slices[startidx] + next1[n-1];
            // excluded
            int exc = 0 + curr1[n];

            prev1[n] = max(inc,exc);    
        }
        next1=curr1;
        curr1=prev1;
    }
    int case1 = curr1[k/3];
    // not taken
    vector<int> prev2(k+2,0);
    vector<int> curr2(k+2,0);
    vector<int> next2(k+2,0);
    for( int startidx=k-1; startidx>=1; startidx--  )
    {
        for( int n=1; n <=k/3; n++ )
        {
            //included
            int inc = slices[startidx] + next2[n-1];
            // excluded
            int exc = 0 + curr2[n];

            prev2[n] = max(inc,exc);    
        }
        next2=curr2;
        curr2=prev2;
    }
    int case2 = curr2[k/3];
    return max(case1,case2);
}
int main() 
{
    vector<int> slices{1,2,3,4,5,6};
    int k = slices.size();
    vector<vector<int>> dp1(k, vector<int> (k,-1));
    int first = solve( slices,0, k-2, dp1, k/3 );
    vector<vector<int>> dp2(k, vector<int> (k,-1));
    int second = solve( slices,1, k-1, dp2, k/3);
    cout<<"Answer Using Recursion and Memoizations: "<<max(first,second)<<endl;     
    cout<<"Answer Using Tabulation: "<<solveTab(slices)<<endl;
    cout<<"Answer Using Space Optimization : "<<solveOpt(slices)<<endl;
    return 0;
}