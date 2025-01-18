// There are n boys and m girls attending a theatre club. To set a play "The Big Bang Theory",
// they need to choose a group containing exactly t actors containing no less than 4 boys and no less than one girl.
// How many ways are there to choose a group? Of course,
// the variants that only differ in the composition of the troupe are considered different.

// Perform all calculations in the 64-bit type: long long for С/С++, int64 for Delphi and long for Java.

// Input
// The only line of the input data contains three integers n, m, t (4 ≤ n ≤ 30, 1 ≤ m ≤ 30, 5 ≤ t ≤ n + m).
#include <vector>
#include <iostream>
using namespace std;

long long nCr(int n, int r)
{
    long long ncrval = 1;
    for (int i = 1; i <= r; i++)
    {
        ncrval = ncrval * (n - (i - 1)) / i;
    }
    return ncrval;
}

long long totalWaysCalculator(int b, int g, int t)
{
    long long numOfWays = 0;
    for (int i = 4; i <= b; i++)
    {
        int girls = t - i;
        if (girls >= 1 && (i + girls == t))
        {
            numOfWays += nCr(b, i) * nCr(g, girls);
        }
    }
    return numOfWays;
}

int main()
{
    int tsize, b, g;
    cin >> b >> g >> tsize;
    cout << totalWaysCalculator(b, g, tsize);
    return 0;
}

// approach 2
is to subtracting all invalid cases from the total case all cases:
n + m
        C
            t
                then subtract the sum of invalid possibilities

// #include <vector>
// #include <iostream>
// using namespace std;

// int nCr(int n, int r)
// {
//     long ncrval = 1;
//     for (int i = 1; i <= r; i++)
//     {
//         ncrval = ncrval * (n - (i - 1)) / i;
//     }
//     return (int)ncrval;
// }

// int totalWaysCalculator(int b, int g, int t)
// {
//     int numOfWays = 0;
//     // minimum of boys is 4 and we are going 1 less than t , so we always have one place for girl
//     for (int i = 4; i < t; i++)
//     {
//         int girls = t - i;
//         if (girls <= g && i <= t)
//         {
//             numOfWays += nCr(t, i) * nCr(g, girls);
//         }
//     }
//     return numOfWays;
// }

// int main()
// {
//     int tsize, b, g;
//     cin >> b >> g >> tsize;
//     cout << totalWaysCalculator(b, g, tsize);
//     return 0;
// }