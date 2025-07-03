#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int oppositePairs(string s)
{
    int ptr1 = 0;
    int ptr2 = s.length() - 1;
    int count = 0;
    while (ptr1 <= ptr2)
    {
        if (s[ptr1] != s[ptr2])
        {
            count++;
        }
        ptr1++;
        ptr2--;
    }
    return count;
}

string tStringMaker(string s)
{
    int n = s.size();
    int m = 0;

    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
            m++;
    }

    string t(n + 1, '0');
    for (int x = m; x <= n; x++)
    {
        if ((n % 2 == 1) || ((x - m) % 2 == 0))
        {
            t[x] = '1';
        }
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