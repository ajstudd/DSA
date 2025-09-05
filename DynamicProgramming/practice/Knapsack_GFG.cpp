class Solution
{
public:
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
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int numOfItems = val.size();
        vector<pair<int, int>> priceAndWeight(numOfItems);
        for (int i = 0; i < numOfItems; i++)
            priceAndWeight[i] = {wt[i], val[i]};
        vector<vector<int>> dp(numOfItems + 1, vector<int>(W + 1, -1));
        return maxPossibleSum(priceAndWeight, 0, 0, W, dp);
    }
};