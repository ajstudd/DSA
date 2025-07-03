#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxPossibleSum(vector<pair<int, int>> &items, int index, int currentWt, int wt, vector<vector<int>> &dp)
{
    if (dp[index][currentWt] != -1)
    {
        return dp[index][currentWt];
    }
    if (index > items.size() - 1)
    {
        return dp[index][currentWt] = 0;
    }

    int notPick = maxPossibleSum(items, index + 1, currentWt, wt, dp);

    int pick = 0;
    if (currentWt + items[index].first <= wt)
    {
        pick = items[index].second + maxPossibleSum(items, index + 1, currentWt + items[index].first, wt, dp);
    }

    return dp[index][currentWt] = max(pick, notPick);
}

int main()
{
    int numOfItems, weight;
    cin >> numOfItems >> weight;
    vector<pair<int, int>> items(numOfItems);
    vector<vector<int>> dp(numOfItems + 1, vector<int>(weight + 1, -1));
    for (int i = 0; i < numOfItems; i++)
    {
        int item, val;
        cin >> item >> val;
        items[i] = {item, val};
    }
    cout << maxPossibleSum(items, 0, 0, weight, dp);
    return 0;
}