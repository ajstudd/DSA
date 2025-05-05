#include <iostream>
#include <string>
using namespace std;

void subsequencePrinter(string &st, int index, string currentSub)
{
    if (index >= st.length())
    {
        cout << currentSub << endl;
        return;
    }

    subsequencePrinter(st, index + 1, currentSub + st[index]);
    subsequencePrinter(st, index + 1, currentSub);
}

int main()
{
    string st = "abcdef";
    subsequencePrinter(st, 0, "");
    return 0;
}