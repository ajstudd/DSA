#include <bits/stdc++.h>
using namespace std;

struct Compare
{
    bool operator()(const vector<int> &a, const vector<int> &b) const
    {
        // max-heap by priority (3rd element)
        return a[2] < b[2];
        // If you want min-heap, use: return a[2] > b[2];
    }
};

int main()
{
    // priority_queue of vector<int>
    priority_queue<vector<int>, vector<vector<int>>, Compare> pq;

    pq.push({101, 501, 5}); // userId=101, taskId=501, priority=5
    pq.push({102, 502, 2});
    pq.push({103, 503, 8});
    pq.push({104, 504, 3});

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        cout << "User: " << top[0]
             << ", Task: " << top[1]
             << ", Priority: " << top[2] << endl;
    }

    return 0;
}
