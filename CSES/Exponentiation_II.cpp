#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;

long long power(long long x, long long k, long long mod)
{
    if (k == 0)
    {
        return 1;
    }
    if (k % 2 == 0)
    {
        long long halfPow = power(x, k / 2, mod);
        return (halfPow * halfPow) % mod;
    }
    else
    {
        long long halfPow = power(x, k / 2, mod);
        return (halfPow * halfPow % mod * x) % mod;
    }
};

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        long long b_c = power(b, c, MOD - 1);
        long long result = power(a, b_c, MOD);
        cout << result << endl;
    }
    return 0;
}
