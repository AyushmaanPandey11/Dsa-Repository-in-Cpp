#include<bits/stdc++.h>
using namespace std;

int solveMem( string &text1, string &text2, int firstidx, int secondidx,vector<vector<int>> &dp )
{
    // base case
    if( firstidx == text1.size() || secondidx == text2.size() )
    {
        return 0;
    }
    if( dp[firstidx][secondidx] != -1 )
        return dp[firstidx][secondidx];
    int ans=0;
    // recursive calling
    if( text1[firstidx] == text2[secondidx] )
        ans = 1 + solveMem(text1, text2, firstidx+1, secondidx+1,dp);
    else
    {
        ans= max( solveMem(text1,text2,firstidx+1,secondidx,dp), solveMem(text1,text2,firstidx,secondidx+1,dp) );
    }
    return dp[firstidx][secondidx]=ans;
}
int solveTab( string &t1, string &t2 )
{
    int str1 = t1.size();
    int str2 = t2.size();
    vector<vector<int>> dp( str1+1, vector<int> (str2+1,0) );
    for( int first= str1-1; first >= 0; first-- )
    {
        for( int second=str2-1;second >=0; second-- )
        {
            int ans=0;
            // recursive calling
            if( t1[first] == t2[second] )
                ans = 1 + dp[first+1][second+1];
            else
            {
                ans= max( dp[first][second+1], dp[first+1][second] );
            }
            dp[first][second]=ans;
        }
    }
    return dp[0][0];
}
int solveSpaceOpt(string &t1, string &t2 )
{
    int str1 = t1.size();
    int str2 = t2.size();
    vector<int> curr( str2+1, 0 ) , next(str2+1,0);
    for( int first= str1-1; first >= 0; first-- )
    {
        for( int second=str2-1;second >=0; second-- )
        {
            int ans=0;
            // recursive calling
            if( t1[first] == t2[second] )
                ans = 1 + next[second+1];
            else
            {
                ans= max( curr[second+1], next[second] );
            }
            curr[second]=ans;
        }
        next=curr;
    }
    return next[0];
}
int main() {
    string text1 = "abcde"; 
    string text2= "ace";
    vector<vector<int>> dp( text1.size(), vector<int> (text2.size(),-1) );
    cout<<"Recursion and Memoization: "<<solveMem( text1,text2,0,0,dp )<<endl;
    cout<<"Tabulation (Bottom Up Approach): "<<solveTab(text1,text2)<<endl;
    cout<<" Space Optimisation:  "<<solveSpaceOpt(text1,text2)<<endl;
    int n1=text1.size();
    int n2=text2.size();
    int dp2[n1][n2];
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(text1[i]==text2[j])
                dp2[i][j]=1+(i-1>=0 && j-1>=0?dp2[i-1][j-1]:0);
            else
                dp2[i][j]=max(i-1>=0?dp2[i-1][j]:0,j-1>=0?dp2[i][j-1]:0);
        }
    }
    cout<<" Another method: "<<dp2[n1-1][n2-1];
    return 0;
}