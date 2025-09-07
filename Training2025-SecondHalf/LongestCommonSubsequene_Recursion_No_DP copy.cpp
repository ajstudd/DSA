#include <iostream>
#include <vector>

using namespace std;

int LCSRecur(int i, string &s1, int j, string &s2)
{
    if (i >= s1.size() || j >= s2.size())
    {
        return 0;
    }
    if (s1[i] == s2[j])
    {
        return 1 + LCSRecur(i + 1, s1, j + 1, s2);
    }
    else
    {
        return max(LCSRecur(i, s1, j + 1, s2), LCSRecur(i + 1, s1, j, s2));
    }
}

int main()
{
    string s1 = "heelo";
    string s2 = "haiyo";
    cout << LCSRecur(0, s1, 0, s2);
    return 0;
}