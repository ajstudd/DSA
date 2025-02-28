#include <iostream>
#include <vector>
using namespace std;

int numOfWays(int i, vector<int> &dp)
{
    // int answer = 0;
    // if (i <= 0)
    // {
    //     return 1;
    // }
    // if (i <= 2)
    // {
    //     return i;
    // }
    for (int j = 3; j <= i; j++)
    {
        for (int k = 1; k <= 6; k++)
            if (j - k >= 0)
            {
                dp[j] += dp[j - k];
            }
    }
    return dp[i];
}

int main()
{
    int n;
    int modulo = 10000000007;
    cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    cout << numOfWays(n, dp) % modulo;
    return 0;
}