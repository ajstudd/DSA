#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_NODES = 1000;

vector<int> adj[MAX_NODES];
int discoveryTime[MAX_NODES], low[MAX_NODES], visited[MAX_NODES];
int timer = 0;
vector<pair<int, int>> bridges;

void dfs(int node, int parent)
{
    visited[node] = 1;
    discoveryTime[node] = low[node] = ++timer;

    for (auto &it : adj[node])
    {
        if (it == parent)
        {
            continue;
        }

        if (visited[it])
        {
            low[node] = min(low[node], discoveryTime[it]);
        }
        else
        {
            dfs(it, node);
            low[node] = min(low[node], low[it]);

            if (low[it] > discoveryTime[node])
            {
                bridges.push_back({node, it});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    fill(visited, visited + n, 0);
    fill(discoveryTime, discoveryTime + n, -1);
    fill(low, low + n, -1);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, -1);
        }
    }

    cout << "Bridges in the graph:\n";
    for (auto &bridge : bridges)
    {
        cout << bridge.first << " - " << bridge.second << endl;
    }

    return 0;
}
