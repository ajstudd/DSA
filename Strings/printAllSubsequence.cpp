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

/*
Worst Case Time Complexity: O(2^n × n)
For each character, we have 2 choices: include it or exclude it from the subsequence.
This creates 2^n total subsequences where n is the string length.
Each subsequence construction involves string concatenation which takes O(n) time.
Total complexity: 2^n subsequences × O(n) time per subsequence = O(2^n × n).
*/