#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long k, a, x, b, y;
        cin >> k >> a >> b >> x >> y;
        if (a < b)
        {
            swap(a, b);
            swap(x, y);
        }
        bool possible = true;
        if (k < a && k < b)
        {
            possible = false;
        }
        long long directKtoB = (k - b + y) / y;
        long long numberOfOpsKtoA = (k - a + x) / x;
        k -= numberOfOpsKtoA * x;
        long long numberOfOpsKtoB = 0;
        if (k >= y)
            numberOfOpsKtoB = (k - b + y) / y;
        long long maxNumber = max(numberOfOpsKtoA + numberOfOpsKtoB, directKtoB);
        if (possible)
            cout << maxNumber << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}

/*
Worst Case Time Complexity: O(t)
The algorithm processes t test cases, each in constant time O(1).
Each test case involves only basic arithmetic operations, comparisons, and assignments.
No loops or recursive calls depend on the input values k, a, b, x, y.
The greedy approach calculates the optimal solution directly without iteration.
*/