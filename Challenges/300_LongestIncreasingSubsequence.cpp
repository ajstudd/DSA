#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        // INFO: 10, 9, 2, 5, 3, 7, 101, 18
        // INFO: n = 8
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        for (int i = 0; i < dp.size(); i++)
        {
            cout << dp[i] << " ";
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of LIS: " << sol.lengthOfLIS(nums) << endl;
    return 0;
}
