#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solveMem(vector<int>& nums, int n, int curr, int prev, vector<vector<int>>& dp) {
    if (curr == n)
        return 0;
    if (dp[curr][prev + 1] != -1) {
        return dp[curr][prev + 1];
    }
    int take = 0;
    if (prev == -1 || nums[curr] > nums[prev]) {
        take = 1 + solveMem(nums, n, curr + 1, curr, dp);
    }
    int nottake = 0 + solveMem(nums, n, curr + 1, prev, dp);

    return dp[curr][prev + 1] = max(take, nottake);
}

int solveTab(vector<int>& nums, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int curr = n - 1; curr >= 0; curr--) {
        for (int prev = curr - 1; prev >= -1; prev--) {
            int take = 0;
            if (prev == -1 || nums[curr] > nums[prev]) {
                take = 1 + dp[curr + 1][curr + 1];
            }
            int nottake = 0 + dp[curr + 1][prev + 1];

            dp[curr][prev + 1] = max(take, nottake);
        }
    }
    return dp[0][0];
}

int solveSpacOpt(vector<int>& nums, int n) {
    vector<int> currrow(n + 1, 0), next(n + 1, 0);
    for (int curr = n - 1; curr >= 0; curr--) {
        for (int prev = curr - 1; prev >= -1; prev--) {
            int take = 0;
            if (prev == -1 || nums[curr] > nums[prev]) {
                take = 1 + next[curr + 1];
            }
            int nottake = 0 + next[prev + 1];
            currrow[prev + 1] = max(take, nottake);
        }
        next = currrow;
    }
    return next[0];
}

int solveOptimal(vector<int>& nums, int n) {
    if (n == 0)
        return 0;
    vector<int> ans;
    ans.push_back(nums[0]);
    for (int idx = 0; idx < n; idx++) {
        if (nums[idx] > ans.back()) {
            ans.push_back(nums[idx]);
        } else {
            int index = lower_bound(ans.begin(), ans.end(), nums[idx]) - ans.begin();
            ans[index] = nums[idx];
        }
    }
    return ans.size();
}


int main() {
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    
    // Using solveMem
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
    int resultMem = solveMem(nums, nums.size(), 0, -1, dp);
    cout << "solveMem result: " << resultMem << endl;

    // Using solveTab
    int resultTab = solveTab(nums, nums.size());
    cout << "solveTab result: " << resultTab << endl;

    // Using solveSpacOpt
    int resultSpacOpt = solveSpacOpt(nums, nums.size());
    cout << "solveSpacOpt result: " << resultSpacOpt << endl;

    // Using solveOptimal
    int resultOptimal = solveOptimal(nums, nums.size());
    cout << "solveOptimal result: " << resultOptimal << endl;

    return 0;
}
