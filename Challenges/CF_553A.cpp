// Kyoya Ootori has a bag with n colored balls that are colored with k different colors. The colors are labeled from 1 to k. Balls of the same color are indistinguishable. He draws balls from the bag one by one until the bag is empty. He noticed that he drew the last ball of color i before drawing the last ball of color i + 1 for all i from 1 to k - 1. Now he wonders how many different ways this can happen.

// Input
// The first line of input will have one integer k (1 ≤ k ≤ 1000) the number of colors.

// Then, k lines will follow. The i-th line will contain ci, the number of balls of the i-th color (1 ≤ ci ≤ 1000).

// The total number of balls doesn't exceed 1000.

// Output
// A single integer, the number of ways that Kyoya can draw the balls from the bag as described in the statement, modulo 1 000 000 007.

#include <vector>
#include <iostream>
using namespace std;

int nCr(int n, int r)
{
    long ncrval = 1;
    for (int i = 1; i <= r; i++)
    {
        ncrval = ncrval * (n - (i - 1)) / i;
    }
    return (int)ncrval;
}

int totalWaysCalculator(vector<int> balls, int size)
{
    int sum = balls[0];
    int numOfWays = 1;
    for (int i = 1; i < size; i++)
    {
        int leftBalls = balls[i] - 1;
        numOfWays *= nCr(leftBalls + sum, leftBalls);
        sum += balls[i];
    }
    return numOfWays;
}

int main()
{
    int n;
    cin >> n;
    vector<int> balls(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> balls[i];
    }
    cout << totalWaysCalculator(balls, n);
    return 0;
}

// REMARK: Wrong answer on test 3 , sir told that this is okay, we will learn to fix it next class