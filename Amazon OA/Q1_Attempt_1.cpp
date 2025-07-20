#include <bits/stdc++.h>
using namespace std;

string findLongestRegex(string x, string y, string z)
{
    int n = x.size();
    string result = "";

    for (int i = 0; i < n; i++)
    {
        if (z[i] == x[i] && z[i] == y[i])
        {
            return "-1";
        }

        string charClass = "";
        for (char c = 'A'; c <= 'Z'; c++)
        {
            if (c != z[i])
            {
                charClass += c;
            }
        }

        if (charClass.length() > 1)
        {
            result += "[" + charClass + "]";
        }
        else
        {
            result += charClass;
        }
    }

    return result;
}

int main()
{
    cout << findLongestRegex("AERB", "ATRC", "AGCB") << endl;
    cout << findLongestRegex("ABCD", "CODE", "CODE") << endl;
    return 0;
}