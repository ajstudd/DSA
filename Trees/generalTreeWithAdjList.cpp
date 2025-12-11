#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    vector<Node *> children;
    Node(int v)
    {
        data = v;
    }
};

vector<vector<int>> adjList;
vector<Node *> nodeList;
vector<int> parentNode;

void buildTree(Node *current, int parent)
{
    parentNode[current->data] = parent;

    for (int neighbor : adjList[current->data])
    {
        if (neighbor == parent)
            continue;
        Node *child = nodeList[neighbor];
        current->children.push_back(child);
        buildTree(child, current->data);
    }
}

int main()
{
    int numberOfNodes = 6;
    vector<pair<int, int>> edges = {
        {1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 6}};
    adjList.assign(numberOfNodes + 1, {});
    nodeList.resize(numberOfNodes + 1);
    for (int i = 0; i <= numberOfNodes; i++)
    {
        nodeList[i] = new Node(i);
    }
    for (auto &edge : edges)
    {
        int firstNode = edge.first;
        int secondNode = edge.second;
        adjList[firstNode].push_back(secondNode);
        adjList[secondNode].push_back(firstNode);
    }
    parentNode.assign(numberOfNodes + 1, 0);
    buildTree(nodeList[1], 0);
    for (int i = 1; i <= numberOfNodes; i++)
    {
        cout << "parent of " << i << " is " << parentNode[i] << endl;
    }
    return 0;
}