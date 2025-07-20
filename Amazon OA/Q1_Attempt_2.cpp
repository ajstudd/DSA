#include <bits/stdc++.h>
using namespace std;

string findLongestRegex(string x, string y, string z)
{
    int n = x.size();

    for (int len = n; len >= 1; len--)
    {
        string regex = "";
        bool valid = true;

        for (int i = 0; i < len; i++)
        {
            set<char> required;
            required.insert(x[i]);
            required.insert(y[i]);

            if (required.size() == 1 && required.count(z[i]))
            {
                valid = false;
                break;
            }

            required.erase(z[i]);

            if (required.empty())
            {
                valid = false;
                break;
            }

            if (required.size() == 1)
            {
                regex += *required.begin();
            }
            else
            {
                regex += "[";
                for (char c : required)
                {
                    regex += c;
                }
                regex += "]";
            }
        }

        if (valid)
        {
            return regex;
        }
    }

    return "-1";
}

int main()
{
    // Test cases
    cout << findLongestRegex("AERB", "ATRC", "AGCB") << endl;
    cout << findLongestRegex("ABCD", "CODE", "CODE") << endl;
    return 0;
}