#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Graph class using an adjacency list
class Graph
{
private:
    vector<vector<int>> adjList; // Adjacency list to store the graph

public:
    // Constructor to initialize a graph with `n` vertices
    Graph(int n)
    {
        adjList.resize(n); // Resizing the adjacency list to have `n` empty vectors
    }

    // Function to add an edge in a directed graph
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v); // Add vertex `v` to the list of vertex `u`
    }

    // Function to add an edge in an undirected graph
    void addUndirectedEdge(int u, int v)
    {
        adjList[u].push_back(v); // Add `v` to `u`'s list
        adjList[v].push_back(u); // Add `u` to `v`'s list (undirected connection)
    }

    // Function to delete an edge from the graph
    void deleteEdge(int u, int v)
    {
        // Remove `v` from `u`'s adjacency list using `remove` and `erase`
        adjList[u].erase(remove(adjList[u].begin(), adjList[u].end(), v), adjList[u].end());
    }

    // Function to delete a vertex and its associated edges
    void deleteVertex(int vertex)
    {
        adjList[vertex].clear(); // Clear all edges originating from the vertex

        // Iterate over all vertices to remove edges pointing to the `vertex`
        for (auto &neighbors : adjList)
        {
            neighbors.erase(remove(neighbors.begin(), neighbors.end(), vertex), neighbors.end());
        }
    }

    // Function to perform Breadth-First Search (BFS)
    void BFS(int start)
    {
        vector<bool> visited(adjList.size(), false); // Keep track of visited nodes
        queue<int> q;                                // Queue to store nodes for BFS
        q.push(start);                               // Start from the given node
        visited[start] = true;                       // Mark the start node as visited

        while (!q.empty())
        {
            int vertex = q.front(); // Get the node at the front of the queue
            q.pop();                // Remove it from the queue
            cout << vertex << " ";  // Print the node

            // Explore all neighbors of the current node
            for (int neighbor : adjList[vertex])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true; // Mark neighbor as visited
                    q.push(neighbor);         // Add neighbor to the queue
                }
            }
        }
        cout << endl; // Print a newline after BFS traversal
    }

    // Function to perform Depth-First Search (DFS)
    void DFS(int start)
    {
        vector<bool> visited(adjList.size(), false); // Keep track of visited nodes
        dfsHelper(start, visited);                   // Call helper for recursive DFS
        cout << endl;                                // Print a newline after DFS traversal
    }

    // Helper function for recursive DFS
    void dfsHelper(int vertex, vector<bool> &visited)
    {
        visited[vertex] = true; // Mark the current node as visited
        cout << vertex << " ";  // Print the current node

        // Recursively visit all unvisited neighbors
        for (int neighbor : adjList[vertex])
        {
            if (!visited[neighbor])
            {
                dfsHelper(neighbor, visited);
            }
        }
    }

    // Function to sort the adjacency list of each vertex
    void sortAdjList()
    {
        for (auto &neighbors : adjList)
        {
            sort(neighbors.begin(), neighbors.end()); // Sort neighbors in ascending order
        }
    }

    // Function to reverse the graph (for directed graphs)
    void reverseGraph()
    {
        vector<vector<int>> reversed(adjList.size()); // Create a new list for the reversed graph

        // Iterate through each vertex and its neighbors
        for (int u = 0; u < adjList.size(); ++u)
        {
            for (int v : adjList[u])
            {
                reversed[v].push_back(u); // Reverse the direction of the edge
            }
        }

        adjList = reversed; // Replace the original adjacency list with the reversed one
    }

    // Function to display the graph's adjacency list
    void display()
    {
        for (int i = 0; i < adjList.size(); ++i)
        {
            cout << i << ": "; // Print the vertex number
            for (int neighbor : adjList[i])
            {
                cout << neighbor << " "; // Print all neighbors of the vertex
            }
            cout << endl; // Newline for the next vertex
        }
    }
};

// Main function to test the Graph class
int main()
{
    Graph g(5); // Create a graph with 5 vertices (0 to 4)

    // Add undirected edges to the graph
    g.addUndirectedEdge(0, 1);
    g.addUndirectedEdge(0, 4);
    g.addUndirectedEdge(1, 2);
    g.addUndirectedEdge(1, 3);
    g.addUndirectedEdge(1, 4);
    g.addUndirectedEdge(3, 4);

    cout << "Graph representation:" << endl;
    g.display(); // Display the graph

    cout << "\nBFS Traversal starting from vertex 0:" << endl;
    g.BFS(0); // Perform BFS starting from vertex 0

    cout << "\nDFS Traversal starting from vertex 0:" << endl;
    g.DFS(0); // Perform DFS starting from vertex 0

    cout << "\nGraph after sorting adjacency lists:" << endl;
    g.sortAdjList(); // Sort the adjacency lists
    g.display();     // Display the graph after sorting

    cout << "\nGraph after reversing:" << endl;
    g.reverseGraph(); // Reverse the graph
    g.display();      // Display the reversed graph

    cout << "\nGraph after deleting edge (1 -> 4):" << endl;
    g.deleteEdge(1, 4); // Delete the edge from 1 to 4
    g.display();        // Display the graph after deleting the edge

    cout << "\nGraph after deleting vertex 3:" << endl;
    g.deleteVertex(3); // Delete vertex 3 and all associated edges
    g.display();       // Display the graph after deleting the vertex

    return 0; // End of program
}
