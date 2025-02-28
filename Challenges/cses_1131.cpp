#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
// LABEL: Tree Diameter
int diameter = 0;
class Solution
{
public:
    vector<vector<int>> createAdjacency(int V, vector<pair<int, int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i].first].push_back(edges[i].second);
            adj[edges[i].second].push_back(edges[i].first);
        }
        return adj;
    }
    // int diameterFinder(int node, vector<vector<int>> adj, int parent)
    // {
    //     int maxheight = 1;
    //     for (int nextNode : adj[node])
    //     {
    //         if (nextNode == parent)
    //         {
    //             continue;
    //         }
    //         int height = diameterFinder(nextNode, adj, node);
    //         diameter = max(diameter, maxheight + height);
    //         maxheight = max(maxheight, height + 1);
    //     }
    //     return maxheight;
    // }
    int diameterFinder(int node, vector<vector<int>> &adj, int parent)
    {
        int maxheight = 0, secondMaxHeight = 0;

        for (int nextNode : adj[node])
        {
            if (nextNode == parent)
                continue;

            int height = diameterFinder(nextNode, adj, node);

            // Track the two longest heights
            if (height > maxheight)
            {
                secondMaxHeight = maxheight;
                maxheight = height;
            }
            else if (height > secondMaxHeight)
            {
                secondMaxHeight = height;
            }

            // Update global diameter using two longest paths
            diameter = max(diameter, maxheight + secondMaxHeight);
        }

        return maxheight + 1;
    }
};

int main()
{
    int V, E;
    cin >> V >> E;
    vector<pair<int, int>> edges;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    Solution obj;
    vector<vector<int>> adj = obj.createAdjacency(V, edges);
    for (int i = 0; i < adj.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << (j < adj[i].size() - 1 ? "," : "");
        }
        cout << "]" << endl;
    }
    obj.diameterFinder(0, adj, -1);
    cout << "diameter:" << diameter;
    return 0;
}
