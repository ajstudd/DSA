#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// mid will come from binary search algo
bool possible(int mid, int h, vector<int> &a)
{
    int damage = 0, n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        int diff = a[i + 1] - a[i];
        if (diff > mid)
        {
            damage += mid;
        }
        else
        {
            damage += diff;
        }
    }
    if (damage >= h)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void minValOfK(int n, int h, vector<int> &a)
{
    int low = 1, high = h, ans;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (possible(mid, h, a))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans << endl;
};

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int numOfAttacks, healthOfDragon;
        cin >> numOfAttacks >> healthOfDragon;
        vector<int> attackTime(numOfAttacks);
        for (int i = 0; i < numOfAttacks; i++)
        {
            cin >> attackTime[i];
        }
        minValOfK(numOfAttacks, healthOfDragon, attackTime);
    }
    return 0;
}