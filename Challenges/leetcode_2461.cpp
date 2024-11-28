//* You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

//* The length of the subarray is k, and
//* All the elements of the subarray are distinct.
//* Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

//* A subarray is a contiguous non-empty sequence of elements within an array.

// *Example 1:

// *Input: nums = [1,5,4,2,9,9,9], k = 3
// *Output: 15
// *Explanation: The subarrays of nums with length 3 are:
// *- [1,5,4] which meets the requirements and has a sum of 10.
// *- [5,4,2] which meets the requirements and has a sum of 11.
// - [4,2,9] which meets the requirements and has a sum of 15.
// - [2,9,9] which does not meet the requirements because the element 9 is repeated.
// - [9,9,9] which does not meet the requirements because the element 9 is repeated.
// We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
// Example 2:

// Input: nums = [4,4,4], k = 3
// Output: 0
// Explanation: The subarrays of nums with length 3 are:
// - [4,4,4] which does not meet the requirements because the element 4 is repeated.
// We return 0 because no subarrays meet the conditions.

// INFO: My initial approach with time exceed
class Solution
{
private:
    int checkSumAndReturn(vector<int> sub)
    {
        int size = sub.size();
        int sum = 0;
        sort(sub.begin(), sub.end());
        for (int i = 0; i < size - 1; i++)
        {
            if (sub[i] == sub[i + 1])
            {
                return 0;
            }
            else
            {
                sum += sub[i];
            }
        }
        return sum;
    }

public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        // conditions
        //  k number of elements
        // all are distint
        // return 0 if no subarray meets the criteria
        // my strategy :
        // find the subarray with maximum sum
        // then check that subarray if it has distinct item,
        // if not, check other, and keep on checking till the end.
        int sum = 0;
        int size = nums.size();
        vector<vector<int>> possiblesubs;
        for (int i = 0; i < size - k; i++)
        {
            vector<int> sub;
            for (int j = i; j < i + k; k++)
            {
                sub.push_back(nums[i]);
            }
            possiblesubs.push_back(sub);
        }
        for (int i = 0; i < possiblesubs.size(); i++)
        {
            int sumvalue = checkSumAndReturn(possiblesubs[i]);
            if (sumvalue > sum)
            {
                sum = sumvalue;
            }
        }
        return sum;
    }
};

// INFO: Optimised approach with two pointers, sliding window technique
// Maintain a window of size k using two pointers. As the window slides, check if all elements are distinct using a set or a map.
// Use a set to ensure all elements in the window are distinct. The set supports insertion, deletion, and lookup in O(1) average time.

#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        long long maxSum = 0, currentSum = 0;
        unordered_set<int> distinctElements;
        int n = nums.size();

        for (int i = 0, j = 0; j < n; ++j)
        {
            // Add the current element to the window
            while (distinctElements.count(nums[j]))
            {
                distinctElements.erase(nums[i]);
                currentSum -= nums[i];
                ++i; // Shrink the window from the left
            }
            distinctElements.insert(nums[j]);
            currentSum += nums[j];

            // Check if the window size is exactly k
            if (j - i + 1 == k)
            {
                maxSum = max(maxSum, currentSum);
                // Slide the window by removing the leftmost element
                distinctElements.erase(nums[i]);
                currentSum -= nums[i];
                ++i;
            }
        }

        return maxSum;
    }
};
