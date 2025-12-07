#include <iostream>
#include <vector>
#include <tuple>
#include <cstdint>
#include <array>
#include <algorithm>

using namespace std;

static const long long MOD = 1000000007LL;
void insert_to_basis(array<long long, 61> &basis, long long value)
{
    for (int bit = 60; bit >= 0; --bit)
    {
        long long mask = (1LL << bit);
        if ((value & mask) == 0)
        {
            continue;
        }
        if (basis[bit] == 0)
        {
            basis[bit] = value;
            return;
        }
        value ^= basis[bit];
    }
}

int main()
{
    int nVertices = 0;
    int mEdges = 0;
    cin >> nVertices >> mEdges;
    vector<vector<tuple<int, long long, int>>> adjacencyList;
    adjacencyList.assign(nVertices + 1, {});

    for (int edgeId = 0; edgeId < mEdges; ++edgeId)
    {
        int u = 0;
        int v = 0;
        long long weight = 0;
        cin >> u >> v >> weight;
        adjacencyList[u].push_back(make_tuple(v, weight, edgeId));
        adjacencyList[v].push_back(make_tuple(u, weight, edgeId));
    }
    int maxPow = max(mEdges, 61);
    vector<long long> pow2Count(maxPow + 5, 1LL);
    for (int i = 1; i <= maxPow + 2; ++i)
    {
        pow2Count[i] = (pow2Count[i - 1] * 2LL) % MOD;
    }
    array<long long, 61> pow2BitMod{};
    pow2BitMod.fill(0);
    pow2BitMod[0] = 1 % MOD;
    for (int b = 1; b <= 60; ++b)
    {
        pow2BitMod[b] = (pow2BitMod[b - 1] * 2LL) % MOD;
    }

    vector<int> visited(nVertices + 1, 0);
    vector<long long> xorFromRoot(nVertices + 1, 0LL);
    vector<int> parentEdge(nVertices + 1, -1);

    long long answer = 0LL;

    for (int startVertex = 1; startVertex <= nVertices; ++startVertex)
    {
        if (visited[startVertex] != 0)
        {
            continue;
        }
        vector<int> stackNodes;
        vector<int> stackParents;
        vector<int> stackParentEdge;
        stackNodes.push_back(startVertex);
        stackParents.push_back(-1);
        stackParentEdge.push_back(-1);

        visited[startVertex] = 1;
        xorFromRoot[startVertex] = 0LL;
        parentEdge[startVertex] = -1;

        vector<int> componentNodes;
        componentNodes.push_back(startVertex);
        vector<long long> cycleXors;

        while (!stackNodes.empty())
        {
            int current = stackNodes.back();
            stackNodes.pop_back();
            int currentParent = stackParents.back();
            stackParents.pop_back();
            int currentParentEdge = stackParentEdge.back();
            stackParentEdge.pop_back();

            for (auto &adjItem : adjacencyList[current])
            {
                int neighbor = get<0>(adjItem);
                long long edgeWeight = get<1>(adjItem);
                int edgeId = get<2>(adjItem);

                if (visited[neighbor] == 0)
                {
                    visited[neighbor] = 1;
                    xorFromRoot[neighbor] = xorFromRoot[current] ^ edgeWeight;
                    parentEdge[neighbor] = edgeId;
                    stackNodes.push_back(neighbor);
                    stackParents.push_back(current);
                    stackParentEdge.push_back(edgeId);
                    componentNodes.push_back(neighbor);
                }
                else
                {
                    if (edgeId != parentEdge[current])
                    {
                        long long cycleValue = xorFromRoot[current] ^ xorFromRoot[neighbor] ^ edgeWeight;
                        if (cycleValue != 0LL)
                        {
                            cycleXors.push_back(cycleValue);
                        }
                        else
                        {
                        }
                    }
                }
            }
        }

        int compSize = (int)componentNodes.size();
        if (compSize <= 1)
        {
            continue;
        }
        array<long long, 61> linearBasis{};
        linearBasis.fill(0LL);
        for (long long v : cycleXors)
        {
            insert_to_basis(linearBasis, v);
        }
        int basisDimension = 0;
        long long basisOr = 0LL;
        for (int b = 0; b <= 60; ++b)
        {
            if (linearBasis[b] != 0LL)
            {
                ++basisDimension;
                basisOr |= linearBasis[b];
            }
        }

        long long pairCount = (1LL * compSize * (compSize - 1) / 2LL) % MOD;

        for (int bit = 0; bit <= 60; ++bit)
        {
            long long bitValueMod = pow2BitMod[bit];

            if ((basisOr >> bit) & 1LL)
            {
                if (basisDimension >= 1)
                {
                    long long waysForThisBit = pow2Count[basisDimension - 1];
                    long long contribution = pairCount;
                    contribution = (contribution * waysForThisBit) % MOD;
                    contribution = (contribution * bitValueMod) % MOD;
                    answer += contribution;
                    answer %= MOD;
                }
            }
            else
            {
                long long countOnes = 0LL;
                for (int node : componentNodes)
                {
                    if (((xorFromRoot[node] >> bit) & 1LL) != 0LL)
                    {
                        ++countOnes;
                    }
                }
                long long countZeros = compSize - countOnes;
                long long pairsWithBitOne = (countOnes * countZeros) % MOD;
                long long waysForThisBit = pow2Count[basisDimension];
                long long contribution = pairsWithBitOne;
                contribution = (contribution * waysForThisBit) % MOD;
                contribution = (contribution * bitValueMod) % MOD;
                answer += contribution;
                answer %= MOD;
            }
        }
    }

    cout << (answer % MOD + MOD) % MOD << endl;
    return 0;
}
