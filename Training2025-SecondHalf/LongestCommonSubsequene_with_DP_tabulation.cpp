#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int subsequenCount(string t1, string t2, int n, int m,
                       vector<vector<int>> &dp)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (t1[i] == t2[j])
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Initialize base cases (already 0 by default)
        for (int i = 0; i < n; i++)
        {
            dp[i][m] = 0;
        }
        for (int j = 0; j < m; j++)
        {
            dp[n][j] = 0;
        }

        return subsequenCount(text1, text2, n, m, dp);
    }
};

int main()
{
    Solution solution;

    // Test cases
    string text1 = "abcde";
    string text2 = "ace";

    cout << "Text 1: " << text1 << endl;
    cout << "Text 2: " << text2 << endl;
    cout << "Longest Common Subsequence Length: " << solution.longestCommonSubsequence(text1, text2) << endl;
    cout << endl;

    // Another test case
    text1 = "abc";
    text2 = "abc";

    cout << "Text 1: " << text1 << endl;
    cout << "Text 2: " << text2 << endl;
    cout << "Longest Common Subsequence Length: " << solution.longestCommonSubsequence(text1, text2) << endl;
    cout << endl;

    // Third test case
    text1 = "abc";
    text2 = "def";

    cout << "Text 1: " << text1 << endl;
    cout << "Text 2: " << text2 << endl;
    cout << "Longest Common Subsequence Length: " << solution.longestCommonSubsequence(text1, text2) << endl;
    cout << endl;

    // Fourth test case
    text1 = "programming";
    text2 = "algorithm";

    cout << "Text 1: " << text1 << endl;
    cout << "Text 2: " << text2 << endl;
    cout << "Longest Common Subsequence Length: " << solution.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}