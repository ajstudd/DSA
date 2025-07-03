#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Given an array arr and constants p, q, r,
// you are to find the maximum value of the expression:
// p * arr[i] + q * arr[j] + r * arr[k]
// 0 < i < j < k < n

int main()
{
    int n, p, q, r;
    cin >> n >> p >> q >> r;
    vector<int> items(n);
    vector<int> PrefixMax(n);
    vector<int> SuffixMax(n);
    for (int i = 0; i < n; i++)
    {
        cin >> items[i];
    }
    int ans = INT_MIN;
    int currentPmax = -1;
    int currentSmax = -1;
    for (int i = 0; i < n; i++)
    {
        currentPmax = max(p * items[i], currentPmax);
        PrefixMax[i] = currentPmax;
        currentSmax = max(r * items[(n - i) - 1], currentSmax);
        SuffixMax[(n - i) - 1] = currentSmax;
    }
    int cmax = INT_MIN;
    for (int i = 1; i < n - 1; i++)
    {
        cmax = max(((PrefixMax[i - 1]) + (q * items[i]) + (SuffixMax[i + 1])), cmax);
        ans = max(cmax, ans);
    }
    cout << ans;
    return 0;
}