#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void DFS(vector<int> &traversed, vector<int> &visited, int node,
         vector<vector<int>> &adj)
{
    if (visited[node])
        return;
    visited[node] = 1;

    for (auto neighbor : adj[node])
    {
        if (!visited[neighbor])
            DFS(traversed, visited, neighbor, adj);
    }

    if (node > 1)
    {
        traversed.push_back(node);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++)
        {
            int p;
            cin >> p;
            adj[i].push_back(p);
        }
    }
    vector<int> visited(n + 1, 0);
    vector<int> traversed;
    DFS(traversed, visited, 1, adj);
    for (int i = 0; i < traversed.size(); i++)
    {
        cout << traversed[i] << " ";
    }
    return 0;
}