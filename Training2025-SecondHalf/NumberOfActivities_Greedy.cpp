#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Activity
{
    int id, start, end;
};

int main()
{
    vector<int> activities(5);
    iota(activities.begin(), activities.end(), 1);
    vector<int> start = {4, 2, 3, 1, 9};
    vector<int> end = {5, 3, 4, 2, 10};
    // vector<pair<int, pair<int, int>>> actData; // or I could use struct
    // for (int i = 0; i < activities.size(); i++)
    // {
    //     actData.push_back({activities[i], {start[i], end[i]}});
    // }
    // sort(actData.begin(), actData.end(),[](const auto &a, const auto &b){
    //     return a.second.second < b.second.second;
    // })
    vector<Activity> actData;
    for (int i = 0; i < activities.size(); i++)
    {
        actData.push_back({activities[i], start[i], end[i]});
    }
    sort(actData.begin(), actData.end(), [](const auto &a, const auto &b)
         { return a.end < b.end; });
    int lastCompleted = actData[0].end;
    int totalPossibleActivities = 1;
    for (int i = 1; i < actData.size(); i++)
    {
        if (lastCompleted <= actData[i].start)
        {
            totalPossibleActivities++;
            lastCompleted = actData[i].end;
        }
    }
    cout << "Total Possible Activities: " << totalPossibleActivities;
    return 0;
}