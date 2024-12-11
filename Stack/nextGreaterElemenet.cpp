#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums)
{
    vector<int> result(nums.size(), -1); // Initialize result with -1
    stack<int> st;                       // Stack to keep indices
    cout << st.top() << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!st.empty()) // Ensure the stack is not empty before accessing st.top()
        {
            cout << nums[st.top()] << endl;
        }
        while (!st.empty() && nums[st.top()] < nums[i])
        {
            result[st.top()] = nums[i]; // Update result for the index at the top of the stack
            st.pop();                   // Pop the processed index
        }
        st.push(i); // Push the current index onto the stack
    }

    cout << "---------------------------" << endl;

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
