#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * @brief Finds the next greater element for each element in the array
 *
 * This function uses a stack-based approach to find the next greater element
 * for each element in the input vector. It traverses the array from right to left,
 * maintaining a stack of elements for which we haven't found a greater element yet.
 *
 * @param nums Vector of integers for which to find next greater elements
 * @return Vector of integers where result[i] contains the next greater element
 *         for nums[i], or -1 if no such element exists
 *
 * @note Time complexity: O(n) where n is the size of the input vector
 * @note Space complexity: O(n) for the result vector and stack
 *
 * @example
 * Input: [4, 5, 2, 25]
 * Output: [5, 25, 25, -1]
 *
 * Input: [13, 7, 6, 12]
 * Output: [-1, 12, 12, -1]
 */

vector<int> nextGreaterElement(vector<int> &nums)
{
    int size = nums.size();
    vector<int> result(size);
    stack<int> st;
    for (int i = size - 1; i >= 0; i--)
    {
        while ((!st.empty()) && st.top() <= nums[i])
            st.pop();
        if (st.empty())
        {
            result[i] = -1;
        }
        else
        {
            result[i] = st.top();
        }
        st.push(nums[i]);
    }
    return result;
}

int main()
{
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> result = nextGreaterElement(nums);

    for (int num : result)
    {
        cout << num << " ";
    }
    return 0;
}

/*
Worst Case Time Complexity: O(n)
Although there's a nested while loop, each element is pushed and popped at most once.
The algorithm processes each element exactly once during the main iteration.
Total stack operations across all iterations: n pushes + at most n pops = O(n).
This is much better than the naive O(n²) approach of checking each element against all following elements.
*/
