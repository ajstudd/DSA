/*
LeetCode 2327: Number of People Aware of a Secret

PROBLEM UNDERSTANDING:
- On day 1, one person discovers a secret
- Each person who knows the secret will share it with one new person per day
  after 'delay' days of knowing it
- Each person forgets the secret after 'forget' days of knowing it
- We need to find how many people know the secret on day 'n'

INTUITION:
- Track each person by when they start sharing and when they forget
- Simulate day by day, removing people who forget and adding new people
- Count active sharers to determine how many new people learn the secret

APPROACH:
1. Use a deque to track people with {shareDay, forgetDay} pairs
2. For each day from 2 to n:
   - Remove people who forgot (forgetDay <= current day)
   - Count active sharers (shareDay <= day < forgetDay)
   - Add new people for each sharer
3. Return total people who know the secret

TIME COMPLEXITY: O(n * k) where k is max people alive at any time
SPACE COMPLEXITY: O(k) for storing active people
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        const int MOD = 1e9 + 7; // Modulo to prevent integer overflow

        // Edge case: if n is 0 or negative, no one knows the secret
        if (n <= 0)
            return 0;

        // CORE DATA STRUCTURE:
        // Deque stores pairs of {shareDay, forgetDay} for each person
        // shareDay: the day this person starts sharing the secret
        // forgetDay: the day this person forgets the secret
        deque<pair<int, int>> dq;

        // INITIALIZATION:
        // First person learns on day 1
        // They will start sharing on day (1 + delay)
        // They will forget on day (1 + forget)
        dq.push_back({1 + delay, 1 + forget});

        // Track total number of people who currently know the secret
        long long total = 1;

        // SIMULATION: Process each day from 2 to n
        for (int day = 2; day <= n; ++day)
        {
            // STEP 1: REMOVE PEOPLE WHO FORGOT TODAY
            // Anyone whose forgetDay <= current day should be removed
            // Since deque is ordered by when people joined, we can pop from front
            while (!dq.empty() && dq.front().second <= day)
            {
                total--;        // Decrease total count
                dq.pop_front(); // Remove from tracking
            }

            // STEP 2: COUNT ACTIVE SHARERS
            // A person is actively sharing if:
            // - They started sharing (shareDay <= day)
            // - They haven't forgotten yet (forgetDay > day)
            int sharers = 0;
            for (auto &p : dq)
            {
                int shareDay = p.first;   // When this person starts sharing
                int forgetDay = p.second; // When this person forgets

                // Check if this person is actively sharing today
                if (shareDay <= day && forgetDay > day)
                    sharers++;
            }

            // STEP 3: ADD NEW PEOPLE
            // Each active sharer tells the secret to one new person today
            // Each new person will start sharing after 'delay' days
            // Each new person will forget after 'forget' days
            for (int i = 0; i < sharers; ++i)
            {
                total++; // Increment total count

                // Add new person with their share and forget days
                dq.push_back({day + delay, day + forget});
            }

            // Apply modulo to prevent overflow
            total %= MOD;
        }

        // FINAL RESULT:
        // Ensure positive result with double modulo technique
        // This handles negative numbers that might arise from modular arithmetic
        return (int)((total % MOD + MOD) % MOD);
    }
};

/*
MAIN FUNCTION WITH TEST CASES AND EXPLANATIONS
*/
int main()
{
    Solution solution;

    cout << "=== LeetCode 2327: Number of People Aware of a Secret ===" << endl;
    cout << "Testing different scenarios with detailed explanations:" << endl
         << endl;

    // TEST CASE 1: Basic example from LeetCode
    cout << "TEST CASE 1:" << endl;
    cout << "Input: n=6, delay=2, forget=4" << endl;
    cout << "Explanation:" << endl;
    cout << "Day 1: Person 1 learns secret" << endl;
    cout << "Day 2: No sharing yet (delay=2)" << endl;
    cout << "Day 3: Person 1 starts sharing -> Person 2 learns" << endl;
    cout << "Day 4: Person 1 still sharing -> Person 3 learns" << endl;
    cout << "Day 5: Person 1 forgets (after 4 days), Person 2 starts sharing -> Person 4 learns" << endl;
    cout << "Day 6: Person 2 still sharing, Person 3 starts sharing -> Persons 5,6 learn" << endl;
    int result1 = solution.peopleAwareOfSecret(6, 2, 4);
    cout << "Expected: 5, Got: " << result1 << endl;
    cout << (result1 == 5 ? "✓ PASSED" : "✗ FAILED") << endl
         << endl;

    // TEST CASE 2: Edge case - forget immediately after delay
    cout << "TEST CASE 2:" << endl;
    cout << "Input: n=4, delay=1, forget=3" << endl;
    cout << "Explanation:" << endl;
    cout << "Day 1: Person 1 learns" << endl;
    cout << "Day 2: Person 1 shares -> Person 2 learns" << endl;
    cout << "Day 3: Person 1 shares -> Person 3 learns, Person 2 shares -> Person 4 learns" << endl;
    cout << "Day 4: Person 1 forgets, Person 2,3 share -> 2 new people" << endl;
    int result2 = solution.peopleAwareOfSecret(4, 1, 3);
    cout << "Expected: 6, Got: " << result2 << endl;
    cout << (result2 == 6 ? "✓ PASSED" : "✗ FAILED") << endl
         << endl;

    // TEST CASE 3: Large delay (no sharing occurs)
    cout << "TEST CASE 3:" << endl;
    cout << "Input: n=3, delay=5, forget=10" << endl;
    cout << "Explanation:" << endl;
    cout << "Day 1: Person 1 learns" << endl;
    cout << "Days 2-3: No sharing yet (delay=5 > n=3)" << endl;
    cout << "Only the original person knows the secret" << endl;
    int result3 = solution.peopleAwareOfSecret(3, 5, 10);
    cout << "Expected: 1, Got: " << result3 << endl;
    cout << (result3 == 1 ? "✓ PASSED" : "✗ FAILED") << endl
         << endl;

    // TEST CASE 4: Single day
    cout << "TEST CASE 4:" << endl;
    cout << "Input: n=1, delay=1, forget=2" << endl;
    cout << "Explanation: Only day 1, one person learns the secret" << endl;
    int result4 = solution.peopleAwareOfSecret(1, 1, 2);
    cout << "Expected: 1, Got: " << result4 << endl;
    cout << (result4 == 1 ? "✓ PASSED" : "✗ FAILED") << endl
         << endl;

    // TEST CASE 5: Immediate sharing and forgetting
    cout << "TEST CASE 5:" << endl;
    cout << "Input: n=5, delay=1, forget=2" << endl;
    cout << "Explanation:" << endl;
    cout << "People share immediately after 1 day but forget after 2 days" << endl;
    cout << "This creates a rapid turnover of who knows the secret" << endl;
    int result5 = solution.peopleAwareOfSecret(5, 1, 2);
    cout << "Got: " << result5 << endl
         << endl;

    // COMPLEXITY ANALYSIS
    cout << "=== COMPLEXITY ANALYSIS ===" << endl;
    cout << "Time Complexity: O(n * k)" << endl;
    cout << "  - n: number of days to simulate" << endl;
    cout << "  - k: maximum number of people alive at any time" << endl;
    cout << "  - In worst case, k can be O(2^min(delay, forget))" << endl
         << endl;

    cout << "Space Complexity: O(k)" << endl;
    cout << "  - k: maximum number of people we need to track" << endl;
    cout << "  - Deque stores at most k people at any time" << endl
         << endl;

    // ALGORITHM WALKTHROUGH
    cout << "=== ALGORITHM WALKTHROUGH ===" << endl;
    cout << "1. INITIALIZATION:" << endl;
    cout << "   - Start with one person knowing the secret on day 1" << endl;
    cout << "   - Track when they start sharing and when they forget" << endl
         << endl;

    cout << "2. DAILY SIMULATION:" << endl;
    cout << "   - Remove people who forgot today" << endl;
    cout << "   - Count active sharers (started sharing but not forgotten)" << endl;
    cout << "   - Add new people (one per active sharer)" << endl
         << endl;

    cout << "3. TRACKING METHOD:" << endl;
    cout << "   - Use deque of {shareDay, forgetDay} pairs" << endl;
    cout << "   - Efficiently remove from front (oldest forgetter)" << endl;
    cout << "   - Add to back (newest learners)" << endl
         << endl;

    cout << "=== KEY INSIGHTS ===" << endl;
    cout << "• The problem is essentially a discrete simulation" << endl;
    cout << "• Each person has a 'lifetime' during which they can share" << endl;
    cout << "• The total grows exponentially initially, then stabilizes" << endl;
    cout << "• Modular arithmetic prevents integer overflow" << endl;
    cout << "• Deque provides efficient insertion/deletion at both ends" << endl;

    return 0;
}
