#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> arr;
void printSubarray(int start, int end)
{
    cout << "[ ";
    for (int k = start; k <= end; k++)
    {
        cout << arr[k] << " ";
    }
    cout << "]" << endl;
}
void generate(int i, int j)
{
    if (i == arr.size())
    {
        return;
    }
    if (j == arr.size())
    {
        generate(i + 1, i + 1);
    }
    else
    {
        printSubarray(i, j);
        generate(i, j + 1);
    }
}

int main()
{
    arr.resize(4);
    iota(arr.begin(), arr.end(), 1);
    generate(0, 0);
    return 0;
}