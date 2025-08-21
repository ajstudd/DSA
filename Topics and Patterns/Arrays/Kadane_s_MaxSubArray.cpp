// Problem 1: Kadane's Algorithm

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the maximum subarray sum using Kadane's Algorithm
int kadaneMaxSubarraySum(vector<int> &nums)
{
    int maxSoFar = nums[0];
    int currMax = nums[0];

    for (int i = 1; i < nums.size(); ++i)
    {
        // Either extend the current subarray or start a new one
        currMax = max(nums[i], currMax + nums[i]);
        maxSoFar = max(maxSoFar, currMax);
    }
    return maxSoFar;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum: " << kadaneMaxSubarraySum(nums) << endl;
    return 0;
}
