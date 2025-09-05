#include <iostream>
#include <vector>
using namespace std;

void sieve(vector<int> &primes)
{
    primes[0] = primes[1] = 0;
    for (int i = 2; i * i < primes.size(); i++)
    {
        if (primes[i] == 1)
        {
            for (int j = i * i; j < primes.size(); j += i)
            {
                primes[j] = 0;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> primes(n + 1, 1);

    sieve(primes);

    cout << "Primes up to " << n << ": ";
    for (int i = 2; i <= n; i++)
    {
        if (primes[i])
            cout << i << " ";
    }
    return 0;
}
