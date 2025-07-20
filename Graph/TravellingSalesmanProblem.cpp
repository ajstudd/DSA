#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int tsp(int currentNode, int count, int costSoFar, vector<vector<int>> &edges, vector<bool> &visited)
{
    int n = edges.size();

    if (count == n)
    {
        // All cities visited, return to start
        return costSoFar + edges[currentNode][0];
    }

    int minCost = INT_MAX;

    for (int nextNode = 0; nextNode < n; nextNode++)
    {
        if (!visited[nextNode])
        {
            visited[nextNode] = true;

            minCost = min(minCost,
                          tsp(nextNode, count + 1, costSoFar + edges[currentNode][nextNode], edges, visited));

            visited[nextNode] = false; // backtrack
        }
    }

    return minCost;
}

int main()
{
    vector<vector<int>> edges = {
        {0, 10, 20, 1},
        {15, 0, 30, 15},
        {99, 2, 0, 10},
        {5, 10, 15, 20}};

    int n = edges.size();
    vector<bool> visited(n, false);
    visited[0] = true; // Start from city 0

    int minCost = tsp(0, 1, 0, edges, visited);
    cout << "Minimum TSP Cost (Pure Brute Force): " << minCost << endl;

    return 0;
}
