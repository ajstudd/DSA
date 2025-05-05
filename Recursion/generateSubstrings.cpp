#include <iostream>
using namespace std;

void generateSubstrings(string s, int start, int end)
{
    if (end > s.length())
        return;

    if (start < end)
    {
        cout << s.substr(start, end - start) << endl;
    }

    generateSubstrings(s, start, end + 1);
    if (end == s.length())
    {
        generateSubstrings(s, start + 1, start + 1);
    }
}

int main()
{
    string s = "abcab";
    generateSubstrings(s, 0, 0);
    return 0;
}
