#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // For iota

using namespace std;
//*Yes I solved it on my own!
//* The comments are just for future understanding.
// FIND function: Returns the representative (root) of the set that 'node' belongs to.
// Uses path compression to flatten the tree, reducing future lookup time.
int find(vector<int> &parent, int node)
{
    if (parent[node] != node)
    {
        parent[node] = find(parent, parent[node]); // Path compression step
    }
    return parent[node];
}

// UNION function: Merges two disjoint sets using union by rank.
// This keeps the resulting tree shallow, improving DSU efficiency.
void unionSet(int v1, int v2, vector<int> &rank, vector<int> &parent)
{
    int parentofV1 = find(parent, v1);
    int parentofV2 = find(parent, v2);

    if (parentofV1 == parentofV2)
        return; // They are already in the same set; adding this edge would create a cycle

    // Union by rank logic:
    // Attach the smaller tree under the larger tree to minimize height.
    if (rank[parentofV1] > rank[parentofV2])
    {
        parent[parentofV2] = parentofV1;
    }
    else if (rank[parentofV1] < rank[parentofV2])
    {
        parent[parentofV1] = parentofV2;
    }
    else
    {
        parent[parentofV2] = parentofV1;
        rank[parentofV1]++;
    }
}

// KRUSKAL's MST function
int kruskalsMST(int V, vector<vector<int>> &edges)
{
    // The goal is to connect all nodes with minimum cost and no cycles.
    // If we include a cycle, that means there's a redundant path (which is not necessary).
    // Preventing cycles ensures that the graph remains a tree.

    vector<int> parent(V), rank(V, 0);

    // Initially, each node is its own parent (self loop). DSU initialization.
    iota(parent.begin(), parent.end(), 0);

    // Step 1: Sort the edge list based on weight (Greedy choice: pick smallest edges first).
    // Example of an edge: {0,3,4} → edge between node 0 and 3 with weight 4
    sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b)
         {
             return a[2] < b[2]; // Sort by the weight (3rd element)
         });

    int totalCost = 0;
    int edgesTaken = 0; // Useful if you want to stop early at V-1 edges.

    // Step 2: Iterate over sorted edges and run DSU to check for cycles.
    for (const auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        // If u and v are not in the same set, add the edge to MST.
        if (find(parent, u) != find(parent, v))
        {
            unionSet(u, v, rank, parent);
            totalCost += wt;
            edgesTaken++;

            // Since MST has exactly V-1 edges, we can stop early.
            if (edgesTaken == V - 1)
                break;
        }
    }

    // At the end, totalCost will be the cost of the Minimum Spanning Tree (MST).
    return totalCost;
}

int main()
{
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges;

    cout << "Enter edges in format: u v weight (0-based indexing)" << endl;
    for (int i = 0; i < E; ++i)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    int minCost = kruskalsMST(V, edges);
    cout << "Minimum Spanning Tree cost: " << minCost << endl;

    return 0;
}
