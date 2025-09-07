#include <iostream>
#include <vector>

using namespace std;

int LCSRecur(int i, string &s1, int j, string &s2, vector<vector<int>> &dp)
{
    if (i >= s1.size() || j >= s2.size())
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (s1[i] == s2[j])
    {
        return dp[i][j] = 1 + LCSRecur(i + 1, s1, j + 1, s2, dp);
    }
    else
    {
        return dp[i][j] = max(LCSRecur(i, s1, j + 1, s2, dp), LCSRecur(i + 1, s1, j, s2, dp));
    }
}

int main()
{
    string s1 = "heelo";
    string s2 = "haiyo";
    // 2D DP because we have to take care of two states/parameters , i and j
    vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
    cout << LCSRecur(0, s1, 0, s2, dp);
    return 0;
}