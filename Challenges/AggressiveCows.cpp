#include <iostream>
#include <vector>

using namespace std;
// logic
//  keep the first cow at 1st place and then keep migrating by checking if the first stall+distance == stall index
// then keep decreasing cows
//  if all  cows are

// or we can sort the array
// this will help in making sure we asssign the cow stall in efficient way rather than going to far distant stall location if it is possible to just have k distance

// we can use binary search
// 1,2,8,9,15,16,19,22
// like suppose if dist of 2 is possible for 3 cows
// even 4 is possible
// but there will be a time when the distance will stop becoming possible
// we need first occurence of not possible distance
// we can use the logic of first occurence

// bool possibleToAssignCows(vector<int> stalls, int d, int cows) {
//     // this was to check if it is possible to assign cows at k distance
// };

// the complexity of my code is n^2
//  I want to use binary search
int firstOccur(vector<int> &stalls, int dist, int cows)
{
    int count = 0;
    int prev = stalls[0];
    int size = stalls.size();
    for (int i = 0; i < size; i++)
    {
        if (count >= cows)
        {
            return dist;
            break;
        }
        else
        {
            if (stalls[i] >= prev + dist)
            {
                count++;
            }
        }
    }
    if (count < cows)
    {
        return -1;
    }
    else
    {
        return dist;
    }
};
int main()
{
    vector<int> stalls = {1, 2, 4, 9, 10, 11, 12};
    int cows = 5;
    int minDist;
    int size = stalls.size();
    for (int i = 0; i < size; i++)
    {
        int occurringPlace = firstOccur(stalls, i, cows);
        if (occurringPlace == -1)
        {
            break;
        }
        else
        {
            minDist = i;
        }
    }
    cout << minDist;
    return 0;
}