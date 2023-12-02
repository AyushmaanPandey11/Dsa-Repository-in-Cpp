#include<bits/stdc++.h>
using namespace std;

int solveMem(vector<int>& satisfaction, int index, int time, vector<vector<int>> &dp)
{
    int n = satisfaction.size();
    if (index == n)
        return 0;
    if (dp[index][time] != -1)
        return dp[index][time];
    int inc = satisfaction[index] * (time + 1) + solveMem(satisfaction, index + 1, time + 1, dp);
    int exc = 0 + solveMem(satisfaction, index + 1, time, dp);
    dp[index][time] = max(inc, exc);

    return dp[index][time];
}
int solveTab(vector<int>& satisfaction)
{
    int n = satisfaction.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for( int index=n-1; index >= 0; index-- )
    {
        for( int time = n-1; time >= 0 ; time-- )
        {
            int inc = satisfaction[index] * (time + 1) + dp[index+1][time+1];
            int exc = 0 + dp[index+1][time];
            dp[index][time] = max(inc, exc);                
        }
    }
    return dp[0][0];
}
int solveSpaceOpt(vector<int>& satisfaction)
{
    int n = satisfaction.size();
    vector<int> curr(n+1,0),next(n+1,0);
    for( int index=n-1; index >= 0; index-- )
    {
        for( int time = n-1; time >= 0 ; time-- )
        {
            int inc = satisfaction[index] * (time + 1) + next[time+1];
            int exc = 0 + next[time];
            curr[time] = max(inc, exc);                
        }
        next=curr;
    }
    return next[0]; 
}
int main() {
    vector<int> satisfaction{4,3,2};
    int n = satisfaction.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    sort(satisfaction.begin(),satisfaction.end());
    cout<<"Maximum Like Time Satisfaction required in Memoization is: "<<solveMem(satisfaction, 0, 0, dp)<<endl;
    cout<<"Maximum Like Time Satisfaction required in Tabulation  is: "<<solveTab(satisfaction)<<endl;
    cout<<"Maximum Like Time Satisfaction required in Space Optimization is: "<<solveSpaceOpt(satisfaction)<<endl;
    return 0;
}

