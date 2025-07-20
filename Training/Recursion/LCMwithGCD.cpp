#include <iostream>
using namespace std;

// LCM of two nums * HCF of Two nums = Product of Two Nums

int GCDFinder(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    // OPTIMIZE:
    //  return GCDFinder(max(a, b), min(a, b));
    return GCDFinder(max(a, b), min(a, b) % max(a, b));
    //*-> this is basically   if (a < b)
    // {
    //     return GCDFinder(b, a);
    // }
    // return GCDFinder(b, a % b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    // LCM = a*b / HCF of a and b;
    cout << ((a * b) / GCDFinder(a, b));
    return 0;
}
