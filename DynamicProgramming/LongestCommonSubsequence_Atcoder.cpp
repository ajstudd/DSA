#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string LCS(string s, string t, int ptr1, int ptr2)
{
    if (ptr1 <= 0 || ptr2 <= 0)
    {
        return "";
    }
    if (s[ptr1 - 1] == t[ptr2 - 1])
    {
        return LCS(s, t, ptr1 - 1, ptr2 - 1) + s[ptr1 - 1];
    }
    else
    {
        string a = LCS(s, t, ptr1 - 1, ptr2);
        string b = LCS(s, t, ptr1, ptr2 - 1);
        return a.length() > b.length() ? a : b;
    }
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << LCS(s, t, s.size(), t.size());
    return 0;
}