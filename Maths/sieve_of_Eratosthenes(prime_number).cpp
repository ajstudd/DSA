#include <iostream>
#include <vector>
using namespace std;

vector<bool> sieve_of_eratosthenes(int n)
{
    vector<bool> prime(n + 1, true);
    prime[0] = false;
    prime[1] = false;
    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }
    // we have all the primes from 0 to n in this vector
    return prime;
}

int main()
{
    int n;
    cin >> n;
    vector<bool> prime;
    prime = sieve_of_eratosthenes(n);
    cout << "if " << n << " is prime ? " << (prime[n] == true ? "Yes" : "No");
    return 0;
}