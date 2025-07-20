#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, px, py, qx, qy;
        cin >> n >> px >> py >> qx >> qy;
        vector<int> distanceToMove(n);
        int totalRange = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> distanceToMove[i];
            totalRange += distanceToMove[i];
        }

        int distanceBetweenX = qx - px;
        int distanceBetweenY = qy - py;
        int dist = round(sqrt(distanceBetweenX * distanceBetweenX + distanceBetweenY * distanceBetweenY));

        if (dist <= totalRange && (dist % 2 == totalRange % 2))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}
