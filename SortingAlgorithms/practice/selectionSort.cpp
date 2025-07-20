#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * @brief Main function that demonstrates the Selection Sort algorithm
 *
 * This function creates a vector of integers and sorts it using the selection sort
 * algorithm. The algorithm works by repeatedly finding the minimum element from
 * the unsorted portion and placing it at the beginning of the unsorted portion.
 *
 * Algorithm steps:
 * 1. Initialize a vector with unsorted integers
 * 2. For each position i from 0 to size-2:
 *    - Find the index of the minimum element in the remaining unsorted portion
 *    - Swap the minimum element with the element at position i
 * 3. Print the sorted array
 *
 * Time Complexity: O(n²) - due to nested loops
 * Space Complexity: O(1) - only uses constant extra space
 *
 * @return int Returns 0 on successful execution
 */
int main()
{
    vector<int> nums = {1, 2, 3, 5, 4, 8, 9, 4, 55, 4, 477, -1};
    int size = nums.size();
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (nums[minIndex] > nums[j])
            {
                minIndex = j;
            }
        }
        swap(nums[i], nums[minIndex]);
    }
    for (int i = 0; i < size; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}