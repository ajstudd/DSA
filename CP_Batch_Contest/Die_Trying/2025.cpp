#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

// You are given a year represented by a string s, consisting of exactly 4 characters. Thus, leading zeros are allowed in the year representation. For example, "0001", "0185", "1375" are valid year representations. You need to express it in the form (a+b)^2, where a and b are non-negative integers, or determine that it is impossible.

// For example, if s = "0001", you can choose a=0, b=1, and write the year as (0+1)^2=1.

// Input
// The first line of the input contains a single integer t (1≤t≤10^4 ) — the number of test cases.

// The following lines describe the test cases.

// The only line of each test case contains a string s, consisting of exactly 4 characters. Each character is a digit from 0 to 9.
// (a+b)^2 == year , output a and b
// otherwise -1
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string year;
        cin >> year;
        pair<int, int> ab;
        int numYear = stoi(year);
        if (numYear == 1)
        {
            cout << 0 << " " << 1 << endl;
            continue;
        }
        int sqrtYear = sqrt((double)numYear);
        bool has_found = false;
        if (sqrtYear * sqrtYear == numYear)
        {
            for (int i = 0; i <= sqrtYear; i++)
            {
                int a = i;
                int b = sqrtYear - i;
                if (b >= 0)
                {
                    ab = {a, b};
                    has_found = true;
                    break;
                }
            }
        }
        if (has_found)
        {
            cout << ab.first << " " << ab.second << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}