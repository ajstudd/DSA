#include <iostream>
#include <vector>
using namespace std;

void parser(vector<int> &items, vector<int> &parsed, int i)
{
    if (i > items.size() - 1)
    {
        return;
    }
    parser(items, parsed, i + 1);
    parsed.push_back(items[i]);
}

int main()
{
    vector<int> items = {1, 5, 7, 8, 6, 9};
    vector<int> parsed;
    parser(items, parsed, 0);
    for (int item : parsed)
    {
        cout << item << endl;
    }
    return 0;
}