// https://codeforces.com/contest/2179/problem/B

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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long long total = 0;
        for (int i = 0; i + 1 < n; i++)
        {
            total += abs(a[i] - a[i + 1]);
        }
        long long ans = total;
        ans = min(ans, total - abs(a[0] - a[1]));
        ans = min(ans, total - abs(a[n - 2] - a[n - 1]));
        for (int i = 1; i + 1 < n; i++)
        {
            long long removed =
                abs(a[i - 1] - a[i]) +
                abs(a[i] - a[i + 1]) -
                abs(a[i - 1] - a[i + 1]);

            ans = min(ans, total - removed);
        }
        cout << ans << "\n";
    }
    return 0;
}
