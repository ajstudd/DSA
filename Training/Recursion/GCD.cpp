#include <iostream>
using namespace std;

int GCDFinder(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    if (a < b)
    {
        return GCDFinder(b, a);
    }
    return GCDFinder(b, a % b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << GCDFinder(a, b);
    return 0;
}

// OPTIMIZE:
//  🚀 Optimization Tip:
//  You can swap a and b directly if a < b like this:

// if (a < b)
// {
//     return GCDFinder(b, a);
// }

/*
Worst Case Time Complexity: O(log(min(a, b)))
This implements the Euclidean algorithm using recursion for finding GCD.
Each recursive call reduces the problem size by at least half via the modulo operation.
The number of recursive calls is proportional to the logarithm of the smaller number.
This is much more efficient than the naive approach of checking all divisors O(min(a, b)).
*/