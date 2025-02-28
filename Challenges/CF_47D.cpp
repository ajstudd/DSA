// first we are looking for all wrong combinations

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void wrongCombiGen(string input, int bitToChange, int index, vector<string> &result)
{
    if (index >= input.length())
    {
        if (bitToChange == 0)
        {
            result.push_back(input);
        }
        return;
    }
    wrongCombiGen(input, bitToChange, index + 1, result);
    if (bitToChange > 0)
    {
        char original = input[index];
        input[index] = original == '0' ? '1' : '0';
        wrongCombiGen(input, bitToChange - 1, index + 1, result);
        input[index] = original;
    }
}
int main()
{
    int cases;
    cout << "cases: ";
    cin >> cases;
    int correctbit;
    string input;
    vector<string> result;
    for (int i = 0; i < cases; i++)
    {
        cout << "guess:";
        cin >> input;
        cout << "correct bits:";
        cin >> correctbit;
        wrongCombiGen(input, correctbit, 0, result);
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
}
