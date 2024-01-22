#include<bits/stdc++.h>
using namespace std; 

struct Job 
{ 
    int id;     // Job Id 
    int dead;   // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 

class Solution 
{
    static bool cmp( Job a , Job b )
    {
        return a.profit > b.profit;
    }
    
    public:
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
{ 
    sort(arr, arr + n, cmp);
    int maxdeadline = INT_MIN;
    
    for (int idx = 0; idx < n; idx++) 
    {
        maxdeadline = max(maxdeadline, arr[idx].dead);
    }
    
    int count = 0;
    int maxprofit = 0;
    vector<int> schedule(maxdeadline + 1, -1);
    
    for (int idx = 0; idx < n; idx++) 
    {
        int currprofit = arr[idx].profit;
        int currid = arr[idx].id;
        int currdeadl = arr[idx].dead;
        
        for (int k = currdeadl; k > 0; k--) 
        {
            if (schedule[k] == -1) 
            {
                maxprofit += currprofit;
                schedule[k] = currid;
                count++;
                break;
            }
        }
    }
    
    vector<int> ans;
    ans.push_back(count);
    ans.push_back(maxprofit);
    return ans;
}

};

// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0; 
}
