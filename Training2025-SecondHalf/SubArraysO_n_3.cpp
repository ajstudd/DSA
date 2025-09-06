#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    vector<int> arr(6);
    iota(arr.begin(), arr.end(), 1);
    vector<vector<int>> result;
    for (int i = 0; i < 6; i++)
    {
        for (int j = i; j < 6; j++)
        {
            vector<int> subset;
            for (int k = i; k <= j; k++)
            {
                subset.push_back(arr[k]);
            }
            result.push_back(subset);
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