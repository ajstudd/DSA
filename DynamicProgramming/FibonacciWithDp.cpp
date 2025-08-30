#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 5;
    vector<int> dp(n + 1, 0);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << "Fibonacci till n=" << n << " :" << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << "fib(" << i << ") = " << dp[i] << endl;
    }

    return 0;
}
