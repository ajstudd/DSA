#include <iostream>
#include <vector>

using namespace std;

// connected graph input:
// 4 5
// 0 1
// 0 2
// 1 2
// 1 3
// 2 3

void DFS(int node, vector<vector<int>> &adj, vector<int> &trav, vector<int> &visited)
{
    visited[node] = 1;
    trav.push_back(node);
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!visited[adj[node][i]])
            DFS(adj[node][i], adj, trav, visited);
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> adjList(nodes);
    for (int i = 0; i < edges; i++)
    {
        int vertex, edge;
        cin >> vertex >> edge;
        adjList[vertex].push_back(edge);
        adjList[edge].push_back(vertex);
    }
    vector<int> trav;
    vector<int> visited(nodes, 0);
    DFS(0, adjList, trav, visited);
    cout << "DFS Traversal" << endl;
    for (int i = 0; i < trav.size(); i++)
    {
        cout << trav[i] << (i < trav.size() - 1 ? " ->" : "");
    }
    return 0;
}