#include <iostream>
using namespace std;

void evenPrinter(int n)
{
    if (n <= 0)
    {
        return;
    }
    int nextitem;
    if (n % 2 == 0)
    {
        cout << n;
        nextitem = n - 2;
    }
    else
    {
        nextitem = n - 1;
    }
    evenPrinter(nextitem);
}

int main()
{
    int n;
    cin >> n;
    evenPrinter(n);
    return 0;
}