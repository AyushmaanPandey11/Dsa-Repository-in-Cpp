#include<bits/stdc++.h>
using namespace std;
int solveMem( int n , vector<int> &dp )
{
    // base case
    if( n <= 1 )
        return 1;
    if( dp[n] != -1 )
        return dp[n];
    int ans=0;
    for( int root = 1 ; root <= n; root++ )
    {
        ans += solveMem(root-1,dp)*solveMem(n-root,dp); 
    } 
    return dp[n]=ans;
}
int solveTab(int n )
{
    vector<int> dp(n+1,0);
    dp[0]=dp[1]=1;
    for( int nodes = 2; nodes<=n; nodes++ )
    {
        for( int root = 1; root <= nodes; root++ )
        {
            dp[nodes] += dp[root-1]*dp[nodes-root];
        }
    }
    return dp[n];
}
long long factorial( int n , vector<long long> &dp )
{
    if (n == 0 || n == 1)
        return 1;
    if( dp[n] != -1 )
        return dp[n];
    dp[n] = n*factorial(n-1,dp); 
    return dp[n];
}

int main() 
{
    int n;
    cout<<"enter your number"<<endl;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<"Total nunber of structurally unique BST created using recursion and memoization are: "<<solveMem(n,dp)<<endl;    
    cout<<"Total nunber of structurally unique BST created using Tabulation are: "<<solveTab(n)<<endl;
    vector<long long> dpCat(2*n+1,-1);
    int ans = (factorial(2*n,dpCat))/(factorial(n+1,dpCat)*factorial(n,dpCat));
    cout<<"Total nunber of structurally unique BST created using Tabulation are: "<<ans<<endl;
    return 0;
}

