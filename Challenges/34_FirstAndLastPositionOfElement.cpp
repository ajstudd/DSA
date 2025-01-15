// class Solution {
// public:
//     int firstOccur(vector<int>& nums, int target, int start, int mid, int end){
//         while(start<=end){
//             if(nums[mid]>target){
//                 end = mid-1;
//                 mid = (start+end)/2;
//                return firstOccur(nums,target, start, mid,end);
//             }
//             else if(nums[mid]<target){
//                 start = mid+1;
//                 mid = (start+end)/2;
//                return firstOccur(nums,target, start, mid,end);
//             }
//             else{
//                 if(nums[mid]==target){
//                     return mid;
//                 }
//                 else{
//                     return -1;
//                 }
//             }
//         }
//         return -1;
//     };
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int size = nums.size()-1;
//         vector<int> result(2,-1);
//         result[0] = firstOccur(nums,target, 0,(0+size)/2,size);
//         if(result[0]==-1){
//             return result;
//         }
//         for(int i=result[0];i<size;i++){
//             if(nums[i+1]!=target && nums[i]==target){
//                 result[1]=i;
//                 break;
//             }
//             else{
//                 i++;
//             }
//         }
//         return result;
//     }
// };

// with binary search
class Solution
{
public:
    int firstOccur(vector<int> &nums, int target, int start, int end)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                if (mid == 0 || nums[mid - 1] != target)
                {
                    return mid;
                }
                end = mid - 1; // Continue searching to the left
            }
        }
        return -1;
    }

    int lastOccur(vector<int> &nums, int target, int start, int end)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                if (mid == nums.size() - 1 || nums[mid + 1] != target)
                {
                    return mid;
                }
                start = mid + 1; // Continue searching to the right
            }
        }
        return -1;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int size = nums.size();
        if (size == 0)
            return {-1, -1};

        int first = firstOccur(nums, target, 0, size - 1);
        if (first == -1)
            return {-1, -1}; // Target not found

        int last = lastOccur(nums, target, first, size - 1);
        return {first, last};
    }
};
