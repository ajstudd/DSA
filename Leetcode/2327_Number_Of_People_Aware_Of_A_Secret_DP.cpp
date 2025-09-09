
/*
 * LeetCode 2327: Number of People Aware of a Secret
 *
 * PROBLEM INTUITION:
 * - On day 1, one person knows the secret
 * - A person can start sharing the secret after 'delay' days of knowing it
 * - A person forgets the secret after 'forget' days of knowing it
 * - We need to find how many people know the secret on day n
 *
 * APPROACH:
 * This is a Dynamic Programming problem where we track:
 * 1. How many new people learn the secret each day (dp array)
 * 2. How many people can share the secret each day (sharers variable)
 *
 * KEY INSIGHTS:
 * - dp[i] = number of new people who learn the secret on day i
 * - A person who learns on day i can share from day (i + delay) to day (i + forget - 1)
 * - The answer is sum of all people who still remember on day n
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        // Use modulo to prevent integer overflow as per problem constraints
        const int MOD = 1e9 + 7;

        // dp[i] = number of new people who learn the secret on day i
        vector<long long> dp(n + 1, 0);

        // Base case: On day 1, exactly 1 person knows the secret
        dp[1] = 1;

        // sharers = number of people who can currently share the secret
        // (i.e., people who learned >= delay days ago but < forget days ago)
        long long sharers = 0;

        // Process each day from 2 to n
        for (int day = 2; day <= n; day++)
        {
            // ADD NEW SHARERS:
            // People who learned the secret 'delay' days ago can now start sharing
            if (day - delay >= 1)
            {
                sharers = (sharers + dp[day - delay]) % MOD;
            }

            // REMOVE OLD SHARERS:
            // People who learned the secret 'forget' days ago forget it today
            // So they stop sharing
            if (day - forget >= 1)
            {
                sharers = (sharers - dp[day - forget] + MOD) % MOD;
                // Adding MOD before taking modulo handles negative numbers correctly
            }

            // NEW PEOPLE LEARNING TODAY:
            // All current sharers will tell the secret to new people
            // So dp[day] = current number of sharers
            dp[day] = sharers;
        }

        // CALCULATE FINAL ANSWER:
        // Count all people who still remember the secret on day n
        // These are people who learned in the last 'forget' days
        long long ans = 0;

        // Check from day (n - forget + 1) to day n
        // These people haven't forgotten yet
        for (int i = n - forget + 1; i <= n; i++)
        {
            if (i >= 1) // Ensure valid day
                ans = (ans + dp[i]) % MOD;
        }

        return (int)ans;
    }
};

// EXAMPLE WALKTHROUGH:
// Let's trace through n=6, delay=2, forget=4
// Day 1: dp[1] = 1, sharers = 0
// Day 2: sharers = 0 (no one can share yet), dp[2] = 0
// Day 3: sharers = 1 (person from day 1 can now share), dp[3] = 1
// Day 4: sharers = 1, dp[4] = 1
// Day 5: sharers = 1 - 1 + 1 = 1 (person from day 1 forgets, person from day 2 starts sharing), dp[5] = 1
// Day 6: sharers = 1 + 1 = 2 (person from day 3 starts sharing), dp[6] = 2
// Answer: dp[3] + dp[4] + dp[5] + dp[6] = 1 + 1 + 1 + 2 = 5

int main()
{
    Solution solution;

    // Test Case 1: Example from LeetCode
    cout << "Test Case 1:" << endl;
    cout << "n=6, delay=2, forget=4" << endl;
    cout << "Expected: 5, Got: " << solution.peopleAwareOfSecret(6, 2, 4) << endl;
    cout << endl;

    // Test Case 2: Simple case
    cout << "Test Case 2:" << endl;
    cout << "n=4, delay=1, forget=3" << endl;
    cout << "Expected: 6, Got: " << solution.peopleAwareOfSecret(4, 1, 3) << endl;
    cout << endl;

    // Test Case 3: Edge case - everyone forgets immediately
    cout << "Test Case 3:" << endl;
    cout << "n=3, delay=1, forget=2" << endl;
    cout << "Expected: 2, Got: " << solution.peopleAwareOfSecret(3, 1, 2) << endl;
    cout << endl;

    // Test Case 4: Large numbers
    cout << "Test Case 4 (Large numbers):" << endl;
    cout << "n=1000, delay=10, forget=50" << endl;
    cout << "Result: " << solution.peopleAwareOfSecret(1000, 10, 50) << endl;

    return 0;
}
