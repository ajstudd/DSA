#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<int> &traversed, vector<int> &visited, int node, vector<std::vector<int>> &adj)
{
    if (visited[node])
    {
        return;
    }
    visited[node] = 1;
    traversed.push_back(node);
    for (int i = 0; i < adj[node].size(); i++)
    {
        DFS(traversed, visited, adj[node][i], adj);
    }
}

int main()
{
    int n = 5;
    vector<int> visited(n, 0);
    vector<std::vector<int>> adj(n);
    vector<int> traversed;
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    DFS(traversed, visited, 0, adj);
    for (int i = 0; i < traversed.size(); i++)
    {
        cout << traversed[i] << ": ";
    }
    return 0;
}