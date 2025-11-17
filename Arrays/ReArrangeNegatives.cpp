#include <iostream>
using namespace std;

// Given an array of positive and negative integers,
// rearrange the array such that positive and negative numbers are placed alternately.
// The order of appearance should be maintained (relative order of positive numbers among themselves and negative numbers among themselves should be preserved).

void rearrangeAlternate(int arr[], int n)
{
    int i = 0, j = 0;

    while (j < n)
    {
        if (arr[j] < 0)
        {
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }

    int pos = i, neg = 0;
    while (pos < n && neg < pos && arr[neg] < 0)
    {
        swap(arr[neg], arr[pos]);
        pos++;
        neg += 2;
    }
}

int main()
{
    int arr[] = {1, 2, -3, -4, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);

    rearrangeAlternate(arr, n);

    cout << "Rearranged Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
