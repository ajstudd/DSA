#include <iostream>
#include <vector>
using namespace std;

void printSubarrays(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout << "{ ";
            for (int k = i; k <= j; k++)
            {
                cout << arr[k] << " ";
            }
            cout << "}\n";
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 3};
    printSubarrays(arr);
}
