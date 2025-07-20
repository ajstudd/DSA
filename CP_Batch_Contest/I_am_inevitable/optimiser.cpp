#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> nums;
        vector<int> numbers(n);
        for (int i = 0; i < n; i++)
        {
            int number;
            cin >> number;
            nums[number] = number;
            numbers[i] = number;
        }
        // conditions:
        // i < j
        //  a[j]-a[i]=j-i
        int numOfPairs = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = n - 1; j > i; j--)
            {
                int diff = j - i;
                int diffOfValues = numbers[j] - numbers[i];
                if (diffOfValues == diff)
                {
                    numOfPairs++;
                }
            }
        }
        cout << numOfPairs << endl;
    }
    return 0;
}