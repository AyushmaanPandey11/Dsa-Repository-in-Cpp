#include<bits/stdc++.h>
using namespace std;
int solveTabulation( vector<int> &coins, int amount )
{
    vector<int> dp(amount+1,INT_MAX);
    dp[0]= 0; // means that 0 coins are required to get to the target sum 0
    for( int idx=1; idx <= amount; idx++ ) // this loop is from amount 1 to amount value where dp[idx] tell mini coins req.
    {
        for( int idy = 0; idy<coins.size(); idy++ )
        {
            if( idx-coins[idy] >= 0 && dp[idx-coins[idy]] != INT_MAX )
            {
                dp[idx] = min( dp[idx] , 1 + dp[idx-coins[idy]] );
            }
        }
    }
    if( dp[amount] == INT_MAX  )
        return -1;
    return dp[amount];
}
int main() 
{
    vector<int> coins{4,3,2,1};
    int target=10;
    int ans = solveTabulation(coins,target);
    cout<<"Minimum number of Coins required to reach "<<target<<"is:"<<ans;
    return 0;
}