#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// *can be solved using binary search
// *TLE was there in brute force beacuse in 1 second we can do 10^8 operations only

// int main()
// {
//     int machine, balls;
//     // if each machine takes i second to make balls, give the shortest time to make n number of balls
//     cin >> machine >> balls;
//     vector<int> seconds(machine);
//     for (int i = 0; i < machine; i++)
//     {
//         cin >> seconds[i];
//     }

//     priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
//     for (int i = 0; i < machine; i++)
//     {
//         pq.push({0, seconds[i]});
//     }

//     long long minimumElapsedTime = 0;
//     for (int i = 0; i < balls; i++)
//     {
//         auto curr = pq.top();
//         pq.pop();
//         minimumElapsedTime = curr.first + curr.second;
//         pq.push({minimumElapsedTime, curr.second});
//     }

//     cout << minimumElapsedTime;
//     return 0;
// }

bool possible(vector<int> &machineSeconds, long long time, int tballs)
{
    long long ballmade = 0;
    for (int i = 0; i < machineSeconds.size(); i++)
    {
        ballmade += (time / machineSeconds[i]);
        if (ballmade >= tballs)
        {
            return true;
        }
    }
    return ballmade >= tballs;
}

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> seconds(n);
    for (int i = 0; i < n; i++)
    {
        cin >> seconds[i];
    }
    long long low = 1, high = 1e18;
    long long mintime;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (possible(seconds, mid, t))
        {
            mintime = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << mintime;
    return 0;
}