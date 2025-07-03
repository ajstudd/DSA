#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMaximum(int arr[], int start, int end)
{
    if (start > end)
    {
        return 0;
    }
    if (start == end)
    {
        return arr[start];
    }
    int mid = (start + end) / 2;
    return max({arr[mid], findMaximum(arr, start, mid - 1), findMaximum(arr, mid + 1, end)});
}

int main()
{
    int arr[] = {6, 5, 4, 17, 99, 1, 2, 3, 17, 19, 2, 3, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << findMaximum(arr, 0, size - 1);
    return 0;
}
