#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class DSU
{
    vector<int> parent, size;

public:
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int node)
    {
        while (parent[node] != node)
        {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
    void unionOfSet(int vertice1, int vertice2)
    {
        int parentOfV1 = find(vertice1);
        int parentOfV2 = find(vertice2);

        if (parentOfV1 == parentOfV2)
            return;

        if (size[parentOfV1] < size[parentOfV2])
        {
            parent[parentOfV1] = parentOfV2;
            size[parentOfV2] += size[parentOfV1];
        }
        else
        {
            parent[parentOfV2] = parentOfV1;
            size[parentOfV1] += size[parentOfV2];
        }
    }
};

int main()
{
    DSU obj(5);
    obj.unionOfSet(0, 1);
    obj.unionOfSet(2, 3);
    obj.unionOfSet(3, 4);
    cout << obj.find(0) << endl; // Output: leader of set containing 0
    cout << obj.find(1) << endl; // Same as above
    cout << obj.find(2) << endl; // Leader of set {2,3,4}
    cout << obj.find(4) << endl; // Same as above
    return 0;
}