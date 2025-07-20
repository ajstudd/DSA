#include <bits/stdc++.h>
using namespace std;

string findLongestRegex(string x, string y, string z)
{
    int n = x.size();

    for (int len = n; len >= 1; len--)
    {
        string regex = "";
        bool possible = true;

        for (int i = 0; i < len; i++)
        {

            if (x[i] == z[i] && y[i] == z[i])
            {
                possible = false;
                break;
            }

            string charClass = "";
            for (char c = 'A'; c <= 'Z'; c++)
            {
                if (c != z[i])
                {
                    charClass += c;
                }
            }

            regex += "[" + charClass + "]";
        }

        if (possible)
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