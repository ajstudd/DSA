#include <iostream>
#include <vector>
#include <stack>
using namespace std;

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
