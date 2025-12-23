// https://codeforces.com/contest/2179/problem/C

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        long long mn = a[0];
        long long diff = a[1] - a[0];
        cout << max(mn, diff) << "\n";
    }
    return 0;
}
