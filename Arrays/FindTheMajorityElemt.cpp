#include <iostream>

// LABEL: Approach: Boyer-Moore Voting Algorithm (O(n))
// Phase 1: Find a Candidate
// Use a counter to keep track of the most frequent element.
// If the count is 0, take the current element as a potential candidate.
// Phase 2: Verify the Candidate
// Count its occurrences to check if it's the actual majority.

int findMajorityElement(int arr[], int n)
{
    int candidate = 0, count = 0;

    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            candidate = arr[i]; // Select new candidate
        }
        count += (arr[i] == candidate) ? 1 : -1;
    }

    // Verify if candidate is actually the majority element
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == candidate)
        {
            count++;
        }
    }

    return (count > n / 2) ? candidate : -1;
}

int main()
{
    int arr[] = {3, 3, 4, 2, 3, 3, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int majorityElement = findMajorityElement(arr, n);

    if (majorityElement != -1)
    {
        std::cout << "Majority Element: " << majorityElement << std::endl;
    }
    else
    {
        std::cout << "No Majority Element Found" << std::endl;
    }

    return 0;
}
