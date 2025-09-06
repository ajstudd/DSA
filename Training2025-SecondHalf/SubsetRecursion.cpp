#include <iostream>
#include <vector>
#include <algorithm>
// LABEL: Same as Subsequence, but can only contain unique elements
using namespace std;

void findSubsets(int index, vector<int> &nums, vector<int> &current, vector<vector<int>> &result)
{
    result.push_back(current);

    for (int i = index; i < nums.size(); ++i)
    {
        // *** This is the crucial part for handling duplicates ***
        // If the current element is the same as the previous one, and we are not at the
        // start of the loop, skip it to avoid generating duplicate subsets.
        if (i > index && nums[i] == nums[i - 1])
        {
            continue;
        }
        current.push_back(nums[i]);
        findSubsets(i + 1, nums, current, result);
        current.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> current;

    // Sort the input array to handle duplicates effectively
    sort(nums.begin(), nums.end());

    findSubsets(0, nums, current, result);
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = subsets(nums);

    for (const auto &sub : result)
    {
        cout << "[ ";
        for (int item : sub)
        {
            cout << item << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}