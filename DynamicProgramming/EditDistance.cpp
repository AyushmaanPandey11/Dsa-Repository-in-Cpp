#include<bits/stdc++.h>
using namespace std;
 
int solve( string &word1, string &word2, int first, int second )
{
    // base cases
    if( first == word1.length() )
        return word2.length()-second;
    if( second == word2.length() )
        return word1.length()-first;
    
    int ans=0;
    if( word1[first] == word2[second] )
        return solve(word1,word2,first+1,second+1);
    else
    {
        int insert = 1 + solve(word1,word2,first,second+1);
        int replace = 1 + solve(word1,word2,first+1,second+1);
        int remove = 1 + solve(word1,word2,first+1,second);
        ans = min(insert,min(replace,remove));
    }   
    return ans;
}
int solveMem( string &word1, string &word2, int first, int second,vector<vector<int>> &dp )
{
    // base cases
    if( first == word1.length() )
        return word2.length()-second;
    if( second == word2.length() )
        return word1.length()-first;
    
    if( dp[first][second] != -1 )
        return dp[first][second];
    int ans=0;
    if( word1[first] == word2[second] )
        return solveMem(word1,word2,first+1,second+1,dp);
    else
    {
        int insert = 1 + solveMem(word1,word2,first,second+1,dp);
        int replace = 1 + solveMem(word1,word2,first+1,second+1,dp);
        int remove = 1 + solveMem(word1,word2,first+1,second,dp);
        ans = min(insert,min(replace,remove));
    }   
    return dp[first][second]=ans;
}
int solveTab( string &word1, string &word2 )
{
    vector<vector<int>> dp( word1.length()+1, vector<int> (word2.length()+1,0));
    // base case value assignmnet
    for( int col = 0 ; col < word2.length() ; col++ )
    {
        // last row values
        dp[word1.length()][col]= word2.length()-col;
    }
    for( int row = 0 ; row < word1.length() ; row++ )
    {
        // last col values
        dp[row][word2.length()]= word1.length()-row;
    }
    for( int first= word1.length()-1; first >=0; first-- )
    {
        for( int second=word2.length()-1;second >=0; second-- )
        {
            int ans=0;
            if( word1[first] == word2[second] )
                ans= dp[first+1][second+1];
            else
            {
                int insert = 1 + dp[first][second+1];
                int replace = 1 +dp[first+1][second+1];
                int remove = 1 + dp[first+1][second];
                ans = min(insert,min(replace,remove));
            }   
            dp[first][second]=ans;
        }
    }
    return dp[0][0];
}
int solveSpaceOpt( string &word1, string &word2 )
{
    vector<int> curr(word2.length()+1,0), next(word2.length()+1,0);
    // base case value assignmnet
    for( int col = 0 ; col < word2.length() ; col++ )
    {
        // last row values
        next[col]= word2.length()-col;
    }
    for( int first= word1.length()-1; first >=0; first-- )
    {
        for( int second=word2.length()-1;second >=0; second-- )
        {
            curr[word2.length()] = word1.length()-first;
            int ans=0;
            if( word1[first] == word2[second] )
                ans= next[second+1];
            else
            {
                int insert = 1 + curr[second+1];
                int replace = 1 +next[second+1];
                int remove = 1 + next[second];
                ans = min(insert,min(replace,remove));
            }   
            curr[second]=ans;
        }
        next=curr;
    }
    return next[0];
}
int main() {
    string word1= "horse";
    string word2="ros";
    if( word1.length() == 0 )
        return word2.length();
    if(word2.length() == 0)
        return word1.length();
    vector<vector<int>> dp( (word1.length()+1), vector<int> (word2.length(),-1));
    cout<<"Answer using Recursion:"<<solve(word1,word2,0,0)<<endl;
    cout<<"Answer using Recursion and Memoization:"<<solveMem(word1,word2,0,0,dp)<<endl;
    cout<<"Answer using Tabulation:"<<solveTab(word1,word2)<<endl;
    cout<<"Answer Tabulation(Space Opt):"<<solveSpaceOpt(word1,word2)<<endl;
    return 0;
}