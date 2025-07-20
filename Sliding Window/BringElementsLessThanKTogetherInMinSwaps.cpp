#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int groupElementsLessThanOrEqualToK(vector<int> &arr, int k)
{
    int n = arr.size();

    // Step 1: Count how many elements are ≤ k
    int count_good = 0;
    for (int x : arr)
        if (x <= k)
            count_good++;

    // Step 2: Find the window of size count_good with minimum bad elements
    int bad = 0;
    for (int i = 0; i < count_good; i++)
        if (arr[i] > k)
            bad++;

    int min_bad = bad;
    int best_start = 0;

    for (int i = 1; i <= n - count_good; i++)
    {
        if (arr[i - 1] > k)
            bad--;
        if (arr[i + count_good - 1] > k)
            bad++;
        if (bad < min_bad)
        {
            min_bad = bad;
            best_start = i;
        }
    }

    // Step 3: Perform swaps to move ≤ k elements to the best window
    int left = best_start;
    int right = best_start;
    int end = best_start + count_good;
    int swaps = 0;

    while (left < end && right < n)
    {
        // Move left until it finds a bad element
        while (left < end && arr[left] <= k)
            left++;
        // Move right until it finds a good element
        right = max(right, left + 1);
        while (right < n && arr[right] > k)
            right++;
        if (left < end && right < n)
        {
            swap(arr[left], arr[right]);
            swaps++;
            left++;
        }
    }

    return swaps;
}

int main()
{
    vector<int> arr = {6, 5, 4, 3, 2, 2, 2, -1, 5, 2, 2, 2};
    int k;
    cin >> k;

    int swap_count = groupElementsLessThanOrEqualToK(arr, k);
    cout << "Minimum swaps: " << swap_count << endl;
    cout << "Modified array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
