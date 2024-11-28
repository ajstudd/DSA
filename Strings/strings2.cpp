#include <iostream>
#include <string>
#include <algorithm>
// to use replace function
using namespace std;

int main()
{
    string ss = "   fly me   to   the moon  ";
    cout << ss.length() << endl;
    cout << ss[0] << endl;
    replace(ss.begin(), ss.end(), ' ', 'x');
    // REMARK: Well the subtring doesn't work like splice, it takes the starting point and how many chars I want after that point
    cout << "substr " << ss.substr(21, 24).length() << endl;
    cout << "substr " << ss.substr(21, 24) << endl;
    ss.append("5");
    ss.push_back('j');
    cout << ss[8] << endl;
    cout << ss << endl;
    return 0;
}