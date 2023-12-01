#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solveMem(std::vector<int>& obstacles, int currlane, int currpos, std::vector<std::vector<int>> &dp)
{
    int n = obstacles.size() - 1;
    // base case
    if (currpos == n)
        return 0;
    if (dp[currlane][currpos] != -1)
        return dp[currlane][currpos];
    // no obstacle
    if (obstacles[currpos + 1] != currlane)
    {
        return solveMem(obstacles, currlane, currpos + 1, dp);
    }
    else // obstacle is present 
    {
        int ans = INT_MAX;
        for (int idx = 1; idx <= 3; idx++)
        {
            if (currlane != idx && obstacles[currpos] != idx)
            {
                ans = std::min(ans, 1 + solveMem(obstacles, idx, currpos, dp));
            }
        }
        dp[currlane][currpos] = ans;
        return dp[currlane][currpos];
    }
}

int solveTab(std::vector<int>& obstacles)
{
    int n = obstacles.size() - 1;
    std::vector<std::vector<int>> dp(4, std::vector<int>(obstacles.size(), 1e9));
    dp[0][n] = dp[1][n] = dp[2][n] = dp[3][n] = 0;
    for (int currpos = n - 1; currpos >= 0; currpos--)
    {
        for (int currlane = 1; currlane <= 3; currlane++)
        {
            // no obstacle
            if (obstacles[currpos + 1] != currlane)
            {
                dp[currlane][currpos] = dp[currlane][currpos + 1];
            }
            else // obstacle is present 
            {
                int ans = 1e9;
                for (int idx = 1; idx <= 3; idx++)
                {
                    if (currlane != idx && obstacles[currpos] != idx)
                    {
                        ans = std::min(ans, 1 + dp[idx][currpos + 1]);
                    }
                }
                dp[currlane][currpos] = ans;
            }
        }
    }
    return std::min(dp[2][0], std::min(1 + dp[3][0], 1 + dp[1][0]));
}

int solveSpace(std::vector<int>& obstacles)
{
    int n = obstacles.size() - 1;
    std::vector<int> curr(4, 1e9);
    std::vector<int> next(4, 1e9);
    next[0] = next[1] = next[2] = next[3] = 0;
    for (int currpos = n - 1; currpos >= 0; currpos--)
    {
        for (int currlane = 1; currlane <= 3; currlane++)
        {
            // no obstacle
            if (obstacles[currpos + 1] != currlane)
            {
                curr[currlane] = next[currlane];
            }
            else // obstacle is present 
            {
                int ans = 1e9;
                for (int idx = 1; idx <= 3; idx++)
                {
                    if (currlane != idx && obstacles[currpos] != idx)
                    {
                        ans = std::min(ans, 1 + next[idx]);
                    }
                }
                curr[currlane] = ans;
            }
        }
        next = curr;
    }
    return std::min(next[2], std::min(1 + next[1], 1 + next[0]));
}

int main()
{

    vector<int> obstacles = {0, 2, 1, 0, 3, 0};

    // Using solveMem
    vector<vector<int>> dpMem(4, vector<int>(obstacles.size(), -1));
    int resultMem = solveMem(obstacles, 2, 0, dpMem);
    std::cout << "solveMem Result: " << resultMem << endl;

    // Using solveTab
    int resultTab = solveTab(obstacles);
    cout << "solveTab Result: " << resultTab << std::endl;

    // Using solveSpace
    int resultSpace = solveSpace(obstacles);
    cout << "solveSpace Result: " << resultSpace << endl;
    return 0;
}
