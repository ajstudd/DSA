#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>

using namespace std;
// https://codeforces.com/problemset/problem/1790/D
// Matryoshka is a wooden toy in the form of a painted doll, inside which you can put a similar doll of a smaller size.

// A set of nesting dolls contains one or more nesting dolls, their sizes are consecutive positive integers. Thus, a set of nesting dolls is described by two numbers: s
//  — the size of a smallest nesting doll in a set and m
//  — the number of dolls in a set. In other words, the set contains sizes of s,s+1,…,s+m−1
//  for some integer s
//  and m
//  (s,m>0
// ).

// You had one or more sets of nesting dolls. Recently, you found that someone mixed all your sets in one and recorded a sequence of doll sizes — integers a1,a2,…,an
// .

// You do not remember how many sets you had, so you want to find the minimum number of sets that you could initially have.

// For example, if a given sequence is a=[2,2,3,4,3,1]
// . Initially, there could be 2
//  sets:

// the first set consisting of 4
//  nesting dolls with sizes [1,2,3,4]
// ;
// a second set consisting of 2
//  nesting dolls with sizes [2,3]
// .
// According to a given sequence of sizes of nesting dolls a1,a2,…,an
// , determine the minimum number of nesting dolls that can make this sequence.

// Each set is completely used, so all its nesting dolls are used. Each element of a given sequence must correspond to exactly one doll from some set.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        multiset<long long> dolls;
        for (int i = 0; i < n; i++)
        {
            long long dollNumber;
            cin >> dollNumber;
            dolls.insert(dollNumber);
        }
        map<long long, int> freq;
        for (long long doll : dolls)
        {
            freq[doll]++;
        }

        long long sets = 0;
        for (auto &p : freq)
        {
            long long val = p.first;
            int count = p.second;

            if (freq[val - 1] < count)
            {
                sets += count - freq[val - 1];
            }
        }
        cout << sets << endl;
    }
    return 0;
}
// Time Limit Exceeeded :
// Input:
// 32
// 6016
// 226170959 801991956 521643357 697099391 ....
