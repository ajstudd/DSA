#include <iostream>
#include <climits> // For INT_MIN

int maxSubarraySum(int arr[], int n)
{
    int maxSum = arr[0], currentSum = arr[0];

    for (int i = 1; i < n; i++)
    {
        currentSum = std::max(arr[i], currentSum + arr[i]); // Extend or start new subarray
        maxSum = std::max(maxSum, currentSum);              // Update max sum
    }

    return maxSum;
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Maximum Subarray Sum: " << maxSubarraySum(arr, n) << std::endl;

    return 0;
}
