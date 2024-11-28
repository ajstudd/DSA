#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // Create a HashMap
    unordered_map<string, int> ageMap;

    // Adding elements
    ageMap["Alice"] = 25;
    ageMap["Bob"] = 30;
    ageMap["Charlie"] = 20;

    // Accessing an element
    cout << "Alice's age: " << ageMap["Alice"] << endl;

    // Searching for a key
    if (ageMap.find("Bob") != ageMap.end())
    {
        cout << "Bob found!" << endl;
    }
    else
    {
        cout << "Bob not found!" << endl;
    }

    // Deleting an element
    ageMap.erase("Alice");
    cout << "Alice removed!" << endl;

    // Traversing the HashMap
    cout << "Traversing HashMap:" << endl;
    for (const auto &pair : ageMap)
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Sorting
    vector<pair<string, int>> sortedAgeMap(ageMap.begin(), ageMap.end());
    sort(sortedAgeMap.begin(), sortedAgeMap.end(), [](const auto &a, const auto &b)
         { return a.second < b.second; });
    cout << "Sorted by age:" << endl;
    for (const auto &pair : sortedAgeMap)
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Reversing key-value pairs
    unordered_map<int, string> reversedMap;
    for (const auto &pair : ageMap)
    {
        reversedMap[pair.second] = pair.first;
    }
    cout << "Reversed Map:" << endl;
    for (const auto &pair : reversedMap)
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
