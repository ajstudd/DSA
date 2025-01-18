int findPeakElement(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[mid + 1])
            high = mid; // Peak is in the left half
        else
            low = mid + 1; // Peak is in the right half
    }
    return low; // Low and high converge at peak
}
// need to understand how this is solving all cases of peak element
[ 10, 5, 2, 1 ]