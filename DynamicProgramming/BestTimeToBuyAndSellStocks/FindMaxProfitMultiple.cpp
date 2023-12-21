#include<bits/stdc++.h>
using namespace std;
 
int solveMem( int index, int buy, vector<int> &prices, vector<vector<int>> &dp )
{
    if( index == prices.size() )
        return 0;
    
    if( dp[index][buy] != -1 )
        return dp[index][buy];
    int profit=0;
    if( buy )
    {
        // bought
        int bought = -prices[index] + solveMem( index+1, 0, prices,dp );
        //skipped
        int skip = solveMem(index+1, 1, prices,dp);
        profit = max(bought,skip);
    }
    else
    {
        // sold
        int sold = prices[index] + solveMem( index+1, 1, prices,dp );
        //skipped
        int skip = solveMem(index+1, 0, prices,dp);
        profit = max(sold,skip);
    }
    return dp[index][buy]=profit;
}
int solveTab( vector<int> &prices )
{
    int n = prices.size();
    vector<vector<int>> dp( n+1, vector<int> (2,0) );
    for( int index=n-1; index>=0; index-- )
    {
        for( int buy = 0; buy <= 1; buy++ )
        {
            int profit=0;
            if( buy )
            {
                // bought
                int bought = -prices[index] + dp[index+1][0];
                //skipped
                int skip = dp[index+1][1];
                profit = max(bought,skip);
            }
            else
            {
                // sold
                int sold = prices[index] + dp[index+1][1];
                //skipped
                int skip = dp[index+1][0];
                profit = max(sold,skip);
            } 
            dp[index][buy]=profit;
        }
    }
    return dp[0][1];
}
int solveSpaceOpt(vector<int> &prices)
{
    int n = prices.size();
    vector<int> curr(n+1,0), next(n+1,0);
    for( int index=n-1; index>=0; index-- )
    {
        for( int buy = 0; buy <= 1; buy++ )
        {
            int profit=0;
            if( buy )
            {
                // bought
                int bought = -prices[index] + next[0];
                //skipped
                int skip = next[1];
                profit = max(bought,skip);
            }
            else
            {
                // sold
                int sold = prices[index] + next[1];
                //skipped
                int skip = next[0];
                profit = max(sold,skip);
            } 
            curr[buy]=profit;
        }
        next=curr;
    }
    return next[1];        
}
int main() {
    vector<int>prices{7,1,3,4,6,2};
    int n = prices.size();
    vector<vector<int>> dp( n, vector<int> (2,-1) );
    cout<<"Max Profit by Multiple buying and selling( Recursion And Memoization ) "<<solveMem(0,1,prices,dp)<<endl;
    cout<<"Max Profit by Multiple buying and selling( Tabulation ) "<<solveTab( prices )<<endl;
    cout<<"Max Profit by Multiple buying and selling( Space Optimisation ) "<<solveSpaceOpt(prices)<<endl;
    return 0;
}
