#include<bits/stdc++.h>
using namespace std;

int solveMem( vector<int>& nums1, vector<int>& nums2, int index, bool swapped, vector<vector<int>> &dp )
{
    int n = nums1.size();
    // base case 
    if( index == n )
        return 0;
    if( dp[index][swapped] != -1 )
        return dp[index][swapped];
    int ans = INT_MAX;
    int prev1 = nums1[index-1];
    int prev2 = nums2[index-1];
    if(swapped)
    {
        swap(prev1,prev2);
        // int temp = prev1;
        // prev1=prev2;
        // prev2=prev1;
    }
    // no swap
    if( nums1[index] > prev1 && nums2[index]>prev2 )
        ans = solveMem( nums1, nums2, index+1, 0,dp );
    if( nums1[index] > prev2 && nums2[index]>prev1 )
        ans = min(ans,1+solveMem(nums1,nums2,index+1,1,dp));
    return dp[index][swapped]=ans;
}
int solveTab( vector<int>& nums1, vector<int>& nums2 )
{
    int n = nums1.size();
    vector<vector<int>> dp( n+1, vector<int> (2,0) );
    for( int index = n-1; index>= 1; index-- )
    {
        for( int swapped=1; swapped >=0; swapped-- )
        {
            int ans = INT_MAX;
            int prev1 = nums1[index-1];
            int prev2 = nums2[index-1];
            if(swapped)
            {
                swap(prev1,prev2);
                // int temp = prev1;
                // prev1=prev2;
                // prev2=prev1;
            }
            // no swap
            if( nums1[index] > prev1 && nums2[index]>prev2 )
                ans = dp[index+1][0];
            if( nums1[index] > prev2 && nums2[index]>prev1 )
                ans = min(ans,1+dp[index+1][1]);
            dp[index][swapped]=ans;
        }
    }
    return dp[1][0];
}
int solveSpaceOpt( vector<int>& nums1, vector<int>& nums2 )
{
    int n = nums1.size();
    int swap=0;
    int noswap=0;
    int currswap=0,currnoswap=0;
    for( int index = n-1; index>= 1; index-- )
    {
        for( int swapped=1; swapped >=0; swapped-- )
        {
            int ans = INT_MAX;
            int prev1 = nums1[index-1];
            int prev2 = nums2[index-1];
            if(swapped)
            {
                int temp = prev1;
                prev1=prev2;
                prev2=temp;
            }
            // no swap
            if( nums1[index] > prev1 && nums2[index]>prev2 )
                ans = noswap;
            if( nums1[index] > prev2 && nums2[index]>prev1 )
                ans = min(ans,1+swap);
            if( swapped )
            {
                currswap=ans;
            }
            else
                currnoswap=ans;
        }
        swap=currswap;
        noswap=currnoswap;
    }
    return min(noswap,swap);
}
int main() {
    vector<int> nums1{1,3,4,7,6};
    vector<int> nums2{0,1,2,5,8};
    nums1.insert(nums1.begin(),-1);
    nums2.insert(nums2.begin(),-1);
    int n = nums1.size();
    vector<vector<int>> dp( n, vector<int> (2,-1) );
    bool swapped = 0;
    cout<<"Minimum Number of Swapping required to make the sequences increasing using recursion and Memoization is: "<<solveMem( nums1, nums2,1,swapped,dp )<<endl;
    cout<<"Minimum Number of Swapping required to make the sequences increasing using Tabulation is: "<<solveTab(nums1,nums2)<<endl;
    cout<<"Minimum Number of Swapping required to make the sequences increasing Space Optimisation is: "<<solveSpaceOpt( nums1,nums2 );
    return 0;
}
