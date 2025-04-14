
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void main()
{
    int num = 12;
    cout << num << endl;
    string sNum = to_string(num);
    cout << sNum << endl;
    int size = sNum.length();
    cout << size << endl;
    int split_index = size / 2;
    cout << split_index << endl;
    int fHalf = stoi(sNum.substr(0, split_index));
    cout << fHalf << endl;
    int sHalf = stoi(sNum.substr(split_index));
    cout << sHalf << endl;
}