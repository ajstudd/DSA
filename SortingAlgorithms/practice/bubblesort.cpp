#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * @brief Main function that demonstrates the bubble sort algorithm
 *
 * This function creates a vector of integers with unsorted values and applies
 * the bubble sort algorithm to sort them in ascending order. The algorithm
 * works by repeatedly stepping through the list, comparing adjacent elements
 * and swapping them if they are in the wrong order. The pass through the list
 * is repeated until the list is sorted.
 *
 * Time Complexity: O(n²) in worst and average case, O(n) in best case
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
        for (int j = 0; j < size - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}