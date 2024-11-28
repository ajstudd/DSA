#include <iostream>
#include <sstream> // For stringstream
#include <vector>  // For vector
using namespace std;

int main()
{
    string sentence = "Split this string into words";
    vector<string> words;

    stringstream ss(sentence); // Create a stringstream from the string
    string word;

    // Extract words separated by spaces
    while (ss >> word)
    {
        words.push_back(word); // Add each word to the vector
    }

    // Output the words to verify the result
    for (const string &w : words)
    {
        cout << w << endl;
    }

    return 0;
}
