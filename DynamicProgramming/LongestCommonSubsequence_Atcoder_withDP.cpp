#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string LCS(string s, string t, int ptr1, int ptr2, vector<vector<string>> &dp)
{
    if (ptr1 <= 0 || ptr2 <= 0)
    {
        return "";
    }
    if (dp[ptr1][ptr2] != "")
        return dp[ptr1][ptr2];

    if (s[ptr1 - 1] == t[ptr2 - 1])
        return dp[ptr1][ptr2] = LCS(s, t, ptr1 - 1, ptr2 - 1, dp) + s[ptr1 - 1];

    string a = LCS(s, t, ptr1 - 1, ptr2, dp);
    string b = LCS(s, t, ptr1, ptr2 - 1, dp);
    return dp[ptr1][ptr2] = a.length() > b.length() ? a : b;
}

int main()
{
    string s, t;
    cin >> s >> t;
    int firstSize = s.size();
    int secondSize = t.size();
    vector<vector<string>> dp(firstSize + 1, vector<string>(secondSize + 1, ""));
    cout << LCS(s, t, firstSize, secondSize, dp);
    return 0;
}