#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 5, 9, 5, 2, 6};
    int size = arr.size();
    int sum = 0;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    cout << sum << endl;
    for (int i = k; i < size + 1; i++)
    {
        sum -= arr[i - k];
        sum += arr[i];
        cout << sum << endl;
    }
    return 0;
}

/*
Worst Case Time Complexity: O(n)
Initial window sum calculation takes O(k) time for the first k elements.
Sliding window technique then processes remaining (n-k) elements in O(1) each.
Total time: O(k) + O(n-k) = O(n), which is much better than naive O(n×k) approach.
This technique avoids recalculating the entire sum for each window position.
*/