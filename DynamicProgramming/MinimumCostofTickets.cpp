#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int solveMem( vector<int> &days, vector<int> &costs, vector<int> &dp, int index )
{
    // base case 
    if( index >= days.size() )
        return 0;
    if( dp[index] != -1 )
        return dp[index];
    // for 1 day ticket 
    int opt1 = costs[0]+ solveMem(days,costs,dp,index+1);
    // for 7 day ticket
    int idx;
    for( idx = index; idx<days.size() && days[idx] < days[index]+7; idx++ );
    int opt2 = costs[1]+ solveMem( days,costs,dp,idx );
    // for 30 day ticket
    for( idx= index; idx<days.size() && days[idx]<days[index]+30; idx++ );
    int opt3 = costs[2]+ solveMem(days,costs,dp,idx);

    dp[index]= min(opt1,min(opt2,opt3));

    return dp[index]; 
}
int solveTab( vector<int> &days, vector<int> &costs )
{
    int n =days.size();
    vector<int> dp(n+1,INT_MAX);
    dp[n]=0;
    for( int k = n-1; k>=0;k-- )
    {
        // for 1 day ticket 
        int opt1 = costs[0]+ dp[k+1];
        // for 7 day ticket
        int idx;
        for( idx = k; idx<days.size() && days[idx] < days[k]+7; idx++ );
        int opt2 = costs[1]+ dp[idx];
        // for 30 day ticket
        for( idx= k; idx<days.size() && days[idx]<days[k]+30; idx++ );
        int opt3 = costs[2]+ dp[idx];

        dp[k]= min(opt1,min(opt2,opt3));
    }
    return dp[0]; 
}
int solveOpt(vector<int>& days, vector<int>& costs)
{
    // using space optimisation using queue
    int ans=0;
    int n = days.size();
    queue<pair<int,int>> month,week;
    for( int day : days )
    {
        // for removing expired days from the front
        while(!month.empty() && month.front().first +30 <= day)
            month.pop();
        // for removing expired days from the front
        while(!week.empty()&& week.front().first +7 <= day)
            week.pop();
        // adding new days to the queues
        month.push(make_pair(day,ans+costs[2]));
        week.push(make_pair(day,ans+costs[1]));
        // updating ans value 
        ans = min( ans+costs[0],min(month.front().second,week.front().second) );
    }
    return ans;
}
int main() 
{
    vector<int> days{2,5,6,7,30};
    vector<int> costs{1,7,30};
    vector<int> dp(days.size()+1,-1);
    cout<<"Minimum Cost of Ticket using Memoization and Recursion is: "<<solveMem( days , costs, dp,0 )<<endl;;
    cout<<"Minimum Cost of Ticket using Tabulation is: "<<solveTab( days , costs )<<endl;
    cout<<"Minimum Cost of Ticket using Space Optimisation is: "<<solveOpt( days , costs )<<endl;
    return 0;
}
