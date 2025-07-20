#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, k;
        cin >> x >> y >> k;
        int totalSticksNeeded = (k * y) + k;
        int operationForSticks = ceil(totalSticksNeeded - 1) / (x - 1);
        int totalOperations = operationForSticks + k;
        cout << totalOperations << endl;
    }
    return 0;
}