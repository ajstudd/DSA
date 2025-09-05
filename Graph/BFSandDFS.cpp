#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> BFS(vector<vector<int>> &adj, int start)
{
    vector<bool> visited(adj.size(), false);
    queue<int> bque;
    vector<int> trav;

    bque.push(start);
    visited[start] = true;

    while (!bque.empty())
    {
        int node = bque.front();
        bque.pop();
        trav.push_back(node);

        for (int i = 0; i < adj[node].size(); i++)
        {
            int neighbor = adj[node][i];
            if (!visited[neighbor])
            {
                bque.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return trav;
}

// LABEL: BFS from one point to another
vector<int> BFS_StartAndEnd(vector<vector<int>> &adj, int start, int end)
{
    vector<bool> visited(adj.size(), false);
    vector<int> parent(adj.size(), -1);
    queue<int> bque;

    bque.push(start);
    visited[start] = true;

    while (!bque.empty())
    {
        int node = bque.front();
        bque.pop();

        if (node == end)
            break; // early stop on finding destination

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                parent[neighbor] = node;
                bque.push(neighbor);
            }
        }
    }

    // Reconstruct path from start to end
    vector<int> path;
    if (!visited[end])
        return path; // no path

    for (int curr = end; curr != -1; curr = parent[curr])
        path.push_back(curr);

    reverse(path.begin(), path.end());
    return path;
}

vector<int> DFS(vector<vector<int>> &adj, int start)
{
    vector<bool> visited(adj.size(), false);
    stack<int> st;
    vector<int> trav;

    st.push(start);

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (!visited[node])
        {
            visited[node] = true;
            trav.push_back(node);

            for (int i = adj[node].size() - 1; i >= 0; i--)
            {
                int neighbor = adj[node][i];
                if (!visited[neighbor])
                {
                    st.push(neighbor);
                }
            }
        }
    }

    return trav;
}

// LABEL: DFS from one point to another
bool dfsUtil(vector<vector<int>> &adj, int node, int end, vector<bool> &visited, vector<int> &parent)
{
    visited[node] = true;

    if (node == end)
        return true;

    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            parent[neighbor] = node;
            if (dfsUtil(adj, neighbor, end, visited, parent))
                return true;
        }
    }
    return false;
}

vector<int> DFS(vector<vector<int>> &adj, int start, int end)
{
    vector<bool> visited(adj.size(), false);
    vector<int> parent(adj.size(), -1);
    vector<int> path;

    if (!dfsUtil(adj, start, end, visited, parent))
        return path;

    for (int curr = end; curr != -1; curr = parent[curr])
        path.push_back(curr);

    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    vector<vector<int>> adj = {
        {1},
        {2, 3},
        {4, 6},
        {4, 5},
        {8},
        {3},
        {7},
        {6},
        {4}};

    vector<int> result = DFS(adj, 0);

    for (int num : result)
    {
        cout << num << endl;
    }

    return 0;
}

/*
Worst Case Time Complexity: O(V + E)
BFS and DFS both visit each vertex V exactly once and examine each edge E exactly once.
BFS uses a queue and visits neighbors level by level, ensuring optimal path discovery.
DFS uses recursion/stack and explores as deep as possible before backtracking.
Both algorithms have the same time complexity but different space and traversal patterns.
*/
