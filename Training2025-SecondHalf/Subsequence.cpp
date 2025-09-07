#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void findSubsequences(int index, vector<int> &current, const vector<int> &arr, vector<vector<int>> &result)
{
    if (index >= arr.size())
    {
        result.push_back(current);
        return;
    }
    current.push_back(arr[index]);
    findSubsequences(index + 1, current, arr, result);
    current.pop_back();
    findSubsequences(index + 1, current, arr, result);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> result;
    vector<int> current;
    findSubsequences(0, current, arr, result);
    for (const auto &sub : result)
    {
        cout << "[ ";
        for (int item : sub)
        {
            cout << item << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}