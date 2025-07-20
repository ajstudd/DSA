#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<pair<int, int>>> ringsInMatrix;
        vector<int> points = {1, 2, 3, 4, 5};
        ringsInMatrix.push_back({{0, 9}, {9, 0}, {9, 9}, {0, 0}});
        ringsInMatrix.push_back({{1, 8}, {8, 1}, {8, 8}, {1, 1}});
        ringsInMatrix.push_back({{2, 2}, {2, 7}, {7, 2}, {7, 7}});
        ringsInMatrix.push_back({{3, 3}, {3, 6}, {6, 3}, {6, 6}});
        ringsInMatrix.push_back({{4, 4}, {4, 5}, {5, 4}, {5, 5}});
        vector<pair<int, int>> arrows;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                char ch;
                cin >> ch;
                if (ch == 'X')
                {
                    arrows.push_back({i, j});
                }
            }
        }
        int totalPoints = 0;
        for (int i = 0; i < arrows.size(); i++)
        {
            int x = arrows[i].first;
            int y = arrows[i].second;

            for (int j = ringsInMatrix.size() - 1; j >= 0; j--)
            {
                int minX = ringsInMatrix[j][0].first, maxX = ringsInMatrix[j][0].first;
                int minY = ringsInMatrix[j][0].second, maxY = ringsInMatrix[j][0].second;

                for (int z = 1; z < ringsInMatrix[j].size(); z++)
                {
                    minX = min(minX, ringsInMatrix[j][z].first);
                    maxX = max(maxX, ringsInMatrix[j][z].first);
                    minY = min(minY, ringsInMatrix[j][z].second);
                    maxY = max(maxY, ringsInMatrix[j][z].second);
                }

                if (x >= minX && x <= maxX && y >= minY && y <= maxY)
                {
                    totalPoints += points[j];
                    break;
                }
            }
        }
        cout << totalPoints << endl;
    }
    return 0;
}