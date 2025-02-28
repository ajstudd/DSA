#include <iostream>
using namespace std;

int sumOfN(int n)
{
    if (n <= 0)
        return 0;

    int sum = 0;
    sum += n + sumOfN(n - 1);
    return sum;
}
int main()
{
    int n;
    cin >> n;
    cout << sumOfN(n);
    return 0;
}
