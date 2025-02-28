#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    int V;
    vector<int> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new vector<int>[V];
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v); // Remove for directed graph
    }

    void shortestPathBFS(int src)
    {
        vector<int> dist(V, -1); // Stores shortest distance from src
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node])
            {
                if (dist[neighbor] == -1)
                { // If not visited
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        // Print shortest distance from src to all nodes
        cout << "Shortest distances from node " << src << ":\n";
        for (int i = 0; i < V; i++)
            cout << "Node " << i << " → Distance " << dist[i] << endl;
    }

    ~Graph()
    {
        delete[] adj;
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(3, 4);

    g.shortestPathBFS(0); // Find shortest paths from node 0

    return 0;
}
