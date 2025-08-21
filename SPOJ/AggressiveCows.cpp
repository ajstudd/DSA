#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool possibleToFitCows(int distance, vector<int> &stalls, int cows)
{
    int cowsPlaced = 1;
    int lastPosition = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - lastPosition >= distance)
        {
            cowsPlaced++;
            lastPosition = stalls[i];
            if (cowsPlaced == cows)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> stalls(n);
        for (int i = 0; i < n; i++)
        {
            cin >> stalls[i];
        }
        sort(stalls.begin(), stalls.end());
        int minGap = stalls[n - 1];
        for (int i = 1; i < n; i++)
        {
            minGap = min(stalls[i] - stalls[i - 1], minGap);
        }
        int start = minGap;
        int end = stalls[n - 1] - stalls[0];
        int minimumDist = end;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (possibleToFitCows(mid, stalls, c))
            {
                minimumDist = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        cout << minimumDist << endl;
    }
    return 0;
}