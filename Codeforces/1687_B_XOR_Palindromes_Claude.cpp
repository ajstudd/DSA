#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string tStringMaker(string s)
{
    int n = s.length();
    int mismatched_pairs = 0;
    int matched_pairs = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
        {
            mismatched_pairs++;
        }
        else
        {
            matched_pairs++;
        }
    }

    bool has_middle = (n % 2 == 1);

    string t = "";

    for (int i = 0; i <= n; i++)
    {
        bool is_good = false;
        if (i >= mismatched_pairs)
        {
            int remaining = i - mismatched_pairs;
            if (remaining <= 2 * matched_pairs && remaining % 2 == 0)
            {
                if (has_middle)
                {
                    is_good = true;
                }
                else
                {
                    is_good = true;
                }
            }
            else if (has_middle && remaining >= 1)
            {
                int remaining_after_middle = remaining - 1;
                if (remaining_after_middle <= 2 * matched_pairs && remaining_after_middle % 2 == 0)
                {
                    is_good = true;
                }
            }
        }

        t += (is_good ? '1' : '0');
    }

    return t;
}

int main()
{
    int tcases;
    cin >> tcases;
    while (tcases--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << tStringMaker(s) << endl;
    }
    return 0;
}