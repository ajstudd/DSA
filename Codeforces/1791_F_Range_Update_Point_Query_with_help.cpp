#include <iostream>
#include <vector>
using namespace std;

long long prefixSum(int index, vector<long long> &fenbic)
{
    long long sum = 0;
    while (index > 0)
    {
        sum += fenbic[index];
        index -= (index & (-index));
    }
    return sum;
}

void update(int index, long long valueToAdd, int size, vector<long long> &fenbic)
{
    while (index <= size)
    {
        fenbic[index] += valueToAdd;
        index += (index & (-index));
    }
}

int main()
{
    int numOfValues, queries;
    cin >> numOfValues >> queries;
    vector<long long> nums(numOfValues);
    for (int i = 0; i < numOfValues; i++)
    {
        cin >> nums[i];
    }

    vector<long long> fenbic(numOfValues + 1);
    for (int i = 1; i <= numOfValues; i++)
    {
        update(i, nums[i - 1], numOfValues, fenbic);
    }

    while (queries--)
    {
        int type, first;
        long long second; // Use long long in case values are large
        cin >> type >> first >> second;

        if (type == 1)
        {
            update(first, second - nums[first - 1], numOfValues, fenbic);
            nums[first - 1] = second;
        }
        if (type == 2)
        {
            cout << prefixSum(second, fenbic) - prefixSum(first - 1, fenbic) << endl;
        }
    }

    return 0;
}
