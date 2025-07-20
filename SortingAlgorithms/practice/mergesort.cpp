#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted halves nums[left...mid] and nums[mid+1...right]
/**
 * @brief Merges two sorted subarrays into a single sorted subarray
 *
 * This function takes two adjacent sorted subarrays within the given vector
 * and merges them into a single sorted subarray. The left subarray spans
 * from index 'left' to 'mid', and the right subarray spans from index
 * 'mid+1' to 'right'. After merging, the elements from index 'left' to
 * 'right' will be sorted in ascending order.
 *
 * @param nums Reference to the vector containing the subarrays to be merged
 * @param left Starting index of the left subarray (inclusive)
 * @param mid Ending index of the left subarray (inclusive)
 * @param right Ending index of the right subarray (inclusive)
 *
 * @pre The subarray nums[left...mid] must be sorted in ascending order
 * @pre The subarray nums[mid+1...right] must be sorted in ascending order
 * @pre left <= mid < right
 *
 * @post The subarray nums[left...right] will be sorted in ascending order
 *
 * Time Complexity: O(n) where n = right - left + 1
 * Space Complexity: O(n) for the temporary array
 */
void merge(vector<int> &nums, int left, int mid, int right)
{
    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (nums[i] <= nums[j])
        {
            temp.push_back(nums[i]);
            i++;
        }
        else
        {
            temp.push_back(nums[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(nums[i]);
        i++;
    }

    while (j <= right)
    {
        temp.push_back(nums[j]);
        j++;
    }

    // Copy sorted elements back into original array
    // starts from left+k, because this section was having the elements in range left to right, so if if left was 3 and right was 6
    // we would have 3 elements in the temp
    // and the loop will go from 0 to 2
    for (int k = 0; k < temp.size(); k++)
    {
        nums[left + k] = temp[k];
    }
}

void mergeSort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

int main()
{
    vector<int> nums = {1, 2, 3, 5, 4, 8, 9, 4, 55, 4, 477, -1};

    mergeSort(nums, 0, nums.size() - 1);

    for (int num : nums)
    {
        cout << num << " ";
    }

    return 0;
}
