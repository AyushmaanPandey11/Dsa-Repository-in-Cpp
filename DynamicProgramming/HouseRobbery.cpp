#include<bits/stdc++.h>
using namespace std;
int solveSpaceOpt( vector<int> &house, int n )
{
    int prev2 = 0; // less than 0
    int prev1 = house[0]; 
    for( int idx=1; idx<n; idx++ )
    {
        int inclusive = prev2 + house[idx];
        int exclusive = prev1 + 0;
        int ans = max(inclusive,exclusive);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
int main ()
{
    vector<int> house{3000, 4500000 , 1000, 56778, 90000};
    int n = house.size();
    if( n == 1 )
        return house[0];
    vector<int> first,second;
    for( int idx =0; idx<n;idx++ )
    {
        if( idx != n-1 )
        {
            first.push_back(house[idx]);
        }
        if( idx != 0 )
        {
            second.push_back(house[idx]);
        }    
    }
    int totalAmountRobbed = max(solveSpaceOpt(first,n),solveSpaceOpt(second,n));
    cout<<"Total Amount Robbed by Robberer without getting detected:"<<totalAmountRobbed;
    return 0;
}