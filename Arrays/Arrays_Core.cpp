#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // this is for accumulate function
using namespace std;

int main()
{
    // array with fixed size;
    int arr[5] = {1, 2, 3, 4, 5};
    // array with automatically size set
    int arr2[] = {1, 2, 3, 4, 5, 6};
    for (const int item : arr2)
    {
        cout << item << endl;
    }
    for (const int item2 : arr)
    {
        cout << item2 << endl;
    }

    // LABEL: Dynamic Arrays
    vector<int> v; // dynamic array

    v.push_back(10); // Insert
    v.push_back(20);
    v.pop_back(); // Remove last

    // Sort
    sort(v.begin(), v.end());

    // Reverse
    reverse(v.begin(), v.end());

    // Find
    if (find(v.begin(), v.end(), 3) != v.end())
        cout << "Found 3";

    // Accumulate (sum)
    int sum = accumulate(v.begin(), v.end(), 0);
    return 0;
}