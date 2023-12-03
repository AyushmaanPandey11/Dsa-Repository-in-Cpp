#include<bits/stdc++.h>
using namespace std;
static bool comp(vector<int> &a, vector<int> &b){
    if(a[0] == b[0])
        return a[1]>b[1];

    return a[0]<b[0];
}
int solve(vector<vector<int>>& envelopes, int n) {
    if (n == 0)
        return 0;
    vector<int> ans;
    ans.push_back(envelopes[0][1]);  // Initialize with the second dimension of the first envelope
    for (int idx = 1; idx < n; idx++) {
        if (envelopes[idx][1] > ans.back()) {
            ans.push_back(envelopes[idx][1]);
        } else {
            int index = lower_bound(ans.begin(), ans.end(), envelopes[idx][1]) - ans.begin();
            ans[index] = envelopes[idx][1];
        }
    }
    return ans.size();
}

int main() {
    vector<vector<int>> envelopes{{5,4},{6,4},{6,7},{2,3}};
    int n = envelopes.size();
    sort(envelopes.begin(), envelopes.end(),comp);
    cout<<"Maximum amount of Envelopes that can be inserted inside one another is: "<<solve(envelopes, n);
    return 0;
}