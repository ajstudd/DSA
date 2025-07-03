#include <iostream>
#include <vector>
using namespace std;

class DSU
{
    vector<int> parent, rank;

public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0); // Initially all ranks are 0
        for (int i = 0; i < n; i++)
            parent[i] = i; // Each node is its own parent
    }

    // Path Compression (directly connecting to ultimate parent)
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Flatten the tree
        return parent[x];
    }

    // Union by Rank
    void unionSet(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return; // already in the same set

        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    // Helper to display parent array
    void printParents()
    {
        cout << "Parent array: ";
        for (int i = 0; i < parent.size(); i++)
            cout << parent[i] << " ";
        cout << endl;
    }
};

int main()
{
    DSU dsu(7); // Nodes from 0 to 6

    dsu.unionSet(0, 1);
    dsu.unionSet(1, 2);
    dsu.unionSet(3, 4);
    dsu.unionSet(5, 6);
    dsu.unionSet(4, 5);

    dsu.printParents(); // See how sets are merged

    cout << "Find(2): " << dsu.find(2) << endl; // Should point to same root as 0 and 1
    cout << "Find(6): " << dsu.find(6) << endl; // Should point to same root as 3, 4, 5

    return 0;
}
