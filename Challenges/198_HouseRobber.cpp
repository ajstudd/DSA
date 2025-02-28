// #include <iostream>
// #include <vector>
// using namespace std;
// int totalRob(int index, vector<int> nums, int &amount, vector<int> &tillNValues)
// {
//     if (index >= nums.size())
//     {
//         return amount;
//     }
//     cout << "amount without addition at " << index << ": " << amount << endl;
//     amount += nums[index];
//     cout << "amount with addition at " << index << ": " << amount << endl;
//     int stolen = totalRob(index + 2, nums, amount, tillNValues);
//     cout << "stolen value at " << index << ": " << stolen << endl;
//     tillNValues[index] = stolen;
//     amount -= nums[index];
//     cout << "amount after removal at " << index << ": " << amount << endl;
//     int notStolen = totalRob(index + 1, nums, amount, tillNValues);
//     cout << "notStolen at " << index << ": " << notStolen << endl;
//     tillNValues[index + 1] = notStolen;
//     return stolen > notStolen ? stolen : notStolen;
// }
// int main()
// {
//     vector<int> nums = {1, 2, 3, 4};
//     int size = nums.size();
//     vector<int> iToLastSum(size + 10, -1);
//     int amount = 0;
//     int total = totalRob(0, nums, amount, iToLastSum);
//     return 0;
// };

// // LABEL:improvised but TLE
// // class Solution
// // {
// // public:
// //     int totalRob(int index, vector<int> nums, int &amount)
// //     {
// //         if (index >= nums.size())
// //         {
// //             return amount;
// //         }
// //         amount += nums[index];
// //         int stolen = totalRob(index + 2, nums, amount);
// //         amount -= nums[index];
// //         int notStolen = totalRob(index + 1, nums, amount);
// //         return stolen > notStolen ? stolen : notStolen;
// //     }
// //     int rob(vector<int> &nums)
// //     {
// //         int amount = 0;
// //         int total = totalRob(0, nums, amount);
// //         return total;
// //     }
// // };

#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the maximum amount to rob
int totalRob(vector<int> &nums, vector<int> &dp, int index)
{
    if (index >= nums.size())
        return 0; // Base case: no houses left to rob
    if (dp[index] != -1)
        return dp[index]; // Return memoized result

    // Rob current house and skip one, or skip current house
    dp[index] = max(nums[index] + totalRob(nums, dp, index + 2),
                    totalRob(nums, dp, index + 1));
    return dp[index];
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);        // DP array to store results
    return totalRob(nums, dp, 0); // Start from index 0
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    cout << "Maximum amount that can be robbed: " << rob(nums) << endl;
    return 0;
}
