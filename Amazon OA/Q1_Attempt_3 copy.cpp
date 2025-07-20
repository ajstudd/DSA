#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

string findLongestRegex(string x, string y, string z)
{
    int n = x.size();
    if (n == 0)
    {
        return "-1";
    }
    int differentiating_pos = -1;
    for (int i = 0; i < n; ++i)
    {
        if (x[i] != z[i] && y[i] != z[i])
        {
            differentiating_pos = i;
            break;
        }
    }
    if (differentiating_pos == -1)
    {
        return "-1";
    }

    string result_regex = "";
    for (int i = 0; i < n; ++i)
    {
        if (i == differentiating_pos)
        {
            string char_class_content = "";
            for (char c = 'A'; c <= 'Z'; ++c)
            {
                if (c != z[i])
                {
                    char_class_content += c;
                }
            }
            result_regex += "[" + char_class_content + "]";
        }
        else
        {
            result_regex += "[ABCDEFGHIJKLMNOPQRSTUVWXYZ]";
        }
        if (i < n - 1)
        {
            result_regex += " ";
        }
    }
    return result_regex;
}

int main()
{
    cout << findLongestRegex("AERB", "ATRC", "AGCB") << endl;
    return 0;
}