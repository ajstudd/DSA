#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void tracePath(int i, int j, int n)
{
    cout << "i= " << i << "j= " << j << endl;
    if (i == n - 1 || j == n - 1)
    {
        return;
    }
    tracePath(i, j + 1, n);
    tracePath(i + 1, j, n);
}

int main()
{
    tracePath(0, 0, 4);
    return 0;
}