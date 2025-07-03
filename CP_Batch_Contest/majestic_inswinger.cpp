#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    int n, k;
    cin >> n;
    vector<int> items(n);
    for (int i = 0; i < n; i++)
    {
        cin >> items[i];
    }
    cin >> k;
    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        while (!dq.empty() && items[dq.back()] < items[i])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
            ans.push_back(items[dq.front()]);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}

// we could have used set, max heap/priority queue for finding biggest element but deletion at middle would be difficult
// to solve it using set, (we are using set because we know it will be sorted and we can remove the element from anywhere)
// also we will maintain a map for the frequency of element so that we do not remove the element which may have appeared twice and is in the current window of our check
// [2,2,1,5,3,4,2]
// keep a map of freq
// freq of:
//  1 - 1
//  2 - 2
//  when we add next element 5
//  5 - 1
//  we will decrease freq of 2 , it gets to 1
//  when we add next element 3,
//  we will decrease freq of 2 , if it gets to 0 we will remove it from set