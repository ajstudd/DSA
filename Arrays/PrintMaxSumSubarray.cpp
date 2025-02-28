#include <iostream>
#include <climits> // For INT_MIN

void maxSubarraySum(int arr[], int n)
{
    int maxSum = arr[0], currentSum = arr[0];
    int start = 0, end = 0, tempStart = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > currentSum + arr[i])
        {
            currentSum = arr[i];
            tempStart = i; // Start a new subarray
        }
        else
        {
            currentSum += arr[i]; // Extend the existing subarray
        }

        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            start = tempStart; // Update start index
            end = i;           // Update end index
        }
    }

    // Printing the result
    std::cout << "Maximum Subarray Sum: " << maxSum << std::endl;
    std::cout << "Subarray: ";
    for (int i = start; i <= end; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // int arr[] = {1, 2, 3, 4, 99, 1, 1, 1, 1, 5, 1157};
    int arr[] = {1, 2, 3, -999, 1, 1, 1, 1, 1, 1, 1, 1, 99999999};
    int n = sizeof(arr) / sizeof(arr[0]);

    maxSubarraySum(arr, n);

    return 0;
}
