#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maxPossibleSum(vector<pair<int, long long>> &items, int index, int currentWt, int wt, vector<vector<long long>> &dp)
{
    if (index >= items.size())
    {
        return 0;
    }

    if (dp[index][currentWt] != -1)
    {
        return dp[index][currentWt];
    }

    long long notPick = maxPossibleSum(items, index + 1, currentWt, wt, dp);

    long long pick = 0;
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

    vector<pair<int, long long>> items(numOfItems);
    vector<vector<long long>> dp(numOfItems, vector<long long>(weight + 1, -1));

    for (int i = 0; i < numOfItems; i++)
    {
        int item;
        long long val;
        cin >> item >> val;
        items[i] = {item, val};
    }

    cout << maxPossibleSum(items, 0, 0, weight, dp) << endl;
    return 0;
}