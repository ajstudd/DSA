#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if (nums.empty())
        return 0;

    int slow = 0; // This pointer keeps track of the last unique element

    for (int fast = 1; fast < nums.size(); ++fast)
    {
        if (nums[fast] != nums[slow])
        {
            ++slow;
            nums[slow] = nums[fast];
        }
    }

    return slow + 1; // New length of array with unique elements
}
// REMARK: This is not deleting elements, it is just bringing unique elements together and printing till the unique elements are there.
int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4};

    int newLength = removeDuplicates(nums);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; ++i)
        cout << nums[i] << " ";
    cout << "\nNew length: " << newLength << endl;

    return 0;
}
