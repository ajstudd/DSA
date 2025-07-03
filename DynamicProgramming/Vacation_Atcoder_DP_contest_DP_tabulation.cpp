#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> activities(n, vector<int>(3));
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> activities[i][j];
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 3; j++)
        {

            dp[i][j] = (max(dp[i + 1][(j + 1) % 3], dp[i + 1][(j + 2) % 3])) + activities[i][j];
        }
    }
    cout << max({dp[0][0],
                 dp[0][1],
                 dp[0][2]});
    return 0;
}