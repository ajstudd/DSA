#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// We have
// N books numbered
// 1 to N.
// Book i assumes that you have read Ci books, the j-th of which is book Pi,j: you must read all these Ci books before reading book i.
// Here, you can read all the books in some order.
// You are trying to read the minimum number of books required to read book 1.
// Print the numbers of the books you must read excluding book
// 1 in the order they should be read. Under this condition, the set of books to read is uniquely determined.
// If there are multiple reading orders that satisfy the condition, you may print any of them.

void DFS(vector<int> &traversed, vector<int> &visited, int node,
         vector<vector<int>> &adj, set<int> &inserted)
{
    if (visited[node])
        return;
    visited[node] = 1;

    for (auto neighbor : adj[node])
    {
        if (!visited[neighbor])
            DFS(traversed, visited, neighbor, adj, inserted);
    }

    if (node > 1 && inserted.find(node) == inserted.end())
    {
        traversed.push_back(node);
        inserted.insert(node);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++)
        {
            int p;
            cin >> p;
            adj[i].push_back(p);
        }
    }
    vector<int> visited(n + 1, 0);
    vector<int> traversed;
    // using set to not repeat nodes
    set<int> st;
    DFS(traversed, visited, 1, adj, st);
    for (int i = 0; i < traversed.size(); i++)
    {
        cout << traversed[i] << " ";
    }
    return 0;
}