#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    vector<string> exercises(3);
    exercises[0] = "chest";
    exercises[1] = "biceps";
    exercises[2] = "back";
    int n;
    cin >> n;
    vector<int> trainingPlan(n);
    vector<int> scoreOfTrainedMuscle(3, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> trainingPlan[i];
    }
    for (int i = 0; i < n; i++)
    {
        int exercise = i % 3;
        scoreOfTrainedMuscle[exercise] += trainingPlan[i];
    }
    int maxIndex = 0;
    for (int i = 0; i < 3; i++)
    {
        if (scoreOfTrainedMuscle[i] > scoreOfTrainedMuscle[maxIndex])
        {
            maxIndex = i;
        }
    }
    cout << exercises[maxIndex];
    return 0;
}