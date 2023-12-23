#include<bits/stdc++.h>
using namespace std;
        // 3D Dynamic Programming
int solveMem( int index, int buy, vector<int> &prices, int limit, vector<vector<vector<int>>> &dp )
{
    if( index == prices.size() )
        return 0;
    if( limit == 0 )
        return 0;
    if( dp[index][buy][limit] != -1 )
        return dp[index][buy][limit];
    int profit=0;
    if( buy )
    {
        // bought
        int bought = -prices[index] + solveMem( index+1, 0, prices,limit,dp );
        //skipped
        int skip = solveMem(index+1, 1, prices,limit,dp);
        profit = max(bought,skip);
    }
    else
    {
        // sold
        int sold = prices[index] + solveMem( index+1, 1, prices,limit-1,dp );
        //skipped
        int skip = solveMem(index+1, 0, prices,limit,dp);
        profit = max(sold,skip);
    }
    return dp[index][buy][limit]=profit;
}
int solveTab( vector<int> &prices )
{
    int n = prices.size();
    vector<vector<vector<int>>> dp( n+1, vector<vector<int>> (2,vector<int> (3,0)) );
    for( int index=n-1; index>=0; index-- )
    {
        for( int buy = 0; buy <= 1; buy++ )
        {
            for( int limit = 1; limit <= 2; limit++ )
            {
                int profit=0;
                if( buy )
                {
                    // bought
                    int bought = -prices[index] + dp[index+1][0][limit];
                    //skipped
                    int skip = dp[index+1][1][limit];
                    profit = max(bought,skip);
                }
                else
                {
                    // sold
                    int sold = prices[index] + dp[index+1][1][limit-1];
                    //skipped
                    int skip = dp[index+1][0][limit];
                    profit = max(sold,skip);
                } 
                dp[index][buy][limit]=profit;
            }
        }
    }
    return dp[0][1][2];
}
int solveSpaceOpt(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> curr(2,vector<int> (3,0)), next(2,vector<int> (3,0));
    for( int index=n-1; index>=0; index-- )
    {
        for( int buy = 0; buy <= 1; buy++ )
        {
            for( int limit=1; limit<=2; limit++ )
            {
                int profit=0;
                if( buy )
                {
                    // bought
                    int bought = -prices[index] + next[0][limit];
                    //skipped
                    int skip = next[1][limit];
                    profit = max(bought,skip);
                }
                else
                {
                    // sold
                    int sold = prices[index] + next[1][limit-1];
                    //skipped
                    int skip = next[0][limit];
                    profit = max(sold,skip);
                } 
                curr[buy][limit]=profit;
            }
        }
        next=curr;
    }
    return next[1][2];        
}
int Profit(vector<int>& prices) {
    int buy1 = INT_MAX;
    int buy2 = INT_MAX;
    int profit1 = 0;
    int profit2 = 0;
    for (auto &price : prices) {
        buy1 = min(buy1, price);                // best observed buy price seen
        profit1 = max(profit1, price - buy1);   // best observed profit window
        buy2 = min(buy2, price - profit1);      // best buy price post-profit1
        profit2 = max(profit2, price - buy2);   // best combined two transaction profit
    }
    return profit2;
}
int main() {
    vector<int> prices{3,3,5,0,0,3,1,4};
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3,-1)));
    cout<<"Find MaxProfit by doing only 2 transactions using Recursion and Memoization: "<<solveMem(0,1,prices,2,dp)<<endl;
    cout<<"Find MaxProfit by doing only 2 transactions using Tabulation: "<<solveTab(prices)<<endl;
    cout<<"Find MaxProfit by doing only 2 transactions using Space optimisation1 : "<<solveSpaceOpt(prices)<<endl;
    cout<<"Find MaxProfit by doing only 2 transactions using onLy Variables: "<<Profit(prices)<<endl;
    return 0;
}