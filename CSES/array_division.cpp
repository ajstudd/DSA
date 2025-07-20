#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>

using namespace std;

bool feasible(int sum, vector<int> &nums, int k)
{
    int index = 0;
    int subSum = 0;
    while (index < nums.size())
    {
        subSum += nums[index];
        if (subSum >= sum)
        {
            subSum = 0;
            --k;
        }
        index++;
    }
    if (k < 0)
    {
        return false;
    }
    return true;
}

int minPossibleSum(int start, int end, vector<int> &nums, int &k)
{
    int minPoSum = end;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (feasible(mid, nums, k))
        {
            minPoSum = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return minPoSum;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int minPossibleMaxSum = 0;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int start = 0, end = accumulate(nums.begin(), nums.end(), 0);
    minPossibleMaxSum = minPossibleSum(start, end, nums, k);
    cout << minPossibleMaxSum;
    return 0;
}
