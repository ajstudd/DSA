#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to return indices of the two numbers that add up to the target
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> numToIndex; // stores num -> index

    for (int i = 0; i < nums.size(); ++i)
    {
        int complement = target - nums[i];

        // If complement exists in map, return the pair of indices
        if (numToIndex.find(complement) != numToIndex.end())
        {
            return {numToIndex[complement], i};
        }

        // Otherwise, store the current number with its index
        numToIndex[nums[i]] = i;
    }

    // If no solution is found (though problem guarantees one), return empty
    return {};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    if (!result.empty())
    {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    }
    else
    {
        cout << "No solution found." << endl;
    }

    return 0;
}
