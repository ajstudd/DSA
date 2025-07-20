#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

void maxInSubarraySizeK(const std::vector<int> &nums, int k)
{
    // array : 7,3,4,9,1,6,2
    // k=3
    deque<int> dq; // stores indices
    vector<int> result;

    for (int i = 0; i < nums.size(); i++)
    {
        // Remove indices that are out of this window
        if (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        // Remove elements smaller than the current from the back
        while (!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }

        dq.push_back(i); // add current element index

        // Record the max for the current window
        if (i >= k - 1)
        {
            result.push_back(nums[dq.front()]);
        }
    }

    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    int k, n;
    std::cin >> k >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> nums[i];
    }
    maxInSubarraySizeK(nums, k);
    return 0;
}