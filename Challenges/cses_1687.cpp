// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cmath>
// using namespace std;

// // observation
// // 5 3
// // 1 1 3 3
// // 4 1
// // 4 2
// // 4 3
// // 5 employees
// // 1 is boss of i+1
// // i = 1 : 2
// // i= 2 : 3
// // 3 is boss of i+1
// // i = 3 : 4
// // i = 4 : 5

// //       (1)  ← General Director
// //      /   \
// //    (2)   (3)
// //         /   \
// //       (4)   (5)

// // queries: 3
// // 4 1
// // boss of 4 and 1 parents away
// // 4 2
// // boss of 4 and 2 parents away
// // 4 3
// // boss of 4 and 3 parents away

// // double result = log2(n);
// class Solution
// {
// public:
//     int time = 0;
//     vector<vector<int>> createAdjacency(int employees, vector<pair<int, int>> &edges)
//     {
//         vector<vector<int>> adj(employees + 1);
//         for (int i = 0; i < edges.size(); i++)
//         {
//             adj[edges[i].first].push_back(edges[i].second);
//             adj[edges[i].second].push_back(edges[i].first);
//         }
//         return adj;
//     }
//     void dfs(int node, int parent, vector<vector<int>> &dp, vector<vector<int>> &adj, int logN, vector<int> &timeIn, vector<int> &timeOut)
//     {
//         // I think n is number of nodes
//         dp[node][0] = parent; // this the immediate parent of that node
//         for (int i = 1; i < logN; i++)
//         {
//             // there is an edge case
//             //    what if we have -1 as value in the parent node array
//             // we can add a check
//             if (dp[node][i - 1] == -1)
//             {
//                 dp[node][i] = -1;
//             }
//             else
//             {
//                 dp[node][i] = dp[dp[node][i - 1]][i - 1];
//             }

//             // other way around
//             //        assume the node which does not have a parent as the parent of itself
//             // so at that time we don't need the check
//         }
//         timeIn[node] = ++time;
//         for (auto &it : adj[node])
//         {
//             if (it != parent)
//             {
//                 dfs(it, node, dp, adj, logN, timeIn, timeOut);
//             }
//             timeOut[node] = ++time;
//         }
//     }
//     int kthParentFinder(int node, int k, vector<vector<int>> dp)
//     {
//         int i = 0;
//         int resultNode = -1;
//         while (k)
//         {
//             if (k & 1)
//             {
//                 resultNode = dp[node][i]; // this array has the nth parent value stored. i is power of 2
//                 // if i=2 , that means 2^2 : 4th parent of n
//             }
//             i++;
//             k /= 2;
//         }
//         return resultNode;
//     }
// };
// int main()
// {
//     int employees, queries;
//     cin >> employees >> queries;
//     vector<int> timeIn(employees + 1);
//     vector<int> timeOut(employees + 1);
//     int ceilVal = ceil(log2(employees));
//     vector<vector<int>> pairedVal(employees + 1, vector<int>(1, -1));
//     pairedVal[1][0] = 1; // for general director;
//     for (int i = 2; i <= employees; i++)
//     {
//         cin >> pairedVal[i][0];
//     }
//     vector<pair<int, int>> edges;
//     for (int i = 1; i < pairedVal.size(); i++)
//     {
//         edges.push_back({i, pairedVal[i][0]});
//     }
//     Solution obj;
//     vector<vector<int>> adj = obj.createAdjacency(employees, edges);
//     vector<vector<int>> dp(employees, vector<int>(ceilVal));
//     obj.dfs(1, -1, dp, adj, ceilVal, timeIn, timeOut);
//     // finding the 2nd parent of node 4
//     cout << obj.kthParentFinder(4, 2, dp);
//     // for (int i = 0; i < adj.size(); i++)
//     // {
//     //     cout << "[";
//     //     for (int j = 0; j < adj[i].size(); j++)
//     //     {
//     //         cout << adj[i][j] << " ";
//     //     }
//     //     cout << "]" << endl;
//     // }
//     return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution
{
public:
    int time = 0;
    vector<vector<int>> createAdjacency(int employees, vector<pair<int, int>> &edges)
    {
        vector<vector<int>> adj(employees + 1);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i].first].push_back(edges[i].second);
            adj[edges[i].second].push_back(edges[i].first);
        }
        return adj;
    }
    void dfs(int node, int parent, vector<vector<int>> &dp, vector<vector<int>> &adj, int logN, vector<int> &timeIn, vector<int> &timeOut)
    {
        dp[node][0] = parent;
        for (int i = 1; i <= logN; i++)
        {
            if (dp[node][i - 1] == -1)
                break;
            dp[node][i] = dp[dp[node][i - 1]][i - 1];
        }

        timeIn[node] = ++time;
        for (auto &it : adj[node])
        {
            if (it != parent)
            {
                dfs(it, node, dp, adj, logN, timeIn, timeOut);
            }
            timeOut[node] = ++time;
        }
    }
    int kthParentFinder(int node, int k, vector<vector<int>> &dp)
    {
        int i = 0;
        while (k && node != -1)
        {
            if (k & 1)
            {
                node = dp[node][i];
            }
            i++;
            k >>= 1;
        }
        return node;
    }
};
int main()
{
    int employees, queries;
    cin >> employees >> queries;
    vector<int> timeIn(employees + 1), timeOut(employees + 1);
    int ceilVal = ceil(log2(employees)) + 1;
    vector<vector<int>> dp(employees + 1, vector<int>(ceilVal, -1));
    vector<vector<int>> adj(employees + 1);
    for (int i = 2; i <= employees; i++)
    {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
        dp[i][0] = boss;
    }
    Solution obj;
    obj.dfs(1, -1, dp, adj, ceilVal, timeIn, timeOut);

    while (queries--)
    {
        int x, k;
        cin >> x >> k;
        cout << obj.kthParentFinder(x, k, dp) << endl;
    }

    return 0;
}
