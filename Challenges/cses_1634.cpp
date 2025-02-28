// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <climits>
// using namespace std;

// int minCoins(int i, int n, vector<int> coins)
// {
//     int size = coins.size();
//     if (i >= size)
//     {
//         if (n == 0)
//         {
//             return 0;
//         }
//         else
//         {
//             return INT_MAX;
//         }
//     }
//     int answer = min(minCoins(i + 1, n, coins), coins[i] + minCoins(i, n - coins[i], coins));
//     cout << "answer" << answer;
//     return answer;
// }

// int main()
// {
//     int numOfCoins, amount;
//     cin >> numOfCoins >> amount;
//     vector<int> coins(numOfCoins);
//     for (int i = 0; i < numOfCoins; i++)
//     {
//         cin >> coins[i];
//     }
//     cout << minCoins(0, amount, coins);
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <climits>
// using namespace std;

// int minCoins(int n, vector<int> coins, vector<vector<int>> &dp)
// {
//     int size = coins.size();
//     for (int i = size - 1; i >= 0; i--)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             dp[i][j] = min(dp[i + 1][n], 1 + dp[i][n - coins[i]]);
//         }
//     }
//     return dp[coins.size()][n];
// }

// int main()
// {
//     int numOfCoins, amount;
//     cin >> numOfCoins >> amount;
//     vector<int> coins(numOfCoins);
//     for (int i = 0; i < numOfCoins; i++)
//     {
//         cin >> coins[i];
//     }
//     vector<vector<int>> dp(numOfCoins + 1, vector<int>(amount + 1));
//     dp[numOfCoins][0] = 0;
//     cout << minCoins(amount, coins, dp);
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int minCoins(int n, vector<int> coins, vector<vector<int>> &dp)
{
    int size = coins.size();

    for (int i = 0; i <= size; i++)
        dp[i][0] = 0;
    for (int j = 1; j <= n; j++)
        dp[size][j] = INT_MAX;

    for (int i = size - 1; i >= 0; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i + 1][j];
            if (j >= coins[i] && dp[i][j - coins[i]] != INT_MAX)
            {
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i]]);
            }
        }
    }
    return dp[0][n];
}

int main()
{
    int numOfCoins, amount;
    cin >> numOfCoins >> amount;
    vector<int> coins(numOfCoins);
    for (int i = 0; i < numOfCoins; i++)
    {
        cin >> coins[i];
    }

    vector<vector<int>> dp(numOfCoins + 1, vector<int>(amount + 1, INT_MAX));

    int result = minCoins(amount, coins, dp);
    if (result == INT_MAX)
        cout << -1 << endl;
    else
        cout << result << endl;

    return 0;
}
