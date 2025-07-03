#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1 = ""
// 2 = "a,b,c"
// 3 = "d,e,f"
// 4 = "g,h,i"
// 5 = "j,k,l"
// 6 = "m,n,o"
// 7 = "p,q,r,s"
// 8 = "t,u,v"
// 9 = "w,x,y,z"

void printCombinations(string sub, vector<vector<char>> &keypad, int index, string &st)
{
    if (index >= st.size())
    {
        cout << sub << endl;
        return;
    }
    if (st[index] < '2' || st[index] > '9')
        return;

    // st[index] - '2' is to handle offset of 2, as out keypad is storing the letters from keypad number 2 in actual phone keypad at 0 index.
    for (int i = 0; i < keypad[st[index] - '2'].size(); i++)
    {
        printCombinations(sub + keypad[st[index] - '2'][i], keypad, index + 1, st);
    }
}

int main()
{
    vector<vector<char>> keypad(8);
    string st;
    cin >> st;
    keypad[0] = {'a', 'b', 'c'};
    keypad[1] = {'d', 'e', 'f'};
    keypad[2] = {'g', 'h', 'i'};
    keypad[3] = {'j', 'k', 'l'};
    keypad[4] = {'m', 'n', 'o'};
    keypad[5] = {'p', 'q', 'r', 's'};
    keypad[6] = {'t', 'u', 'v'};
    keypad[7] = {'w', 'x', 'y', 'z'};
    printCombinations("", keypad, 0, st);
    return 0;
}

// ---------------------------------------------------------------------------------------------------------------------------------------
// Pass by reference, saving memory
// void printCombinations(string &sub, vector<vector<char>> &keypad, int index, string &st)
// {
//     if (index >= st.size())
//     {
//         cout << sub << endl;
//         return;
//     }
//     if (st[index] < '2' || st[index] > '9')
//         return;

//     // st[index] - '2' is to handle offset of 2, as out keypad is storing the letters from keypad number 2 in actual phone keypad at 0 index.
//     for (int i = 0; i < keypad[st[index] - '2'].size(); i++)
//     {
//         sub.push_back(keypad[st[index] - '2'][i]);
//         printCombinations(sub, keypad, index + 1, st);
//         sub.pop_back();
//     }
// }

// int main()
// {
//     vector<vector<char>> keypad(8);
//     string st;
//     cin >> st;
//     keypad[0] = {'a', 'b', 'c'};
//     keypad[1] = {'d', 'e', 'f'};
//     keypad[2] = {'g', 'h', 'i'};
//     keypad[3] = {'j', 'k', 'l'};
//     keypad[4] = {'m', 'n', 'o'};
//     keypad[5] = {'p', 'q', 'r', 's'};
//     keypad[6] = {'t', 'u', 'v'};
//     keypad[7] = {'w', 'x', 'y', 'z'};
//     string sub = "";
//     printCombinations(sub, keypad, 0, st);
//     return 0;
// }