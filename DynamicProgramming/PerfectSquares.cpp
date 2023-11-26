#include<iostream>
#include<vector>
using namespace std;
int solveMem( int n , vector<int> & dp )
    {
        if( n == 0 )
            return 0;
        if(dp[n]!= -1)
        {
            return dp[n];
        }
        int ans= n;
        for( int idx=1 ; idx*idx <= n ; idx++ )
        {
            ans = min( ans, 1+solveMem(n-idx*idx,dp) );
        }
        dp[n]=ans;
        return dp[n];
    }
    int solveTab( int n )
    {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int idx=1; idx<=n;idx++) // loop for dp indices values
        {
            for( int idy=1; idy*idy <= idx; idy++ ) // for each dp indices finding minimum
            {
                if( idx - idy*idy >= 0 )
                {
                    dp[idx]= min(dp[idx],1+dp[idx - idy*idy]);
                }
            }
        }
        return dp[n];
    }
    int main() {
        int n = 10;
        vector<int> dp(n+1,-1);
        cout<<"Minimum Number of squares required to get the value  "<<n<<" Using recursion And Memoization is: "<<solveMem(n,dp)<<endl;
        cout<<"Minimum Number of squares required to get the value "<<n<<" Using Tabulation is: "<<solveTab(n)<<endl;

        return 0;
    }