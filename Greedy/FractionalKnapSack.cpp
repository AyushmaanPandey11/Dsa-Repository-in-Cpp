#include<bits/stdc++.h>
using namespace std;

static bool cmp(pair<double, vector<int>> a, pair<double, vector<int>> b)
{
    return a.first > b.first;
}

double fractionalKnapSack(int capacity, vector<vector<int>> &item, int n)
{
    vector<pair<double, vector<int>>> v;
    for (int idx = 0; idx < n; idx++)
    {
        double perunitValue = (1.0 * item[idx][0]) / item[idx][1];
        pair<double, vector<int>> p = make_pair(perunitValue, item[idx]);
        v.push_back(p);
    }
    sort(v.begin(), v.end(), cmp);
    double totalValue = 0;
    for (int idx = 0; idx < n; idx++)
    {
        if (v[idx].second[1] > capacity)
        {
            totalValue += capacity * v[idx].first;
            capacity = 0;
        }
        else
        {
            totalValue += v[idx].first;
            capacity = capacity - v[idx].second[1];
        }
    }
    return totalValue;
}

int main()
{
    int capacity = 50;
    vector<vector<int>> item{ {60, 10}, {100, 20}, {120, 30} };
    int n = 3;
    cout << "Maximum value of items thief can take in his knapsack is: " << fractionalKnapSack(capacity, item, n);
    return 0;
}
