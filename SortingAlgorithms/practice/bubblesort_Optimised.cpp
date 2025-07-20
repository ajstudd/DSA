#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * @brief Main function demonstrating optimized bubble sort algorithm
 *
 * This function implements an optimized version of bubble sort that includes
 * an early termination condition. The algorithm sorts a predefined vector
 * of integers in ascending order and then displays the sorted result.
 *
 * Optimization features:
 * - Uses a flag (hasValueSwapped) to detect if any swaps occurred during a pass
 * - Terminates early if no swaps are made, indicating the array is already sorted
 * - Reduces the inner loop range with each iteration since the largest elements
 *   "bubble up" to their correct positions
 *
 * Time Complexity:
 * - Best case: O(n) when array is already sorted
 * - Average/Worst case: O(n²)
 *
 * Space Complexity: O(1) - sorts in-place
 *
 * @return int Returns 0 on successful execution
 */
int main()
{
    vector<int> nums = {1, 2, 3, 5, 4, 8, 9, 4, 55, 4, 477, -1};
    int size = nums.size();
    for (int i = 0; i < size - 1; i++)
    {
        bool hasValueSwapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                hasValueSwapped = true;
            }
        }
        if (!hasValueSwapped)
        {
            break;
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}