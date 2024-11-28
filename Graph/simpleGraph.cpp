#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    vector<vector<int>> adjList;

public:
    Graph(int n)
    {
        adjList.resize(n);
    }

    // Add an undirected edge
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Display the adjacency list
    void display()
    {
        for (int i = 0; i < adjList.size(); ++i)
        {
            cout << i << ": ";
            for (int neighbor : adjList[i])
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(5);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(3, 4);

    // Display the adjacency list
    cout << "Adjacency List:" << endl;
    g.display();

    return 0;
}
