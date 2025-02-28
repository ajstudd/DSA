#include <iostream>
using namespace std;

int GCDFinder(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    if (a < b)
    {
        return GCDFinder(b, a);
    }
    return GCDFinder(b, a % b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << GCDFinder(a, b);
    return 0;
}

// OPTIMIZE:
//  🚀 Optimization Tip:
//  You can swap a and b directly if a < b like this:

// if (a < b)
// {
//     return GCDFinder(b, a);
// }