#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long countingNum(int i, bool tight, int prevDigit, bool leadingZeros, string &s, vector<vector<vector<vector<long long>>>> &dp)
{
    if (i >= s.size())
        return 1;

    if (dp[i][tight][prevDigit + 1][leadingZeros] != -1)
        return dp[i][tight][prevDigit + 1][leadingZeros];

    char up = tight ? s[i] : '9';
    long long answer = 0;

    for (char ch = '0'; ch <= up; ch++)
    {
        if (leadingZeros || ch - '0' != prevDigit)
        {
            answer += countingNum(i + 1, tight && (ch == up), ch - '0', leadingZeros && (ch == '0'), s, dp);
        }
    }

    return dp[i][tight][prevDigit + 1][leadingZeros] = answer;
}

long long countValid(long long num)
{
    if (num < 0)
        return 0;

    string s = to_string(num);

    vector<vector<vector<vector<long long>>>> dp(s.size(), vector<vector<vector<long long>>>(2, vector<vector<long long>>(11, vector<long long>(2, -1))));

    return countingNum(0, true, -1, true, s, dp);
}

int main()
{
    long long a, b;
    cin >> a >> b;
    cout << countValid(b) - countValid(a - 1) << endl;
    return 0;
}
