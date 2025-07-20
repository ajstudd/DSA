#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, px, py, qx, qy;
        cin >> n >> px >> py >> qx >> qy;
        vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        int dx = qx - px;
        int dy = qy - py;
        long long dist_sq = 1LL * dx * dx + 1LL * dy * dy;
        long long sum_sq = 1LL * sum * sum;

        if (dist_sq <= sum_sq)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
