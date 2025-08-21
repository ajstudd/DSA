#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int binarySearch(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1; // Not found
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-10, -3, 0, 5, 9, 12};
    int target = 9;

    int index = sol.binarySearch(nums, target);
    if (index != -1)
        cout << "Target found at index " << index << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}
