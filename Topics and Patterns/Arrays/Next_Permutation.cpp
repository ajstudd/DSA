#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to generate the next lexicographical permutation
void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int i = n - 2;

    // Step 1: Find the break point
    while (i >= 0 && nums[i] >= nums[i + 1])
    {
        i--;
    }

    // Step 2: If found, find the next greater element and swap
    if (i >= 0)
    {
        int j = n - 1;
        while (nums[j] <= nums[i])
        {
            j--;
        }
        swap(nums[i], nums[j]);
    }

    // Step 3: Reverse the elements from i+1 to end
    reverse(nums.begin() + i + 1, nums.end());
}

// Helper function to print the vector
void printVector(const vector<int> &nums)
{
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    cout << "Original permutation: ";
    printVector(nums);

    nextPermutation(nums);

    cout << "Next permutation: ";
    printVector(nums);

    return 0;
}
