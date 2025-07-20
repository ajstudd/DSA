#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * @brief Main function that demonstrates insertion sort algorithm
 *
 * This function creates a vector of integers with unsorted values and applies
 * the insertion sort algorithm to sort them in ascending order. The algorithm
 * works by iterating through the array starting from the second element,
 * comparing each element with the previous sorted portion, and inserting it
 * at the correct position by shifting larger elements to the right.
 *
 * Time Complexity: O(n²) in worst case, O(n) in best case
 * Space Complexity: O(1) - sorts in place
 *
 * @return int Returns 0 on successful execution
 */
int main()
{
    vector<int> nums = {1, 2, 3, 5, 4, 8, 9, 4, 55, 4, 477, -1};
    int size = nums.size();
    for (int i = 1; i < size; i++)
    {
        int current = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > current)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = current;
    }
    for (int i = 0; i < size; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}