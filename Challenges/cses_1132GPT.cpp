#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> distA, distB;

void dfs(int node, int parent, int depth, vector<int> &dist, int &farthestNode)
{
    dist[node] = depth;

    if (depth > dist[farthestNode])
        farthestNode = node;

    for (int next : adj[node])
    {
        if (next != parent)
        {
            dfs(next, node, depth + 1, dist, farthestNode);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    adj.resize(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    distA.assign(n + 1, 0);
    int nodeA = 1;
    dfs(1, -1, 0, distA, nodeA);

    distA.assign(n + 1, 0);
    dfs(nodeA, -1, 0, distA, nodeA);

    distB.assign(n + 1, 0);
    int nodeB = nodeA;
    dfs(nodeA, -1, 0, distB, nodeB);

    for (int i = 1; i <= n; i++)
    {
        cout << max(distA[i], distB[i]) << " ";
    }
    cout << endl;

    return 0;
}
