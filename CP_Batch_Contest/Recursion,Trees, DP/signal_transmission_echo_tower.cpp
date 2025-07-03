#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCostToReachN(int index, vector<int> &dp, vector<int> &towers)
{
    if (index >= towers.size())
    {
        return 0;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    if (index == towers.size() - 1)
    {
        return dp[index] = 0;
    }

    int cost1 = abs(towers[index + 1] - towers[index]) + minCostToReachN(index + 1, dp, towers);

    if (index + 2 < towers.size())
    {
        int cost2 = abs(towers[index + 2] - towers[index]) + minCostToReachN(index + 2, dp, towers);
        return dp[index] = min(cost1, cost2);
    }
    else
    {
        return dp[index] = cost1;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> towers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> towers[i];
    }
    vector<int> dp(n + 1, -1);
    cout << minCostToReachN(0, dp, towers) << endl;
    return 0;
}
