#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// greedy based question
int mimimumMonth(int k, vector<int> &a)
{
    if (k == 0)
    {
        return 0;
    }
    int req = k;
    int count = 0;
    int sum = 0;
    for (int i = 0; i < 12; i++)
    {
        sum += a[i];
        if (sum >= k)
        {
            count = i + 1;
            break;
        }
    }
    if (count == 0)
    {
        return -1;
    }
    else
    {
        return count;
    }
};

int main()
{
    int requiredGrowth;
    cin >> requiredGrowth;
    vector<int> plantGrowthInMonth(12);
    for (int i = 0; i < 12; i++)
    {
        cin >> plantGrowthInMonth[i];
    }
    sort(plantGrowthInMonth.begin(), plantGrowthInMonth.end(), greater<int>());
    cout << mimimumMonth(requiredGrowth, plantGrowthInMonth);
    return 0;
}