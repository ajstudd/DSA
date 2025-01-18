
// carvers = 3
// people = n
// pattern of people want : a(i) it ranges from 1 to 10^9
// carvers can choose a pattern x in advance .
// x ranges from 1 to 10^9
// if the toy pattern is y, the carver who has chosen x pattern, the carver will take modulus of |x-y| time.
// the more the toy resembles the one he can make instantly, the faster the carver will cope with the work.
// the carvers can choose who will take on the job.
// carvers can take the work of different people at the same time.
// carvers want to choose patterns for preparation in such a way that the maximum waiting time over all people is as small as possible.
// Output the best maximum waiting time that the carvers can achieve.

// there are three persons in the town
// a,b,c
// each can take :
// |x-yi| time
// |y-yi| time
// |z-yi| time

// suppose each carver chooses a pattern from 1 to 10^9
// a,b,c (this from 1 to 10^9)
// list of people requested :
// 1,2,5,7,9,11,12,17 (this is also from 1 to 10^9)
// we can also sort the request list

// we can try carvers to have highest request num and one to have lowest

// and mid will be average of two

// lets try an example
// a = 1
// c = 17
// b = 9

// waiting time after successful allotment to relevant carvers
// 0,1,4,2,0,2,3,0
// the max waiting time is 4

// suppose we have 1,4,4,14,19,37,59,73,98
// we can solve it using binary search and there will be monotonic function
like first worker will have a[0]+waiting time then it will cover some requests,
 then we will move to first element which is not fulfilled by first worker and the new pattern number assigned to second number is a[already moved i]+wt and then again we will cover some range
then we will move to third worker if the request list is not fulfilled
if the request is fulfilled by some watiting time range
we can decrease the wt and check for lower wt if it is possible
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isFeasible(const vector<int> &a, int n, int T)
{
    int carvers = 1;
    int start = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] - start > 2 * T)
        {
            carvers++;
            start = a[i];
            if (carvers > 3)
                return false;
        }
    }
    return true;
}

int smallestMaxWaitingTime(vector<int> &a, int n)
{
    sort(a.begin(), a.end());
    int left = 0, right = a[n - 1] - a[0], answer = right;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (isFeasible(a, n, mid))
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return answer;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        cout << smallestMaxWaitingTime(a, n) << endl;
    }
    return 0;
}
