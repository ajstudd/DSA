#include <iostream>
using namespace std;

int numberOfOperations(int n, int k)
{
    if (k == 1)
    {
        return n;
    }

    int operations = 0;
    while (n > 0)
    {
        operations += n % k;
        n /= k;
    }
    return operations;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        cout << numberOfOperations(n, k) << endl;
    }
    return 0;
}