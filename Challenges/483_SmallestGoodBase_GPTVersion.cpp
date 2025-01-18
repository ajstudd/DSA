#include <iostream>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

// Convert base representation to number
long long convertBaseToNum(int ones, long long base)
{
    long long finalVal = 1;     // Start with 1
    long long currentPower = 1; // Power of base

    for (int i = 1; i < ones; i++)
    {
        currentPower *= base;
        if (currentPower > LLONG_MAX / base) // Check for overflow
            return LLONG_MAX;
        finalVal += currentPower;
        if (finalVal > LLONG_MAX)
            return LLONG_MAX; // Prevent overflow
    }
    return finalVal;
}

// Find the smallest good base
int smallestGoodBaseFinder(long long num)
{
    for (int ones = 63; ones >= 2; ones--)
    { // Max bits in a long long
        long long start = 2, end = num - 1;

        while (start <= end)
        {
            long long mid = start + (end - start) / 2;
            long long converted = convertBaseToNum(ones, mid);

            if (converted == num)
            {
                return mid; // Return the smallest valid base
            }
            else if (converted > num || converted < 0)
            { // Handle overflow
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
    }
    return num - 1; // Default base when no solution is found
}

// Wrapper to convert to string and handle input
string smallestGoodBase(string n)
{
    long long stringToNum = stoll(n); // Convert string to long long
    int base = smallestGoodBaseFinder(stringToNum);
    return to_string(base);
}

// Main function to test
int main()
{
    cout << smallestGoodBase("13") << endl; // Should output "3"
    return 0;
}
