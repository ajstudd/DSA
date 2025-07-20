#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>

using namespace std;

bool feasible(long long maxSum, vector<long long> &nums, long long k)
{
    long long index = 0;
    long long subSum = 0;
    long long subarraysUsed = 1;

    while (index < (long long)nums.size())
    {
        if (subSum + nums[index] > maxSum)
        {
            subarraysUsed++;
            subSum = nums[index];
        }
        else
        {
            subSum += nums[index];
        }
        index++;
    }

    return subarraysUsed <= k;
}

long long minPossibleSum(long long start, long long end, vector<long long> &nums, long long k)
{
    long long minPoSum = end;
    while (start <= end)
    {
        long long mid = start + (end - start) / 2;
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
    long long n, k;
    cin >> n >> k;
    long long minPossibleMaxSum = 0;
    vector<long long> nums(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    long long start = *max_element(nums.begin(), nums.end());
    long long end = accumulate(nums.begin(), nums.end(), 0LL);
    minPossibleMaxSum = minPossibleSum(start, end, nums, k);
    cout << minPossibleMaxSum;
    return 0;
}
