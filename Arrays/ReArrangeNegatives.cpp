#include <iostream>

void rearrangeAlternate(int arr[], int n)
{
    int i = 0, j = 0;

    while (j < n)
    {
        if (arr[j] < 0)
        {
            std::swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }

    int pos = i, neg = 0;
    while (pos < n && neg < pos && arr[neg] < 0)
    {
        std::swap(arr[neg], arr[pos]);
        pos++;
        neg += 2;
    }
}

int main()
{
    int arr[] = {1, 2, -3, -4, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);

    rearrangeAlternate(arr, n);

    std::cout << "Rearranged Array: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}
