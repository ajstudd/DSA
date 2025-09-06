#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    vector<int> arr(6);
    iota(arr.begin(), arr.end(), 1);
    vector<vector<int>> result;
    for (int i = 0; i < arr.size(); i++)
    {
        vector<int> current_subArray;
        for (int j = i; j < arr.size(); j++)
        {
            current_subArray.push_back(arr[j]);
            result.push_back(current_subArray);
        }
    }
    for (const auto &sub : result)
    {
        for (int item : sub)
        {
            cout << item << " , ";
        }
        cout << endl;
    }
    return 0;
}