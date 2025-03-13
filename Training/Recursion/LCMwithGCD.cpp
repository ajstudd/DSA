#include <iostream>
using namespace std;

int GCDFinder(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    // OPTIMIZE:
    //  return GCDFinder(max(a, b), min(a, b));
    return GCDFinder(max(a, b), min(a, b) % max(a, b));
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << ((a * b) / GCDFinder(a, b));
    return 0;
}
