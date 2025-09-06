#include <iostream>
#include <vector>

using namespace std;

// We need the original 'm' to reset the inner loop
void nestedLoop(int n, int m, const int original_m)
{
    // Base case: Outer loop finished
    if (n < 0)
    {
        return;
    }

    // Inner loop logic
    if (m < 0)
    {
        // Inner loop finished, print a newline and start next outer loop
        cout << endl;
        nestedLoop(n - 1, original_m, original_m);
    }
    else
    {
        // This is the body of the inner loop
        cout << "(" << n << ", " << m << ") ";

        // Next "iteration" of the inner loop
        nestedLoop(n, m - 1, original_m);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    // We pass 'm' as original_m to remember the starting value
    nestedLoop(n, m, m);
    return 0;
}