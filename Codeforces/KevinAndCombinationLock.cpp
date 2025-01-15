// Kevin is trapped in Lakeside Village by Grace. At the exit of the village, there is a combination lock that can only be unlocked if Kevin solves it.

// The combination lock starts with an integer x
// . Kevin can perform one of the following two operations zero or more times:

// If x≠33
// , he can select two consecutive digits 3
//  from x
//  and remove them simultaneously. For example, if x=13323
// , he can remove the second and third 3
// , changing x
//  to 123
// .
// If x≥33
// , he can change x
//  to x−33
// . For example, if x=99
// , he can choose this operation to change x
//  to 99−33=66
// .
// When the value of x
//  on the combination lock becomes 0
// , Kevin can unlock the lock and escape from Lakeside Village. Please determine whether it is possible for Kevin to unlock the combination lock and escape.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤104
// ).

// The only line of each test case contains a positive integer x
//  (1≤x≤109
// ).

// Output
// For each test case, output "YES" or "NO" (without quotes) in one line, representing whether Kevin can unlock the combination lock and escape. You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

// Example
// InputCopy
// 5
// 165
// 6369
// 666
// 114514
// 133333332
// OutputCopy
// YES
// YES
// NO
// NO
// YES

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool canBeSolved(int num)
{
}

int main()
{
    vector<int> inputs;
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> inputs[i];
    }
}

// INFO: This was solved using chat gpt
// *First question in Codeforces Global Round 28
// REMARK: Memort Limit Exceeded
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

// Helper function to check if Kevin can unlock the lock
bool canUnlock(int x, unordered_set<int> &visited)
{
    // Base case: if x becomes 0, return true
    if (x == 0)
        return true;

    // If x is already visited, return false to avoid loops
    if (visited.count(x))
        return false;

    // Mark x as visited
    visited.insert(x);

    // Operation 1: Subtract 33 if x >= 33
    if (x >= 33 && canUnlock(x - 33, visited))
    {
        return true;
    }

    // Operation 2: Remove two consecutive digits
    string numStr = to_string(x);
    int len = numStr.length();
    for (int i = 0; i < len - 1; ++i)
    {
        string newNumStr = numStr.substr(0, i) + numStr.substr(i + 2);
        if (!newNumStr.empty())
        {
            int newNum = stoi(newNumStr);
            if (canUnlock(newNum, visited))
            {
                return true;
            }
        }
    }

    // If neither operation works, return false
    return false;
}

int main()
{
    int t; // Number of test cases
    cin >> t;

    while (t--)
    {
        int x;
        cin >> x;

        // Use a set to track visited states for the current test case
        unordered_set<int> visited;

        // Check if the number can be unlocked
        if (canUnlock(x, visited))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}

// INFO: Chat GPT Attempt 2
// *First question in Codeforces Global Round 28
// REMARK: Wrong Answer on pretest 1
#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

bool canUnlock(int x)
{
    queue<int> q;
    unordered_set<int> visited;

    q.push(x);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        // If the number becomes 0, Kevin can unlock
        if (current == 0)
        {
            return true;
        }

        // Mark the current number as visited
        if (visited.count(current))
        {
            continue;
        }
        visited.insert(current);

        // Operation 1: Subtract 33 if current >= 33
        if (current >= 33)
        {
            q.push(current - 33);
        }

        // Operation 2: Remove two consecutive digits
        string numStr = to_string(current);
        int len = numStr.length();

        for (int i = 0; i < len - 1; ++i)
        {
            string newNumStr = numStr.substr(0, i) + numStr.substr(i + 2);
            if (!newNumStr.empty())
            {
                int newNum = stoi(newNumStr);
                q.push(newNum);
            }
        }
    }

    // If we exhaust all possibilities without finding 0, return false
    return false;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x;
        cin >> x;

        if (canUnlock(x))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}

// Third try
// again wrong answer
#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

bool canUnlock(int x)
{
    queue<int> q;
    unordered_set<int> visited;

    // Start with the given number
    q.push(x);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        // If the number becomes 0, Kevin can unlock the lock
        if (current == 0)
        {
            return true;
        }

        // Mark the current number as visited
        if (visited.count(current))
        {
            continue;
        }
        visited.insert(current);

        // Operation 1: Subtract 33 if current >= 33
        if (current >= 33)
        {
            q.push(current - 33);
        }

        // Operation 2: Remove two consecutive digits
        string numStr = to_string(current);
        int len = numStr.length();

        for (int i = 0; i < len - 1; ++i)
        {
            string newNumStr = numStr.substr(0, i) + numStr.substr(i + 2);
            if (!newNumStr.empty())
            {
                int newNum = stoi(newNumStr);
                q.push(newNum);
            }
        }
    }

    // If we exhaust all possibilities without finding 0, return false
    return false;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x;
        cin >> x;

        if (canUnlock(x))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
