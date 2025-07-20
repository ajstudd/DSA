// User function template for C++

class Solution
{
public:
    void floydWarshall(vector<vector<int>> &dist)
    {
        int n = dist.size();
        int Infinity = 1e8;
        for (int secondary = 0; secondary < n; secondary++)
        {
            for (int source = 0; source < n; source++)
            {
                for (int destination = 0; destination < n; destination++)
                {
                    if (dist[source][secondary] != Infinity && dist[secondary][destination] != Infinity) //*we had to add this check to fulfill geeks for geeks given constraint of 1e8
                        dist[source][destination] = min(dist[source][destination], dist[source][secondary] + dist[secondary][destination]);
                }
            }
        }
    }
};