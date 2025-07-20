#include <iostream>
using namespace std;

// if lines a->b intersect with lines c->d or vice versa in a clock return yes.
// clock has numbers from 1 to 12
int main()
{

    // can use plotting the coordinates on line segment, and check if they are overlapping
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a < b)
        {
            swap(a, b);
        }
        if (b < d)
        {
            swap(b, d);
        }
        if ((c > a && c < b) || (d > a && d < b) || (a > c && a < d) || (b > c && b < d))
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}