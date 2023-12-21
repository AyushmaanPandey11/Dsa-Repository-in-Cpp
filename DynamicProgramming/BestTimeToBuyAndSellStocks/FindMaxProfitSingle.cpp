#include<bits/stdc++.h>
using namespace std;


int maxProfit(vector<int>& prices) {
    int profit = 0;
    int mini = prices[0];
    for( int idx=1; idx<prices.size();idx++ )
    {
        int diff = prices[idx]-mini;
        profit = max(profit,diff);
        mini = min(mini,prices[idx]);
    }
    return profit;
}
int main()
{
    vector<int> prices{7,1,3,4,6,2};
    cout<<"Max Profit You can have by buying and selling the stock is: "<<maxProfit(prices);
    return 0;
}
