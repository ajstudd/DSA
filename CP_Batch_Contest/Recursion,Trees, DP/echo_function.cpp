#include <iostream>
#include <unordered_map>
using namespace std;

// 0 <= n <= 10^18
long long echofun(long long n, unordered_map<long long, long long> &dp)
{
    if (dp.find(n) != dp.end())
    {
        return dp[n];
    }
    if (n == 0)
    {
        return dp[n] = 1;
    }
    else
    {
        return dp[n] = echofun(n / 2, dp) + echofun(n / 3, dp);
    }
}

int main()
{
    long long n;
    cin >> n;
    unordered_map<long long, long long> dp;
    cout << echofun(n, dp);
    return 0;
}

// why Recursion will give TLE,
// n <= 10^18
// and our time complexity is : 2^steps
// total steps = log base 2(10^18)
// 2^steps = 2^(log base 2(10^18)), which in return will give 10^18 again

// Another thing, vector or array creation of size 10^6 will give Runtime Error

// how much size increase we get when we use long long?