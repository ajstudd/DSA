#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> posPrimes(n + 1, 1);
    posPrimes[0] = 0;
    posPrimes[1] = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (posPrimes[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                posPrimes[j] = 0;
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        if (posPrimes[i])
        {
            cout << i << ", ";
        }
    }
    return 0;
}