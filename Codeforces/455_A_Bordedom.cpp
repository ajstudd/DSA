#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<long long, long long> freq;
long long sol(long long num, vector<long long> &dp)
{
    dp[0] = 0;
    dp[1] = freq[1];
    for (int i = 2; i <= num; i++)
    {
        dp[i] = max(dp[i - 1], freq[i] * i + dp[i - 2]);
    }
    return dp[num];
}

int main()
{
    int n;
    cin >> n;
    vector<long long> nums(n);
    long long maximumVal = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        freq[nums[i]]++;
        maximumVal = max(maximumVal, nums[i]);
    }
    vector<long long> dp(maximumVal + 1, 0);
    long long maxval = sol(maximumVal, dp);
    cout << maxval << endl;
    return 0;
}