#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> lis(vector<int> nums)
{
    int size = nums.size();
    vector<int> result(size);
    for (int i = 0; i < size; i++)
    {
        if (result.size() >= size || result.back() < nums[i])
        {
            result.push_back(nums[i]);
        }
        else
        {
            int ind = (*lower_bound(result.begin(), result.end(), nums[i])) - (result.begin());
            result[ind] = nums[i];
        }
    }
    return result;
};
int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    return 0;
}
