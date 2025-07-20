#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Main function that solves a competitive programming problem involving two numbers and two operations.
 *
 * For each test case, given four integers a, b, x, y:
 * - a, b: initial numbers where we want to transform 'a' to equal 'b'
 * - x: cost of adding 1 to 'a'
 * - y: cost of XOR operation that flips the least significant bit of 'a'
 *
 * The program calculates the minimum cost to make a equal to b using the available operations:
 * 1. Add 1 to 'a' (cost x)
 * 2. XOR 'a' with 1 (cost y) - this flips between even/odd
 *
 * Special cases handled:
 * - If a == b, cost is 0
 * - If a > b, only possible if a = b + 1 and a is odd (using XOR), otherwise impossible (-1)
 * - If a < b, compares two strategies:
 *   a) Adding only: (b - a) * x
 *   b) Using cycles of add+XOR operations to minimize cost
 *
 * @return 0 on successful execution
 */
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, x, y;
        cin >> a >> b >> x >> y;

        if (a == b)
        {
            cout << 0 << endl;
            continue;
        }

        if (a > b)
        {
            if (a == b + 1 && (a % 2 == 1))
            {
                cout << y << endl;
            }
            else
            {
                cout << -1 << endl;
            }
            continue;
        }

        int cost_addonly = (b - a) * x;

        int cost_cycles = 0;
        int diff = b - a;

        if (a % 2 == 0)
        {
            cost_cycles += y;
            a += 1;
            diff -= 1;
        }
        else
        {
            cost_cycles += x + y;
            a += 2;
            diff -= 2;
        }

        if (diff < 0)
        {
            cout << min(cost_addonly, cost_cycles) << endl;
            continue;
        }

        int num_cycles = diff / 2;
        cost_cycles += num_cycles * (x + y);

        if (diff % 2 == 1)
        {
            cost_cycles += x;
        }

        cout << min(cost_addonly, cost_cycles) << endl;
    }

    return 0;
}
