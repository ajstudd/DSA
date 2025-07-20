#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        int total_cost = 0;
        if (a > b && (a - b > 1 || a % 2 == 0))
        {
            cout << -1 << endl;
        }
        else if (x > y)
        {
            int units = b - a;
            if (a % 2 == 0)
            {
                total_cost = ceil(units / 2) * y + floor(units / 2) * x;
            }
            else
            {
                if (a > b)
                {
                    total_cost = y;
                }
                else
                {
                    total_cost = ceil(units / 2) * x + floor(units / 2) * y;
                }
            }
            cout << total_cost << endl;
        }
        else
        {
            int units = b - a;
            if (a > b)
            {
                total_cost = y;
            }
            else
            {
                total_cost = units * x;
                cout << total_cost << endl;
            }
        }
    }
    return 0;
};