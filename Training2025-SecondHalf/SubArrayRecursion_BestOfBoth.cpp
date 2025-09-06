#include <iostream>
#include <vector>
using namespace std;

void generateSubarraysFromStart(int index,
                                vector<int> &current_subarray,
                                const vector<int> &arr,
                                vector<vector<int>> &result)
{
    if (index >= arr.size())
    {
        return;
    }
    current_subarray.push_back(arr[index]);
    result.push_back(current_subarray);
    generateSubarraysFromStart(index + 1, current_subarray, arr, result);
}

void generateAllSubarrays(int start_index, const vector<int> &arr, vector<vector<int>> &result)
{
    if (start_index >= arr.size())
    {
        return;
    }
    vector<int> current_subarray;
    generateSubarraysFromStart(start_index, current_subarray, arr, result);
    generateAllSubarrays(start_index + 1, arr, result);
}

int main()
{
    vector<int> arr = {1, 2, 4, 5};
    vector<vector<int>> result;
    generateAllSubarrays(0, arr, result);
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