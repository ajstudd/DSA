#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// connected graph input:
// 4 5
// 0 1
// 0 2
// 1 2
// 1 3
// 2 3

// Iterative DFS using stack and for loop
void DFS(int startNode, vector<vector<int>> &adj, vector<int> &trav, vector<int> &visited)
{
    stack<int> st;
    st.push(startNode);

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (!visited[node])
        {
            visited[node] = 1;
            trav.push_back(node);

            // Add neighbors to stack (in reverse order to maintain left-to-right traversal)
            for (int i = adj[node].size() - 1; i >= 0; i--)
            {
                if (!visited[adj[node][i]])
                {
                    st.push(adj[node][i]);
                }
            }
        }
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