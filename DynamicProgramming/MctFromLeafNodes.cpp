#include<bits/stdc++.h>
using namespace std;

int solveMem( vector<int> &arr, int left, int right,  map<pair<int,int>,int> &maxi, vector<vector<int>> &dp )
{
    if( left == right )
        return 0;
    if( dp[left][right] != -1 )
        return dp[left][right];
    int ans = INT_MAX;
    for( int k=left; k < right; k++ )
    {
        ans= min( ans, maxi[{left,k}]*maxi[{k+1,right}] + solveMem(arr,left,k,maxi,dp) + solveMem(arr,k+1,        right,maxi,dp) );
    }
    return dp[left][right]=ans;
}
int main() 
{
    vector<int> arr{6,2,4,6,8};
    int n = arr.size();
    map<pair<int,int>,int> maxi;
    vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
    for( int left = 0; left <n ; left++ )
    {
        maxi[{left,left}]= arr[left];
        for( int right = left; right < n ;right++ )
        {
            maxi[{left,right}]= max(arr[right],maxi[{left,right-1}]);
        }
    }
    cout<<"Minimum Cost of Sum of Non-leaf nodes values "<<solveMem(arr,0,n-1,maxi,dp);    
    return 0;
}
