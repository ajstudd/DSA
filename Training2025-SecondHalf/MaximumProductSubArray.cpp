#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> arr = {1, 5, 6, -99, 8, 9, 14};

    int maxEndingHere = arr[0];
    int minEndingHere = arr[0];
    int maxSoFar = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            swap(maxEndingHere, minEndingHere); // negative flips roles
        }

        maxEndingHere = max(arr[i], maxEndingHere * arr[i]);
        minEndingHere = min(arr[i], minEndingHere * arr[i]);

        maxSoFar = max(maxSoFar, maxEndingHere);
    }

    cout << "Maximum product subarray = " << maxSoFar << endl;
    return 0;
}
