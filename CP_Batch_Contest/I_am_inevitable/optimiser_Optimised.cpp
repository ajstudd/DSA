#include <iostream>
#include <unordered_map>
using namespace std;

// conditions : i>j
// a[j]-a[i]=j-i
// if we solve this eq: a[j]-a[i]=j-i
// a[j]-j = a[i]-i
// now we find the pairs
// we found the numbers which satisfy
// now formula to find number of pairs in n numbers
// nC2 = (n*(n-1))/2
// we will find such number of pairs for each set
int main()
{
    int t;
    cin >> t;

    // a[j]-a[i]=i
    while (t--)
    {
        int n;
        cin >> n;

        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            freq[x - i]++;
        }

        long long pairs = 0;
        for (auto &[key, count] : freq)
        {
            pairs += (long long)count * (count - 1) / 2;
        }

        cout << pairs << "\n";
    }

    return 0;
}
