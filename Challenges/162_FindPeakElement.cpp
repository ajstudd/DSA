// class Solution {
// public:
// this solution is giving O(n) time complexity.
//     int findPeakElement(vector<int>& nums) {
//         int peak;
//         int size = nums.size();
//         if (size == 1) {
//             return 0;
//         }
//         else if (size < 3) {
//             if (nums[0] > nums[1]) {
//                 peak = 0;
//             }
//             else{
//             peak = 1;
//             }
//         } else {
//             for (int i = 0; i < size; i++) {
//                 if (i<1 && nums[i]>nums[i+1]) {
//                     peak = i;
//                     break;
//                 }
//                 else if(i>size-2 && nums[i]>nums[i-1]){
//                     peak = i;
//                     break;
//                 }
//                 else if(nums[i]>nums[i+1] && nums[i]>nums[i-1]){
//                      peak = i;
//                     break;
//                 }
//             }
//         }
//         return peak;
//     }
// };

// O(log n) time with binary search
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int start = 0, end = nums.size() - 1;
        while (start < end)
        {
            int mid = start + (end - start) / 2;
            // If the mid element is less than the next element, the peak lies to the right
            if (nums[mid] < nums[mid + 1])
            {
                start = mid + 1;
            }
            // Otherwise, the peak lies to the left (or it could be the mid itself)
            else
            {
                end = mid;
            }
        }
        // At the end of the loop, start and end will converge at the peak element
        return start;
    }
};
