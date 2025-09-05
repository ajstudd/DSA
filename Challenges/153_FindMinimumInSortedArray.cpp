// 0,1,2,3,4,5,6
// 1,2,3,4,5,6,0
// 2,3,4,5,6,0,1
// 3,4,5,6,0,1,2
// 4,5,6,0,1,2,3
// 5,6,0,1,2,3,4
// 6,0,1,2,3,4,5
// 0,1,2,3,4,5,6

// logic :
// to check if array is rotated : we will compare first with last element
// then we will check if the rotation has crossed the mid and migrated to the left half
// for that we will check if the mid element is greater than the first element
// if yes, we will repeat the process on the left side
// otherwise we will look in the right side
class Solution
{
public:
    int minimium(vector<int> &nums, int start, int end, int mid)
    {
        // 4,5,6,0,1,2,3
        // 2,1
        while (start <= end)
        {
            if (nums[start] > nums[end])
            {
                if (nums[start] > nums[mid])
                {
                    if (nums[mid - 1] > nums[mid])
                    {
                        return nums[mid];
                    }
                    end = mid;
                    mid = (start + end) / 2;
                    return minimium(nums, start, end, mid);
                }
                else
                {
                    if (nums[mid + 1] < nums[mid])
                    {
                        return nums[mid + 1];
                    }
                    start = mid;
                    mid = (start + end) / 2;
                    return minimium(nums, start, end, mid);
                }
            }
            else
            {
                return nums[0];
            }
        }
        return nums[mid];
    };
    int findMin(vector<int> &nums)
    {
        int start = 0;
        int end = nums.size() - 1;
        int mid = (start + end) / 2;
        return minimium(nums, start, end, mid);
    }
};

/*
Worst Case Time Complexity: O(log n)
This implements binary search on a rotated sorted array to find the minimum element.
Each recursive call eliminates half of the search space by comparing mid with start/end.
The algorithm makes at most log₂(n) recursive calls where n is the array size.
This is much better than linear search O(n) that would check every element sequentially.
*/