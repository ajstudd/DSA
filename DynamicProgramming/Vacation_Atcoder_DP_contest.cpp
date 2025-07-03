#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxPoints(int dayNumber, int chosenActivity, vector<vector<int>> &activities, vector<vector<int>> &dp)
{
    if (dp[dayNumber][chosenActivity] != -1)
    {
        return dp[dayNumber][chosenActivity];
    }
    if (dayNumber > activities.size() - 1)
    {
        return dp[dayNumber][chosenActivity] = 0;
    }
    dp[dayNumber][chosenActivity] = (max(maxPoints(dayNumber + 1, (chosenActivity + 1) % 3, activities, dp),
                                         maxPoints(dayNumber + 1, (chosenActivity + 2) % 3, activities, dp))) +
                                    activities[dayNumber][chosenActivity];
    return dp[dayNumber][chosenActivity];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> activities(n, vector<int>(3));
    vector<vector<int>> dp(n + 1, vector<int>(3, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> activities[i][j];
        }
    }
    cout << max({maxPoints(0, 0, activities, dp), maxPoints(0, 1, activities, dp), maxPoints(0, 2, activities, dp)});
    return 0;
}