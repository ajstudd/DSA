#include <iostream>
using namespace std;
int main()
{
    int n = 10;
    int gap = 0;
    for (int i = n; i >= 1; i--)
    {
        int j = (n - gap) / 2;
        for (int k = 0; k < j; k++)
        {
            cout << "*";
        }
        for (int k = 0; k < gap; k++)
        {
            cout << " ";
        }
        for (int k = 0; k < j; k++)
        {
            cout << "*";
        }
        if (i <= (n / 2))
        {
            gap -= 2;
        }
        else if (i > (n / 2) && gap + 2 < n)
        {
            gap += 2;
        }
        cout << endl;
    }
    return 0;
}