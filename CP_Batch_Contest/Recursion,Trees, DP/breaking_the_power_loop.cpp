#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
// 1<=n,k<=10^9
int binarySearch(long long num, int k)
{
    int start = 0;
    int end = 31;
    int suitable = 0;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        long long power = 1;
        bool overflow = false;

        for (int i = 0; i < mid; i++)
        {
            if (power > num / k)
            {
                overflow = true;
                break;
            }
            power *= k;
        }

        if (!overflow && power <= num)
        {
            suitable = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return suitable;
}

int numberOfOperation(int n, int k)
{
    int ops = 0;
    while (n > 0)
    {
        if (n < k)
        {
            ops += n;
            n = 0;
        }
        else
        {
            int x = binarySearch(n, k);
            n -= pow(k, x);
            ops += 1;
        }
    }
    return ops;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        cout << numberOfOperation(n, k) << endl;
    }
    return 0;
}