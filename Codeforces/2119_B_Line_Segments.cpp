#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>

// You are given two points (px,py)
//  and (qx,qy)
//  on a Euclidean plane.

// You start at the starting point (px,py)
//  and will perform n
//  operations. In the i
// -th operation, you must choose any point such that the Euclidean distance∗
//  between your current position and the point is exactly ai
// , and then move to that point.

// Determine whether it is possible to reach the terminal point (qx,qy)
//  after performing all operations.

// ∗
// The Euclidean distance between (x1,y1)
//  and (x2,y2)

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤10^4
// ). The description of the test cases follows.

// The first line of each test case contains a single integer n
//  (1≤n≤10^3
// ) — the length of the sequence a
// .

// The second line of each test case contains four integers px,py,qx,qy
//  (1≤px,py,qx,qy≤10^7
// ) — the coordinates of the starting point and terminal point.

// The third line of each test case contains n
//  integers a1,a2,…,an
//  (1≤ai≤10^4
// ) — the distance to move in each operation.

// It is guaranteed that the sum of n
//  over all test cases does not exceed 2⋅10^5
// .

// Output
// For each test case, output "Yes" if it is possible to reach the terminal point (qx,qy)
//  after all operations; otherwise, output "No".

// You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

using namespace std;

// We can use the vector’s triangle property, that sum of two sides should be greater than third side.

// Degenerate and Non-degenerate triangle

// if we have an array , [V1,V2,V3]

// so the maximum area we can reach upon stretching the vectors is the circle.

// we can use the vector’s triangle property to check if the point falls inside the circle, we can even reach it or not.

// We will use minimum range and max range.

// Find the distance between the point 1 and point 2, then use min max to check if it is possible to reach that distance.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, px, py, qx, qy;
        cin >> n >> px >> py >> qx >> qy;
        vector<int> distanceToMove(n);
        int totalRange = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> distanceToMove[i];
            totalRange += distanceToMove[i];
        }
        int distBetweenPandQ = sqrt(pow(qx - px, 2) + pow(qy - py, 2));
        // check if it is possible to make a triangle that gives that distance which is distBetweenPandQ
    }
    return 0;
};