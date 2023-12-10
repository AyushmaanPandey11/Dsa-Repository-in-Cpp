#include<bits/stdc++.h>
using namespace std;
int longestArithSeqLength(vector<int>& nums) 
{
    int n = nums.size();
    if( n <= 2 )
        return n;
    unordered_map<int,int> dp[n+1];
    int ans =0;
    for( int idx=1; idx<n;idx++ )
    {
        for( int prev=0; prev<idx;prev++ )
        {
            int diff = nums[idx]-nums[prev];
            if( dp[prev].count(diff) )
            // 1 is added to include the idx element count as we are storing it to idx dp of difference diff
                dp[idx][diff] = 1+ dp[prev][diff];
            else
            // 2 as when no early value is found , it will then found new squence of length 2 of (nums[prev],nums[idx])
                dp[idx][diff]=2;
            ans = max(ans,dp[idx][diff]);
        }
    }
    return ans;    
}
int main()
{
    vector<int> nums{1,7,10,13,19};
    int n = nums.size();
    cout<<" Longest Arithmetic Sequence length in the array is: "<<longestArithSeqLength(nums);
    return 0;
}