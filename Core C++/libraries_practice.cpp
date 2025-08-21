#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string st = "Junaid";
    cout << "String before edits: " << st << endl;
    st.append(" Ahmad");
    cout << "String after append: " << st << endl;
    cout << "Subtring from 0 to 4: " << st.substr(0, 4) << endl;
    cout << "Subtring from 4 to last: " << st.substr(4) << endl;
    st.replace(0, 6, "Jazzy");
    cout << "Replaced String from 0 to 6: " << st << endl;

    cout << "Vector Practice: " << st << endl;
    return 0;
}
