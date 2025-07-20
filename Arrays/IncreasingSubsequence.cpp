#include <iostream>
#include <vector>

using namespace std;

void increasingSubsequence(vector<int> &nums, int index, vector<int> current, vector<vector<int>> &ans)
{

    if (index > nums.size() - 1)
    {
        ans.push_back(current);
        return;
    }
    current.push_back(nums[index]);
    int size = current.size();
    if (size > 0 && nums[index] > current[size - 1])
    {
        increasingSubsequence(nums, index + 1, current, ans);
        current.pop_back();
        increasingSubsequence(nums, index + 1, current, ans);
    }
    else
    {
        increasingSubsequence(nums, index + 1, current, ans);
    }
}

int main()
{
    vector<int> nums = {8, 2, 3, 4, 17, 2, 5, 11};
    vector<vector<int>> ans;
    increasingSubsequence(nums, 0, {}, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ", ";
        }
        cout << endl;
    }
    return 0;
}