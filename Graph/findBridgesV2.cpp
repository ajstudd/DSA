#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs(v, adj, visited);
        }
    }
}

bool isConnectedAfterRemovingEdge(vector<vector<int>> &adj, int V, int u, int v)
{
    // Remove edge u-v temporarily
    adj[u].erase(remove(adj[u].begin(), adj[u].end(), v), adj[u].end());
    adj[v].erase(remove(adj[v].begin(), adj[v].end(), u), adj[v].end());

    vector<bool> visited(V, false);
    dfs(0, adj, visited);

    // Restore edge u-v
    adj[u].push_back(v);
    adj[v].push_back(u);

    // Check if all nodes are visited
    for (bool vis : visited)
    {
        if (!vis)
            return false;
    }
    return true;
}

void findBridges(int V, vector<vector<int>> &adj)
{
    for (int u = 0; u < V; u++)
    {
        for (int v : adj[u])
        {
            if (u < v)
            { // To avoid duplicate checking
                if (!isConnectedAfterRemovingEdge(adj, V, u, v))
                {
                    cout << "Bridge found: " << u << " - " << v << endl;
                }
            }
        }
    }
}

int main()
{
    int V = 5;
    vector<vector<int>> adj(V);

    adj[0] = {1, 2};
    adj[1] = {0, 2};
    adj[2] = {0, 1, 3};
    adj[3] = {2, 4};
    adj[4] = {3};

    findBridges(V, adj);

    return 0;
}
