#include <iostream>
#include <vector>

using namespace std;

// Forward declaration is needed because the functions call each other
void generateAllSubarrays(int start_index, const vector<int> &arr, vector<vector<int>> &result);
void generateSubarraysFromStart(int start_index, int end_index, const vector<int> &arr, vector<vector<int>> &result);

// This function acts like the "outer loop": for (int i = 0; ...)
void generateAllSubarrays(int start_index, const vector<int> &arr, vector<vector<int>> &result)
{
    if (start_index >= arr.size())
    {
        return;
    }
    generateSubarraysFromStart(start_index, start_index, arr, result);
    generateAllSubarrays(start_index + 1, arr, result);
}

void generateSubarraysFromStart(int start_index, int end_index, const vector<int> &arr, vector<vector<int>> &result)
{
    if (end_index >= arr.size())
    {
        return;
    }
    vector<int> current_subarray;
    for (int k = start_index; k <= end_index; ++k)
    {
        current_subarray.push_back(arr[k]);
    }
    result.push_back(current_subarray);
    generateSubarraysFromStart(start_index, end_index + 1, arr, result);
}

int main()
{
    vector<int> arr = {1, 2, 4};
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