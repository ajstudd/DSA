#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

static const int MAXN = 100000;
static const int INF = 1000000000;

vector<vector<int>> adjacencyList;
vector<int> subtreeSize;
vector<int> centroidParent;
vector<bool> isCentroid;
vector<vector<pair<int, int>>> centroidPaths;
vector<multiset<int>> centroidWhiteDistances;
vector<bool> isWhite;

int totalNodesInSubtree;

void computeSubtreeSize(int currentNode, int parentNode)
{
    subtreeSize[currentNode] = 1;
    for (int neighbor : adjacencyList[currentNode])
    {
        if (neighbor != parentNode && !isCentroid[neighbor])
        {
            computeSubtreeSize(neighbor, currentNode);
            subtreeSize[currentNode] += subtreeSize[neighbor];
        }
    }
}

int findCentroid(int currentNode, int parentNode, int totalNodes)
{
    for (int neighbor : adjacencyList[currentNode])
    {
        if (neighbor != parentNode && !isCentroid[neighbor] && subtreeSize[neighbor] > totalNodes / 2)
        {
            return findCentroid(neighbor, currentNode, totalNodes);
        }
    }
    return currentNode;
}

void storeDistances(int currentNode, int parentNode, int currentCentroid, int currentDistance)
{
    centroidPaths[currentNode].push_back({currentCentroid, currentDistance});
    for (int neighbor : adjacencyList[currentNode])
    {
        if (neighbor != parentNode && !isCentroid[neighbor])
        {
            storeDistances(neighbor, currentNode, currentCentroid, currentDistance + 1);
        }
    }
}

void buildCentroidDecomposition(int entryNode, int parentCentroid)
{
    computeSubtreeSize(entryNode, -1);
    int centroid = findCentroid(entryNode, -1, subtreeSize[entryNode]);
    isCentroid[centroid] = true;
    centroidParent[centroid] = parentCentroid;
    storeDistances(centroid, -1, centroid, 0);
    for (int neighbor : adjacencyList[centroid])
    {
        if (!isCentroid[neighbor])
        {
            buildCentroidDecomposition(neighbor, centroid);
        }
    }
}

void toggleNodeColor(int node)
{
    isWhite[node] = !isWhite[node];
    for (auto &pathInfo : centroidPaths[node])
    {
        int centroid = pathInfo.first;
        int distanceToCentroid = pathInfo.second;
        if (isWhite[node])
        {
            centroidWhiteDistances[centroid].insert(distanceToCentroid);
        }
        else
        {
            auto it = centroidWhiteDistances[centroid].find(distanceToCentroid);
            if (it != centroidWhiteDistances[centroid].end())
            {
                centroidWhiteDistances[centroid].erase(it);
            }
        }
    }
}

int queryMinDistance(int node)
{
    int minDistance = INF;
    for (auto &pathInfo : centroidPaths[node])
    {
        int centroid = pathInfo.first;
        int distanceToCentroid = pathInfo.second;
        if (!centroidWhiteDistances[centroid].empty())
        {
            int nearestWhite = *centroidWhiteDistances[centroid].begin();
            minDistance = min(minDistance, nearestWhite + distanceToCentroid);
        }
    }
    if (minDistance == INF)
    {
        return -1;
    }
    return minDistance;
}

int main()
{
    int nNodes = 0;
    cin >> nNodes;

    adjacencyList.assign(nNodes + 1, {});
    for (int i = 0; i < nNodes - 1; i++)
    {
        int u = 0;
        int v = 0;
        cin >> u >> v;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    subtreeSize.assign(nNodes + 1, 0);
    centroidParent.assign(nNodes + 1, -1);
    isCentroid.assign(nNodes + 1, false);
    centroidPaths.assign(nNodes + 1, {});
    centroidWhiteDistances.assign(nNodes + 1, {});
    isWhite.assign(nNodes + 1, false);

    buildCentroidDecomposition(1, -1);

    int queryCount = 0;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++)
    {
        int queryType = 0;
        int node = 0;
        cin >> queryType >> node;
        if (queryType == 0)
        {
            toggleNodeColor(node);
        }
        else if (queryType == 1)
        {
            cout << queryMinDistance(node) << endl;
        }
    }

    return 0;
}
