#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void BFS(vector<int> &traversed, vector<int> &visited, int node, vector<std::vector<int>> adj)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    traversed.push_back(node);
    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        for (int i = 0; i < adj[currentNode].size(); i++)
        {
            int neighbor = adj[currentNode][i];
            if (!visited[adj[currentNode][i]])
            {
                q.push(neighbor);
                visited[neighbor] = 1;
                traversed.push_back(neighbor);
            }
        }
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
    BFS(traversed, visited, 0, adj);
    for (int i = 0; i < traversed.size(); i++)
    {
        cout << traversed[i] << ": ";
    }
    return 0;
}