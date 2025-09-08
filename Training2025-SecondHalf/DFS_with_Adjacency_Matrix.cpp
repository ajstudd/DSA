#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adjMatrix, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";

    int n = adjMatrix.size();
    for (int j = 0; j < n; j++)
    {
        if (adjMatrix[node][j] == 1 && !visited[j])
        {
            dfs(j, adjMatrix, visited);
        }
    }
}

int main()
{
    // Example adjacency matrix (4 nodes)
    vector<vector<int>> adjMatrix = {
        {0, 1, 1, 0}, // 0
        {0, 0, 1, 0}, // 1
        {1, 0, 0, 1}, // 2
        {0, 0, 0, 1}  // 3
    };

    int n = adjMatrix.size();
    vector<bool> visited(n, false);

    cout << "DFS starting from node 2: ";
    dfs(2, adjMatrix, visited);

    return 0;
}
