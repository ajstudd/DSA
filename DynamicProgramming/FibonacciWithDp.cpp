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

/*
Worst Case Time Complexity: O(n)
The algorithm fills the DP array from index 2 to n in a single loop, each taking O(1) time.
The printing loop also takes O(n) time to display all computed values.
Space complexity is O(n) for the DP array, but we compute each Fibonacci number only once.
This is much better than the exponential O(2^n) naive recursive approach.
*/
