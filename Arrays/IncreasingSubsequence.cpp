#include <iostream>
#include <vector>

using namespace std;

/*
APPROACH: Generate All Increasing Subsequences using Backtracking
- Use recursion to explore all possible subsequences
- At each index, we have two choices: include or exclude the current element
- Include the element only if it maintains the increasing order (current element >= last element in subsequence)
- Use backtracking to explore both possibilities
- Base case: when we reach the end of array, add the current subsequence to result (if length >= 2)
*/

void increasingSubsequence(vector<int> &nums, int index, vector<int> &current, vector<vector<int>> &ans)
{
    // Base case: reached end of array
    if (index == nums.size())
    {
        // Only add subsequences with length >= 2
        if (current.size() >= 2)
        {
            ans.push_back(current);
        }
        return;
    }

    // Choice 1: Include current element (if it maintains increasing order)
    if (current.empty() || nums[index] >= current.back())
    {
        current.push_back(nums[index]);
        increasingSubsequence(nums, index + 1, current, ans);
        current.pop_back(); // Backtrack
    }

    // Choice 2: Exclude current element (always possible)
    increasingSubsequence(nums, index + 1, current, ans);
}

int main()
{
    vector<int> nums = {8, 2, 3, 4, 17, 2, 5, 11};
    vector<vector<int>> ans;
    vector<int> current; // Initialize empty current subsequence

    increasingSubsequence(nums, 0, current, ans);

    cout << "All increasing subsequences (length >= 2):" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
            if (j < ans[i].size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}