#include <iostream>

using namespace std;
/**
 * @brief Calculates x raised to the power of k using fast exponentiation algorithm
 *
 * This function implements the fast exponentiation algorithm (also known as
 * exponentiation by squaring) to compute x^k efficiently in O(log k) time
 * complexity instead of the naive O(k) approach.
 *
 * The algorithm works by:
 * - If k is 0, return 1 (base case: any number to power 0 is 1)
 * - If k is even, compute x^(k/2) and square the result
 * - If k is odd, compute x^(k/2), square it, and multiply by x
 *
 * @param x The base number to be raised to a power
 * @param k The exponent (power), must be non-negative
 * @return The result of x^k
 *
 * @note This implementation assumes k >= 0. For negative exponents,
 *       additional handling would be required.
 * @note Time complexity: O(log k)
 * @note Space complexity: O(log k) due to recursive call stack
 */
int power(int x, int k)
{
    if (k == 0)
    {
        return 1;
    }
    if (k % 2 == 0)
    {
        int halfPow = power(x, k / 2);
        return halfPow * halfPow;
    }
    else
    {
        int halfPow = power(x, k / 2);
        return halfPow * halfPow * x;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << power(n, k);
    return 0;
}
