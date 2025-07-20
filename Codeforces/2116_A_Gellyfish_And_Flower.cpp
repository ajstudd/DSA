#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int minOfGellyfish = min(a, c);
        int minOfFlower = min(b, d);
        if (minOfGellyfish >= minOfFlower)
        {
            cout << "Gellyfish" << endl;
        }
        else
        {
            cout << "Flower" << endl;
        }
    }
    return 0;
}