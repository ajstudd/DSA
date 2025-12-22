#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> nums(n - 1);
    long long sum = 0;
    long long actualSum = n * (n + 1) / 2;
    for (long long i = 0; i < n - 1; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }
    long long missing = actualSum - sum;
    cout << missing;
    return 0;
}